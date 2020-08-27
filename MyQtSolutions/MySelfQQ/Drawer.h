#pragma once

#include <QToolBox>
#include <QToolButton>
#include "Widget.h"
#include <map>

using namespace std;


class Drawer : public QToolBox
{
	Q_OBJECT

public:
	Drawer(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = 0);
	~Drawer();

	void InitUI();
	void connectSlots();

signals:
	void ShowChatWidgetSignal(QString, const QIcon&);

private slots:
	void showChatWidget();

	void showChatWidget1();
	void showChatWidget2();
	void showChatWidget3();

	void deleteWgtPtr(QString windowFlag);

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


	map<QString, Widget*> widgetMap;

	Widget* chatWidget1 = nullptr;
	Widget* chatWidget2 = nullptr;
	Widget* chatWidget3 = nullptr;

};
