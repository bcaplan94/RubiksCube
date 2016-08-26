#include "cubeinput.h"
#include "ui_cubeinput.h"
#include "qpainter.h"

CubeInput::CubeInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CubeInput)
{
    ui->setupUi(this);
    setUpBrush();
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(nextSave()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(close()));

    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(update()));
    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(update()));
    connect(ui->comboBox_3,SIGNAL(currentIndexChanged(int)),this,SLOT(update()));
    connect(ui->comboBox_4,SIGNAL(currentIndexChanged(int)),this,SLOT(update()));
    connect(ui->comboBox_5,SIGNAL(currentIndexChanged(int)),this,SLOT(update()));
    connect(ui->comboBox_6,SIGNAL(currentIndexChanged(int)),this,SLOT(update()));
    connect(ui->comboBox_7,SIGNAL(currentIndexChanged(int)),this,SLOT(update()));
    connect(ui->comboBox_8,SIGNAL(currentIndexChanged(int)),this,SLOT(update()));

}

CubeInput::~CubeInput()
{
    delete ui;
}

void CubeInput::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setRenderHints(QPainter::Antialiasing);

    painter.setPen(Qt::black);
    painter.setRenderHints(QPainter::Antialiasing);

    if(ui->comboBox->currentIndex() == -1){
        painter.setBrush(Qt::NoBrush);
    }
    else{
        painter.setBrush(brushList[ui->comboBox->currentIndex()]);
    }
    painter.drawRect(60,60,88,55);

    if(ui->comboBox_4->currentIndex() == -1){
        painter.setBrush(Qt::NoBrush);
    }
    else{
        painter.setBrush(brushList[ui->comboBox_4->currentIndex()]);
    }
    painter.drawRect(60,115,88,55);

    if(ui->comboBox_6->currentIndex() == -1){
        painter.setBrush(Qt::NoBrush);
    }
    else{
        painter.setBrush(brushList[ui->comboBox_6->currentIndex()]);
    }
    painter.drawRect(60,170,88,55);

    if(ui->comboBox_2->currentIndex() == -1){
        painter.setBrush(Qt::NoBrush);
    }
    else{
        painter.setBrush(brushList[ui->comboBox_2->currentIndex()]);
    }
    painter.drawRect(148,60,88,55);

    painter.setBrush(brushList[side]);
    painter.drawRect(148,115,88,55);

    if(ui->comboBox_7->currentIndex() == -1){
        painter.setBrush(Qt::NoBrush);
    }
    else{
        painter.setBrush(brushList[ui->comboBox_7->currentIndex()]);
    }
    painter.drawRect(148,170,88,55);

    if(ui->comboBox_3->currentIndex() == -1){
        painter.setBrush(Qt::NoBrush);
    }
    else{
        painter.setBrush(brushList[ui->comboBox_3->currentIndex()]);
    }
    painter.drawRect(236,60,88,55);
    if(ui->comboBox_5->currentIndex() == -1){
        painter.setBrush(Qt::NoBrush);
    }
    else{
        painter.setBrush(brushList[ui->comboBox_5->currentIndex()]);
    }
    painter.drawRect(236,115,88,55);
    if(ui->comboBox_8->currentIndex() == -1){
        painter.setBrush(Qt::NoBrush);
    }
    else{
        painter.setBrush(brushList[ui->comboBox_8->currentIndex()]);
    }
    painter.drawRect(236,170,88,55);



}

char CubeInput::convertToChar(int i){
    char result;
    switch(i){
    case 0:
        result = 'o';
        break;
    case 1:
        result = 'b';
        break;
    case 2:
        result = 'r';
        break;
    case 3:
        result = 'g';
        break;
    case 4:
        result = 'w';
        break;
    case 5:
        result = 'y';
        break;
    }
    return result;
}

void CubeInput::nextSave(){
    inputSquares << convertToChar(ui->comboBox->currentIndex());
    inputSquares << convertToChar( ui->comboBox_2->currentIndex());
    inputSquares << convertToChar(ui->comboBox_3->currentIndex());
    inputSquares << convertToChar(ui->comboBox_4->currentIndex());
    inputSquares << convertToChar(side);
    inputSquares << convertToChar( ui->comboBox_5->currentIndex());
    inputSquares << convertToChar(ui->comboBox_6->currentIndex());
    inputSquares << convertToChar(ui->comboBox_7->currentIndex());
    inputSquares << convertToChar(ui->comboBox_8->currentIndex());
    if(side!= 5){
        side++;
        ui->comboBox->setCurrentIndex(-1);
        ui->comboBox_2->setCurrentIndex(-1);
        ui->comboBox_3->setCurrentIndex(-1);
        ui->comboBox_4->setCurrentIndex(-1);
        ui->comboBox_5->setCurrentIndex(-1);
        ui->comboBox_6->setCurrentIndex(-1);
        ui->comboBox_7->setCurrentIndex(-1);
        ui->comboBox_8->setCurrentIndex(-1);
        if(side==5){
            ui->pushButton->setText("Save");
        }
        update();
    }
    else{
        ui->pushButton->setText("Next");
        this->accept();
    }
}

void CubeInput::setUpBrush(){

QColor o(255,128,0);
QColor r(255,0,0);
QColor b(0,0,255);
QColor g(0,204,0);
QColor w(255,255,255);
QColor y(255,255,0);

QBrush bO(o);
brushList << bO;
QBrush bB(b);
brushList << bB;
QBrush bR(r);
brushList << bR;
QBrush  bG(g);
brushList << bG;
QBrush bW(w);
brushList << bW;
QBrush bY(y);
brushList << bY;
}
