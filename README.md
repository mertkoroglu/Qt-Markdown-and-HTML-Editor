# Qt-HTML-and-Markdown-Editor

## Overview

This is a Qt-based text editor application that supports plain text, Markdown, and HTML file formats. It provides functionality to open, edit, save, and convert between these formats. The editor allows you to switch between a text view and a Markdown preview.

## Features
![i3](https://github.com/user-attachments/assets/6e245883-446b-4b10-b0bf-0f8c3405455c)
![i4](https://github.com/user-attachments/assets/65b75be2-7c2d-4cbc-bc7e-5a31aa63f91d)
![i1](https://github.com/user-attachments/assets/498d1770-2190-402b-a325-b2b8ee7a6782)
![i2](https://github.com/user-attachments/assets/ba7cd9f7-60b7-4943-bedb-22680f423f2d)


- **Open Files**: Open `.txt`, `.md`, and `.html` files from the user's desktop.
- **Save Files**: Save files in `.txt`, `.md`, and `.html` formats.
- **Markdown Preview**: Toggle between plain text and Markdown preview modes.
- **File Handling**: Supports saving changes and handling unsaved work with prompts.

## Getting Started

### Prerequisites

- **Qt Framework**: Ensure that Qt (version 5.15 or later) is installed on your system.
- **C++ Compiler**: A compatible C++ compiler for building the application.

### Building the Application

1. **Clone the Repository**:
    ```sh
    git clone <repository_url>
    cd <repository_directory>
    ```

2. **Run Qt Creator**: Open the project file `.pro` in Qt Creator.

3. **Build the Project**: Click on the "Build" button in Qt Creator or run the following commands in the terminal:
    ```sh
    qmake
    make
    ```

4. **Run the Application**: After building, run the executable from Qt Creator or from the terminal:
    ```sh
    ./<executable_name>
    ```

### Using the Application

1. **Opening Files**:
   - Click the "Open File" button to select and open a file.
   - Supported file types: `.txt`, `.md`, `.html`.

2. **Editing Files**:
   - The editor displays the content of the opened file. Make changes as needed.

3. **Saving Files**:
   - Click the "Save" button to save changes to the current file.
   - Click the "Save As" button to save the content to a new file with a selected format.

4. **Markdown Preview**:
   - Check the "Markdown" checkbox to switch to the Markdown preview mode.
   - Uncheck the "Markdown" checkbox to return to the plain text editor.

5. **Handling Unsaved Changes**:
   - When closing the application or opening a new file, you will be prompted to save changes if there are unsaved modifications.

## File Format Handling

- **Plain Text (`.txt`)**: Standard text file format.
- **Markdown (`.md`)**: Markdown formatted text with support for basic Markdown syntax.
- **HTML (`.html`)**: HTML formatted text with basic inline styling.

## Example HTML Content for Testing

To test HTML content, you can use the following HTML snippet:

```html
<h1 style="color:blue;">Hello World</h1>
<p style="font-size:16px;">This is a paragraph with inline styling.</p>
<ul>
	<li style="color:red;">Item 1</li>
	<li style="color:green;">Item 2</li>
</ul>
```
