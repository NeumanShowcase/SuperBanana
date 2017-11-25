#include "gametextures.h"
#define DISTANCESTOPPLAYER 20
GameTextures::GameTextures()
{
}
void GameTextures::paintFloor(QPainter *qp)
{
    for (int i = 0; i < myFloorArr.size(); ++i)
    {
        myFloorArr.at(i)->paintOut(qp);
    }

}
int GameTextures::collisionCheck(Player *playerToCheck)
{

    if (myDragonboss != nullptr)
    {
        if (myDragonboss->checkCollision(playerToCheck) == 1)
        {
            delete myDragonboss;
            myDragonboss = nullptr;
            return 2;
        }
        else if (myDragonboss->checkCollision(playerToCheck) == 2 || myDragonboss->hitByFireBall(playerToCheck))
        {
            return 666;
        }

    }
    for (int i = 0; i < myFloorArr.size(); ++i)
    {
    if (myFloorArr.at(i)->hitObject(playerToCheck))
    {
        return true;
    }
    }
    for (int i = 0; i < myPickablesArr.size(); ++i)
       {
           if (myPickablesArr.at(i) == nullptr)
           {
               continue;
           }

           if (myPickablesArr.at(i)->hitObject(playerToCheck))

           {
              if (myPickablesArr.at(i)->getType() == "endGameButton")
              {
                  myPickablesArr.erase(myPickablesArr.begin()+i);
                  return 3;
              }
              else
              {
                   myPickablesArr.erase(myPickablesArr.begin()+i);
                   return 2;
               }
           }
       }






    if (playerToCheck->getPlayerHat() > RESOLUTION)
    {
        return 666;
    }
    return false;
}
// this constructs floor tiles, if left zeroed on call creates tile after last one on default length //
void GameTextures::addFloorHere(int Xpos,int Ypos)
{
    // find the tile X most to the right in arr //
    int findHighest = 0;
    // find that tiles height (Y-pos) //
    int whatHeight = 0;
    if (Xpos == 0 && Ypos == 0)
    {
        // finding last tile //
        for (int i = 0; i < myFloorArr.size(); ++i)
        {
            if(myFloorArr.at(i)->getPixmapRight() > findHighest)
            {
            findHighest = myFloorArr.at(i)->getPixmapRight();
            whatHeight = myFloorArr.at(i)->getPixmapTop();
            }
        }
        // then add it to arr on last arr index //
        myFloorArr.push_back(new flooring(findHighest,whatHeight));

    }
    else
    myFloorArr.push_back(new flooring(Xpos,Ypos));
}

 void GameTextures::addPickup(int Xpos,int Ypos,int typeOfPickup,int howMany)
 {
     int apart = 0;
     if (howMany > 1)
     {

         for (int i =0; i < howMany;++i)
         {
          myPickablesArr.push_back(new pickupItem(Xpos+apart,Ypos,typeOfPickup));
          apart += 40;
         }
     }
     else
     myPickablesArr.push_back(new pickupItem(Xpos,Ypos,typeOfPickup));
 }
 void GameTextures::paintCoin(QPainter *qp)
 {

     for (int i = 0; i < myPickablesArr.size(); ++i)
     {
            if (myPickablesArr.at(i) == nullptr)
            {
                continue;
            }
             myPickablesArr.at(i)->paintOut(qp);
     }

 }
void GameTextures::paintWindowBorders(QPainter *qp)
{


    myWindowBorder.setHeight(720);
    myWindowBorder.setWidth(1280);
    qp->drawRect(myWindowBorder);
    qp->drawPixmap(0,0,1280,720,myBackground);

}
 void GameTextures::timeToMoveObjects(Player* inputtedPlayer)
 {
     if ((myWindowBorder.width() - inputtedPlayer->getPlayerRight()) < DISTANCETOSTARTMOVEWORLD)
     {
         moveWorld();
         inputtedPlayer->moveMe(-SPEEDOFWORLD);
     }
     if (inputtedPlayer->getPlayerLeft() <  DISTANCESTOPPLAYER)
     {
         inputtedPlayer->setPlayerstate("idle");
         inputtedPlayer->moveMe(+SPEEDOFWORLD);
     }
 }
void GameTextures::moveWorld()
{
   for (auto flooring : myFloorArr) // access by reference to avoid copying
    {
       {
           flooring->moveThisObjectLeft();
       }
    }
   for (auto coins : myPickablesArr) // access by reference to avoid copying
    {
       {
           coins->moveThisObjectLeft();
       }
    }
   if (myDragonboss != nullptr)
   {
   myDragonboss->moveThisObjectLeft();
   }
}
void GameTextures::clearLevel(void)
{
  // myFloorArr.clear();
   // myPickablesArr.clear();
}
void GameTextures::reWindToStart(void)
{
        for (int i= 0; i < myFloorArr.at(0)->getMovedSteps(); ++i )
        {
            for (auto flooring : myFloorArr) // access by reference to avoid copying
             {
                {
                    flooring->moveThisObjectRight();
                }
             }
            for (auto coins : myPickablesArr) // access by reference to avoid copying
             {
                {
                    coins->moveThisObjectRight();
                }
             }
            if (myDragonboss != nullptr)
            {
            myDragonboss->moveThisObjectRight();
            }
             }

myFloorArr.at(0)->setMovedSteps(0);
}

void GameTextures::spawnDragonboss(int Xpos, int Ypos)
{
myDragonboss = new dragonBoss(Xpos,Ypos);
}
void GameTextures::paintDragonboss(QPainter* paintFromHere)
{
    if (myDragonboss != nullptr)
    {
    myDragonboss->paintOut(paintFromHere);
    myDragonboss->spitFire(8);
    myDragonboss->paintFire(paintFromHere);
    }
}




// directions are 'north' 'west' 'northEast' 'south' 'southeast' etc //
