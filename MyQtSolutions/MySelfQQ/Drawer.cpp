#include "Drawer.h"
#include <qgroupbox.h>
#include <QVBoxLayout>



Drawer::Drawer(QWidget *parent, Qt::WindowFlags f)
	: QToolBox(parent)
{

	InitUI();

}

Drawer::~Drawer()
{
}

void Drawer::InitUI()
{
	setWindowTitle(QString::fromLocal8Bit("Myself QQ 2020"));		//	设置主窗体标题
	setWindowIcon(QPixmap(":/images/qq.png"));		//	设置主窗体标题栏图标

	toolBtn1 = new QToolButton;
	toolBtn1->setText(QString::fromLocal8Bit("大牛"));
	toolBtn1->setIcon(QPixmap(":/images/1.png"));
	toolBtn1->setIconSize(QPixmap(":/images/1.png").size());
	toolBtn1->setAutoRaise(true);
	toolBtn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn2 = new QToolButton;
	toolBtn2->setText(QString::fromLocal8Bit("大神"));
	toolBtn2->setIcon(QPixmap(":/images/2.png"));
	toolBtn2->setIconSize(QPixmap(":/images/2.png").size());
	toolBtn2->setAutoRaise(true);
	toolBtn2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn3 = new QToolButton;
	toolBtn3->setText(QString::fromLocal8Bit("大师"));
	toolBtn3->setIcon(QPixmap(":/images/3.png"));
	toolBtn3->setIconSize(QPixmap(":/images/3.png").size());
	toolBtn3->setAutoRaise(true);
	toolBtn3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn4 = new QToolButton;
	toolBtn4->setText(QString::fromLocal8Bit("大佬"));
	toolBtn4->setIcon(QPixmap(":/images/4.png"));
	toolBtn4->setIconSize(QPixmap(":/images/4.png").size());
	toolBtn4->setAutoRaise(true);
	toolBtn4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn5 = new QToolButton;
	toolBtn5->setText(QString::fromLocal8Bit("卡卡罗特"));
	toolBtn5->setIcon(QPixmap(":/images/5.png"));
	toolBtn5->setIconSize(QPixmap(":/images/5.png").size());
	toolBtn5->setAutoRaise(true);
	toolBtn5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn6 = new QToolButton;
	toolBtn6->setText(QString::fromLocal8Bit("路飞"));
	toolBtn6->setIcon(QPixmap(":/images/6.png"));
	toolBtn6->setIconSize(QPixmap(":/images/6.png").size());
	toolBtn6->setAutoRaise(true);
	toolBtn6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn7 = new QToolButton;
	toolBtn7->setText(QString::fromLocal8Bit("旋涡鸣人"));
	toolBtn7->setIcon(QPixmap(":/images/7.png"));
	toolBtn7->setIconSize(QPixmap(":/images/7.png").size());
	toolBtn7->setAutoRaise(true);
	toolBtn7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn8 = new QToolButton;
	toolBtn8->setText(QString::fromLocal8Bit("多弗朗明哥"));
	toolBtn8->setIcon(QPixmap(":/images/8.png"));
	toolBtn8->setIconSize(QPixmap(":/images/8.png").size());
	toolBtn8->setAutoRaise(true);
	toolBtn8->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

	toolBtn9 = new QToolButton;
	toolBtn9->setText(QString::fromLocal8Bit("黑神话悟空"));
	toolBtn9->setIcon(QPixmap(":/images/9.png"));
	toolBtn9->setIconSize(QPixmap(":/images/9.png").size());
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


