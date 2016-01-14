#include "widget.h"
#include "gamescene.h"
Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QGraphicsView *view = new QGraphicsView(this);
    GameScene *scene = new GameScene();
    view->setScene(scene);
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->show();

    //Pour des raisons de timing, la fenêtre est en taille fixe.
    resize(1280,720);
}

Widget::~Widget()
{

}
