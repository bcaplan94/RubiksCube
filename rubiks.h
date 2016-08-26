
#ifndef rubiks_H
#define rubiks_H
#include "rubixAlgorithms.hpp"
#include <stdio.h>
#include <QObject>

class rubiks: public QObject{

    Q_OBJECT

public:
    explicit rubiks(QObject *parent = 0);

    char squares[54];
    std::string cubes[26];
    QList<int>* movesQueue = new QList<int>;
    QStringList movesStringQueue;

    rubixAlgorithms *rAlgor;
    rubixMoves *rMoves;

    int timerId;
    bool running = false;
    int speed = 1000;
    void runThrough();
public slots:
        void solve();
        void makeMove(int i = -999);

private:
   // rubixAlgorithms *rAlgor;
   // rubixMoves *rMoves;

    virtual void timerEvent(QTimerEvent * event);
    int numOfMoves;

    //steps to solve rubiks cube
    void step1Cross();
    void step1Corners();
    void step2();
    void step3Cross();
    void step3Sides();
    void step3CornersPt1();
    void step3CornersPt2();

    void setUp();

private slots:

  signals:
    void updatePaint(int);
};

#endif /* rubiks_hpp */
