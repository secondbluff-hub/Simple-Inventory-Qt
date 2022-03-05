#include "MainGUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto gui = new MainGUI;
    gui->show();
    return a.exec();
}
