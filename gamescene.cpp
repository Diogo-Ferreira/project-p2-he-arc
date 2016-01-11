#include "gamescene.h"
#include "tiledjsonmapparsor.h"
#include "QDebug"
#include <QPixmap>
#include <QThread>
#include <QTimer>
#include <QMediaPlayer>

GameScene::GameScene()
{

    mapParsor = new TiledJsonMapParsor(":map/level1.json");
    //addItem(mapParsor->layers->value("Ground"));
    //this->setBackgroundBrush(QColor(29,42,55));
    addItem(mapParsor->layers->value("Ground"));

    MyCharacter * char1 = new MyCharacter(0,100,this,mapParsor);
    MyCharacter * char2 = new MyCharacter(100,0,this,mapParsor);
    char1->setZValue(99);
    char2->setZValue(98);
    posHelper = new QGraphicsEllipseItem(0,0,10,10);
    posHelper->setBrush(Qt::red);
    addItem(posHelper);

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

    //MUSIC
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl(":sounds/music.mp3"));
    music->setVolume(100);
    music->play();

}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_T :
        characters[character]->touched();
        break;
    case Qt::Key_P :
        qDebug() << "Change de joueur" << endl;
        characters[character]->KeyDown = false;
        characters[character]->KeyUp = false;
        characters[character]->KeyRight = false;
        characters[character]->KeyLeft = false;
        characters[character]->pix = new QPixmap(":/img/character/blueballshadow.png");
        characters[character]->setPixmap(characters[character]->pix->copy(0,0,50,50));
        character++;
        if(character > characters.count()-1)
            character = 0;
        characters[character]->pix = new QPixmap(":/img/character/blueballhalo.png");
        characters[character]->setPixmap(characters[character]->pix->copy(0,0,50,50));
        break;
    default:
        characters[character]->keyPressEvent(event);
        break;
    }
    posHelper->setPos(characters[character]->pos());
    qDebug() << mapParsor->layers->value("Ground")->getTilePropretyByPos(characters[character]->x(),characters[character]->y());
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    characters[character]->keyReleaseEvent(event);
}
