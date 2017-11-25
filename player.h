#ifndef PLAYER_H
#define PLAYER_H
// includes //
#include <QPixmap>
#include <QPainter>
#include <qmovie.h>
// FOR LINUX OR MAC DISABLE //
//#include <windows.h>
#include <qmediaplayer.h>
#include <QSound>
// defines //
#define JUMPREPEATS 10
#define GRAVITY 2.0

#define PLAYERLIVES 3
using namespace std;
class Player
{
public:
    // create the player wich will be played by the user //
    Player();
    Player(int Xpos,int Ypos);

    // Paint me//
    void paintOut(QPainter *paintMeFromHere);
    // function to move player X, Y steps //
    void moveMe(float stepsX = 0,float stepsY = 0);
    // starting the spawn process / game //
    void startGravity(void);
    // Setting state of movement //
     void setPlayerstate(string state);
    // functions related to get information on attributes //
    float getPlayerLeft(void);

    float getPlayerRight(void);

    float getPlayerHat(void);

    float getPlayerShoes(void);

    QPoint getPlayerCenter(void);

    string getmyLaststate(void);

    string getPlayerstate(void);

    void jump(int X=0,int Y=0);

    void setmyLaststate(string newLaststate);

    void setStopFalling(int);

    float getPixHeight(void);

    void looseLife(void);

    void respawn(void);

    int getLives(void);

    void moveThisObjectLeft(void);

    void moveThisObjectRight(void);

    int checkCollision(Player* playerToCheck);

    void playSound(int whatsound);
protected:
     // contains bitmap //
    QPixmap myPlayerPic;
    float myPlayerPixWidth;
    float myPlayerPixHeight;
    // position of player //
    float myPlayerXpos;
    float myPlayerYpos;
    // state of player //
    string myPlayerstate;
    string mylastState;
    int stopFalling = 0;
    int myLives = PLAYERLIVES;
    // if player has GIF pic //
    QMovie myAnim;
    QMediaPlayer myMediaPlayer;
};

#endif // PLAYER_H
