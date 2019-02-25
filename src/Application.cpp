#include "../include/Application.h"

Application::Application(const QApplication& app) : app(app) {
}

void Application::InitApp() {
    FileData fd = ShowSelectFilesForm();
    ShowComparatorForm(&fd);
}

FileData Application::ShowSelectFilesForm() {
    FilesOpener *files_opener = new FilesOpener;
    SelectFilesForm select_files_form(app, files_opener);
    select_files_form.show();
    app.exec();
    return select_files_form.ProcessFiles();
}

void Application::ShowComparatorForm(FileData* fd) {
    Comparator comparator;
    ComparatorForm comparator_form;
    comparator_form.ShowCompared(comparator.Compare(fd), fd);
    
    if (!fd->IsEmpty()) {
        comparator_form.show();
        app.exec();
    }
}

Application::~Application() {
}