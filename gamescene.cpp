#include "gamescene.h"
#include "tiledjsonmapparsor.h"
#include "QDebug"
#include <QPixmap>
#include <QThread>
#include <QTimer>

GameScene::GameScene()
{

    mapParsor = new TiledJsonMapParsor("desert_t.json");
    addItem(mapParsor->layers->value("Ground"));
    //this->setBackgroundBrush(Qt::black);
    MyCharacter * char1 = new MyCharacter(0,100);
    MyCharacter * char2 = new MyCharacter(100,0);
    char1->setZValue(1);
    char2->setZValue(2);
    isSonar = false;
    this->addItem(char1);
    this->addItem(char2);
    characters.append(char1);
    characters.append(char2);
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_P :
            qDebug() << "Change de joueur" << endl;
            characters[character]->KeyDown = false;
            characters[character]->KeyUp = false;
            characters[character]->KeyRight = false;
            characters[character]->KeyLeft = false;
            character++;
            if(character > characters.count()-1)
                character = 0;
            break;

        case Qt::Key_Space:
        {
        if(!isSonar)
        {
            isSonar = true;
            circle = new QGraphicsEllipseItem();
            circle->setBrush(Qt::red);
            circle->setRect(characters[character]->x()-125,characters[character]->y()-100, 300,300);
            circle->setZValue(0);
            this->addItem(circle);
            timer = new QTimer();

            connect(timer, SIGNAL(timeout()), this, SLOT(removeCircle()));
            timer->start();
            timer->setInterval(2000);

        }
            break;
        }
        default:
            characters[character]->keyPressEvent(event);
            break;
    }
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    characters[character]->keyReleaseEvent(event);
}

void GameScene::removeCircle()
{
    removeItem(circle);
    timer->stop();
    isSonar = false;
}
