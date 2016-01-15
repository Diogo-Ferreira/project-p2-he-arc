#include "gamescene.h"
#include "tiledjsonmapparsor.h"
#include "QDebug"
#include <QPixmap>
#include <QThread>
#include <QTimer>
#include <QMediaPlayer>

GameScene::GameScene()
{

    mapParsor = new TiledJsonMapParsor(":map/level3.json");
    this->setBackgroundBrush(QColor(29,42,55));

    MyCharacter * char1 = new MyCharacter(25, 25, 4, "Ray", true, this, mapParsor);
    MyCharacter * char2 = new MyCharacter(1200, 640, 4, "Nina", false, this, mapParsor);

    this->addItem(char1);
    this->addItem(char2);
    characters.append(char1);
    characters.append(char2);

    char1->setZValue(99);
    char2->setZValue(100);

    // GameScene Rectangle
    QRect rect(0,0,1280,720);
    this->setSceneRect(rect);

    // HUD
    this->gameHUD = new GameHUD();
    this->gameHUD->update(char1->nbSonarMax, char2->nbSonarLeft);
    this->gameHUD->setZValue(100); // Top Layer
    this->addItem(gameHUD);

    // Music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl(":sounds/music.mp3"));
    music->setVolume(100);
    music->play();

    // Timer
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(timer()));
    timer->start(1000);
}

/**
 * @brief Gestion des touches, particulièrement la touche P pour
 *        changer de joueur, le reste est transférer vers le joueur
 * @param event
 */
void GameScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_P :
            qDebug() << "Change de joueur" << endl;
            characters[character]->stop();
            characters[character]->setImage(false);
            character++;
            if(character > characters.count()-1) character = 0;
            characters[character]->setImage(true);
            this->gameHUD->update(characters[character]->nbSonarMax, characters[character]->nbSonarLeft);
            this->gameHUD->updateName(characters[character]->name);
            break;
        default:
            checkIfPlayersTogheter();
            characters[character]->keyPressEvent(event);
            break;
    }
}
/**
 * @brief Test si les 2 joueurs sont proches (condition de victoire)
 */
void GameScene::checkIfPlayersTogheter(){
    QPointF p1 = characters.first()->pos();
    QPointF p2 = characters.last()->pos();
    qDebug() << "magn : " << (p2 - p1).manhattanLength();
    if((p2 - p1).manhattanLength() <= 30){
        QMessageBox::information(
                NULL,
                tr("Victoire !"),
                tr("Victoire !") );
    }
}
/**
 * @brief Propagation des events dans le personnage
 * @param event
 */
void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    characters[character]->keyReleaseEvent(event);
}

/**
 * @brief Calcul du temps de jeu.
 */
void GameScene::timer(){
    this->time++;
    this->gameHUD->updateTime(this->time);
}
