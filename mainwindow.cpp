#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include <QtUiTools>
#include <iostream>
/*
#define xPos 300
#define yPos 200

#define xPos2 700
#define yPos2 257

#define yPosT -40
#define xPosR 550
#define xPosB 75
#define yPosB 350
*/

#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rubiksCube = new rubiks(this);
    guiSetup();
    connect(ui->scramButton,SIGNAL(clicked()),this,SLOT(scrambleCube()));
    connect(ui->solveButton,SIGNAL(clicked()),this,SLOT(solveCube()));
    connect(ui->action,SIGNAL(triggered()),this, SLOT(showDialog()));
    connect(d,SIGNAL(updateSettings(int)),this,SLOT(mUpdateSettings(int)));
    connect(ui->stepButton,SIGNAL(clicked()),this,SLOT(step()));
    connect(ui->inputButton,SIGNAL(clicked()),cubeInput,SLOT(open()));
    connect(cubeInput,SIGNAL(accepted()),this,SLOT(setInput()));
    connect(ui->actionLoad_Cube,SIGNAL(triggered()),this,SLOT(loadCube()));
    connect(ui->actionSave_Cube,SIGNAL(triggered()),this,SLOT(cubeSave()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);

    QColor bl(54,50,50);
    QBrush blb(bl);
    painter.setBrush(blb);
    painter.drawConvexPolygon(mPolygons[54]);

    painter.setPen(Qt::black);
    painter.setRenderHints(QPainter::Antialiasing);

    //painter.drawLine(QPoint(xPosB,yPosB),QPoint(xPos-30-15,yPos+30+15));
    //painter.drawLine(QPoint(xPosB+100 + 50,100+yPosB +50+9), QPoint(xPos-15+100-15 + 50-15,100+yPos+15+15 +50+9+15) );
    //painter.drawLine(QPoint(xPosB+100 + 50,yPosB+9),QPoint(xPos+100 + 50,yPos+9));
    if(rubiksCube->running){
        ui->stepButton->setEnabled(false);
        ui->scramButton->setEnabled(false);
        ui->solveButton->setEnabled(false);
        ui->inputButton->setEnabled(false);
    }
    else{
        ui->inputButton->setEnabled(true);
        ui->stepButton->setEnabled(true);
        ui->scramButton->setEnabled(true);
        ui->solveButton->setEnabled(true);
    }


    for(int i =0; i <9; i++){
    painter.setBrush(brushList[colors.indexOf(rubiksCube->squares[i])]);
    painter.drawConvexPolygon(mPolygons[i]);
    }

    for(int i = 18, j =27; i<27; i++, j++){
        painter.setBrush(brushList[colors.indexOf(rubiksCube->squares[j])]);
        painter.drawConvexPolygon(mPolygons[i]);
    }

    for(int i = 9, j =36; i<18; i++, j++){
        painter.setBrush(brushList[colors.indexOf(rubiksCube->squares[j])]);
        painter.drawConvexPolygon(mPolygons[i]);
    }

    for(int i = 27, j = 18; i<36; i++, j++){
        painter.setBrush(brushList[colors.indexOf(rubiksCube->squares[j])]);
        painter.drawConvexPolygon(mPolygons[i]);
    }

    for(int i = 36, j = 45; i<45; i++, j++){
        painter.setBrush(brushList[colors.indexOf(rubiksCube->squares[j])]);
        painter.drawConvexPolygon(mPolygons[i]);
    }

    for(int i = 45, j = 9; i<54; i++, j++){
        painter.setBrush(brushList[colors.indexOf(rubiksCube->squares[j])]);
        painter.drawConvexPolygon(mPolygons[i]);
    }

    if(highlight != -1){
        QColor c(189,164,61);
        QPen p(c);
        p.setWidth(5);
        painter.setPen(p);
        painter.setBrush(Qt::NoBrush);


    switch (highlight){

    case 0: case 1:
        //void fFTurnRight2();
        painter.drawConvexPolygon(mPolygons[9]);
        painter.drawConvexPolygon(mPolygons[10]);
        painter.drawConvexPolygon(mPolygons[11]);
        painter.drawConvexPolygon(mPolygons[20]);
        painter.drawConvexPolygon(mPolygons[23]);
        painter.drawConvexPolygon(mPolygons[26]);

        painter.drawConvexPolygon(mPolygons[36]);
        painter.drawConvexPolygon(mPolygons[37]);
        painter.drawConvexPolygon(mPolygons[38]);
        painter.drawConvexPolygon(mPolygons[45]);
        painter.drawConvexPolygon(mPolygons[48]);
        painter.drawConvexPolygon(mPolygons[51]);
        break;
    case 2: case 3:
        painter.drawConvexPolygon(mPolygons[15]);
        painter.drawConvexPolygon(mPolygons[16]);
        painter.drawConvexPolygon(mPolygons[17]);
        painter.drawConvexPolygon(mPolygons[18]);
        painter.drawConvexPolygon(mPolygons[21]);
        painter.drawConvexPolygon(mPolygons[24]);


        painter.drawConvexPolygon(mPolygons[42]);
        painter.drawConvexPolygon(mPolygons[43]);
        painter.drawConvexPolygon(mPolygons[44]);
        painter.drawConvexPolygon(mPolygons[47]);
        painter.drawConvexPolygon(mPolygons[50]);
        painter.drawConvexPolygon(mPolygons[53]);
        break;
    case 4: case 5:
        painter.drawConvexPolygon(mPolygons[0]);
        painter.drawConvexPolygon(mPolygons[1]);
        painter.drawConvexPolygon(mPolygons[2]);
        painter.drawConvexPolygon(mPolygons[18]);
        painter.drawConvexPolygon(mPolygons[19]);
        painter.drawConvexPolygon(mPolygons[20]);


        painter.drawConvexPolygon(mPolygons[27]);
        painter.drawConvexPolygon(mPolygons[28]);
        painter.drawConvexPolygon(mPolygons[29]);
        painter.drawConvexPolygon(mPolygons[45]);
        painter.drawConvexPolygon(mPolygons[46]);
        painter.drawConvexPolygon(mPolygons[47]);
        break;
    case 6: case 7:
        painter.drawConvexPolygon(mPolygons[6]);
        painter.drawConvexPolygon(mPolygons[7]);
        painter.drawConvexPolygon(mPolygons[8]);
        painter.drawConvexPolygon(mPolygons[24]);
        painter.drawConvexPolygon(mPolygons[25]);
        painter.drawConvexPolygon(mPolygons[26]);


        painter.drawConvexPolygon(mPolygons[33]);
        painter.drawConvexPolygon(mPolygons[34]);
        painter.drawConvexPolygon(mPolygons[35]);
        painter.drawConvexPolygon(mPolygons[51]);
        painter.drawConvexPolygon(mPolygons[52]);
        painter.drawConvexPolygon(mPolygons[53]);
        break;
    case 8: case 9:
        painter.drawConvexPolygon(mPolygons[0]);
        painter.drawConvexPolygon(mPolygons[3]);
        painter.drawConvexPolygon(mPolygons[6]);
        painter.drawConvexPolygon(mPolygons[9]);
        painter.drawConvexPolygon(mPolygons[12]);
        painter.drawConvexPolygon(mPolygons[15]);

        painter.drawConvexPolygon(mPolygons[29]);
        painter.drawConvexPolygon(mPolygons[32]);
        painter.drawConvexPolygon(mPolygons[35]);
        painter.drawConvexPolygon(mPolygons[38]);
        painter.drawConvexPolygon(mPolygons[41]);
        painter.drawConvexPolygon(mPolygons[44]);
        break;
    case 10: case 11:
        painter.drawConvexPolygon(mPolygons[2]);
        painter.drawConvexPolygon(mPolygons[5]);
        painter.drawConvexPolygon(mPolygons[8]);
        painter.drawConvexPolygon(mPolygons[11]);
        painter.drawConvexPolygon(mPolygons[14]);
        painter.drawConvexPolygon(mPolygons[17]);


        painter.drawConvexPolygon(mPolygons[27]);
        painter.drawConvexPolygon(mPolygons[30]);
        painter.drawConvexPolygon(mPolygons[33]);
        painter.drawConvexPolygon(mPolygons[36]);
        painter.drawConvexPolygon(mPolygons[39]);
        painter.drawConvexPolygon(mPolygons[42]);
        break;
    }
    }
    //painter.drawLine(QPoint(xPosB,100+yPosB +50),QPoint(xPos-15-15-15,100+yPos+15+15 +50+15));
}

void MainWindow::guiSetup(){
    listViewModel = new QStringListModel();
    ui->listView->setModel(listViewModel);
    cubeSetup();
    brushListSetup();
}

void MainWindow::cubeSetup(){
    int xPos;
    int yPos;

    if(layout == projection){
         xPos = 250 + ((this->width() - 300) / 2) -30; //300;
         yPos = 200 + 50;
    }
    else{
        xPos = 385;
        yPos = 200 + 50;
    }

    int xPos2 = xPos + 400;
    int yPos2 = yPos + 57;

    int yPosT = yPos - 240;
    int xPosR = xPos + 250;
    int xPosB = xPos -225; //75;
    int yPosB = yPos + 150;//350;


    QPolygon polygons;
    for(int i =0;i<55;i++){
        QPolygon q;
        mPolygons <<q;
    }

    //front side of Rubik's Cube
    mPolygons[0] << QPoint(xPos,yPos) << QPoint(xPos + 50,yPos+3) << QPoint(xPos + 50,yPos +50+3) << QPoint(xPos,yPos +50);
    mPolygons[1] << QPoint(xPos+50,yPos+3) << QPoint(xPos+50 + 50,yPos+6) << QPoint(xPos+50 + 50,yPos +50+6) << QPoint(xPos + 50,yPos +50+3);
    mPolygons[2]  << QPoint(xPos+100,yPos+6) << QPoint(xPos+100 + 50,yPos+9) << QPoint(xPos+100 + 50,yPos +50+9) << QPoint(xPos + 100,yPos +50+6);

    mPolygons[3]  << QPoint(xPos,50+yPos) << QPoint(xPos + 50,50+yPos+3) << QPoint(xPos + 50,50+yPos +50+3) << QPoint(xPos,50+yPos +50);
    mPolygons[4]  << QPoint(xPos+50,50+yPos+3) << QPoint(xPos+50 + 50,50+yPos+6) << QPoint(xPos+50 + 50,50+yPos +50+6) << QPoint(xPos + 50,50+yPos +50+3);
    mPolygons[5]  << QPoint(xPos+100,50+yPos+6) << QPoint(xPos+100 + 50,50+yPos+9) << QPoint(xPos+100 + 50,50+yPos +50+9) << QPoint(xPos + 100,50+yPos +50+6);

    mPolygons[6]  << QPoint(xPos,100+yPos) << QPoint(xPos + 50,100+yPos+3) << QPoint(xPos + 50,100+yPos +50+3) << QPoint(xPos,100+yPos +50);
    mPolygons[7]  << QPoint(xPos+50,100+yPos+3) << QPoint(xPos+50 + 50,100+yPos+6) << QPoint(xPos+50 + 50,100+yPos +50+6) << QPoint(xPos + 50,100+yPos +50+3);
    mPolygons[8]  << QPoint(xPos+100,100+yPos+6) << QPoint(xPos+100 + 50,100+yPos+9) << QPoint(xPos+100 + 50,100+yPos +50+9) << QPoint(xPos + 100,100+yPos +50+6);

    //bottom side of cube
    mPolygons[9]  <<  QPoint(xPos,100+yPos +50) <<  QPoint(xPos + 50,100+yPos +50+3) << QPoint(xPos + 50-15,100+yPos +50+3+15) << QPoint(xPos-15,100+yPos +50+15) ;
    mPolygons[10]  <<  QPoint(xPos+50,100+yPos+3 +50) <<  QPoint(xPos + 50 +50,100+yPos +50+6) << QPoint(xPos+50 + 50-15,100+yPos +50+6+15) << QPoint(xPos+50-15,100+yPos+3 +50+15) ;
    mPolygons[11]  <<  QPoint(xPos+100,100+yPos+6 +50) <<  QPoint(xPos + 50 +100,100+yPos +50+9) << QPoint(xPos+100 + 50-15,100+yPos +50+9+15) << QPoint(xPos+100-15,100+yPos+6 +50+15) ;

    mPolygons[12]  <<  QPoint(xPos-15,100+yPos+15 +50) <<  QPoint(xPos-15 + 50,100+yPos+15 +50+3) << QPoint(xPos -15+ 50-15,100+yPos+15 +50+3+15) << QPoint(xPos-15-15,100+yPos+15 +50+15) ;
    mPolygons[13]  <<  QPoint(xPos+50-15,100+yPos+3+15 +50) <<  QPoint(xPos-15 + 50 +50,100+yPos+15 +50+6) << QPoint(xPos+50-15 + 50-15,100+yPos+15 +50+6+15) << QPoint(xPos+50-15-15,100+yPos+15+3 +50+15) ;
    mPolygons[14]  <<  QPoint(xPos+100-15,100+yPos+6+15 +50) <<  QPoint(xPos-15 + 50 +100,100+yPos+15 +50+9) << QPoint(xPos+100-15 + 50-15,100+yPos+15 +50+9+15) << QPoint(xPos-15+100-15,100+yPos+15+6 +50+15) ;

    mPolygons[15]  <<  QPoint(xPos-15-15,100+yPos+15+15 +50) <<  QPoint(xPos-15-15 + 50,100+yPos+15+15 +50+3) << QPoint(xPos-15 -15+ 50-15,100+yPos+15+15 +50+3+15) << QPoint(xPos-15-15-15,100+yPos+15+15 +50+15) ;
    mPolygons[16]  <<  QPoint(xPos+50-15-15,100+yPos+15+3+15 +50) <<  QPoint(xPos-15-15 + 50 +50,100+yPos+15+15 +50+6) << QPoint(xPos-15+50-15 + 50-15,100+yPos+15+15 +50+6+15) << QPoint(xPos-15+50-15-15,100+yPos+15+15+3 +50+15) ;
    mPolygons[17]  <<  QPoint(xPos+100-15-15,100+yPos+15+6+15 +50) <<  QPoint(xPos-15-15 + 50 +100,100+yPos+15+15 +50+9) << QPoint(xPos-15+100-15 + 50-15,100+yPos+15+15 +50+9+15) << QPoint(xPos-15-15+100-15,100+yPos+15+15+6 +50+15) ;

    //left side of cube
    mPolygons[26]  <<  QPoint(xPos-15,100+yPos+15) <<  QPoint(xPos,100+yPos) << QPoint(xPos,100+yPos +50) << QPoint(xPos-15,100+yPos +50+15) ;
    mPolygons[25]  << QPoint(xPos-30,100+yPos+30) <<  QPoint(xPos-15,100+yPos+15) <<QPoint(xPos-15,100+yPos +50+15) << QPoint(xPos-30,100+yPos +50+30);
    mPolygons[24]  << QPoint(xPos-30-15,100+yPos+30+15) <<  QPoint(xPos-30,100+yPos+30) <<QPoint(xPos-30,100+yPos +50+30) << QPoint(xPos-45,100+yPos+15 +50+30);

    mPolygons[23]  <<  QPoint(xPos-15,50+yPos+15) <<  QPoint(xPos,50+yPos) << QPoint(xPos,50+yPos +50) << QPoint(xPos-15,50+yPos +50+15) ;
    mPolygons[22]  << QPoint(xPos-30,50+yPos+30) <<  QPoint(xPos-15,50+yPos+15) <<QPoint(xPos-15,50+yPos +50+15) << QPoint(xPos-30,50+yPos +50+30);
    mPolygons[21]  << QPoint(xPos-30-15,50+yPos+30+15) <<  QPoint(xPos-30,50+yPos+30) <<QPoint(xPos-30,50+yPos +50+30) << QPoint(xPos-45,50+yPos+15 +50+30);

    mPolygons[20]  <<  QPoint(xPos-15,yPos+15) <<  QPoint(xPos,yPos) << QPoint(xPos,yPos +50) << QPoint(xPos-15,yPos +50+15) ;
    mPolygons[19]  << QPoint(xPos-30,yPos+30) <<  QPoint(xPos-15,yPos+15) <<QPoint(xPos-15,yPos +50+15) << QPoint(xPos-30,yPos +50+30);
    mPolygons[18]  << QPoint(xPos-30-15,yPos+30+15) <<  QPoint(xPos-30,yPos+30) <<QPoint(xPos-30,yPos +50+30) << QPoint(xPos-45,yPos+15 +50+30);

   if(layout == twoCubes){
    //back side
    mPolygons[27] << QPoint(xPos2,yPos2) << QPoint(xPos2 + 50,yPos2-3) << QPoint(xPos2 + 50,yPos2 +50-3) << QPoint(xPos2,yPos2 +50);
    mPolygons[28] << QPoint(xPos2+50,yPos2-3) << QPoint(xPos2 + 100,yPos2-6) << QPoint(xPos2+100,yPos2 +50-6) << QPoint(xPos2+50,yPos2 +50-3);
    mPolygons[29] << QPoint(xPos2+100,yPos2-6) << QPoint(xPos2+150,yPos2-9) << QPoint(xPos2+150,yPos2 +50-9) << QPoint(xPos2+100,yPos2 +50-6);

    mPolygons[30] << QPoint(xPos2,50+yPos2) << QPoint(xPos2 + 50,50+yPos2-3) << QPoint(xPos2 + 50,50+yPos2 +50-3) << QPoint(xPos2,50+yPos2 +50);
    mPolygons[31] << QPoint(xPos2+50,50+yPos2-3) << QPoint(xPos2 + 100,50+yPos2-6) << QPoint(xPos2+100,50+yPos2 +50-6) << QPoint(xPos2+50,50+yPos2 +50-3);
    mPolygons[32] << QPoint(xPos2+100,50+yPos2-6) << QPoint(xPos2+150,50+yPos2-9) << QPoint(xPos2+150,50+yPos2 +50-9) << QPoint(xPos2+100,50+yPos2 +50-6);

    mPolygons[33] << QPoint(xPos2,100+yPos2) << QPoint(xPos2 + 50,100+yPos2-3) << QPoint(xPos2 + 50,100+yPos2 +50-3) << QPoint(xPos2,100+yPos2 +50);
    mPolygons[34] << QPoint(xPos2+50,100+yPos2-3) << QPoint(xPos2 + 100,100+yPos2-6) << QPoint(xPos2+100,100+yPos2 +50-6) << QPoint(xPos2+50,100+yPos2 +50-3);
    mPolygons[35] << QPoint(xPos2+100,100+yPos2-6) << QPoint(xPos2+150,100+yPos2-9) << QPoint(xPos2+150,100+yPos2 +50-9) << QPoint(xPos2+100,100+yPos2 +50-6);

    //top
    mPolygons[42] << QPoint(xPos2-15,yPos2-15) << QPoint(xPos2-15+50,yPos2-3-15) << QPoint(xPos2 + 50,yPos2-3) << QPoint(xPos2,yPos2);
    mPolygons[43] << QPoint(xPos2-15+50,yPos2-3-15) << QPoint(xPos2-15+100,yPos2-6-15) << QPoint(xPos2 +100,yPos2-6) << QPoint(xPos2 + 50,yPos2-3);
    mPolygons[44] << QPoint(xPos2-15+100,yPos2-6-15) << QPoint(xPos2-15+150,yPos2-9-15) << QPoint(xPos2 +150,yPos2-9) << QPoint(xPos2 +100,yPos2-6);

    mPolygons[39] << QPoint(xPos2-15-15,yPos2-15-15) << QPoint(xPos2-15-15+50,yPos2-15-3-15) << QPoint(xPos2-15 + 50,yPos2-15-3) << QPoint(xPos2-15,yPos2-15);
    mPolygons[40] << QPoint(xPos2-15-15+50,yPos2-15-3-15) << QPoint(xPos2-15-15+100,yPos2-15-6-15) << QPoint(xPos2-15 +100,yPos2-15-6) << QPoint(xPos2-15 + 50,yPos2-15-3);
    mPolygons[41] << QPoint(xPos2-15-15+100,yPos2-15-6-15) << QPoint(xPos2-15-15+150,yPos2-15-9-15) << QPoint(xPos2-15 +150,yPos2-15-9) << QPoint(xPos2-15 +100,yPos2-15-6);

    mPolygons[36] << QPoint(xPos2-15-15-15,yPos2-30-15) << QPoint(xPos2-15-15-15+50,yPos2-30-3-15) << QPoint(xPos2-15-15 + 50,yPos2-30-3) << QPoint(xPos2-15-15,yPos2-30);
    mPolygons[37] << QPoint(xPos2-15-15-15+50,yPos2-30-3-15) << QPoint(xPos2-15-15-15+100,yPos2-30-6-15) << QPoint(xPos2-15-15 +100,yPos2-30-6) << QPoint(xPos2-15 -15+ 50,yPos2-30-3);
    mPolygons[38] << QPoint(xPos2-15-15-15+100,yPos2-30-6-15) << QPoint(xPos2-15-15-15+150,yPos2-30-9-15) << QPoint(xPos2-15-15 +150,yPos2-30-9) << QPoint(xPos2-15 -15+100,yPos2-30-6);

    //right
    mPolygons[45] << QPoint(xPos2-45,yPos2-45) << QPoint(xPos2-15-15,yPos2-15-15) << QPoint(xPos2-15-15,yPos2-15-15+50) <<  QPoint(xPos2-45,yPos2-45+50);
    mPolygons[46] << QPoint(xPos2-15-15,yPos2-15-15) << QPoint(xPos2-15,yPos2-15) << QPoint(xPos2-15,yPos2-15 +50) <<  QPoint(xPos2-15-15,yPos2-15-15+50);
    mPolygons[47] << QPoint(xPos2-15,yPos2-15) << QPoint(xPos2,yPos2) << QPoint(xPos2,yPos2 +50) <<  QPoint(xPos2-15,yPos2-15 +50);

    mPolygons[48] << QPoint(xPos2-45,50+yPos2-45) << QPoint(xPos2-15-15,50+yPos2-15-15) << QPoint(xPos2-15-15,50+yPos2-15-15+50) <<  QPoint(xPos2-45,50+yPos2-45+50);
    mPolygons[49] << QPoint(xPos2-15-15,50+yPos2-15-15) << QPoint(xPos2-15,50+yPos2-15) << QPoint(xPos2-15,50+yPos2-15 +50) <<  QPoint(xPos2-15-15,50+yPos2-15-15+50);
    mPolygons[50] << QPoint(xPos2-15,50+yPos2-15) << QPoint(xPos2,50+yPos2) << QPoint(xPos2,50+yPos2 +50) <<  QPoint(xPos2-15,50+yPos2-15 +50);

    mPolygons[51] << QPoint(xPos2-45,100+yPos2-45) << QPoint(xPos2-15-15,100+yPos2-15-15) << QPoint(xPos2-15-15,100+yPos2-15-15+50) <<  QPoint(xPos2-45,100+yPos2-45+50);
    mPolygons[52] << QPoint(xPos2-15-15,100+yPos2-15-15) << QPoint(xPos2-15,100+yPos2-15) << QPoint(xPos2-15,100+yPos2-15 +50) <<  QPoint(xPos2-15-15,100+yPos2-15-15+50);
    mPolygons[53] << QPoint(xPos2-15,100+yPos2-15) << QPoint(xPos2,100+yPos2) << QPoint(xPos2,100+yPos2 +50) <<  QPoint(xPos2-15,100+yPos2-15 +50);
   }

   if(layout == projection){
    mPolygons[42]  <<  QPoint(xPos,100+yPosT +50) <<  QPoint(xPos + 50,100+yPosT +50+3) << QPoint(xPos + 50-15,100+yPosT +50+3+15) << QPoint(xPos-15,100+yPosT +50+15) ;
    mPolygons[43]  <<  QPoint(xPos+50,100+yPosT+3 +50) <<  QPoint(xPos + 50 +50,100+yPosT +50+6) << QPoint(xPos+50 + 50-15,100+yPosT +50+6+15) << QPoint(xPos+50-15,100+yPosT+3 +50+15) ;
    mPolygons[44]  <<  QPoint(xPos+100,100+yPosT+6 +50) <<  QPoint(xPos + 50 +100,100+yPosT +50+9) << QPoint(xPos+100 + 50-15,100+yPosT +50+9+15) << QPoint(xPos+100-15,100+yPosT+6 +50+15) ;

    mPolygons[39]  <<  QPoint(xPos-15,100+yPosT+15 +50) <<  QPoint(xPos-15 + 50,100+yPosT+15 +50+3) << QPoint(xPos -15+ 50-15,100+yPosT+15 +50+3+15) << QPoint(xPos-15-15,100+yPosT+15 +50+15) ;
    mPolygons[40]  <<  QPoint(xPos+50-15,100+yPosT+3+15 +50) <<  QPoint(xPos-15 + 50 +50,100+yPosT+15 +50+6) << QPoint(xPos+50-15 + 50-15,100+yPosT+15 +50+6+15) << QPoint(xPos+50-15-15,100+yPosT+15+3 +50+15) ;
    mPolygons[41]  <<  QPoint(xPos+100-15,100+yPosT+6+15 +50) <<  QPoint(xPos-15 + 50 +100,100+yPosT+15 +50+9) << QPoint(xPos+100-15 + 50-15,100+yPosT+15 +50+9+15) << QPoint(xPos-15+100-15,100+yPosT+15+6 +50+15) ;

    mPolygons[36]  <<  QPoint(xPos-15-15,100+yPosT+15+15 +50) <<  QPoint(xPos-15-15 + 50,100+yPosT+15+15 +50+3) << QPoint(xPos-15 -15+ 50-15,100+yPosT+15+15 +50+3+15) << QPoint(xPos-15-15-15,100+yPosT+15+15 +50+15) ;
    mPolygons[37]  <<  QPoint(xPos+50-15-15,100+yPosT+15+3+15 +50) <<  QPoint(xPos-15-15 + 50 +50,100+yPosT+15+15 +50+6) << QPoint(xPos-15+50-15 + 50-15,100+yPosT+15+15 +50+6+15) << QPoint(xPos-15+50-15-15,100+yPosT+15+15+3 +50+15) ;
    mPolygons[38]  <<  QPoint(xPos+100-15-15,100+yPosT+15+6+15 +50) <<  QPoint(xPos-15-15 + 50 +100,100+yPosT+15+15 +50+9) << QPoint(xPos-15+100-15 + 50-15,100+yPosT+15+15 +50+9+15) << QPoint(xPos-15-15+100-15,100+yPosT+15+15+6 +50+15) ;

    //right side of cube
    mPolygons[51]  <<  QPoint(xPosR-15,100+yPos+15) <<  QPoint(xPosR,100+yPos) << QPoint(xPosR,100+yPos +50) << QPoint(xPosR-15,100+yPos +50+15) ;
    mPolygons[52]  << QPoint(xPosR-30,100+yPos+30) <<  QPoint(xPosR-15,100+yPos+15) <<QPoint(xPosR-15,100+yPos +50+15) << QPoint(xPosR-30,100+yPos +50+30);
    mPolygons[53]  << QPoint(xPosR-30-15,100+yPos+30+15) <<  QPoint(xPosR-30,100+yPos+30) <<QPoint(xPosR-30,100+yPos +50+30) << QPoint(xPosR-45,100+yPos+15 +50+30);

    mPolygons[48]  <<  QPoint(xPosR-15,50+yPos+15) <<  QPoint(xPosR,50+yPos) << QPoint(xPosR,50+yPos +50) << QPoint(xPosR-15,50+yPos +50+15) ;
    mPolygons[49]  << QPoint(xPosR-30,50+yPos+30) <<  QPoint(xPosR-15,50+yPos+15) <<QPoint(xPosR-15,50+yPos +50+15) << QPoint(xPosR-30,50+yPos +50+30);
    mPolygons[50]  << QPoint(xPosR-30-15,50+yPos+30+15) <<  QPoint(xPosR-30,50+yPos+30) <<QPoint(xPosR-30,50+yPos +50+30) << QPoint(xPosR-45,50+yPos+15 +50+30);

    mPolygons[45]  <<  QPoint(xPosR-15,yPos+15) <<  QPoint(xPosR,yPos) << QPoint(xPosR,yPos +50) << QPoint(xPosR-15,yPos +50+15) ;
    mPolygons[46]  << QPoint(xPosR-30,yPos+30) <<  QPoint(xPosR-15,yPos+15) <<QPoint(xPosR-15,yPos +50+15) << QPoint(xPosR-30,yPos +50+30);
    mPolygons[47]  << QPoint(xPosR-30-15,yPos+30+15) <<  QPoint(xPosR-30,yPos+30) <<QPoint(xPosR-30,yPos +50+30) << QPoint(xPosR-45,yPos+15 +50+30);

    //back
    mPolygons[29] << QPoint(xPosB,yPosB) << QPoint(xPosB + 50,yPosB+3) << QPoint(xPosB + 50,yPosB +50+3) << QPoint(xPosB,yPosB +50);
    mPolygons[28] << QPoint(xPosB+50,yPosB+3) << QPoint(xPosB+50 + 50,yPosB+6) << QPoint(xPosB+50 + 50,yPosB +50+6) << QPoint(xPosB + 50,yPosB +50+3);
    mPolygons[27]  << QPoint(xPosB+100,yPosB+6) << QPoint(xPosB+100 + 50,yPosB+9) << QPoint(xPosB+100 + 50,yPosB +50+9) << QPoint(xPosB + 100,yPosB +50+6);

    mPolygons[32]  << QPoint(xPosB,50+yPosB) << QPoint(xPosB + 50,50+yPosB+3) << QPoint(xPosB + 50,50+yPosB +50+3) << QPoint(xPosB,50+yPosB +50);
    mPolygons[31]  << QPoint(xPosB+50,50+yPosB+3) << QPoint(xPosB+50 + 50,50+yPosB+6) << QPoint(xPosB+50 + 50,50+yPosB +50+6) << QPoint(xPosB + 50,50+yPosB +50+3);
    mPolygons[30]  << QPoint(xPosB+100,50+yPosB+6) << QPoint(xPosB+100 + 50,50+yPosB+9) << QPoint(xPosB+100 + 50,50+yPosB +50+9) << QPoint(xPosB + 100,50+yPosB +50+6);

    mPolygons[35]  << QPoint(xPosB,100+yPosB) << QPoint(xPosB + 50,100+yPosB+3) << QPoint(xPosB + 50,100+yPosB +50+3) << QPoint(xPosB,100+yPosB +50);
    mPolygons[34]  << QPoint(xPosB+50,100+yPosB+3) << QPoint(xPosB+50 + 50,100+yPosB+6) << QPoint(xPosB+50 + 50,100+yPosB +50+6) << QPoint(xPosB + 50,100+yPosB +50+3);
    mPolygons[33]  << QPoint(xPosB+100,100+yPosB+6) << QPoint(xPosB+100 + 50,100+yPosB+9) << QPoint(xPosB+100 + 50,100+yPosB +50+9) << QPoint(xPosB + 100,100+yPosB +50+6);
   }
   mPolygons[54] << QPoint(250,100) << QPoint(this->width()-50,100)  << QPoint(this->width()-50,this->height()-100) << QPoint(250,this->height()-100);
}

void MainWindow::brushListSetup(){

    QColor o(255,128,0);
    QColor r(255,0,0);
    QColor b(0,0,255);
    QColor g(0,204,0);
    QColor w(255,255,255);
    QColor y(255,255,0);

    QBrush bO(o);
    brushList << bO;
    QBrush bR(r);
    brushList << bR;
    QBrush bB(b);
    brushList << bB;
    QBrush  bG(g);
    brushList << bG;
    QBrush bW(w);
    brushList << bW;
    QBrush bY(y);
    brushList << bY;
}

void MainWindow::updatingPaint(int i){
    listViewModel->setStringList(rubiksCube->movesStringQueue);
    highlight = i;
    update();
}

void MainWindow::solveCube(){
    rubiksCube->solve();
}

void MainWindow::scrambleCube(){
    rubiksCube->movesStringQueue.clear();
    rubiksCube->movesQueue->clear();
    rubiksCube->running = true;
    listViewModel->setStringList(rubiksCube->movesStringQueue);
    srand ( time(NULL) );

    timerId = startTimer(250);

}

void MainWindow::timerEvent(QTimerEvent *event){
    if(rubiksCube->movesQueue->size() != 10){
        int move = rand() % 12;
        rubiksCube->makeMove(move);
    }
    else{

        killTimer(timerId);
        rubiksCube->running = false;
        rubiksCube->movesQueue->clear();
        update();
    }
}

void MainWindow::mUpdateSettings(int i){
    layout = static_cast<layouts>(i);
    if(solveType != d->solveType){
        solveType = d->solveType;
        switchSpeed();
    }
    mPolygons.clear();
    cubeSetup();
    update();
}
void MainWindow::showDialog(){
    d->open();
}

void MainWindow::step(){
    ui->stepButton->setEnabled(false);
    rubiksCube->running= true;
    if(solveType == 0){
        rubiksCube->timerId = rubiksCube->startTimer(500);
    }
    else{
        rubiksCube->runThrough();
    }
}

void MainWindow::switchSpeed(){

    if(rubiksCube->timerId){
        rubiksCube->killTimer(rubiksCube->timerId);
    }
    switch (solveType){

    case 0:
        rubiksCube->speed = -999;
        rubiksCube->running = false;
        break;
    case 1:
        rubiksCube->speed = 500;
        break;
    case 2:
        rubiksCube->speed = 1000;
        break;
    case 3:
        rubiksCube->speed = 2000;
        break;
     }
    if(rubiksCube->running){
        rubiksCube->timerId = rubiksCube->startTimer(rubiksCube->speed);
    }
}

void MainWindow::setInput(){
    if(validate(cubeInput->inputSquares)){
    for(int i=0;i< 54; i++){
        rubiksCube->squares[i] = cubeInput->inputSquares[i];
    }
    update();
    }
    cubeInput->inputSquares.clear();
    cubeInput->side = 0;
}

bool MainWindow::validate(QList<char> sqInCu){
    int red =0;
    int white=0;
    int blue=0;
    int orange=0;
    int green=0;
    int yellow=0;
 foreach(char c, sqInCu){
    switch(c){
    case 'o':
        orange++;
        break;
    case 'b':
        blue++;
        break;
    case 'r':
        red++;
        break;
    case 'g':
        green++;
        break;
    case 'w':
        white++;
        break;
    case 'y':
        yellow++;
        break;
    }
 }
    if(red == 9 && white == 9 && blue == 9 && orange == 9 && green == 9 && yellow ==9 ){
        return true;
    }
    else{
        return false;
    }
}

void MainWindow::loadCube(){
    QFile file(QFileDialog::getOpenFileName(this,
                                            tr("Open Cube"), "/home", tr("Cube Files (*.rc)")));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    char cube[54];
    file.readLine(cube,55);
    std::cout<<cube;
    for(int i=0;i<54;i++){
        rubiksCube->squares[i] = cube[i];
    }
    update();
    file.close();
}

void MainWindow::cubeSave(){

    QString  s = QFileDialog::getSaveFileName(this, "Save file", "/");
    s+=".rc";
    QFile file(s);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << rubiksCube->squares;
        file.close();
    }
}
