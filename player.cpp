#include "player.h"
#define STARTINGXPOS 400
#define STARTINGYPOS 0
#define PLAYER2HEIGHT 46
#define PLAYER2WIDTH 46
#define DISTANCETOCOLLIDE 80
Player::Player()
{

}
Player::Player(int Xpos,int Ypos)
{
//myPlayerPic(":/Resources/images/player1.png")
myPlayerXpos = Xpos;
myPlayerYpos = Ypos;
myPlayerstate = "down";
QSize sizeOfPlayer2;
sizeOfPlayer2.setHeight(PLAYER2HEIGHT);
sizeOfPlayer2.setWidth(PLAYER2WIDTH);
myPlayerPixHeight =PLAYER2HEIGHT;
myPlayerPixWidth = PLAYER2WIDTH;

myAnim.setFileName(":/Resources/images/player2.gif");
myAnim.setScaledSize(sizeOfPlayer2);
myAnim.start();

}
void Player::paintOut(QPainter * paintMeFromHere)
{

//    if (myPlayerstate == "Left")
//    {
//        myPlayerPic.load(":/Resources/images/player1.png");
//    }
//    if (myPlayerstate == "Right")
//    {
//        myPlayerPic.load(":/Resources/images/player1Right.png");
//    }
//    if (myPlayerstate == "Down")
//    {
//        myPlayerPic.load(":/Resources/images/stone.png");
//    }


    if(myAnim.isValid())
        {
             paintMeFromHere->drawPixmap(myPlayerXpos,myPlayerYpos,myAnim.currentPixmap());
        }


        // paintMeFromHere->drawPixmap(myPlayerXpos,myPlayerYpos,myPlayerPixWidth,myPlayerPixHeight,myPlayerPic);
}

void Player::moveMe(float stepsX,float stepsY)
{
    myPlayerXpos += stepsX;
    myPlayerYpos += stepsY;
}
 void Player::startGravity(void)
 {
   if (mylastState == "inair")
   {
       myPlayerYpos -= GRAVITY;
   }

   else  if (stopFalling == 0)
    {
    myPlayerYpos += GRAVITY;
    }


 }
 float Player::getPlayerLeft(void)
 {
     return myPlayerXpos;
 }

 float Player::getPlayerRight(void)
 {
     return myPlayerXpos + myPlayerPixWidth;
 }

 float Player::getPlayerHat(void)
 {
     return myPlayerYpos;
 }
 float Player::getPlayerShoes(void)
 {
     return myPlayerYpos + myPlayerPixHeight;
 }
 void Player::jump(int X,int Y)
 {
    playSound(1);
   for (int i = 0; i < JUMPREPEATS; ++i)
   {
       myPlayerXpos += X;
       //myPlayerYpos += Y;
   }

 }
string Player::getPlayerstate(void)
{
    return myPlayerstate;
}
void Player::setPlayerstate(string newPlayerstate)
{
    myPlayerstate = newPlayerstate;
}
string Player::getmyLaststate(void)
{
    return mylastState;
}

void Player::setmyLaststate(string newLaststate)
{
    mylastState = newLaststate;
}
void Player::setStopFalling(int toggle)
{
    stopFalling = toggle;
}
float Player::getPixHeight(void)
{
    return myPlayerPixHeight;
}
void Player::looseLife(void)
{
    if (myLives == 0)
    {
        myPlayerstate = "DEAD";
    }
    else
    --myLives;
}
void Player::respawn(void)
{
   myPlayerXpos = STARTINGXPOS;
   myPlayerYpos = STARTINGYPOS;
}
int Player::getLives(void)
{
    return myLives;
}
void Player::moveThisObjectLeft(void)
{
    --myPlayerXpos;
}
int Player::checkCollision(Player* checkthisplayer)
{
    QPoint returnedPlayerCenter = checkthisplayer->getPlayerCenter();
    float resultingDistance = sqrt((pow(returnedPlayerCenter.x()-(myPlayerXpos+myPlayerPixWidth/2),2) + (pow(returnedPlayerCenter.y()-(myPlayerYpos+myPlayerPixHeight/2),2) )));
    if (resultingDistance < DISTANCETOCOLLIDE)
    {
        return true;
    }
    if (checkthisplayer->getPlayerShoes() == myPlayerYpos && (checkthisplayer->getPlayerRight() > myPlayerXpos) )
    {
        if (checkthisplayer->getPlayerLeft() <= myPlayerXpos+myPlayerPixWidth)
        {
           qDebug("COLLISION!!!!!");
            return 2;
        }
    }
        return false;
}
QPoint Player::getPlayerCenter(void)
{
    QPoint playerCenter;
    playerCenter.setX(myPlayerXpos + (myPlayerPixWidth / 2));
    playerCenter.setY(myPlayerYpos + (myPlayerPixHeight / 2));
    return playerCenter;
}

void Player::moveThisObjectRight(void)
{
    ++myPlayerXpos;
}
void Player::playSound(int whatsound)
{
    switch (whatsound)
    {
    case 1:
    {

        myMediaPlayer.setMedia(QUrl("qrc:Resources/Sounds/jump.mp3"));
        myMediaPlayer.setVolume(150);
        myMediaPlayer.play();
        break;
    }

    }
}
