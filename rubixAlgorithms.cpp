//
//  rubixAlgorithms.cpp
//  rubixBegin
//
//  Created by Brian Caplan on 7/10/16.
//  Copyright © 2016 Brian Caplan. All rights reserved.
//

#include "rubixAlgorithms.hpp"
#include <string>
#include <iostream>
#include <regex>
using namespace std;

rubixAlgorithms::rubixAlgorithms(std::string* cubes, rubixMoves* moves){
    this->cubes = cubes;
    this->moves = moves;
}

int rubixAlgorithms::findCube(string s){
    int i = 0;
    if(s.size() == 3){
    string temp = "[,,][,,][,,]";
    temp.insert(1,1,s[0]);
    temp.insert(3,1,s[1]);
    temp.insert(5,1,s[2]);
    temp.insert(8,1,s[0]);
    temp.insert(10,1,s[1]);
    temp.insert(12,1,s[2]);
    temp.insert(15,1,s[0]);
    temp.insert(17,1,s[1]);
    temp.insert(19,1,s[2]);
    
    regex e(temp);
    while(!regex_match(cubes[i],e) || i > 26){
        i++;
    }
    return i;
    }
    
    else if (s.size() ==2){
        
        string temp = "[,][,]";
        temp.insert(1,1,s[0]);
        temp.insert(3,1,s[1]);
        temp.insert(6,1,s[0]);
        temp.insert(8,1,s[1]);
        regex e(temp);
        while(!regex_match(cubes[i],e) || i > 26){
            i++;
        }
        return i;
    }
    else{
        while(s!= cubes[i]){
            i++;
        }
        return i;
    }
}

int rubixAlgorithms::cross(int i){
    
    switch (i){
            case 1:case 9:case 11:
                moves->fFTurnRight();
                break;
            case 3: case 5: case 7:
                moves->topTurnRight();
                break;
            case 20:
                moves->leftTurnDown();
                break;
            case 22:
                moves->rightTurnDown();
                break;
            case 24:
                moves->bacFTurnLeft();
                break;
            case 14:
                moves->leftTurnDown();
                moves->topTurnRight();
                moves->leftTurnUp();
                break;
            case 16:
                moves->rightTurnDown();
                moves->topTurnLeft();
                moves->rightTurnUp();
                break;
            case 18:
                moves->leftTurnDown();
                moves->fFTurnRight();
                moves->leftTurnUp();
                moves->topTurnRight();
                moves->fFTurnRight();
                moves->fFTurnRight();
                break;
    }
    return i;
}

int rubixAlgorithms::cornersLvl1(int i){
    switch (i){
        case 0:case 6:case 8:
            moves->topTurnLeft();
            break;
        case 2:
            moves->leftTurnUp();
            moves->topTurnLeft();
            moves->leftTurnDown();
            break;
        case 19:
            moves->rightTurnUp();
            moves->topTurnLeft();
            moves->rightTurnDown();
            break;
        case 23:
            moves->leftTurnDown();
            moves->topTurnLeft();
            moves->leftTurnUp();
            break;
        case 25:
            moves->rightTurnDown();
            moves->topTurnRight();
            moves->rightTurnUp();
            break;
        case 17:
            moves->leftTurnUp();
            moves->topTurnRight();
            moves->leftTurnDown();
            moves->topTurnLeft();
            moves->topTurnLeft();
            moves->fFTurnRight();
            moves->topTurnRight();
            moves->fFTurnLeft();
            break;
    }
    return i;
}

void rubixAlgorithms::level2(int i){
    switch (i){
        case 1: case 3: case 7:
            moves->topTurnLeft();
            break;
        case 5: case 9:
            moves->leftTurnUp();
            moves->topTurnLeft();
            moves->leftTurnDown();
            moves->topTurnLeft();
            moves->fFTurnRight();
            moves->topTurnRight();
            moves->fFTurnLeft();
            break;
        case 11:
            moves->rightTurnUp();
            moves->topTurnRight();
            moves->rightTurnDown();
            moves->topTurnRight();
            moves->fFTurnLeft();
            moves->topTurnLeft();
            moves->fFTurnRight();
            break;
        case 14:
            moves->bacFTurnRight();
            moves->topTurnLeft();
            moves->bacFTurnLeft();
            moves->topTurnLeft();
            moves->leftTurnDown();
            moves->topTurnRight();
            moves->leftTurnUp();
            break;
        case 16:
            moves->rightTurnDown();
            moves->topTurnLeft();
            moves->rightTurnUp();
            moves->topTurnLeft();
            moves->bacFTurnLeft();
            moves->topTurnRight();
            moves->bacFTurnRight();
            break;
    }
}

void rubixAlgorithms::lvl3Cross(){
    moves->fFTurnRight();
    moves->rightTurnUp();
    moves->topTurnLeft();
    moves->rightTurnDown();
    moves->topTurnRight();
    moves->fFTurnLeft();
}

void rubixAlgorithms::lvl3Sides(){
    moves->rightTurnUp();
    moves->topTurnLeft();
    moves->topTurnLeft();
    moves->rightTurnDown();
    moves->topTurnRight();
    moves->rightTurnUp();
    moves->topTurnRight();
    moves->rightTurnDown();
}

void rubixAlgorithms::lvl3Corners(){
    moves->leftTurnUp();
    moves->topTurnLeft();
    moves->rightTurnUp();
    moves->topTurnRight();
    moves->leftTurnDown();
    moves->topTurnLeft();
    moves->rightTurnDown();
    moves->topTurnRight();
}

void rubixAlgorithms::lvl3CornersFinal(){
    lvl3Sides();
    moves->leftTurnUp();
    moves->topTurnLeft();
    moves->topTurnLeft();
    moves->leftTurnDown();
    moves->topTurnLeft();
    moves->leftTurnUp();
    moves->topTurnLeft();
    moves->leftTurnDown();
}

