//
//  stepsRubix.hpp
//  rubixBegin
//
//  Created by Brian Caplan on 7/17/16.
//  Copyright © 2016 Brian Caplan. All rights reserved.
//

#ifndef stepsRubix_hpp
#define stepsRubix_hpp
#include "rubixAlgorithms.hpp"
#include <stdio.h>
#include <QObject>


class stepsRubix: public QObject{

    Q_OBJECT

public:
    explicit stepsRubix(QObject *parent = 0);

    void step1Cross();
    void step1Corners();
    void step2();
    void step3Cross();
    void step3Sides();
    void step3CornersPt1();
    void step3CornersPt2();

    void setUp();

    char squares[54];
    std::string cubes[26];
public slots:
  signals:
    void updatePaint();

private:
    rubixAlgorithms *rAlgor;
    rubixMoves *rMoves;

};

#endif /* stepsRubix_hpp */
