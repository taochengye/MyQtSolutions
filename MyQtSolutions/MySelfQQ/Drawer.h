#pragma once

#include <QToolBox>
#include <QToolButton>

class Drawer : public QToolBox
{
	Q_OBJECT

public:
	Drawer(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = 0);
	~Drawer();

	void InitUI();

private:
	QToolButton *toolBtn1;
	QToolButton *toolBtn2;
	QToolButton *toolBtn3;
	QToolButton *toolBtn4;
	QToolButton *toolBtn5;
	QToolButton *toolBtn6;
	QToolButton *toolBtn7;
	QToolButton *toolBtn8;
	QToolButton *toolBtn9;

};
