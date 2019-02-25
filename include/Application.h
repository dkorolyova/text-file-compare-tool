
#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>
#include <qt5/QtWidgets/qwidget.h>
#include <memory>
#include "ComparatorForm.h"
#include "SelectFilesForm.h"
#include "Comparator.h"
#include "FilesOpener.h"

class Application {
public:
    Application(const QApplication& app);
    void InitApp();
    virtual ~Application();
private:
    const QApplication& app;
    FileData ShowSelectFilesForm();
    void ShowComparatorForm(FileData* fd);
};

#endif /* APPLICATION_H */

