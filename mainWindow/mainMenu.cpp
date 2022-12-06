#include "mainMenu.h"
#include "gameBoard.h"

#include <QHBoxLayout>
#include <QApplication>

mainMenu::mainMenu(QWidget *parent)
    : QWidget(parent)
{
    m_pNewGame = new QPushButton("New Game", this);
    m_pQuit = new QPushButton("Quit", this);

    // Connect signals with slots
    QObject::connect(m_pNewGame, SIGNAL(clicked()), this, SLOT(hideMenu()));
    auto pBoard = gameBoard::GameBoard();
    QObject::connect(m_pNewGame, SIGNAL(clicked()), pBoard, SLOT(onNewGame()));
    QObject::connect(m_pQuit, SIGNAL(clicked()), this, SLOT(quitGame()));

    QHBoxLayout *pLayout = new QHBoxLayout(this);
    pLayout->addWidget(m_pNewGame);
    pLayout->addWidget(m_pQuit);
}

void mainMenu::hideMenu()
{
    hide();
    auto pInventory = Inventory::inventory();
    if (pInventory) pInventory->reset();
    emit onNewGame();
}

void mainMenu::quitGame()
{
    qApp->exit();
}
