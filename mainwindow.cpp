#include "mainwindow.h"
#include "ui_mainwindow.h"
#define JUMPHEIGHT 50
#define PLAYERSTARTINGXPOS 400
#define PLAYERSTARTINGYPOS 0
MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // begin initializing main window/gui //
    ui->setupUi(this);
    // update timer //
    myTimer = new QTimer(this);
    connect(myTimer, SIGNAL(timeout()), this, SLOT(update()));
    myTimer->start(5);
    // add player //
    myPlayer = new Player(PLAYERSTARTINGXPOS,PLAYERSTARTINGYPOS);
    // set background //
    QPixmap background(":/Resources/images/gamebackground.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, background);
    this->setPalette(palette);



    // myGametex.loadBackGround();
    // Making first level here //
    myGametex.addFloorHere(0,400);
    //myGametex.addFloorHere(400,100);
    myGametex.addFloorHere(200,600);
   // myGametex.addFloorHere(600,700);
    // creates floor directly after last set tile for faster creation of level //
    myGametex.addFloorHere();

    // Add pickables to created map //
    myGametex.addPickup(20,300,0,5);
    myGametex.addPickup(150,500,0,5);
    myGametex.addPickup(600,500,0,10);

    myGametex.addPickup(1300,500,1,1);
    // Add boss //
    myGametex.spawnDragonboss(1000,300);
    // show playerscore on HUD //
    ui->lcdNumber_2->display(myPlayer->getLives());
    ui->lcdNumber_2->update();

}

void MainWindow::mousePressEvent(QMouseEvent *mouseEvent)
{
    qDebug("X: %d, Y: %d", mouseEvent->x(),mouseEvent->y());
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter Painter(this);
    // check if player is alive //
    if(myPlayer->getPlayerstate() == "DEAD")
    {
        collisionState = 1;
        myTimer->stop();
        myPlayer->setStopFalling(1);
        ui->lcdNumber->setBaseSize(1280,720);
        ui->lcdNumber->resize(1280,720);
        ui->lcdNumber->showFullScreen();
       // ui->lcdNumber->update();
        QTest::qSleep(10);

        qDebug("GAME IS OVER SCORE IS: %d",myPlayerScore);


    }
    // main game loop //

     if(myPlayer->getPlayerstate() != "DEAD")
     {
             myGametex.paintWindowBorders(&Painter);

            myPlayer->startGravity();

            myGametex.paintFloor(&Painter);

            myGametex.paintCoin(&Painter);

            myPlayer->paintOut(&Painter);

            myGametex.timeToMoveObjects(myPlayer);

            collisionState = myGametex.collisionCheck(myPlayer);

            myGametex.paintDragonboss(&Painter);
}



if (myPlayer->getmyLaststate() == "inair")
{
    ++dontJumpToHigh;
    if(dontJumpToHigh > JUMPHEIGHT)
    {
        myPlayer->setmyLaststate("Down");
        dontJumpToHigh = 0;
    }
}


    // these lines are for countinues moving while state of player is set //

    if (myPlayer->getPlayerstate() == "Right")
    {
        myPlayer->moveMe(1);
    }
    else if(myPlayer->getPlayerstate() == "Left")
    {
        myPlayer->moveMe(-1);
    }
    if (collisionState == 1)
    {
         // qDebug("COLLISION!!!!!");
           myPlayer->setStopFalling(1);
    }
    else if (collisionState == 0 || collisionState == 2)
    {
        myPlayer->setStopFalling(0);
   }
   if (collisionState == 2)

   {
            myPlayerScore += 10;
            QSound::play(":/Resources/Sounds/coinpling.wav");

            ui->lcdNumber->display(myPlayerScore);
            ui->lcdNumber->update();
            qDebug("Player picked up coin");
   }

    else if (collisionState == 666)
    {
        myPlayer->looseLife();
        QSound::play(":/Resources/Sounds/died.wav");
        myGametex.reWindToStart();
        myPlayer->respawn();

        ui->lcdNumber_2->display(myPlayer->getLives());
        ui->lcdNumber_2->update();
        qDebug("Player Died");
    }

    else if (collisionState == 3)
        {
            qDebug("THIS MARKS THE END OF THE GAME LINK TO HIGHSCORE FUNCTION");
            QSound::play(":/Resources/Sounds/coinpling.wav");
            myPlayerScore += 100;
            myPlayer->setPlayerstate("DEAD");
        }

 }



 void MainWindow::keyPressEvent(QKeyEvent *onKeyDown)
 {
    char keyPressed = onKeyDown->key();
    //&qDebug("CHAR %c", keyPressed);

    switch (keyPressed)
    {
    case MOVELEFT:
        {
          qDebug("Moving Left");
          myPlayer->setPlayerstate("Left");

          break;
        }

    case DOWN:
        {
          qDebug("Moving Down");
          myPlayer->setPlayerstate("Down");
          if (!myGametex.collisionCheck(myPlayer))
          {
         // myPlayer->moveMe(0,5);
          }
          break;
        }
    case MOVERIGHT:
    {
         qDebug("Moving Right");
         myPlayer->setPlayerstate("Right");

         break;
    }
    case JUMP:

    {
//        if (myPlayer->getmyLaststate() == "Right" && myPlayer->getPlayerstate() != "down")
//        {
//            qDebug("Moving Right and up");
//            myPlayer->jump(1,-1);
//        }
        if(myPlayer->getmyLaststate() != "inair" && myPlayer->getmyLaststate() != "down" && myPlayer->getmyLaststate() != "nojump" && myGametex.collisionCheck(myPlayer))
        {
         qDebug("Jumping");
         myPlayer->jump(0,-JUMPHEIGHT);
         myPlayer->setmyLaststate("inair");
        }
        break;
    }
    }




 }


// when key is released //
void MainWindow::keyReleaseEvent(QKeyEvent *onKeyRelease)
{
    char keyReleased = onKeyRelease->key();

    // check if jumpkey is released to toggle states and also check for autorepeat (holding key down) issue //
    if (keyReleased == JUMP && !onKeyRelease->isAutoRepeat())
 {
     qDebug("key released!");
     //myPlayer->setStopFalling(0);
     myPlayer->setmyLaststate("Down");
     dontJumpToHigh = 0;
//     if (myPlayer->getmyLaststate() == "Right")
//     {
//         myPlayer->setPlayerstate("RightDown");
//     }
//     else if (myPlayer->getmyLaststate() == "Left")
//     {
//         myPlayer->setPlayerstate("LeftDown");
//     }
//     else
//      myPlayer->setPlayerstate("down");
 }

    if (keyReleased == MOVERIGHT && !onKeyRelease->isAutoRepeat())
 {
     qDebug("stopping right");
     myPlayer->setmyLaststate("Right");
     myPlayer->setPlayerstate("idle");

 }
    if (keyReleased == MOVELEFT && !onKeyRelease->isAutoRepeat())
 {
     qDebug("key released Left!");
     myPlayer->setmyLaststate("Left");
     myPlayer->setPlayerstate("idle");

 }
}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{

//    ui->label->close();
//    ui->pushButton->close();
//    ui->pushButton_2->close();
//    ui->pushButton_3->close();
  //  delete(ui->pushButton);
//    delete(ui->label);
  //  delete(ui->pushButton_2);
 //   delete(ui->pushButton_3);

}
void MainWindow::endGameScreen(void)
{
    QLCDNumber FINALSCORE;
    myGametex.clearLevel();
   FINALSCORE.display(myPlayerScore);
   FINALSCORE.update();
   FINALSCORE.showFullScreen();
}
