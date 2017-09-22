#ifndef FRACTALGRAPHICSITEM_H
#define FRACTALGRAPHICSITEM_H

#include <QGraphicsPixmapItem>

class FractalGraphicsItem : public QGraphicsPixmapItem
{
public:
    explicit FractalGraphicsItem(QGraphicsItem *parent = Q_NULLPTR);

protected:
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

};

#endif // FRACTALGRAPHICSITEM_H
