#pragma once

#include <QtWidgets/QWidget>
#include "ui_LoginWgt.h"



class LoginWgt : public QWidget
{
    Q_OBJECT

public:
    LoginWgt(QWidget *parent = Q_NULLPTR);

private:
    Ui::LoginWgtClass ui;
};
