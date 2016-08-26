#include "rubiks.h"

//
//  rubiks.cpp
//  rubixBegin
//
//  Created by Brian Caplan on 7/17/16.
//  Copyright © 2016 Brian Caplan. All rights reserved.
//
#include "rubixMoves.hpp"
#include <iostream>
#include <cmath>
#include <QTimer>

rubiks::rubiks(QObject *parent):QObject(parent){
    setUp();
    rMoves = new rubixMoves(squares, cubes, movesQueue);
    rAlgor = new rubixAlgorithms(cubes, rMoves);
}


void rubiks::setUp(){
    connect(this,SIGNAL(updatePaint(int)),this->parent(),SLOT(updatingPaint(int)));

    for (int i = 0; i < 54; i++){
        if(i<9){squares[i] = 'o';}
        else if(i<18){squares[i] = 'b';}
        else if(i<27){squares[i] = 'r';}
        else if(i<36){squares[i] = 'g';}
        else if(i<45){squares[i] = 'w';}
        else if(i<54){squares[i] = 'y';}
    }
}

void rubiks::solve(){
    QList<char> tSquares;

    for(char c: squares){
        tSquares << c;
    }

    movesQueue->clear();
    movesStringQueue.clear();

    step1Cross();
    step1Corners();
    step2();
    step3Cross();
    step3Sides();
    step3CornersPt1();
    step3CornersPt2();

    for(int i=0;i< 54; i++){
        squares[i] = tSquares[i];
    }

    for(int i = 0; i<movesQueue->count(); i++){
        switch (movesQueue->at(i)){
        case 0:
            movesStringQueue << QString::number(i) + " Front Face Turn Right";
            break;
        case 1:
            movesStringQueue << QString::number(i) + " Front Face Turn Left";
            break;
        case 2:
            movesStringQueue << QString::number(i) + " Back Face Turn Right";
            break;
        case 3:
            movesStringQueue << QString::number(i) + " Back Face Turn Left";
            break;
        case 4:
            movesStringQueue << QString::number(i) + " Top Turn Right";
            break;
        case 5:
            movesStringQueue << QString::number(i) + " Top Turn Left";
            break;
        case 6:
           movesStringQueue << QString::number(i) + " Bottom Turn Right";
            break;
        case 7:
            movesStringQueue << QString::number(i) + " Bottom Turn Left";
            break;
        case 8:
            movesStringQueue << QString::number(i) + " Left Turn Up";
            break;
        case 9:
            movesStringQueue << QString::number(i) + " Left Turn Down";
            break;
        case 10:
             movesStringQueue << QString::number(i) + " Right Turn Up";
            break;
        case 11:
            movesStringQueue << QString::number(i) + " Right Turn Down";
            break;
        }
    }
    emit updatePaint(-1);
}

void rubiks::runThrough(){
    if(speed!=-999){
        timerId = startTimer(speed);
    }
}

void rubiks::step1Cross(){
    rMoves->switchOrange();
    while(18 != rAlgor->findCube("ow") || squares[37] != 'w'){
        rAlgor->cross(rAlgor->findCube("ow"));
    }

    rMoves->switchRed();
    while(18 != rAlgor->findCube("rw") || squares[43] != 'w'){
        rAlgor->cross(rAlgor->findCube("rw"));
    }

    rMoves->switchBlue();
    while(18 != rAlgor->findCube("bw") || squares[41] != 'w'){
        rAlgor->cross(rAlgor->findCube("bw"));
    }

    rMoves->switchGreen();
    while(18 != rAlgor->findCube("gw") || squares[39] != 'w'){
        rAlgor->cross(rAlgor->findCube("gw"));
    }

    rMoves->switchOrange();
}

void rubiks::step1Corners(){
    while(17 != rAlgor->findCube("ogw") || squares[36] != 'w'){
        rAlgor->cornersLvl1(rAlgor->findCube("ogw"));
    }

    rMoves->switchBlue();
    while(17 != rAlgor->findCube("obw") || squares[38] != 'w'){
        rAlgor->cornersLvl1(rAlgor->findCube("obw"));
    }

    rMoves->switchRed();
    while(17 != rAlgor->findCube("rbw") || squares[44] != 'w'){
        rAlgor->cornersLvl1(rAlgor->findCube("rbw"));
    }

    rMoves->switchGreen();
    while(17 != rAlgor->findCube("rgw") || squares[42] != 'w'){
        rAlgor->cornersLvl1(rAlgor->findCube("rgw"));
    }

    rMoves->switchOrange();
}

void rubiks::step2(){

    while(9 != rAlgor->findCube("og") || squares[3] != 'o'){
        rAlgor->level2(rAlgor->findCube("og"));
    }

    rMoves->switchBlue();
    while(9 != rAlgor->findCube("ob") || squares[12] != 'b'){
        rAlgor->level2(rAlgor->findCube("ob"));
    }

    rMoves->switchRed();
    while(9 != rAlgor->findCube("br") || squares[21] != 'r'){
        rAlgor->level2(rAlgor->findCube("br"));
    }

    rMoves->switchGreen();
    while(9 != rAlgor->findCube("rg") || squares[30] != 'g'){
        rAlgor->level2(rAlgor->findCube("rg"));
    }

    rMoves->switchOrange();
}

void rubiks::step3Cross(){
    while (squares[46] != 'y' || squares[48] != 'y' || squares[50] != 'y' || squares[52] != 'y'){

        //dot
        if(squares[46] != 'y' && squares[48] != 'y' && squares[50] != 'y' && squares[52] != 'y'){
            rAlgor->lvl3Cross();
        }

        //L
        if ((squares[46] == 'y' && squares[50] == 'y') || (squares[48] == 'y' && squares[52] == 'y')){
            rMoves->topTurnRight();
        }
        if ((squares[46]== 'y' && squares[48] == 'y') || (squares[50]== 'y' && squares[52] == 'y')){
            rAlgor->lvl3Cross();
        }


        //line
        if(squares[46]== 'y' && squares[52] == 'y'){
            rMoves->topTurnRight();
        }
        if(squares[48]== 'y' && squares[50] == 'y'){
            rAlgor->lvl3Cross();
        }

    }
    rMoves->switchOrange();
}

void rubiks::step3Sides(){
    std::string colInPlace = "";
    while(squares[1] != 'o' || squares[10] != 'b' || squares[19] != 'r' || squares[28] != 'g'){
        colInPlace.clear();
        if (squares[1] == 'o'){colInPlace = colInPlace + "o";}
        if (squares[10] == 'b'){colInPlace = colInPlace + "b";}
        if (squares[19] == 'r'){colInPlace = colInPlace + "r";}
        if (squares[28] == 'g'){colInPlace = colInPlace + "g";}


        if(colInPlace.size() < 2){
            rMoves->topTurnRight();
        }
        else{
            if(colInPlace == "or" || colInPlace == "bg" || colInPlace == "rg") {
                rAlgor->lvl3Sides();
            }
            else if(colInPlace == "og"){
                rMoves->switchBlue();
                rAlgor->lvl3Sides();
            }
            else if(colInPlace == "ob"){
                rMoves->switchRed();
                rAlgor->lvl3Sides();
            }
            else if(colInPlace == "br"){
                rMoves->switchGreen();
                rAlgor->lvl3Sides();
            }
        }
        rMoves->switchOrange();
    }
}

void rubiks::step3CornersPt1(){
    while(rAlgor->findCube("ogy") != 0 || rAlgor->findCube("oyb") != 2 || rAlgor->findCube("bry") != 8 ||rAlgor->findCube("rgy") != 6){
        int cubePlace = 0;

        if(rAlgor->findCube("oyb") == 2){cubePlace = 1;}
        else if(rAlgor->findCube("bry") == 8){cubePlace = 2;}
        else if(rAlgor->findCube("rgy") == 6){cubePlace = 3;}
        else if(rAlgor->findCube("ogy") == 0){cubePlace = 4;}


        switch (cubePlace){
            case 0: case 1:
                rAlgor->lvl3Corners();
                break;
            case 2:
                rMoves->switchBlue();
                rAlgor->lvl3Corners();
                break;
            case 3:
                rMoves->switchRed();
                rAlgor->lvl3Corners();
                break;
            case 4:
                rMoves->switchGreen();
                rAlgor->lvl3Corners();
                break;
        }

        rMoves->switchOrange();
    }
}

void rubiks::step3CornersPt2(){
    while(squares[45] != 'y' || squares[47] != 'y' || squares[51] != 'y' || squares[53] != 'y'){
        std::string s = "";
        s = (squares[45] !='y') ? (s + "r") : s+"";
        s = (squares[47] !='y') ? (s + "b") : s+"";
        s = (squares[51] !='y') ? (s + "g") : s+"";
        s = (squares[53] !='y') ? (s + "o") : s+"";

        if(s.size() < 2 || s.size() == 4){
            rAlgor->lvl3CornersFinal();
        }
        else if(s.size() == 2){
            if (s == "rg"){
                    rMoves->switchRed();
                rAlgor->lvl3CornersFinal();
            }
            else if (s =="rb"){
                rMoves->switchBlue();
                rAlgor->lvl3CornersFinal();
            }
            else if (s =="bo" || s == "ro" || s == "bg"){
                rAlgor->lvl3CornersFinal();
            }
            else if (s =="go"){
                    rMoves->switchGreen();
                rAlgor->lvl3CornersFinal();
            }
        }

        else if(s.size() == 3){

            if(s == "rbg"){
                rMoves->switchBlue();
                rAlgor->lvl3CornersFinal();
            }
            else if(s == "rgo"){
                rMoves->switchRed();
                rAlgor->lvl3CornersFinal();
            }
            else{
                rAlgor->lvl3CornersFinal();
            }
        }
        rMoves->switchOrange();
    }
}

void rubiks::timerEvent(QTimerEvent *event){
    if(movesQueue->size()>0){
        running = true;
        int move = movesQueue->at(0);
        emit updatePaint(move);
        if(speed == -999){
            QTimer::singleShot(250, this, SLOT(makeMove()));
            killTimer(timerId);
        }
        else{
            QTimer::singleShot(speed/2, this, SLOT(makeMove()));
        }
    }
    else{
        std::cout << numOfMoves;
        killTimer(timerId);
        running = false;
        emit updatePaint(-1);
    }
}

void rubiks::makeMove(int i){
    if(i == -999){
        i = movesQueue->at(0);
        movesQueue->pop_front();
        movesStringQueue.pop_front();
    }
    else{
        *movesQueue << i;
    }
    switch (i){

    case 0:
         rMoves->fFTurnRight2();
        break;
    case 1:
        rMoves->fFTurnLeft2();
        break;
    case 2:
        rMoves->bacFTurnRight2();
        break;
    case 3:
        rMoves->bacFTurnLeft2();
        break;
    case 4:
        rMoves->topTurnRight2();
        break;
    case 5:
        rMoves->topTurnLeft2();
        break;
    case 6:
        rMoves->bottTurnRight2();
        break;
    case 7:
        rMoves->bottTurnLeft2();
        break;
    case 8:
        rMoves->leftTurnUp2();
        break;
    case 9:
        rMoves->leftTurnDown2();
        break;
    case 10:
         rMoves->rightTurnUp2();
        break;
    case 11:
        rMoves->rightTurnDown2();
        break;
    }
    if(speed== -999){
        running = false;
    }
    emit updatePaint(-1);
}
