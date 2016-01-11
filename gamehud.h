#ifndef GAMEHUD_H
#define GAMEHUD_H

#include <QtWidgets>

class GameHUD : public QGraphicsItemGroup
{
public:
    GameHUD(int nbEmissions, int nbCheckpoints);
    void update(int nbEmissions, int nbEmissionsLeft, int nbCheckpoints, int nbCheckpointsLeft);
    void removeItems();

private:
    QGraphicsItemGroup *playtime;   // Playtime
    QGraphicsItemGroup *player;     // Actual player
    QGraphicsItemGroup *sonar;      // Sonar emissions left
    QGraphicsItemGroup *level;      // Level / Checkpoints

    // Values
    int nbEmissions;
    int nbEmissionsLeft;
    int nbCheckpoints;
    int nbCheckpointsLeft;

    void init();

    void increase();

};

#endif // GAMEHUD_H
