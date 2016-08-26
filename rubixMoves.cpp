//
//  rubixMoves.cpp
//  rubixBegin
//
//  Created by Brian Caplan on 7/10/16.
//  Copyright © 2016 Brian Caplan. All rights reserved.
//

#include "rubixMoves.hpp"

#include "rubixAlgorithms.hpp"
#include <string>
#include <iostream>
using namespace std;
int rubixMoves::iter;

rubixMoves::rubixMoves(char* sq,string* cu, QList<int> * mq){
    squares = sq;
    cubes = cu;
    movesQueue = mq;
    side = 'o';
    transfered = false;
    iter = 0;
    switchOrange();
}

void rubixMoves::switchGreen(){
    switchOrange();
    side = 'g';
    std::string cu[26];
    cu[0]= cubes[0];
    for(int i =0; i< 26; i++){
        cu[i] = cubes[i];
    }
    cubes[0]=cu[6];
    cubes[1]=cu[3];
    cubes[2]=cu[0];
    cubes[3]=cu[7];
    cubes[4]=cu[4];
    cubes[5]=cu[1];
    cubes[6]=cu[8];
    cubes[7]=cu[5];
    cubes[8]=cu[2];
    cubes[9]=cu[14];
    cubes[10]=cu[12];
    cubes[11]=cu[9];
    cubes[12]=cu[15];
    cubes[13]=cu[10];
    cubes[14]=cu[16];
    cubes[15]=cu[13];
    cubes[16]=cu[11];
    cubes[17]=cu[23];
    cubes[18]=cu[20];
    cubes[19]=cu[17];
    cubes[20]=cu[24];
    cubes[21]=cu[21];
    cubes[22]=cu[18];
    cubes[23]=cu[25];
    cubes[24]=cu[22];
    cubes[25]=cu[19];
}


void rubixMoves::switchOrange(){
    side = 'o';
    for(int i= 0; i <26;i++){
        cubes[i].clear();
    }
    cubes[0].insert(0,1,squares[0]).insert(1,1,squares[29]).insert(2,1,squares[51]);
    cubes[1].insert(0,1,squares[1]).insert(1,1,squares[52]);
    cubes[2].insert(0,1,squares[2]).insert(1,1,squares[9]).insert(2,1,squares[53]);
    cubes[3].insert(0,1,squares[28]).insert(1,1,squares[48]);
    cubes[4] = squares[49];
    cubes[5].insert(0,1,squares[50]).insert(1,1,squares[10]);
    cubes[6].insert(0,1,squares[20]).insert(1,1,squares[27]).insert(2,1,squares[45]);
    cubes[7].insert(0,1,squares[19]).insert(1,1,squares[46]);
    cubes[8].insert(0,1,squares[11]).insert(1,1,squares[18]).insert(2,1,squares[47]);
    cubes[9].insert(0,1,squares[3]).insert(1,1,squares[32]);
    cubes[10].insert(0,1,squares[4]);
    cubes[11].insert(0,1,squares[5]).insert(1,1,squares[12]);
    cubes[12] = squares[31];
    cubes[13] = squares[13];
    cubes[14].insert(0,1,squares[23]).insert(1,1,squares[30]);
    cubes[15] = squares[22];
    cubes[16].insert(0,1,squares[14]).insert(1,1,squares[21]);
    cubes[17].insert(0,1,squares[6]).insert(1,1,squares[35]).insert(2,1,squares[36]);
    cubes[18].insert(0,1,squares[7]).insert(1,1,squares[37]);
    cubes[19].insert(0,1,squares[8]).insert(1,1,squares[15]).insert(2,1,squares[38]);
    cubes[20].insert(0,1,squares[34]).insert(1,1,squares[39]);
    cubes[21] = squares[40];
    cubes[22].insert(0,1,squares[16]).insert(1,1,squares[41]);
    cubes[23].insert(0,1,squares[26]).insert(1,1,squares[33]).insert(2,1,squares[42]);
    cubes[24].insert(0,1,squares[25]).insert(1,1,squares[43]);
    cubes[25].insert(0,1,squares[17]).insert(1,1,squares[24]).insert(2,1,squares[44]);
}

void rubixMoves::switchBlue(){
    switchOrange();
    side = 'b';
    std::string cu[26];
    for(int i =0; i<26; i++){
        cu[i] = cubes[i];
    }
    cubes[0]=cu[2];
    cubes[1]=cu[5];
    cubes[2]= cu[8];
    cubes[3] = cu[1];
    cubes[4]=cu[4];
    cubes[5]=cu[7];
    cubes[6]= cu[0];
    cubes[7] = cu[3];
    cubes[8]=cu[6];
    cubes[9]=cu[11];
    cubes[10]= cu[13];
    cubes[11] = cu[16];
    cubes[12]=cu[10];
    cubes[13]=cu[15];
    cubes[14]= cu[9];
    cubes[15] = cu[12];
    cubes[16]=cu[14];
    cubes[17]=cu[19];
    cubes[18]= cu[22];
    cubes[19] = cu[25];
    cubes[20]=cu[18];
    cubes[21]=cu[21];
    cubes[22]= cu[24];
    cubes[23] = cu[17];
    cubes[24]=cu[20];
    cubes[25]= cu[23];
    
}

void rubixMoves::switchRed(){
    switchOrange();
    side = 'r';
    std::string cu[26];
    for(int i =0; i< 26; i++){
        cu[i] = cubes[i];
    }
    cubes[0]=cu[8];
    cubes[1]=cu[7];
    cubes[2]= cu[6];
    cubes[3] = cu[5];
    cubes[4]=cu[4];
    cubes[5]=cu[3];
    cubes[6]= cu[2];
    cubes[7] = cu[1];
    cubes[8]=cu[0];
    cubes[9]=cu[16];
    cubes[10]= cu[15];
    cubes[11] = cu[14];
    cubes[12]=cu[13];
    cubes[13]=cu[12];
    cubes[14]= cu[11];
    cubes[15] = cu[10];
    cubes[16]=cu[9];
    cubes[17]=cu[25];
    cubes[18]= cu[24];
    cubes[19] = cu[23];
    cubes[20]=cu[22];
    cubes[21]=cu[21];
    cubes[22]= cu[20];
    cubes[23] = cu[19];
    cubes[24]=cu[18];
    cubes[25]= cu[17];
    
}

void rubixMoves::fFTurnRight(){
    
    if(side != 'o' && transfered == false){
        if(side == 'r'){
            switchOrange();
            transfered = true;
            bacFTurnLeft();
            switchRed();
        }
        if(side == 'b'){
            switchOrange();
            transfered = true;
            rightTurnUp();
            switchBlue();
        }
        if(side == 'g'){
            switchOrange();
            transfered = true;
            leftTurnDown();
            switchGreen();
        }
    }
    else{
     cout<< iter << " ";
     *movesQueue << 0;

    //cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[17];
    cubes[17] = cubes[19];
    cubes[19] = cubes[2];
    cubes[2]= temp;
    
    temp = cubes[1];
    cubes[1] = cubes[9];
    cubes[9]=cubes[18];
    cubes[18] = cubes[11];
    cubes[11] = temp;
    
    //squares
    char t = squares[0];
    squares[0] = squares[6];
    squares[6] = squares[8];
    squares[8] = squares[2];
    squares[2] = t;
    t= squares[1];
    squares[1] =squares[3];
    squares[3] = squares[7];
    squares[7] = squares[5];
    squares[5] = t;
    t=squares[51];
    squares[51] =squares[35];
    squares[35] = squares[38];
    squares[38] = squares[9];
    squares[9] = t;
    t=squares[52];
    squares[52] = squares[32];
    squares[32]= squares[37];
    squares[37]= squares[12];
    squares[12]=t;
    t=squares[53];
    squares[53] = squares[29];
    squares[29] = squares[36];
    squares[36] = squares[15];
    squares[15] =t;
    transfered = false;
        iter++;
    }
}

void rubixMoves::fFTurnLeft(){
    
    if(side != 'o' && transfered == false){
        if(side == 'r'){
            switchOrange();
            transfered = true;
            bacFTurnRight();
            switchRed();
        }
        if(side == 'b'){
            switchOrange();
            transfered = true;
            rightTurnDown();
            switchBlue();
        }
        if(side == 'g'){
            switchOrange();
            transfered = true;
            leftTurnUp();
            switchGreen();
        }
    }
    else{
        cout<< iter << " ";
        *movesQueue << 1;
    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[2];
    cubes[2] = cubes[19];
    cubes[19] = cubes[17];
    cubes[17]= temp;
    
    temp = cubes[1];
    cubes[1] = cubes[11];
    cubes[11]=cubes[18];
    cubes[18] = cubes[9];
    cubes[9] = temp;
    
    //new squares
    char t = squares[0];
    squares[0] = squares[2];
    squares[2] = squares[8];
    squares[8] = squares[6];
    squares[6] = t;
    
    t= squares[1];
    squares[1] =squares[5];
    squares[5] = squares[7];
    squares[7] = squares[3];
    squares[3]= t;
    
    t=squares[51];
    squares[51] =squares[9];
    squares[9] = squares[38];
    squares[38] = squares[35];
    squares[35] = t;
    t=squares[52];
    squares[52] = squares[12];
    squares[12]= squares[37];
    squares[37]= squares[32];
    squares[32]=t;
    t=squares[53];
    squares[53] = squares[15];
    squares[15] = squares[36];
    squares[36] = squares[29];
    squares[29] =t;
        transfered = false;
        iter++;
    }
}

void rubixMoves::bacFTurnRight(){
    if(side != 'o' && transfered == false){
        if(side == 'r'){
            switchOrange();
            transfered = true;
            fFTurnLeft();
            switchRed();
        }
        if(side == 'b'){
            switchOrange();
            transfered = true;
            leftTurnUp();
            switchBlue();
        }
        if(side == 'g'){
            switchOrange();
            transfered = true;
            rightTurnDown();
            switchGreen();
        }
    }
    else{
    cout<< iter << " ";
    *movesQueue << 2;
    //new cubes
    string temp;
    temp = cubes[8];
    cubes[8] = cubes[6];
    cubes[6] = cubes[23];
    cubes[23] = cubes[25];
    cubes[25] = temp;
    
    temp = cubes[7];
    cubes[7] = cubes[14];
    cubes[14] = cubes[24];
    cubes[24] = cubes[16];
    cubes[16] = temp;
    
    //new squares
    char t = squares[18];
    squares[18] = squares[20];
    squares[20] = squares[26];
    squares[26] = squares[24];
    squares[24] = t;
    
    t= squares[19];
    squares[19] =squares[23];
    squares[23] = squares[25];
    squares[25] = squares[21];
    squares[21]= t;
    
    t=squares[47];
    squares[47] =squares[27];
    squares[27] = squares[42];
    squares[42] = squares[17];
    squares[17] = t;
    t=squares[46];
    squares[46] = squares[30];
    squares[30]= squares[43];
    squares[43]= squares[14];
    squares[14]=t;
    t=squares[45];
    squares[45] = squares[33];
    squares[33] = squares[44];
    squares[44] = squares[11];
    squares[11] =t;
        transfered=false;
        iter++;
    }
    
}

void rubixMoves::bacFTurnLeft(){
    if(side != 'o' && transfered == false){
        if(side == 'r'){
            switchOrange();
            transfered = true;
            fFTurnRight();
            switchRed();
        }
        if(side == 'b'){
            switchOrange();
            transfered = true;
            leftTurnUp();
            switchBlue();
        }
        if(side == 'g'){
            switchOrange();
            transfered = true;
            leftTurnUp();
            switchGreen();
        }
    }
    else{
    cout<< iter << " ";
    *movesQueue << 3;
    //new cubes
    string temp;
    temp = cubes[8];
    cubes[8] = cubes[25];
    cubes[25] = cubes[23];
    cubes[23] = cubes[6];
    cubes[6] = temp;
    
    temp = cubes[7];
    cubes[7] = cubes[16];
    cubes[16] = cubes[24];
    cubes[24] = cubes[14];
    cubes[14] = temp;
    
    //new squares
    char t = squares[18];
    squares[18] = squares[24];
    squares[24] = squares[26];
    squares[26] = squares[20];
    squares[20] = t;
    
    t= squares[19];
    squares[19] =squares[21];
    squares[21] = squares[25];
    squares[25] = squares[23];
    squares[23]= t;
    
    t=squares[47];
    squares[47] =squares[17];
    squares[17] = squares[42];
    squares[42] = squares[27];
    squares[27] = t;
    t=squares[46];
    squares[46] = squares[14];
    squares[14]= squares[43];
    squares[43]= squares[30];
    squares[30]=t;
    t=squares[45];
    squares[45] = squares[11];
    squares[11] = squares[44];
    squares[44] = squares[33];
    squares[33] =t;
        transfered = false;
        iter++;
    }
}

void rubixMoves::topTurnRight(){
    char tempSide = side;
    switchOrange();
    
    cout<< iter << " ";
    *movesQueue << 4;
    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[6];
    cubes[6] = cubes[8];
    cubes[8] = cubes[2];
    cubes[2] = temp;
    
    temp = cubes[1];
    cubes[1] = cubes[3];
    cubes[3] = cubes[7];
    cubes[7] = cubes[5];
    cubes[5] = temp;
    
    //new squares
    char t = squares[45];
    squares[45] = squares[47];
    squares[47] = squares[53];
    squares[53] = squares[51];
    squares[51] = t;
    
    t= squares[46];
    squares[46] =squares[50];
    squares[50] = squares[52];
    squares[52] = squares[48];
    squares[48]= t;
    
    t=squares[0];
    squares[0] = squares[27];
    squares[27] = squares[18];
    squares[18] = squares[9];
    squares[9] = t;
    t=squares[1];
    squares[1] = squares[28];
    squares[28]= squares[19];
    squares[19]= squares[10];
    squares[10]= t;
    t=squares[2];
    squares[2] = squares[29];
    squares[29] = squares[20];
    squares[20] = squares[11];
    squares[11] = t;
    
    switch(tempSide){
    case 'r':
            switchRed();
            break;
    case 'b':
            switchBlue();
            break;
    case 'g':
            switchGreen();
            break;
    }
    iter++;
}
void rubixMoves::topTurnLeft(){
    char tempSide = side;

    switchOrange();
    cout<< iter << " ";
    *movesQueue << 5;
    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[2];
    cubes[2] = cubes[8];
    cubes[8] = cubes[6];
    cubes[6] = temp;
    
    temp = cubes[1];
    cubes[1] = cubes[5];
    cubes[5] = cubes[7];
    cubes[7] = cubes[3];
    cubes[3] = temp;
    
    //new squares
    char t = squares[45];
    squares[45] = squares[51];
    squares[51] = squares[53];
    squares[53] = squares[47];
    squares[47] = t;
    
    t= squares[46];
    squares[46] =squares[48];
    squares[48] = squares[52];
    squares[52] = squares[50];
    squares[50]= t;
    
    t=squares[0];
    squares[0] = squares[9];
    squares[9] = squares[18];
    squares[18] = squares[27];
    squares[27] = t;
    t=squares[1];
    squares[1] = squares[10];
    squares[10]= squares[19];
    squares[19]= squares[28];
    squares[28]= t;
    t=squares[2];
    squares[2] = squares[11];
    squares[11] = squares[20];
    squares[20] = squares[29];
    squares[29] = t;
    switch(tempSide){
        case 'r':
            switchRed();
            break;
        case 'b':
            switchBlue();
            break;
        case 'g':
            switchGreen();
            break;
    }
    iter++;
    
}

void rubixMoves::bottTurnRight(){
    char tempSide = side;

    switchOrange();
    cout<< iter << " ";
    *movesQueue << 6;

    //new cubes
    string temp;
    temp = cubes[17];
    cubes[17] = cubes[23];
    cubes[23] = cubes[25];
    cubes[25] = cubes[19];
    cubes[19] = temp;
    
    temp = cubes[18];
    cubes[18] = cubes[20];
    cubes[20] = cubes[24];
    cubes[24] = cubes[22];
    cubes[22] = temp;
    
    //new squares
    char t = squares[6];
    squares[6] = squares[33];
    squares[33] = squares[24];
    squares[24] = squares[15];
    squares[15] = t;
    
    t= squares[7];
    squares[7] =squares[34];
    squares[34] = squares[25];
    squares[25] = squares[16];
    squares[16]= t;
    
    t=squares[8];
    squares[8] = squares[35];
    squares[35] = squares[26];
    squares[26] = squares[17];
    squares[17] = t;
    t=squares[36];
    squares[36] = squares[42];
    squares[42]= squares[44];
    squares[44]= squares[38];
    squares[38]= t;
    t=squares[37];
    squares[37] = squares[39];
    squares[39] = squares[43];
    squares[43] = squares[41];
    squares[41] = t;
    switch(tempSide){
        case 'r':
            switchRed();
            break;
        case 'b':
            switchBlue();
            break;
        case 'g':
            switchGreen();
            break;
    }
    iter++;

}

void rubixMoves::bottTurnLeft(){
    char tempSide = side;

    switchOrange();
    cout<< iter << " ";
    *movesQueue << 7;

    //new cubes
    string temp;
    temp = cubes[17];
    cubes[17] = cubes[19];
    cubes[19] = cubes[25];
    cubes[25] = cubes[23];
    cubes[23] = temp;
    
    temp = cubes[18];
    cubes[18] = cubes[22];
    cubes[22] = cubes[24];
    cubes[24] = cubes[20];
    cubes[20] = temp;
    
    //new squares
    char t = squares[6];
    squares[6] = squares[15];
    squares[15] = squares[24];
    squares[24] = squares[33];
    squares[33] = t;
    
    t= squares[7];
    squares[7] =squares[16];
    squares[16] = squares[25];
    squares[25] = squares[34];
    squares[34]= t;
    
    t=squares[8];
    squares[8] = squares[17];
    squares[17] = squares[26];
    squares[26] = squares[35];
    squares[35] = t;
    t=squares[36];
    squares[36] = squares[38];
    squares[38]= squares[44];
    squares[44]= squares[42];
    squares[42]= t;
    t=squares[37];
    squares[37] = squares[41];
    squares[41] = squares[43];
    squares[43] = squares[39];
    squares[39] = t;
    switch(tempSide){
        case 'r':
            switchRed();
            break;
        case 'b':
            switchBlue();
            break;
        case 'g':
            switchGreen();
            break;
    }
    iter++;
}

void rubixMoves::leftTurnUp(){
    
    if(side != 'o' && transfered == false){
        if(side == 'r'){
            switchOrange();
            transfered = true;
            rightTurnDown();
            switchRed();
        }
        if(side == 'b'){
            switchOrange();
            transfered = true;
            fFTurnLeft();
            switchBlue();
        }
        if(side == 'g'){
            switchOrange();
            transfered = true;
            bacFTurnRight();
            switchGreen();
        }
    }
    else{
        cout<< iter << " ";
        *movesQueue << 8;

    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[17];
    cubes[17] = cubes[23];
    cubes[23] = cubes[6];
    cubes[6] = temp;
    
    temp = cubes[9];
    cubes[9] = cubes[20];
    cubes[20] = cubes[14];
    cubes[14] = cubes[3];
    cubes[3] = temp;
    
    //new squares
    char t = squares[0];
    squares[0] = squares[36];
    squares[36] = squares[26];
    squares[26] = squares[45];
    squares[45] = t;
    
    t= squares[3];
    squares[3] =squares[39];
    squares[39] = squares[23];
    squares[23] = squares[48];
    squares[48]= t;
    
    t=squares[6];
    squares[6] = squares[42];
    squares[42] = squares[20];
    squares[20] = squares[51];
    squares[51] = t;
    
    t=squares[29];
    squares[29] = squares[35];
    squares[35]= squares[33];
    squares[33]= squares[27];
    squares[27]= t;
    t=squares[32];
    squares[32] = squares[34];
    squares[34] = squares[30];
    squares[30] = squares[28];
    squares[28] = t;
        transfered =false;
        iter++;
    }
}

void rubixMoves::leftTurnDown(){
    
    if(side != 'o' && transfered == false){
        if(side == 'r'){
            switchOrange();
            transfered = true;
            rightTurnUp();
            switchRed();
        }
        if(side == 'b'){
            switchOrange();
            transfered = true;
            fFTurnRight();
            switchBlue();
        }
        if(side == 'g'){
            switchOrange();
            transfered = true;
            bacFTurnLeft();
            switchGreen();
        }
    }
    else{
        cout<< iter << " ";
        *movesQueue << 9;

    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[6];
    cubes[6] = cubes[23];
    cubes[23] = cubes[17];
    cubes[17] = temp;
    
    temp = cubes[9];
    cubes[9] = cubes[3];
    cubes[3] = cubes[14];
    cubes[14] = cubes[20];
    cubes[20] = temp;
    
    //new squares
    char t = squares[0];
    squares[0] = squares[45];
    squares[45] = squares[26];
    squares[26] = squares[36];
    squares[36] = t;
    
    t= squares[3];
    squares[3] =squares[48];
    squares[48] = squares[23];
    squares[23] = squares[39];
    squares[39]= t;
    
    t=squares[6];
    squares[6] = squares[51];
    squares[51] = squares[20];
    squares[20] = squares[42];
    squares[42] = t;
    
    t=squares[29];
     squares[29] = squares[27];
     squares[27]= squares[33];
     squares[33]= squares[35];
     squares[35]= t;
     t=squares[32];
     squares[32] = squares[28];
     squares[28] = squares[30];
     squares[30] = squares[34];
     squares[34] = t;
    transfered = false;
        iter++;
    }
}

void rubixMoves::rightTurnUp(){
    
    if(side != 'o' && transfered == false){
        if(side == 'r'){
            switchOrange();
            transfered = true;
            leftTurnDown();
            switchRed();
        }
        if(side == 'b'){
            switchOrange();
            transfered = true;
            bacFTurnLeft();
            switchBlue();
        }
        if(side == 'g'){
            switchOrange();
            transfered = true;
            fFTurnRight();
            switchGreen();
        }
    }
    else{
        cout<< iter << " ";
        *movesQueue << 10;

    //new cubes
    string temp;
    temp = cubes[2];
    cubes[2] = cubes[19];
    cubes[19] = cubes[25];
    cubes[25] = cubes[8];
    cubes[8] = temp;
    
    temp = cubes[11];
    cubes[11] = cubes[22];
    cubes[22] = cubes[16];
    cubes[16] = cubes[5];
    cubes[5] = temp;
    
    //new squares
    char t = squares[2];
    squares[2] = squares[38];
    squares[38] = squares[24];
    squares[24] = squares[47];
    squares[47] = t;
    
    t= squares[5];
    squares[5] =squares[41];
    squares[41] = squares[21];
    squares[21] = squares[50];
    squares[50]= t;
    
    t=squares[8];
    squares[8] = squares[44];
    squares[44] = squares[18];
    squares[18] = squares[53];
    squares[53] = t;
    
    t=squares[9];
    squares[9] = squares[15];
    squares[15]= squares[17];
    squares[17]= squares[11];
    squares[11]= t;
    t=squares[12];
    squares[12] = squares[16];
    squares[16] = squares[14];
    squares[14] = squares[10];
    squares[10] = t;
        transfered = false;
        iter++;
    }
}

void rubixMoves::rightTurnDown(){
    
    if(side != 'o' && transfered == false){
        if(side == 'r'){
            switchOrange();
            transfered = true;
            leftTurnUp();
            switchRed();
        }
        if(side == 'b'){
            switchOrange();
            transfered = true;
            bacFTurnRight();
            switchBlue();
        }
        if(side == 'g'){
            switchOrange();
            transfered = true;
            fFTurnLeft();
            switchGreen();
        }
    }
    else{
        cout<< iter << " ";
        *movesQueue << 11;

    //new cubes
    string temp;
    temp = cubes[2];
    cubes[2] = cubes[8];
    cubes[8] = cubes[25];
    cubes[25] = cubes[19];
    cubes[19] = temp;
    
    temp = cubes[11];
    cubes[11] = cubes[5];
    cubes[5] = cubes[16];
    cubes[16] = cubes[22];
    cubes[22] = temp;
    
    //new squares
    char t = squares[2];
    squares[2] = squares[47];
    squares[47] = squares[24];
    squares[24] = squares[38];
    squares[38] = t;
    
    t= squares[5];
    squares[5] =squares[50];
    squares[50] = squares[21];
    squares[21] = squares[41];
    squares[41]= t;
    
    t=squares[8];
    squares[8] = squares[53];
    squares[53] = squares[18];
    squares[18] = squares[44];
    squares[44] = t;
    
    t=squares[9];
     squares[9] = squares[11];
     squares[11]= squares[17];
     squares[17]= squares[15];
     squares[15]= t;
     t=squares[12];
     squares[12] = squares[10];
     squares[10] = squares[14];
     squares[14] = squares[16];
     squares[16] = t;
        transfered = false;
        iter++;
    }
}

////////////////////////

void rubixMoves::fFTurnRight2(){
    //cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[17];
    cubes[17] = cubes[19];
    cubes[19] = cubes[2];
    cubes[2]= temp;

    temp = cubes[1];
    cubes[1] = cubes[9];
    cubes[9]=cubes[18];
    cubes[18] = cubes[11];
    cubes[11] = temp;

    //squares
    char t = squares[0];
    squares[0] = squares[6];
    squares[6] = squares[8];
    squares[8] = squares[2];
    squares[2] = t;
    t= squares[1];
    squares[1] =squares[3];
    squares[3] = squares[7];
    squares[7] = squares[5];
    squares[5] = t;
    t=squares[51];
    squares[51] =squares[35];
    squares[35] = squares[38];
    squares[38] = squares[9];
    squares[9] = t;
    t=squares[52];
    squares[52] = squares[32];
    squares[32]= squares[37];
    squares[37]= squares[12];
    squares[12]=t;
    t=squares[53];
    squares[53] = squares[29];
    squares[29] = squares[36];
    squares[36] = squares[15];
    squares[15] =t;

}

void rubixMoves::fFTurnLeft2(){

    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[2];
    cubes[2] = cubes[19];
    cubes[19] = cubes[17];
    cubes[17]= temp;

    temp = cubes[1];
    cubes[1] = cubes[11];
    cubes[11]=cubes[18];
    cubes[18] = cubes[9];
    cubes[9] = temp;

    //new squares
    char t = squares[0];
    squares[0] = squares[2];
    squares[2] = squares[8];
    squares[8] = squares[6];
    squares[6] = t;

    t= squares[1];
    squares[1] =squares[5];
    squares[5] = squares[7];
    squares[7] = squares[3];
    squares[3]= t;

    t=squares[51];
    squares[51] =squares[9];
    squares[9] = squares[38];
    squares[38] = squares[35];
    squares[35] = t;
    t=squares[52];
    squares[52] = squares[12];
    squares[12]= squares[37];
    squares[37]= squares[32];
    squares[32]=t;
    t=squares[53];
    squares[53] = squares[15];
    squares[15] = squares[36];
    squares[36] = squares[29];
    squares[29] =t;
}

void rubixMoves::bacFTurnRight2(){

    //new cubes
    string temp;
    temp = cubes[8];
    cubes[8] = cubes[6];
    cubes[6] = cubes[23];
    cubes[23] = cubes[25];
    cubes[25] = temp;

    temp = cubes[7];
    cubes[7] = cubes[14];
    cubes[14] = cubes[24];
    cubes[24] = cubes[16];
    cubes[16] = temp;

    //new squares
    char t = squares[18];
    squares[18] = squares[20];
    squares[20] = squares[26];
    squares[26] = squares[24];
    squares[24] = t;

    t= squares[19];
    squares[19] =squares[23];
    squares[23] = squares[25];
    squares[25] = squares[21];
    squares[21]= t;

    t=squares[47];
    squares[47] =squares[27];
    squares[27] = squares[42];
    squares[42] = squares[17];
    squares[17] = t;
    t=squares[46];
    squares[46] = squares[30];
    squares[30]= squares[43];
    squares[43]= squares[14];
    squares[14]=t;
    t=squares[45];
    squares[45] = squares[33];
    squares[33] = squares[44];
    squares[44] = squares[11];
    squares[11] =t;
}

void rubixMoves::bacFTurnLeft2(){
    //new cubes
    string temp;
    temp = cubes[8];
    cubes[8] = cubes[25];
    cubes[25] = cubes[23];
    cubes[23] = cubes[6];
    cubes[6] = temp;

    temp = cubes[7];
    cubes[7] = cubes[16];
    cubes[16] = cubes[24];
    cubes[24] = cubes[14];
    cubes[14] = temp;

    //new squares
    char t = squares[18];
    squares[18] = squares[24];
    squares[24] = squares[26];
    squares[26] = squares[20];
    squares[20] = t;

    t= squares[19];
    squares[19] =squares[21];
    squares[21] = squares[25];
    squares[25] = squares[23];
    squares[23]= t;

    t=squares[47];
    squares[47] =squares[17];
    squares[17] = squares[42];
    squares[42] = squares[27];
    squares[27] = t;
    t=squares[46];
    squares[46] = squares[14];
    squares[14]= squares[43];
    squares[43]= squares[30];
    squares[30]=t;
    t=squares[45];
    squares[45] = squares[11];
    squares[11] = squares[44];
    squares[44] = squares[33];
    squares[33] =t;
}

void rubixMoves::topTurnRight2(){
    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[6];
    cubes[6] = cubes[8];
    cubes[8] = cubes[2];
    cubes[2] = temp;

    temp = cubes[1];
    cubes[1] = cubes[3];
    cubes[3] = cubes[7];
    cubes[7] = cubes[5];
    cubes[5] = temp;

    //new squares
    char t = squares[45];
    squares[45] = squares[47];
    squares[47] = squares[53];
    squares[53] = squares[51];
    squares[51] = t;

    t= squares[46];
    squares[46] =squares[50];
    squares[50] = squares[52];
    squares[52] = squares[48];
    squares[48]= t;

    t=squares[0];
    squares[0] = squares[27];
    squares[27] = squares[18];
    squares[18] = squares[9];
    squares[9] = t;
    t=squares[1];
    squares[1] = squares[28];
    squares[28]= squares[19];
    squares[19]= squares[10];
    squares[10]= t;
    t=squares[2];
    squares[2] = squares[29];
    squares[29] = squares[20];
    squares[20] = squares[11];
    squares[11] = t;


}
void rubixMoves::topTurnLeft2(){

    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[2];
    cubes[2] = cubes[8];
    cubes[8] = cubes[6];
    cubes[6] = temp;

    temp = cubes[1];
    cubes[1] = cubes[5];
    cubes[5] = cubes[7];
    cubes[7] = cubes[3];
    cubes[3] = temp;

    //new squares
    char t = squares[45];
    squares[45] = squares[51];
    squares[51] = squares[53];
    squares[53] = squares[47];
    squares[47] = t;

    t= squares[46];
    squares[46] =squares[48];
    squares[48] = squares[52];
    squares[52] = squares[50];
    squares[50]= t;

    t=squares[0];
    squares[0] = squares[9];
    squares[9] = squares[18];
    squares[18] = squares[27];
    squares[27] = t;
    t=squares[1];
    squares[1] = squares[10];
    squares[10]= squares[19];
    squares[19]= squares[28];
    squares[28]= t;
    t=squares[2];
    squares[2] = squares[11];
    squares[11] = squares[20];
    squares[20] = squares[29];
    squares[29] = t;
}

void rubixMoves::bottTurnRight2(){

    //new cubes
    string temp;
    temp = cubes[17];
    cubes[17] = cubes[23];
    cubes[23] = cubes[25];
    cubes[25] = cubes[19];
    cubes[19] = temp;

    temp = cubes[18];
    cubes[18] = cubes[20];
    cubes[20] = cubes[24];
    cubes[24] = cubes[22];
    cubes[22] = temp;

    //new squares
    char t = squares[6];
    squares[6] = squares[33];
    squares[33] = squares[24];
    squares[24] = squares[15];
    squares[15] = t;

    t= squares[7];
    squares[7] =squares[34];
    squares[34] = squares[25];
    squares[25] = squares[16];
    squares[16]= t;

    t=squares[8];
    squares[8] = squares[35];
    squares[35] = squares[26];
    squares[26] = squares[17];
    squares[17] = t;
    t=squares[36];
    squares[36] = squares[42];
    squares[42]= squares[44];
    squares[44]= squares[38];
    squares[38]= t;
    t=squares[37];
    squares[37] = squares[39];
    squares[39] = squares[43];
    squares[43] = squares[41];
    squares[41] = t;
}

void rubixMoves::bottTurnLeft2(){

    //new cubes
    string temp;
    temp = cubes[17];
    cubes[17] = cubes[19];
    cubes[19] = cubes[25];
    cubes[25] = cubes[23];
    cubes[23] = temp;

    temp = cubes[18];
    cubes[18] = cubes[22];
    cubes[22] = cubes[24];
    cubes[24] = cubes[20];
    cubes[20] = temp;

    //new squares
    char t = squares[6];
    squares[6] = squares[15];
    squares[15] = squares[24];
    squares[24] = squares[33];
    squares[33] = t;

    t= squares[7];
    squares[7] =squares[16];
    squares[16] = squares[25];
    squares[25] = squares[34];
    squares[34]= t;

    t=squares[8];
    squares[8] = squares[17];
    squares[17] = squares[26];
    squares[26] = squares[35];
    squares[35] = t;
    t=squares[36];
    squares[36] = squares[38];
    squares[38]= squares[44];
    squares[44]= squares[42];
    squares[42]= t;
    t=squares[37];
    squares[37] = squares[41];
    squares[41] = squares[43];
    squares[43] = squares[39];
    squares[39] = t;
}

void rubixMoves::leftTurnUp2(){

    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[17];
    cubes[17] = cubes[23];
    cubes[23] = cubes[6];
    cubes[6] = temp;

    temp = cubes[9];
    cubes[9] = cubes[20];
    cubes[20] = cubes[14];
    cubes[14] = cubes[3];
    cubes[3] = temp;

    //new squares
    char t = squares[0];
    squares[0] = squares[36];
    squares[36] = squares[26];
    squares[26] = squares[45];
    squares[45] = t;

    t= squares[3];
    squares[3] =squares[39];
    squares[39] = squares[23];
    squares[23] = squares[48];
    squares[48]= t;

    t=squares[6];
    squares[6] = squares[42];
    squares[42] = squares[20];
    squares[20] = squares[51];
    squares[51] = t;

    t=squares[29];
    squares[29] = squares[35];
    squares[35]= squares[33];
    squares[33]= squares[27];
    squares[27]= t;
    t=squares[32];
    squares[32] = squares[34];
    squares[34] = squares[30];
    squares[30] = squares[28];
    squares[28] = t;
}

void rubixMoves::leftTurnDown2(){

    //new cubes
    string temp;
    temp = cubes[0];
    cubes[0] = cubes[6];
    cubes[6] = cubes[23];
    cubes[23] = cubes[17];
    cubes[17] = temp;

    temp = cubes[9];
    cubes[9] = cubes[3];
    cubes[3] = cubes[14];
    cubes[14] = cubes[20];
    cubes[20] = temp;

    //new squares
    char t = squares[0];
    squares[0] = squares[45];
    squares[45] = squares[26];
    squares[26] = squares[36];
    squares[36] = t;

    t= squares[3];
    squares[3] =squares[48];
    squares[48] = squares[23];
    squares[23] = squares[39];
    squares[39]= t;

    t=squares[6];
    squares[6] = squares[51];
    squares[51] = squares[20];
    squares[20] = squares[42];
    squares[42] = t;

    t=squares[29];
     squares[29] = squares[27];
     squares[27]= squares[33];
     squares[33]= squares[35];
     squares[35]= t;
     t=squares[32];
     squares[32] = squares[28];
     squares[28] = squares[30];
     squares[30] = squares[34];
     squares[34] = t;
}

void rubixMoves::rightTurnUp2(){

    //new cubes
    string temp;
    temp = cubes[2];
    cubes[2] = cubes[19];
    cubes[19] = cubes[25];
    cubes[25] = cubes[8];
    cubes[8] = temp;

    temp = cubes[11];
    cubes[11] = cubes[22];
    cubes[22] = cubes[16];
    cubes[16] = cubes[5];
    cubes[5] = temp;

    //new squares
    char t = squares[2];
    squares[2] = squares[38];
    squares[38] = squares[24];
    squares[24] = squares[47];
    squares[47] = t;

    t= squares[5];
    squares[5] =squares[41];
    squares[41] = squares[21];
    squares[21] = squares[50];
    squares[50]= t;

    t=squares[8];
    squares[8] = squares[44];
    squares[44] = squares[18];
    squares[18] = squares[53];
    squares[53] = t;

    t=squares[9];
    squares[9] = squares[15];
    squares[15]= squares[17];
    squares[17]= squares[11];
    squares[11]= t;
    t=squares[12];
    squares[12] = squares[16];
    squares[16] = squares[14];
    squares[14] = squares[10];
    squares[10] = t;
}

void rubixMoves::rightTurnDown2(){

    //new cubes
    string temp;
    temp = cubes[2];
    cubes[2] = cubes[8];
    cubes[8] = cubes[25];
    cubes[25] = cubes[19];
    cubes[19] = temp;

    temp = cubes[11];
    cubes[11] = cubes[5];
    cubes[5] = cubes[16];
    cubes[16] = cubes[22];
    cubes[22] = temp;

    //new squares
    char t = squares[2];
    squares[2] = squares[47];
    squares[47] = squares[24];
    squares[24] = squares[38];
    squares[38] = t;

    t= squares[5];
    squares[5] =squares[50];
    squares[50] = squares[21];
    squares[21] = squares[41];
    squares[41]= t;

    t=squares[8];
    squares[8] = squares[53];
    squares[53] = squares[18];
    squares[18] = squares[44];
    squares[44] = t;

    t=squares[9];
     squares[9] = squares[11];
     squares[11]= squares[17];
     squares[17]= squares[15];
     squares[15]= t;
     t=squares[12];
     squares[12] = squares[10];
     squares[10] = squares[14];
     squares[14] = squares[16];
     squares[16] = t;
}

