#include "object.h"

#include <QMimeData>
#include <QDrag>
#include <QApplication>

Object::Object( QWidget *parent /* = nullptr */,
                int objType /* = Apple */,
                const QString& imagePath /* = sAppleImagePath */) :
    QLabel(parent),
    mObjectType(objType),
    mImagePath(imagePath)
{
    QPixmap pix;

    if (pix.load(imagePath))
    {
        resize(300, 300);
        pix = pix.scaled(size());
        setPixmap(pix);
    }
}

void Object::startDrag()
{
    QMimeData *pMimeData = new QMimeData;
    QPixmap objectImage = pixmap();

    pMimeData->setText(QString::number(mObjectType));
    pMimeData->setImageData(objectImage);

    QDrag *pDrag = new QDrag(this);
    pDrag->setMimeData(pMimeData);
    pDrag->setPixmap(objectImage);
    pDrag->exec();
}

void Object::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_pDragPos = event->pos();
    }
    QWidget::mousePressEvent(event);
}

void Object::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        int distance = (event->pos() - m_pDragPos).manhattanLength();
        if (distance > QApplication::startDragDistance())
            startDrag();
    }
    QWidget::mouseMoveEvent(event);
}


int Object::getObjectType() const
{
    return mObjectType;
}

QString Object::getImagePath() const
{
    return mImagePath;
}
