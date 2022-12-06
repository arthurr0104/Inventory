#ifndef MAINMENU_H
#define MAINMENU_H

#include <QPushButton>

class mainMenu : public QWidget
{
    Q_OBJECT

public:
    mainMenu(QWidget *parent = nullptr);

signals:
    void onNewGame();
private slots:
    void hideMenu();

    void quitGame();

private:
    QPushButton *m_pNewGame = nullptr;
    QPushButton *m_pQuit = nullptr;
};
#endif // MAINMENU_H
