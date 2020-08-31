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
	ui.friendListTreeWgt->header()->hide();
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
	int iCount = ui.friendListTreeWgt->topLevelItemCount();
	for (int i = 0; i < iCount; i++)
	{
		auto treeItem = ui.friendListTreeWgt->topLevelItem(i);
		treeItem->setIcon(1, QPixmap(":/images/Ö÷´°¿ÚÍ¼±ê/arrow_r.png"));
	}

//	ui.treeWidget->setStyleSheet("QTreeView::branch:has-children:!has-siblings:closed,\
//QTreeView::branch:closed:has-children:has-siblings{border-image: none; image: url(:/QtXmlTest/Resources/image/plus.png);}\
//QTreeView::branch:open:has-children:!has-siblings,\
//QTreeView::branch:open:has-children:has-siblings{border-image: none; image: url(:/QtXmlTest/Resources/image/minus.png);}");

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
