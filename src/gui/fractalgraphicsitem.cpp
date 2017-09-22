#include <QDebug>
#include <QGraphicsSceneHoverEvent>

#include "fractalgraphicsitem.h"

FractalGraphicsItem::FractalGraphicsItem(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{

}

void FractalGraphicsItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    qDebug() << Q_FUNC_INFO << event->scenePos();
    QGraphicsPixmapItem::hoverMoveEvent(event);
}
