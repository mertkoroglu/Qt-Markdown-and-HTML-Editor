#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFile>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private:
    void saveFile();
    void saveAsFile();
    void openFile();
private slots:
    void on_saveBtn_clicked();

    void on_saveAsBtn_clicked();

    void on_openFileBtn_clicked();

    void on_cbMarkdown_stateChanged(int arg1);

protected:
    void closeEvent(QCloseEvent *event) override;  // Declare the closeEvent method

private:
    Ui::Dialog *ui;
    QFile currentFile;
    QString desktopPath;
};
#endif // DIALOG_H
