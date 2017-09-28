#include <QDebug>
#include <QGraphicsSceneHoverEvent>

#include "fractalgraphicsitem.h"

FractalGraphicsItem::FractalGraphicsItem(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{

}

//void FractalGraphicsItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
//    qDebug() << Q_FUNC_INFO << event->scenePos();
//    QGraphicsPixmapItem::hoverMoveEvent(event);
//}

void FractalGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << Q_FUNC_INFO << event->scenePos() << " " << event->button();
}

//void FractalGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
//    qDebug() << Q_FUNC_INFO << event->scenePos();
//}

void FractalGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << Q_FUNC_INFO << event->scenePos();
}
