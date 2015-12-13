#include "myrect.h"
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>



MyRect::MyRect()
{
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateEnv()));
    timer->start(1);
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_A :
        case Qt::Key_Left :
            this->KeyLeft = true;
            break;
        case Qt::Key_D :
        case Qt::Key_Right :
            this->KeyRight = true;
            break;
        case Qt::Key_W :
        case Qt::Key_Up :
            this->KeyUp = true;
            break;
        case Qt::Key_S :
        case Qt::Key_Down :
            this->KeyDown = true;
            break;
        case Qt::Key_Space :
            changeCharacter();
            break;
    }
    this->movePlayer();
}

void MyRect::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_A :
    case Qt::Key_Left :
        this->KeyLeft = false;
        break;
    case Qt::Key_D :
    case Qt::Key_Right :
        this->KeyRight = false;
        break;
    case Qt::Key_W :
    case Qt::Key_Up :
        this->KeyUp = false;
        break;
    case Qt::Key_S :
    case Qt::Key_Down :
        this->KeyDown = false;
        break;
    }
    this->movePlayer();
}

void MyRect::movePlayer()
{
    if (this->KeyLeft) setPos(x()-1, y());
      else if (this->KeyRight) setPos(x()+1, y());;
    if (this->KeyDown) setPos(x(), y()+1);
      else if (this->KeyUp) setPos(x(), y()-1);
}

void MyRect::changeCharacter()
{
    foreach (QObject *character, parent()->children()) {
        qDebug() << "1" << endl;
    }
}

void MyRect::updateEnv()
{
    this->movePlayer();
}
