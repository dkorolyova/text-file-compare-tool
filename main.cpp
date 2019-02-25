
#include <QApplication>

#include "./include/Application.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    
    Application application(app);
    application.InitApp();
    
    return 0;
}