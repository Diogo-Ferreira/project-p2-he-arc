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
    char1->setZValue(99);
    char2->setZValue(98);


    isSonar = false;
    this->addItem(char1);
    this->addItem(char2);
    characters.append(char1);
    characters.append(char2);

    // GameScene Rectangle
    QRect rect(0,0,1280,720);
    this->setSceneRect(rect);


    // HUD
    this->gameHUD = new GameHUD();
    this->gameHUD->setZValue(100); // Top Layer
    this->addItem(gameHUD);

    // Test Cover Rectangle
    // COMMENTER POUR REVOIR LA MAP
    QGraphicsRectItem *cover = new QGraphicsRectItem(QRect(0,0,1280,720));
    cover->setBrush(Qt::black);
    cover->setZValue(97);
    this->addItem(cover);

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
            circle->setBrush(Qt::blue);
            circle->setRect(characters[character]->x()-125,characters[character]->y()-100, 300,300);
            circle->setZValue(99);
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
