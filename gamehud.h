#ifndef GAMEHUD_H
#define GAMEHUD_H

#include <QtWidgets>
#include <QObject>

class GameHUD : public QGraphicsItemGroup
{

public:
    GameHUD();
    void update(int nbEmissions, int nbEmissionsLeft);
    void updateName(QString name);
    void updateTime(int time);
    void removeItems();

private:
    QGraphicsItemGroup *playtime;   // Playtime
    QGraphicsItemGroup *player;     // Actual player
    QGraphicsItemGroup *sonar;      // Sonar emissions left
    QGraphicsItemGroup *level;      // Level / Checkpoints
    QGraphicsTextItem *txtPlayerName;
    QGraphicsTextItem *txtPlaytime;
};

#endif // GAMEHUD_H
