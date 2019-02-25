
#ifndef _NEWFORM_H
#define _NEWFORM_H

#include <QFileDialog>
#include <memory>
#include "ui_SelectFilesForm.h"
#include "FileData.h"
#include "FilesOpener.h"


class SelectFilesForm : public QDialog {
    Q_OBJECT
public:
    SelectFilesForm(const QApplication& app, FilesOpener*);
    FileData ProcessFiles();
    std::string OpenFile();
    void BtnOk();
    virtual ~SelectFilesForm();
public slots:
    void PressedBrowse(QLineEdit* path, std::string&);
    void CloseApp();
private:
    const QApplication& app;
    Ui::SelectFilesForm widget;
    std::string path_first_file_;
    std::string path_second_file_;
    FilesOpener *files_opener;
};

#endif /* _NEWFORM_H */
