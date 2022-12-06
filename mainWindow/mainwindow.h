#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gameBoard.h"
#include "mainMenu.h"

#include <QWidget>

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    mainWindow();

private slots:
    void onGoToMainMenu();
    void enableGoToButton();

private:
    mainMenu *m_pMainMenu;
    gameBoard *m_pGameBoard;
    QPushButton *m_pGoToMenu;
};

#endif // MAINWINDOW_H
