#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    int layout;
    int solveType =2;
public slots:

signals:
    void updateSettings(int);

private:
    Ui::Dialog *ui;

private slots:
    void save();
    void settingsChange();
    void cancel();
};

#endif // DIALOG_H
