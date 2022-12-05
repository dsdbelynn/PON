#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//无边框
    //setAttribute(Qt::WA_TranslucentBackground);//背景透明
}

Dialog::~Dialog()
{
    delete ui;
}
