#include "Drawer.h"
#include <qgroupbox.h>
#include <QVBoxLayout>



Drawer::Drawer(QWidget *parent, Qt::WindowFlags f)
	: QToolBox(parent)
{

	InitUI();
	connectSlots();
}

Drawer::~Drawer()
{
}

void Drawer::InitUI()
{
	setWindowTitle(QString::fromLocal8Bit("Myself QQ 2020"));		//	设置主窗体标题
	setWindowIcon(QPixmap(":/images/qq.png"));		//	设置主窗体标题栏图标

	
	QSize head(75, 75);

	toolBtn1 = new QToolButton;
	toolBtn1->setText(QString::fromLocal8Bit("大牛"));
	toolBtn1->setIcon(QPixmap(":/Widget/images/headportrait/1.jpg"));
	//toolBtn1->setIconSize(QPixmap(":/Widget/images/headportrait/1.jpg").size());
	toolBtn1->setIconSize(head);
	toolBtn1->setAutoRaise(true);
	toolBtn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn2 = new QToolButton;
	toolBtn2->setText(QString::fromLocal8Bit("大神"));
	toolBtn2->setIcon(QPixmap(":/Widget/images/headportrait/2.jpg"));
	//toolBtn2->setIconSize(QPixmap(":/Widget/images/headportrait/2.jpg").size());
	toolBtn2->setIconSize(head);
	toolBtn2->setAutoRaise(true);
	toolBtn2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn3 = new QToolButton;
	toolBtn3->setText(QString::fromLocal8Bit("大师"));
	toolBtn3->setIcon(QPixmap(":/Widget/images/headportrait/3.jpg"));
	//toolBtn3->setIconSize(QPixmap(":/Widget/images/headportrait/3.jpg").size());
	toolBtn3->setIconSize(head);
	toolBtn3->setAutoRaise(true);
	toolBtn3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn4 = new QToolButton;
	toolBtn4->setText(QString::fromLocal8Bit("大佬"));
	toolBtn4->setIcon(QPixmap(":/Widget/images/headportrait/4.jpg"));
	//toolBtn4->setIconSize(QPixmap(":/Widget/images/headportrait/4.jpg").size());
	toolBtn4->setIconSize(head);
	toolBtn4->setAutoRaise(true);
	toolBtn4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn5 = new QToolButton;
	toolBtn5->setText(QString::fromLocal8Bit("卡卡罗特"));
	toolBtn5->setIcon(QPixmap(":/Widget/images/headportrait/5.jpg"));
	//toolBtn5->setIconSize(QPixmap(":/Widget/images/headportrait/5.jpg").size());
	toolBtn5->setIconSize(head);
	toolBtn5->setAutoRaise(true);
	toolBtn5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn6 = new QToolButton;
	toolBtn6->setText(QString::fromLocal8Bit("路飞"));
	toolBtn6->setIcon(QPixmap(":/Widget/images/headportrait/6.jpg"));
	//toolBtn6->setIconSize(QPixmap(":/Widget/images/headportrait/6.jpg").size());
	toolBtn6->setIconSize(head);
	toolBtn6->setAutoRaise(true);
	toolBtn6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn7 = new QToolButton;
	toolBtn7->setText(QString::fromLocal8Bit("旋涡鸣人"));
	toolBtn7->setIcon(QPixmap(":/Widget/images/headportrait/7.jpg"));
	//toolBtn7->setIconSize(QPixmap(":/Widget/images/headportrait/7.jpg").size());
	toolBtn7->setIconSize(head);
	toolBtn7->setAutoRaise(true);
	toolBtn7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn8 = new QToolButton;
	toolBtn8->setText(QString::fromLocal8Bit("多弗朗明哥"));
	toolBtn8->setIcon(QPixmap(":/Widget/images/headportrait/8.jpg"));
	//toolBtn8->setIconSize(QPixmap(":/Widget/images/headportrait/8.jpg").size());
	toolBtn8->setIconSize(head);
	toolBtn8->setAutoRaise(true);
	toolBtn8->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn9 = new QToolButton;
	toolBtn9->setText(QString::fromLocal8Bit("黑神话悟空"));
	toolBtn9->setIcon(QPixmap(":Widget/images/headportrait/9.png"));
	//toolBtn9->setIconSize(QPixmap(":Widget/images/headportrait/9.png").size());
	toolBtn9->setIconSize(head);
	toolBtn9->setAutoRaise(true);
	toolBtn9->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	QGroupBox *groupBox = new QGroupBox;
	QVBoxLayout *layout = new QVBoxLayout(groupBox);
	layout->setMargin(20);
	layout->setAlignment(Qt::AlignLeft);
	layout->addWidget(toolBtn1);
	layout->addWidget(toolBtn2);
	layout->addWidget(toolBtn3);
	layout->addWidget(toolBtn4);
	layout->addWidget(toolBtn5);
	layout->addWidget(toolBtn6);
	layout->addWidget(toolBtn7);
	layout->addWidget(toolBtn8);
	layout->addWidget(toolBtn9);
	layout->addStretch();		//	插入一个占位符

	this->addItem((QWidget*)groupBox, QString::fromLocal8Bit("群成员"));

}

void Drawer::connectSlots()
{
	//connect(toolBtn1, SIGNAL(clicked()), this, SLOT(showChatWidget1()));
	//connect(toolBtn2, SIGNAL(clicked()), this, SLOT(showChatWidget2()));
	//connect(toolBtn3, SIGNAL(clicked()), this, SLOT(showChatWidget3()));

	connect(toolBtn1, SIGNAL(clicked()), this, SLOT(showChatWidget()));
	connect(toolBtn2, SIGNAL(clicked()), this, SLOT(showChatWidget()));
	connect(toolBtn3, SIGNAL(clicked()), this, SLOT(showChatWidget()));
	connect(toolBtn4, SIGNAL(clicked()), this, SLOT(showChatWidget()));
	connect(toolBtn5, SIGNAL(clicked()), this, SLOT(showChatWidget()));
	connect(toolBtn6, SIGNAL(clicked()), this, SLOT(showChatWidget()));
	connect(toolBtn7, SIGNAL(clicked()), this, SLOT(showChatWidget()));
	connect(toolBtn8, SIGNAL(clicked()), this, SLOT(showChatWidget()));
	connect(toolBtn9, SIGNAL(clicked()), this, SLOT(showChatWidget()));
}



// ********************************************** SLOTS ********************************************

void Drawer::showChatWidget()
{
	QToolButton* qToolBtn = qobject_cast<QToolButton *>(sender());
	QString qstr = qToolBtn->text();



	if (widgetMap.count(qstr) == 0 || !widgetMap[qstr]->isWindow())
	{
		QIcon icon = qToolBtn->icon();
		Widget *chatWidget = new Widget(0, qstr);
		chatWidget->setWindowTitle(qstr);
		chatWidget->setWindowIcon(icon);

		widgetMap[qstr] = chatWidget;
		bool ret = connect(chatWidget, SIGNAL(closeWindow(QString)), this, SLOT(deleteWgtPtr(QString)));
	}

	if (widgetMap[qstr] != nullptr)
	{
		Widget *chatWidget = widgetMap[qstr];
		chatWidget->showNormal();
		//if (chatWidget->isHidden())
		//	chatWidget->show();
		//if (chatWidget->isMinimized())
		//{
		//	//chatWidget->hide();
		//	//chatWidget->show();
		//	chatWidget->showNormal();
		//}
	}

}



void Drawer::showChatWidget1()
{
	if (chatWidget1 != nullptr)
	{
		delete(chatWidget1);
		chatWidget1 = nullptr;
	}
	chatWidget1 = new Widget(0, toolBtn1->text());
	chatWidget1->setWindowTitle(toolBtn1->text());
	chatWidget1->setWindowIcon(toolBtn1->icon());
	chatWidget1->show();
}

void Drawer::showChatWidget2()
{
	if (chatWidget2 != nullptr)
	{
		delete(chatWidget2);
		chatWidget2 = nullptr;
	}
	chatWidget2 = new Widget(0, toolBtn2->text());
	chatWidget2->setWindowTitle(toolBtn2->text());
	chatWidget2->setWindowIcon(toolBtn2->icon());
	chatWidget2->show();
}

void Drawer::showChatWidget3()
{
	if (chatWidget3 != nullptr)
	{
		delete(chatWidget3);
		chatWidget3 = nullptr;
	}
	chatWidget3 = new Widget(0, toolBtn3->text());
	chatWidget3->setWindowTitle(toolBtn3->text());
	chatWidget3->setWindowIcon(toolBtn3->icon());
	chatWidget3->show();
}

void Drawer::deleteWgtPtr(QString windowFlag)
{
	if (widgetMap.count(windowFlag) > 0)
	{
		bool ret = disconnect(widgetMap[windowFlag], SIGNAL(closeWindow(QString)), this, SLOT(deleteWgtPtr(QString)));
		widgetMap.erase(windowFlag);
	}
}


