#include "mainwindow.h"
#include "mainmenu.h"

#include <QApplication>
#include <QLocale>
#include <QtCore>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    MainMenu m = MainMenu(&w);

    m.setWindowModality(Qt::ApplicationModal);
    w.show();
    m.show();
    return app.exec();
}
