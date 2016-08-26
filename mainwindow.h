#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qpainter.h"
#include "rubiks.h"
#include "dialog.h"
#include "qframe.h"
#include <QtUiTools>
#include "cubeinput.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStringListModel* listViewModel;
private:
    Ui::MainWindow *ui;

    virtual void paintEvent(QPaintEvent *e);
    virtual void timerEvent(QTimerEvent * event);

    void guiSetup();
    void cubeSetup();
    void brushListSetup();
    void switchSpeed();

    QList<QPolygon> mPolygons;
    QList<QBrush> brushList;
    rubiks* rubiksCube;
    int highlight = -1;
    int timerId;
    int solveType = 2;
    Dialog* d = new Dialog(this);
    CubeInput* cubeInput = new CubeInput(this);

    enum layouts {projection,twoCubes};
    layouts layout = projection;

    QList<char> colors = {'o', 'r', 'b', 'g', 'w', 'y'};
     bool validate(QList<char>);
public slots:
    void updatingPaint(int);
    void mUpdateSettings(int);

private slots:
    void scrambleCube();
    void solveCube();
    void showDialog();
    void step();
    void setInput();
    void loadCube();
    void cubeSave();
signals:

};


#endif // MAINWINDOW_H
