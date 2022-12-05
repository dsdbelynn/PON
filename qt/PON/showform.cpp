#include "showform.h"
#include "ui_showform.h"
ShowForm::ShowForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowForm)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    //setAttribute(Qt::WA_TranslucentBackground);
}

ShowForm::~ShowForm()
{
    delete ui;
}

void ShowForm::enterEvent(QEvent *)
{
    this->close();
}
