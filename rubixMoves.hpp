//
//  rubixMoves.hpp
//  rubixBegin
//
//  Created by Brian Caplan on 7/10/16.
//  Copyright © 2016 Brian Caplan. All rights reserved.
//

#ifndef rubixMoves_hpp
#define rubixMoves_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <qlist.h>

class rubixMoves{
    
public:
    rubixMoves(char* sq, std::string* cu, QList<int> * mq);
    ~rubixMoves();
    void switchRed();
    void switchGreen();
    void switchBlue();
    void switchOrange();
    
    void fFTurnRight();
    void fFTurnLeft();
    void bacFTurnRight();
    void bacFTurnLeft();
    void topTurnRight();
    void topTurnLeft();
    void bottTurnRight();
    void bottTurnLeft();
    void leftTurnUp();
    void leftTurnDown();
    void rightTurnUp();
    void rightTurnDown();

    void fFTurnRight2();
    void fFTurnLeft2();
    void bacFTurnRight2();
    void bacFTurnLeft2();
    void topTurnRight2();
    void topTurnLeft2();
    void bottTurnRight2();
    void bottTurnLeft2();
    void leftTurnUp2();
    void leftTurnDown2();
    void rightTurnUp2();
    void rightTurnDown2();
    
private:
    char* squares;
    std::string* cubes;
    char side;
    bool transfered;
    static int iter;

    QList<int>* movesQueue;
};


#endif /* rubixMoves_hpp */
