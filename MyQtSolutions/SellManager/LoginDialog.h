#pragma once

#include <QDialog>
#include "ui_LoginDialog.h"


class LoginDialog : public QDialog
{
	Q_OBJECT

public:
	LoginDialog(QWidget *parent = Q_NULLPTR);
	~LoginDialog();

	void InitUI();
	void connectSlots();

private slots:
	void on_loginBtn_clicked();
	void on_quitBtn_clicked();

private:
	Ui::LoginDialog ui;
};
