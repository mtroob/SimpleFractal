#ifndef COLORINGSETTINGSWIDGET_H
#define COLORINGSETTINGSWIDGET_H

#include <QWidget>

#include <memory>
#include "color/coloringalgorithm.h"

using namespace fractal;

class QComboBox;
class QPushButton;

class ColoringSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColoringSettingsWidget(QWidget *parent = 0);

    std::shared_ptr<ColoringAlgorithm> getColoringAlgorithm() const;

private:
    QComboBox* _coloring_type;
//    QPushButton* _apply_changes;

    std::shared_ptr<ColoringAlgorithm> _coloring_algorithm;

    int _min_colors = 2;
    int _max_colors = 2;

signals:
    void newColoring();

public slots:

private slots:
    void algorithmChanged(QString);
};

#endif // COLORINGSETTINGSWIDGET_H
