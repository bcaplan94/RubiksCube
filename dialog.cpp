#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(save()));
    connect(ui->layoutComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(settingsChange()));
    connect(ui->buttonBox,SIGNAL(rejected()),this,SLOT(cancel()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::settingsChange(){
    emit updateSettings( ui->layoutComboBox->currentIndex());
}

void Dialog::save(){
    layout= ui->layoutComboBox->currentIndex();
    solveType = ui->speedComboBox->currentIndex();
    emit updateSettings(layout);
}

void Dialog::cancel(){
    ui->layoutComboBox->setCurrentIndex(layout);
    ui->speedComboBox->setCurrentIndex(solveType);
    emit updateSettings( layout);
}
