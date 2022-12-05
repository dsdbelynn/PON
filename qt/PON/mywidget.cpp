#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}

void MyWidget::enterEvent(QEvent *)
{
    this->close();
}
