#ifndef OBJECT_H
#define OBJECT_H

#include "strings.h"

#include <QLabel>
#include <QMouseEvent>

class Object: public QLabel
{
    Q_OBJECT
public:
    enum objectType{EmptyObject, Apple};

    Object(QWidget *parent = nullptr,
           int objType = Apple,
           const QString& imagePath = sAppleImagePath);

    // Getters for imagePath and object type
    int getObjectType() const;
    QString getImagePath() const;

protected:
    // Override the functions for draging
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
private:    
    void startDrag();

    int mObjectType;
    QString mImagePath;
    QPoint m_pDragPos;
};

#endif // OBJECT_H
