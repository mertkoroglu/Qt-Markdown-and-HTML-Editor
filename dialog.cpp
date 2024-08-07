#include "dialog.h"
#include "./ui_dialog.h"

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    desktopPath = QDir::homePath() + "/Desktop";
    ui->fileNameField->setText("Not Open");
    ui->markdownEditor->setVisible(false);
}

Dialog::~Dialog()
{
    if (currentFile.isOpen()) {
        currentFile.close();
    }

    delete ui;
}

void Dialog::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Save Changes?",
                                                              "Do you want to save changes before closing the editor?",
                                                              QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);


    if (reply == QMessageBox::Yes) {
        if (currentFile.isOpen()) {
            saveFile();
        } else {
            saveAsFile();
        }
    } else if (reply == QMessageBox::No) {
        ui->fileNameField->setText("Not Open");
        event->accept();
        return;
    } else if (reply == QMessageBox::Cancel) {
        event->ignore();
        return;
    }

    event->accept();
}

void Dialog::saveFile()
{
    if(currentFile.isOpen()){
        currentFile.seek(0);  // Move the file position to the start
        QTextStream out(&currentFile);
        QString str = ui->textEdit->toPlainText() + "\n";
        out << str;
        out.flush();  // Flush the stream buffer to the file
        currentFile.resize(out.pos());  // Truncate the file if the new content is shorter

    }else{
        saveAsFile();
    }
}

void Dialog::saveAsFile()
{

    QString filename = QFileDialog::getSaveFileName(this, "Save As", desktopPath, tr("Text Files (*.txt);;Markdown Files (*.md);;HTML Files (*.html)"));

    if (filename.isEmpty())
        return;


    QFile file(filename);

    // Open the file
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Could not open currentFile for reading and writing";
        return;
    }

    QTextStream out(&file);

    out << ui->textEdit->toPlainText() + "\n";


    // Update currentFile to the new file
    if (currentFile.isOpen()) {
        currentFile.close();
    }

    currentFile.setFileName(filename);

    // Open the currentFile with write permissions
    if (!currentFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
    }


    file.close();
    ui->fileNameField->setText(filename);
}

void Dialog::openFile()
{
    if (currentFile.isOpen()) {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Save Changes?", "Do you want to save changes before opening a new file?",
                                           QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes) {
            saveFile();
        } else if (reply == QMessageBox::Cancel) {
            return;
        }
        currentFile.close();
    }

    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), desktopPath, tr("Text Files (*.txt);;Markdown Files (*.md);;HTML Files (*.html)"));

    if (filename.isEmpty())
        return;

    currentFile.setFileName(filename);

    if (!currentFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning() << "Could not open currentFile for reading and writing";
        return;
    }

    QTextStream in(&currentFile);

    ui->textEdit->setText(in.readAll());
    ui->fileNameField->setText(filename);
}

void Dialog::on_saveBtn_clicked()
{
    saveFile();
}


void Dialog::on_saveAsBtn_clicked()
{
    saveAsFile();
}

void Dialog::on_openFileBtn_clicked()
{
    openFile();
    if(ui->cbMarkdown->checkState()){
        ui->cbMarkdown->setCheckState(Qt::Unchecked);
    }
}



void Dialog::on_cbMarkdown_stateChanged(int arg1)
{
    if(ui->cbMarkdown->checkState()){
        ui->markdownEditor->setMarkdown(ui->textEdit->toPlainText());
        ui->textEdit->setVisible(false);
        ui->markdownEditor->setVisible(true);
    }else{

        ui->textEdit->setVisible(true);
        ui->markdownEditor->setVisible(false);
    }
}

