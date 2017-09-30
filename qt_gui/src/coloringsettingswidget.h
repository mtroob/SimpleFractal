#ifndef COLORINGSETTINGSWIDGET_H
#define COLORINGSETTINGSWIDGET_H

#include <QWidget>

#include <memory>
#include "color/coloringalgorithm.h"
#include "color/linearinterpolatedcoloring.h"

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
    void loadColorMaps();

    QComboBox* _coloring_type;
    QComboBox* _color_map_type;

    std::shared_ptr<ColoringAlgorithm> _coloring_algorithm;
    std::map<std::string, std::shared_ptr<ColorMap>> _color_map_array;

signals:
    void newColoring();

public slots:

private slots:
    void algorithmChanged(QString);
    void colorMapChanged(QString);
};

#endif // COLORINGSETTINGSWIDGET_H
