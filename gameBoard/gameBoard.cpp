#include "gameBoard.h"

#include <QHBoxLayout>

gameBoard* gameBoard::m_pGameBoard = nullptr;

gameBoard* gameBoard::GameBoard(QWidget* parent)
{
    if (!m_pGameBoard)
        m_pGameBoard = new gameBoard(parent);
    return m_pGameBoard;
}


gameBoard::gameBoard(QWidget *parent) : QWidget(parent)
{
    m_pInventory = Inventory::createInventory();
    m_pObject = new Object(this);

    QHBoxLayout *pLayout = new QHBoxLayout(this);
    pLayout->addWidget(m_pInventory);
    pLayout->addWidget(m_pObject);

    pLayout->setSpacing(220);

    setLayout(pLayout);
    setDisabled(true);
}

Inventory* gameBoard::getInventory() const
{
    return m_pInventory;
}

Object* gameBoard::getObject() const
{
    return m_pObject;
}

void gameBoard::onNewGame()
{
    setEnabled(true);
}

