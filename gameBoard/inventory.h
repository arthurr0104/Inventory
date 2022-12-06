#ifndef INVENTORY_qH
#define INVENTORY_H

#include "object.h"

#include <QTableWidget>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMouseEvent>
#include <QDragMoveEvent>
#include <QObject>

class Inventory : public QTableWidget
{
    Q_OBJECT
public:
    // This method makes unique inventory and returns its pointer if we already have inventory this function return it
    static Inventory* createInventory(int rows = 3, int columns = 3, QWidget *parent = nullptr);
    // Get the unique inventory pointer
    static Inventory* inventory();

    void reset() override;

protected:
    Inventory(int rows, int columns, QWidget *parent);

    static Inventory* m_pInventory;

    void dragEnterEvent(QDragEnterEvent*) override;
    void dropEvent(QDropEvent*) override;
    // Override the functions for draging
    void mousePressEvent(QMouseEvent*) override;
    void dragMoveEvent(QDragMoveEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent *) override;

signals:
    void signalCellClicked(int, int);

private slots:
    void dumpObject(int, int);

private:
    class Cell : public QTableWidgetItem
    {
    public:
        Cell(const QIcon &icon, const QString &text, int type = Type);

        void setType(int type);
        int getType() const;
        int count() const;
        void setCount(int count);
    private:
        int mObjectsCount;
        int mObjectType;
    };

    void startDraging(int posx, int posy);

    void setAllCellsEmpty();
    // Number of cells
    int mSize = 0;
    QPoint mDragPos;


};

#endif // INVENTORY_H
