#pragma once

#include <QtWidgets/QWidget>
#include "ui_LoginWgt.h"
#include "FriendListWgt.h"


class LoginWgt : public QWidget
{
    Q_OBJECT

public:
    LoginWgt(QWidget *parent = Q_NULLPTR);

	void InitUI();
	void connectSlots();

private slots:
	void on_loginBtn_clicked();

private:
    Ui::LoginWgtClass ui;
};
