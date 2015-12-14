#include "gamehud.h"
#include <QtWidgets>


GameHUD::GameHUD()
{

    int spacing = 34;

    // HUD groups initialization
    this->playtime  =   new QGraphicsItemGroup();
    this->player    =   new QGraphicsItemGroup();
    this->sonar     =   new QGraphicsItemGroup();
    this->level     =   new QGraphicsItemGroup();


    // Personal font Use
    QFontDatabase::addApplicationFont(":/fonts/Dici's Handwrite.ttf");
    QFont *dicisHUD = new QFont("DicisHandwrite", 20);

    // Construction of the playtime group
    QGraphicsPixmapItem *picChrono = new QGraphicsPixmapItem(QPixmap("img/chrono.png"));
    picChrono->setPos(20,20);

    QGraphicsTextItem *txtPlaytime = new QGraphicsTextItem("Temps de jeu");
    txtPlaytime->setDefaultTextColor(Qt::white); // Text Color
    txtPlaytime->setFont(*dicisHUD);
    txtPlaytime->setPos(90, 20);

    // Construction of the level group
    QGraphicsPixmapItem *picLevel = new QGraphicsPixmapItem(QPixmap("img/level.png"));
    picLevel->setPos(50,530);

    QGraphicsTextItem *txtLevel = new QGraphicsTextItem("Niveau");
    txtLevel->setDefaultTextColor(Qt::white); // Text Color
    txtLevel->setFont(*dicisHUD);
    txtLevel->setPos(110, 550);

    QGraphicsTextItem *txtCheck = new QGraphicsTextItem("Checkpoints");
    txtCheck->setDefaultTextColor(Qt::white); // Text Color
    txtCheck->setFont(*dicisHUD);
    txtCheck->setPos(50, 600);


    for(int i = 0; i <= 4; i++){
        QGraphicsPixmapItem *picCheckA = new QGraphicsPixmapItem(QPixmap("img/checkA.png"));
        picCheckA->setPos(50 + (spacing*i),640);
        this->level->addToGroup(picCheckA);
    }

    for(int i = 0; i <= 3; i++){
        QGraphicsPixmapItem *picCheckI = new QGraphicsPixmapItem(QPixmap("img/checkI.png"));
        picCheckI->setPos(50 + (4*spacing) + (spacing*i),640);
        this->level->addToGroup(picCheckI);
    }



    // Construction of the player group
    QGraphicsTextItem *txtPlayer = new QGraphicsTextItem("Player");
    txtPlayer->setDefaultTextColor(Qt::white); // Text Color
    txtPlayer->setFont(*dicisHUD);
    txtPlayer->setPos(1000, 20);


    // Construction of the Sonar Group
    QGraphicsTextItem *txtSonarEmission = new QGraphicsTextItem("Sonar Emissions");
    txtSonarEmission->setDefaultTextColor(Qt::white); // Text Color
    txtSonarEmission->setFont(*dicisHUD);
    txtSonarEmission->setPos(1000, 600);

    for(int i = 0; i <= 3; i++){
        QGraphicsPixmapItem *sonarA = new QGraphicsPixmapItem(QPixmap("img/sonarA.png"));
        sonarA->setPos(1200 - (spacing*i),640);
        this->level->addToGroup(sonarA);
    }

    for(int i = 0; i <= 4; i++){
        QGraphicsPixmapItem *sonarI = new QGraphicsPixmapItem(QPixmap("img/sonarI.png"));
        sonarI->setPos(1200 - (4*spacing) - (spacing*i),640);
        this->level->addToGroup(sonarI);
    }




    this->sonar->addToGroup(txtSonarEmission);

    this->playtime->addToGroup(txtPlaytime);
    this->playtime->addToGroup(picChrono);

    this->player->addToGroup(txtPlayer);

    this->level->addToGroup(txtLevel);
    this->level->addToGroup(txtCheck);
    this->level->addToGroup(picLevel);

    // Add the playtime group to the HUD
    this->addToGroup(playtime);
    this->addToGroup(level);
    this->addToGroup(sonar);
    this->addToGroup(player);

    /*
    QHBoxLayout *line1 = new QHBoxLayout;
    QHBoxLayout *line2 = new QHBoxLayout;
    QVBoxLayout *col1 = new QVBoxLayout;
*/


// http://doc.qt.io/qt-5/qgraphicslinearlayout.html
// http://www.qtcentre.org/threads/33998-Issue-in-placing-the-QGraphicsItems-into-QGraphicsLayout
//http://doc.qt.io/qt-5/qtwidgets-graphicsview-basicgraphicslayouts-example.html
}

