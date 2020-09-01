#include "FriendListWgt.h"

FriendListWgt::FriendListWgt(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	InitUI();
	connectSlots();
}

FriendListWgt::~FriendListWgt()
{
}


void FriendListWgt::InitUI()
{

	QPushButton test;
	ui.pushButton_11->setIconSize(ui.pushButton_11->size());
	ui.pushButton_11->setIcon(QIcon(":/LoginWgt/images/mainwindow/arrow_r.png"));

	//ui.searchLineEdit->setIcon(QIcon(":/images/Ö÷´°¿ÚÍ¼±ê/arrow_r.png"));

	setFriendListIcon();
}


void FriendListWgt::connectSlots()
{
	bool ret = connect(ui.msgListBtn, SIGNAL(clicked()), this, SLOT(setStackWgtMsgList()));
	ret = connect(ui.friendListBtn, SIGNAL(clicked()), this, SLOT(setStackWgtFriendList()));
	ret = connect(ui.spaceListBtn, SIGNAL(clicked()), this, SLOT(setStackWgtSpaceList()));
}


void FriendListWgt::setFriendListIcon()
{


//	ui.friendListTreeWgt->setStyleSheet("QTreeView::branch:has-children:!has-siblings:closed,\
//QTreeView::branch:closed:has-children:has-siblings{border-image: none; image: url(:/LoginWgt/images/mainwindow/arrow_r.png);}\
//QTreeView::branch:open:has-children:!has-siblings,\
//QTreeView::branch:open:has-children:has-siblings{border-image: none; image: url(:/LoginWgt/images/mainwindow/arrow_d.png);}");

}

void FriendListWgt::setStackWgtMsgList()
{
	ui.mainStackedWgt->setCurrentIndex(0);
}

void FriendListWgt::setStackWgtFriendList()
{
	ui.mainStackedWgt->setCurrentIndex(1);
}

void FriendListWgt::setStackWgtSpaceList()
{
	ui.mainStackedWgt->setCurrentIndex(2);
}
