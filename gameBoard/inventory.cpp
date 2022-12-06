#include "inventory.h"

#include <QHeaderView>
#include <QScrollBar>
#include <QMimeData>
#include <QDrag>
#include <QApplication>

Inventory *Inventory::m_pInventory = nullptr;

Inventory* Inventory::createInventory(int rows, int columns, QWidget *parent)
{
    if (!m_pInventory) m_pInventory = new Inventory(rows, columns, parent);

    return m_pInventory;
}

Inventory* Inventory::inventory()
{
    return m_pInventory;

}

Inventory::Inventory(int rows, int columns, QWidget *parent)
    : QTableWidget(rows, columns, parent), mSize(rows * columns)
{
    // Select empty state
    setAllCellsEmpty();
    // Allow drag & drop
    // setDragDropMode(QAbstractItemView::DragDrop);
    setAcceptDrops(true);
    setDragEnabled(true);

    // Chose the fixed size
    setIconSize({300, 300});
    setFixedSize((302 * columns), (302 * rows));
    // Disable headers and hide the scroll bars
    horizontalHeader()->setVisible(false);
    verticalHeader()->setVisible (false);
    verticalScrollBar()->hide();
    horizontalScrollBar()->hide();
    setShowGrid(false);
}

Inventory::Cell::Cell(const QIcon &icon, const QString &text, int type) :
    QTableWidgetItem(icon, text, type),
    mObjectsCount(0),
    mObjectType(type)
{

}

void Inventory::Cell::setType(int type)
{
    mObjectType = type;
}

int Inventory::Cell::getType() const
{
    return mObjectType;
}

int Inventory::Cell::count() const
{
    return mObjectsCount;
}

void Inventory::Cell::setCount(int count)
{
    mObjectsCount = count;
}

void Inventory::setAllCellsEmpty()
{
    QPixmap emptyCellImage;

    if (!emptyCellImage.load(sEmptyObjectImagePath)) return;

    for (int r = 0; r < rowCount(); ++r)
    {
        for (int c = 0; c < columnCount(); ++c)
        {
            Cell *pCell = new Cell(emptyCellImage, QString::number(0,1000), Object::EmptyObject);

            pCell->setSizeHint({300, 300});
            pCell->setTextAlignment(Qt::AlignBottom | Qt::AlignRight);
            pCell->setForeground(QBrush(QColor(0, 0, 0)));
            setItem(r, c, pCell);
            resizeColumnToContents(c);
            resizeRowToContents(r);
         }
    }
    QObject::connect(this, SIGNAL(signalCellClicked(int,int)), this, SLOT(dumpObject(int,int)));
}

void Inventory::reset()
{
    QPixmap emptyCellImage;
    Cell* pCell = nullptr;

    if (!emptyCellImage.load(sEmptyObjectImagePath)) return;

    for (int r = 0; r < rowCount(); ++r)
    {
        for (int c = 0; c < columnCount(); ++c)
        {
            pCell = static_cast<Cell*>(item(r, c));
            pCell->setCount(0);
            pCell->setText("0");
            pCell->setType(Object::EmptyObject);
            pCell->setIcon(emptyCellImage);
        }
    }
}

void Inventory::dumpObject(int row, int column)
{
    Cell* pCell = static_cast<Cell*>(itemAt(row, column));;
    if (!pCell) return;

    if (pCell->getType() != Object::EmptyObject)
    {
      int count = pCell->count();
      pCell->setCount(--count);
      pCell->setText(QString::number(count));

      if (!count)
      {
          pCell->setIcon(QIcon(sEmptyObjectImagePath));
          pCell->setType(Object::EmptyObject);
      }
    }
}

void Inventory::startDraging(int posx, int posy)
{
    QMimeData *pMimeData = new QMimeData;

    Cell *currentCell = static_cast<Cell*>(itemAt(posx, posy));

    if (!currentCell) return;
    QIcon objectIcon = currentCell->icon();
    int objectsCount = currentCell->count();


    pMimeData->setText(QString::number(objectsCount));
    pMimeData->setImageData(objectIcon);

    QDrag *pDrag = new QDrag(this);
    pDrag->setMimeData(pMimeData);
    pDrag->setPixmap(objectIcon.pixmap(300));
    pDrag->exec(Qt::MoveAction);
}

void Inventory::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && event->isEndEvent())
        emit signalCellClicked(event->pos().x(), event->pos().y());
}


void Inventory::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
        mDragPos = event->pos();
}

void Inventory::mouseMoveEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - mDragPos).manhattanLength();
        if (distance > QApplication::startDragDistance())
        {
            startDraging(event->position().x(), event->position().y());
        }
    }
}

void Inventory::dropEvent(QDropEvent *event)
{
    auto pos = event->position();
    Cell *pTargetCell= static_cast<Cell*>(itemAt(QPoint(pos.x(), pos.y())));
    if (!pTargetCell) return;

    auto pMimeData = event->mimeData();
    if (!pMimeData) return;

    bool sourceIsThis = (event->source() == this);
    int dragObjectType;

    Cell *pDragingCelll = static_cast<Cell*>(itemAt(mDragPos));
    if (!pDragingCelll) return;
    !sourceIsThis ? dragObjectType = pMimeData->text().toInt() : dragObjectType = pDragingCelll->getType();

    if (sourceIsThis)
    {
        if(pDragingCelll == pTargetCell) return;
        int count = pTargetCell->count() + pDragingCelll->count();
        pTargetCell->setIcon(pDragingCelll->icon());
        pTargetCell->setCount(count);
        pTargetCell->setText(QString::number(count));
        pTargetCell->setType(dragObjectType);

        pDragingCelll->setCount(0);
        pDragingCelll->setText(QString::number(0));
        pDragingCelll->setType(Object::EmptyObject);

        QPixmap emptyCellImage;
        if (emptyCellImage.load(sEmptyObjectImagePath))
            pDragingCelll->setIcon(emptyCellImage);
    }
    else
    {
        pTargetCell->setIcon(pMimeData->imageData().value<QPixmap>());
        pTargetCell->setText(QString::number(pTargetCell->count() + 1));
        pTargetCell->setCount(pTargetCell->count() + 1);
        pTargetCell->setType(dragObjectType);
    }
}

void Inventory::dragMoveEvent(QDragMoveEvent* event)
{
    event->setDropAction(Qt::MoveAction);
    event->accept();
}

void Inventory::dragEnterEvent(QDragEnterEvent* event)
{
    Cell *pTargetCell= static_cast<Cell*>(itemAt(event->position().x(), event->position().y()));
    if (!pTargetCell) return;

    auto pMimeData = event->mimeData();
    if (!pMimeData) return;

    bool sourceIsThis = (event->source() == this);
    int targetCellType = pTargetCell->getType();
    int dragObjectType;

    if (sourceIsThis)
    {
        Cell *pDragCell = static_cast<Cell*>(itemAt(mDragPos));
        if(pDragCell == pTargetCell) event->ignore();
        dragObjectType = pDragCell->getType();
    }
    else
    {
        dragObjectType = pMimeData->text().toInt();
    }

    if ((dragObjectType != Object::EmptyObject) &&
           (targetCellType == dragObjectType  || targetCellType == Object::EmptyObject))
    {

        event->acceptProposedAction();
        event->accept();;
    }
}

