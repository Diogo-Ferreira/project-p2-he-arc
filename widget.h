#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "tiledjsonmapparsor.h"
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    TiledJsonMapParsor *mapParsor;
    ~Widget();
};

#endif // WIDGET_H
