#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "inventory.h"
#include "object.h"
#include <QPushButton>

class gameBoard: public QWidget
{
    Q_OBJECT

public:

    // gameBoards should not be cloneable.
    gameBoard(const gameBoard&) = delete;
    // gameBoards should not be assignable.
    void operator=(const gameBoard&) = delete;

    // This function creates a unique game board and returns its pointer
    static gameBoard* GameBoard(QWidget *parent = nullptr);

    // This function returns the pointer of inventory
    Inventory* getInventory() const;

    // This function returns the pointer of main object
    Object* getObject() const;

protected:
    gameBoard(QWidget *parent = nullptr);
    // This is a pointer on a unique game board
    static gameBoard *m_pGameBoard;
private slots:
    void onNewGame();

private:
    Inventory *m_pInventory;
    Object *m_pObject;

};





#endif // GAMEBOARD_H
