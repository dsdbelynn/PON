#ifndef SHOWFORM_H
#define SHOWFORM_H

#include <QWidget>
#include "mywidget.h"

namespace Ui {
class ShowForm;
}

class ShowForm : public QWidget
{
    Q_OBJECT

public:
    explicit ShowForm(QWidget *parent = nullptr);
    ~ShowForm();

private:
    Ui::ShowForm *ui;
protected:
    void enterEvent(QEvent *);
};

#endif // SHOWFORM_H
