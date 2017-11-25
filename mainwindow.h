#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/* keyMapping */
#define MOVELEFT ''
#define MOVERIGHT ''
#define JUMP ''

#define DOWN ''
#define LEFTMOVEMENT 10
//#define GAMEFPS 60


/* includes */
#include "player.h"
#include "platform.h"
#include "gametextures.h"
#include <QMediaPlayer>
#include <QTimer>
#include <QPaintEvent>
#include <QMainWindow>
#include <QDebug>
#include <QPainter>
#include <QTest>
// FOR UNIX OR MACOS DISABLE //
//#include <windows.h>
#include <QKeyEvent>
/* Defines */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
   // Draws the screen //
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *ileaveitblankifiwant);
    void keyReleaseEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *mouseEvent);
    void endGameScreen(void);

public slots:
   virtual void doNextFrame() {repaint();}

private slots:
    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
    Player* myPlayer;
    QTimer* myTimer;
    Platform myPlatform;
    GameTextures myGametex;
    int myPlayerScore = 0;
    int collisionState = 0;
    int dontJumpToHigh = 0;
};

#endif // MAINWINDOW_H
