#include "mainwindow.h"

#include <QGridLayout>
#include <QApplication>
#include <QScreen>

mainWindow::mainWindow()
{
    m_pMainMenu = new mainMenu(this);
    m_pGameBoard = gameBoard::GameBoard(this);
    m_pGoToMenu = new QPushButton("Main Menu", this);
    m_pGoToMenu->setDisabled(true);

    QObject::connect(m_pGoToMenu, SIGNAL(clicked()), this, SLOT(onGoToMainMenu()));
    QObject::connect(m_pMainMenu, SIGNAL(onNewGame()), this, SLOT(enableGoToButton()));
    // Create a layout and add widgets to that
    QGridLayout *pLayout = new QGridLayout(this);
    // Add widgets to the layout
    pLayout->addWidget(m_pMainMenu, 0, 0);
    pLayout->addWidget(m_pGameBoard, 1, 0);
    pLayout->addWidget(m_pGoToMenu, 0, 1);
    setLayout(pLayout);

    const auto screenGeometry =  QApplication::primaryScreen()->geometry();
    setFixedSize(screenGeometry.size());
    show();
}

void mainWindow::onGoToMainMenu()
{
    m_pGameBoard->setDisabled(true);
    m_pMainMenu->show();
}

void mainWindow::enableGoToButton()
{
    m_pGoToMenu->setEnabled(true);
}

