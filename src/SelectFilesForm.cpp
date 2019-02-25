
#include "../include/SelectFilesForm.h"

SelectFilesForm::SelectFilesForm(const QApplication& app, FilesOpener *files_opener): app(app), files_opener(files_opener) {
    widget.setupUi(this);
    connect(widget.btnBrowseFirst, &QPushButton::clicked,
            [ = ](){this->PressedBrowse(widget.pathFirstFile, path_first_file_);});
    connect(widget.btnBrowseSecond, &QPushButton::clicked,
            [ = ](){this->PressedBrowse(widget.pathSecondFile, path_second_file_);});
            widget.btnBoxCloseOk->button(widget.btnBoxCloseOk->Ok)->setDisabled(true);
    connect(widget.btnBoxCloseOk->button(widget.btnBoxCloseOk->Ok), SIGNAL(clicked()), this, SLOT(ProcessFiles()));
    connect(widget.btnBoxCloseOk->button(widget.btnBoxCloseOk->Close), SIGNAL(clicked()), this, SLOT(CloseApp()));
}

std::string SelectFilesForm::OpenFile() {
    QString filename = QFileDialog::getOpenFileName (
            this,
            "Open Text file",
            QDir::currentPath(),
            "All files (*.*) ;;");
    return filename.toStdString();
}

void SelectFilesForm::PressedBrowse(QLineEdit *path, std::string& path_string) {
    path_string = this->OpenFile();
    path->setText(path_string.c_str());
    this->BtnOk();
}

void SelectFilesForm::BtnOk() {
    if (!(path_first_file_.empty()) && !(path_second_file_.empty())) {
        widget.btnBoxCloseOk->button(widget.btnBoxCloseOk->Ok)->setEnabled(true);
    }   
}

FileData SelectFilesForm::ProcessFiles() {
    return files_opener->OpenFiles(path_first_file_, path_second_file_);
}

void SelectFilesForm::CloseApp() {
    app.quit();
}

SelectFilesForm::~SelectFilesForm() {
}
