#ifndef CUBEINPUT_H
#define CUBEINPUT_H

#include <QDialog>

namespace Ui {
class CubeInput;
}

class CubeInput : public QDialog
{
    Q_OBJECT

public:
    explicit CubeInput(QWidget *parent = 0);
    ~CubeInput();

    virtual void paintEvent(QPaintEvent *e);

    QList<char> inputSquares;
    int side = 0;

private:
    Ui::CubeInput *ui;

    void setUpBrush();
    char convertToChar(int i);
    QList<QBrush> brushList;

private slots:
    void nextSave();

};

#endif // CUBEINPUT_H
