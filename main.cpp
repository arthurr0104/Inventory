#include "mainWindow/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a game
    mainWindow Game;

    return a.exec();
}
