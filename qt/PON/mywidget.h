#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QDialog>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);


protected:
    void enterEvent(QEvent *);

signals:

public slots:
};

#endif // MYWIDGET_H
