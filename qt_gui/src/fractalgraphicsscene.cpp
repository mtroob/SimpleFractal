#include <QDebug>
#include <QGraphicsSceneEvent>
#include <QGraphicsRectItem>

#include "fractalgraphicsscene.h"

FractalGraphicsScene::FractalGraphicsScene(QObject *parent)
{
    _size_rect = new QRect(0, 0, 900, 600);
    _selection_rect = new QGraphicsRectItem();
    _selection_rect->setZValue(1);
    _selection_rect->setOpacity(0.2);
    _selection_rect->setBrush(QBrush(Qt::white));
    addItem(_selection_rect);

    _selection_active = false;
    _selection_enable = false;
    _mouse_moved = false;

}

void FractalGraphicsScene::selectionEnable(bool enable) {
    _selection_enable = enable;
}

void FractalGraphicsScene::selectionReset() {
    _selection_rect->setVisible(false);
}

void FractalGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "Double Left Click";
        emit leftButtonDoubleClicked(event->scenePos().toPoint());
    }
    QGraphicsScene::mouseDoubleClickEvent(event);
}

void FractalGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    auto current_position = event->scenePos().toPoint();
    // start fractal area selection
    if (event->button() == Qt::LeftButton) {
        _mouse_moved = false;
        if (_selection_enable && _size_rect->contains(current_position)) {
            _selection_active = true;
            _selection_start_corner = current_position;
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

void FractalGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    _mouse_moved = true;
    const auto X_Y_SCALE = 2.0 / 3.0;
    if (_selection_active) {
        auto current_position = event->scenePos().toPoint();

        // fix current_position to be inside fractal drawing area
        setLimits(current_position, *_size_rect);

        auto rect_size = abs(_selection_start_corner - current_position);

        // rescale selection rectangle size to conform to X/Y ratio
        if (rect_size.x() > rect_size.y()) {
            rect_size.ry() = rect_size.x() * X_Y_SCALE;
        } else {
            rect_size.rx() = rect_size.y() * 1 / X_Y_SCALE;
        }

        if (rect_size.x() > 5 && rect_size.y() > 5) {
            // recalcualte current_position so
            // so that it doesn't go outside fractal drawing area
            // and the selection rectangle size still coforms to X/Y ratio
            {
                auto x_direction = (_selection_start_corner.x() > current_position.x()) ? -1 : 1;
                auto y_direction = (_selection_start_corner.y() > current_position.y()) ? -1 : 1;

                auto left = _selection_start_corner.x() + x_direction * rect_size.x();
                if (left < 0) {
                    rect_size.rx() += left;
                    rect_size.ry() += left * X_Y_SCALE;
                }

                auto right = _selection_start_corner.x() + x_direction * rect_size.x();
                if (right > (_size_rect->width() - 1)) {
                    rect_size.rx() -= right - (_size_rect->width() - 1);
                    rect_size.ry() -= (right - (_size_rect->width() - 1)) * X_Y_SCALE;
                }

                auto top = _selection_start_corner.y() + y_direction * rect_size.y();
                if (top < 0) {
                    rect_size.ry() += top;
                    rect_size.rx() += top * 1 / X_Y_SCALE;
                }

                auto bottom = _selection_start_corner.y() + y_direction * rect_size.y();
                if (bottom > (_size_rect->height() - 1)) {
                    rect_size.ry() -= bottom - (_size_rect->height() - 1);
                    rect_size.rx() -= (bottom - (_size_rect->height() - 1)) * 1 / X_Y_SCALE;
                }

                current_position.rx() = _selection_start_corner.x() + x_direction * rect_size.x();
                current_position.ry() = _selection_start_corner.y() + y_direction * rect_size.y();
            }

            QPoint top_left, bottom_right;

            // find top left rectangle corner
            if (_selection_start_corner.x() > current_position.x()) {
                top_left.rx() = current_position.x();
                bottom_right.rx() = _selection_start_corner.x();
            } else {
                top_left.rx() = _selection_start_corner.x();
                bottom_right.rx() = current_position.x();
            }

            // find bottom right rectangle corner
            if (_selection_start_corner.y() > current_position.y()) {
                top_left.ry() = current_position.y();
                bottom_right.ry() = _selection_start_corner.y();
            } else {
                top_left.ry() = _selection_start_corner.y();
                bottom_right.ry() = current_position.y();
            }

            _selection_rect->setRect({top_left, bottom_right});
            _selection_rect->setVisible(true);
        }
        else
            _selection_rect->setVisible(false);
    }
}

void FractalGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    // end of area selection action
    if (_selection_enable && _selection_active && _mouse_moved) {
        _mouse_moved = false;
        _selection_active = false;
        qDebug() << "Area Selection";
        emit areaSelected(_selection_rect->rect().toRect());
    }
    // single mouse button clicks
    else {
        switch (event->button()) {
        case Qt::RightButton :
            qDebug() << "Single Right Click";
            emit rightButtonClicked(event->pos().toPoint());
            break;
        case Qt::LeftButton :
            qDebug() << "Single Left Click";
            emit leftButtonClicked(event->pos().toPoint());
            break;
        default:
            break;
        }
        _selection_active = false;
    }
}

// helper functions

QPoint abs(const QPoint& point) {
    return {abs(point.x()), abs(point.y())};
}

void setLimits(QPoint& point, const QRect& limits) {
    if (point.x() > limits.right())
        point.rx() = limits.right();
    if (point.x() < limits.left())
        point.rx() = limits.left();
    if (point.y() > limits.bottom())
        point.ry() = limits.bottom();
    if (point.y() < limits.top())
        point.ry() = limits.top();
}
