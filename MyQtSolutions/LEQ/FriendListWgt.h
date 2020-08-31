#pragma once

#include <QWidget>
#include "ui_FriendListWgt.h"

class FriendListWgt : public QWidget
{
	Q_OBJECT

public:
	FriendListWgt(QWidget *parent = Q_NULLPTR);
	~FriendListWgt();


signals:

private slots:
	//void nothing();
	void setStackWgtMsgList();
	void setStackWgtFriendList();
	void setStackWgtSpaceList();



private:
	Ui::FriendListWgt ui;

	void InitUI();
	void connectSlots();
	void setFriendListIcon();
};
