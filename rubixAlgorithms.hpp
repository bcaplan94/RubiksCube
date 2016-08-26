//
//  rubixAlgorithms.hpp
//  rubixBegin
//
//  Created by Brian Caplan on 7/10/16.
//  Copyright © 2016 Brian Caplan. All rights reserved.
//

#ifndef rubixAlgorithms_hpp
#define rubixAlgorithms_hpp

#include "rubixMoves.hpp"
#include <stdio.h>
#include <string>

class rubixAlgorithms{
    
public:
    rubixAlgorithms(std::string* cubes, rubixMoves* moves);
    ~rubixAlgorithms();
    
    int findCube(std::string s);
    int cross(int i);
    int cornersLvl1(int i);
    void level2(int i);
    void lvl3Cross();
    void lvl3Sides();
    void lvl3Corners();
    void lvl3CornersFinal();
    
private:
    std::string* cubes;
    rubixMoves* moves;
};


#endif /* rubixAlgorithms_hpp */
