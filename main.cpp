#include "mainwindow.h"
#include "mainmenu.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    MainMenu m;

    w.show();
    m.show();
    return app.exec();
}
