#pragma once

#include <QWidget>
#include <QMouseEvent>

class QPopupWgt : public QWidget
{
	Q_OBJECT

public:
	QPopupWgt(QWidget *parent = nullptr);
	~QPopupWgt();

public:

	QString listName = QString::fromLocal8Bit("那美克星人");
	unsigned int fontSize = 10;
	int totalCount = 0;
	int onlineCount = 0;

protected:
	void mousePressEvent(QMouseEvent *event);
	void contextMenuEvent(QContextMenuEvent * event);
	void mouseMoveEvent(QMouseEvent * event);
	void paintEvent(QPaintEvent *event);

private:
	bool isMouseInWgt = false;

private slots:
	void changecolor();
};
