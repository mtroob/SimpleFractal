#ifndef FRACTALGRAPHICSSCENE_H
#define FRACTALGRAPHICSSCENE_H

#include <QGraphicsScene>

class QGraphicsRectItem;

class FractalGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    FractalGraphicsScene(QObject *parent = Q_NULLPTR);

    // Enables/disables area selection mode
    void selectionEnable(bool enable);
    // Resets current area selection
    void selectionReset();

protected:

    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:

    bool _selection_enable;
    bool _selection_active;
    bool _mouse_moved;
    QPoint _selection_start_corner;
    QGraphicsRectItem* _selection_rect;

signals:
    void areaSelected(QRect);
    void rightButtonClicked(QPoint);
    void leftButtonClicked(QPoint);
    void leftButtonDoubleClicked(QPoint);

public slots:

private slots:

};

QPoint abs(const QPoint& point);
void setLimits(QPoint& point, const QRect& limits);

#endif // FRACTALGRAPHICSSCENE_H
