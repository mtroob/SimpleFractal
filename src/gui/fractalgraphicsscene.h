#ifndef FRACTALGRAPHICSSCENE_H
#define FRACTALGRAPHICSSCENE_H

#include <QGraphicsScene>

class FractalGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    FractalGraphicsScene(QObject *parent = Q_NULLPTR);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

protected:
//    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:

signals:

public slots:

private slots:

};

#endif // FRACTALGRAPHICSSCENE_H
