#include "widget.h"
#include "gamescene.h"
Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QGraphicsView *view = new QGraphicsView(this);
    GameScene *scene = new GameScene();
    view->setScene(scene);
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    //view->setViewport(new QGLWidget());
    view->show();
    resize(1280,720);
}

Widget::~Widget()
{

}
