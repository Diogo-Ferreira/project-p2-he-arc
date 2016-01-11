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
    this->setBackgroundBrush(QColor(29,42,55));
    //addItem(mapParsor->layers->value("Ground"));

    MyCharacter * char1 = new MyCharacter(0,100);
    MyCharacter * char2 = new MyCharacter(100,0);
    char1->setZValue(99);
    char2->setZValue(98);
    posHelper = new QGraphicsEllipseItem(0,0,10,10);
    posHelper->setBrush(Qt::red);
    addItem(posHelper);
    sonarView = new QGraphicsPixmapItem();
    addItem(sonarView);


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
    /*QGraphicsRectItem *cover = new QGraphicsRectItem(QRect(0,0,1280,720));
    cover->setBrush(QColor(29,42,55));
    cover->setZValue(97);
    this->addItem(cover);*/

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


    case Qt::Key_Space:
    {
        if(!isSonar)
        {
            isSonar = true;
            //            circle = new QGraphicsEllipseItem();
            //            circle->setBrush(Qt::blue);
            //            circle->setRect(characters[character]->x()-125,characters[character]->y()-100, 300,300);
            //            circle->setZValue(99);
            //            this->addItem(circle);
            /*sonarView = new QGraphicsPixmapItem(mapParsor->layers->value("Ground")->getLayerImgCopy(
                                                    characters[character]->x()-125,
                                                    characters[character]->y()-100,
                                                    300,
                                                    300,
                                                    QPixmap(":/img/character/sonarmask.png")
                                                    ));
            sonarView->setPos(characters[character]->pos().x() - 120,characters[character]->pos().y() - 120);*/

//            timer = new QTimer();

//            connect(timer, SIGNAL(timeout()), this, SLOT(removeCircle()));
//            timer->start();
//            timer->setInterval(2000);
            QPixmap pix = QPixmap(":img/character/sonar.png");
            circle = new QGraphicsPixmapItem(pix);

            circle->setX(characters[character]->x()-120);
            circle->setY(characters[character]->y()-120);
            circle->setZValue(96);
            circle->setTransformOriginPoint(150,150);
            //sonarView->setTransformOriginPoint(150,150);

            i = 0.00;
            animationfinie = false;
            addItem(circle);
            //addItem(sonarView);
            timer2 = new QTimer();

            connect(timer2, SIGNAL(timeout()), this, SLOT(updateCircle()));
            timer2->start();
            timer2->setInterval(1);

            timer = new QTimer();

            connect(timer, SIGNAL(timeout()), this, SLOT(removeCircle()));
            timer->start();
            timer->setInterval(2500);

            i = 0.00;

        }
        break;
    }
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

void GameScene::removeCircle()
{
    removeItem(circle);
    removeItem(sonarView);
    timer->stop();
    timer2->stop();
    isSonar = false;
}

void GameScene::updateCircle()
{
    if(animationfinie && i > 0)
    {
        circle->setScale(i);
        //sonarView->setScale(i);
        removeItem(sonarView);
        sonarView = new QGraphicsPixmapItem(mapParsor->layers->value("Ground")->getLayerImgCopy(
                                                characters[character]->x()-150*i,
                                                characters[character]->y()-150*i,
                                                300*i,
                                                300*i,
                                                QPixmap(":/img/character/sonarmask.png")
                                                ));
        sonarView->setPos((characters[character]->pos().x()+25) - sonarView->pixmap().size().width()/2,(characters[character]->pos().y()+25) - sonarView->pixmap().size().height()/2);
        circle->setPos((characters[character]->pos().x()+25) - circle->pixmap().size().width()/2,(characters[character]->pos().y()+25)- circle->pixmap().size().height()/2);
        //sonarView->setTransformOriginPoint(150,150);
        addItem(sonarView);
        if(i > 1)
        {
            i -= 0.001;
        }else{
            i -= 0.010;
        }

    }else if(!animationfinie){
        circle->setScale(i);
        //sonarView->setScale(i);
        removeItem(sonarView);
        sonarView = new QGraphicsPixmapItem(mapParsor->layers->value("Ground")->getLayerImgCopy(
                                                characters[character]->x()-150*i,
                                                characters[character]->y()-150*i,
                                                300*i,
                                                300*i,
                                                QPixmap(":/img/character/sonarmask.png")
                                                ));
        sonarView->setPos((characters[character]->pos().x()+25) - sonarView->pixmap().size().width()/2,(characters[character]->pos().y()+25)- sonarView->pixmap().size().height()/2);
        circle->setPos((characters[character]->pos().x()+25) - circle->pixmap().size().width()/2,(characters[character]->pos().y()+25)- circle->pixmap().size().height()/2);
        //sonarView->setTransformOriginPoint(150,150);
        addItem(sonarView);
        if(i > 1)
        {
            i += 0.001;
        }else{
            i += 0.003;
        }

        if(i > 1.5)
        {
            animationfinie = true;
        }
    }
}
