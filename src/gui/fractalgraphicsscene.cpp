#include <QDebug>
#include <QGraphicsSceneEvent>

#include "fractalgraphicsscene.h"

FractalGraphicsScene::FractalGraphicsScene(QObject *parent)
{

}

void FractalGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << Q_FUNC_INFO << event->scenePos();
    QGraphicsScene::mouseDoubleClickEvent(event);
}

//void FractalGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
//    qDebug() << Q_FUNC_INFO << event->scenePos();
//    QGraphicsScene::mouseMoveEvent(event);
//}
