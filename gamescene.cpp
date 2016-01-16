#include "gamescene.h"
#include "tiledjsonmapparsor.h"
#include "QDebug"
#include <QPixmap>
#include <QThread>
#include <QTimer>
#include <QMediaPlayer>

GameScene::GameScene()
{

    //Map
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
            characters[characterId]->stop();
            characters[characterId]->setImage(false);
            characterId++;
            if(characterId > characters.count()-1) characterId = 0;
            characters[characterId]->setImage(true);
            this->gameHUD->update(characters[characterId]->nbSonarMax, characters[characterId]->nbSonarLeft);
            this->gameHUD->updateName(characters[characterId]->name);
            break;
        default:
            checkIfPlayersArentDead();
            checkIfPlayersTogheter();
            characters[characterId]->keyPressEvent(event);
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
    if(abs((p2 - p1).manhattanLength()) <= 30){
        QMessageBox::information(
                NULL,
                tr("Victoire !"),
                tr("Victoire !") );
        exit(0);
    }
}


/**
 * @brief Un des des personnages est-il mort ? si oui on arrête le jeu
 */
void GameScene::checkIfPlayersArentDead(){

    if(characters.first()->lifes <= 0 || characters.last()->lifes <= 0){
        QMessageBox::information(
                NULL,
                tr("Defaite :( !"),
                tr("Vous avez tué Nina et Rey :(") );
        exit(0);//Un peu brutale, mais nous n'avons pas d'autre interface pour le moment
    }

}

/**
 * @brief Propagation des events dans le personnage
 * @param event
 */
void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    characters[characterId]->keyReleaseEvent(event);
}

/**
 * @brief Calcul du temps de jeu (Approximatif).
 */
void GameScene::timer(){
    this->time++;
    this->gameHUD->updateTime(this->time);
}
