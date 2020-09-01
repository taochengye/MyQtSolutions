#include "QPopupWgt.h"
#include <QPainter>

QPopupWgt::QPopupWgt(QWidget *parent)
	: QWidget(parent)
{
	setMouseTracking(true);
	
	bool ret = connect(this, SIGNAL(QHoverEvent::GraphicsSceneHoverEnter), this, SLOT(changecolor()));
}

QPopupWgt::~QPopupWgt()
{

}


void QPopupWgt::changecolor()
{
	int i = 0;
}


void QPopupWgt::mouseMoveEvent(QMouseEvent * event)
{
	auto pos = event->globalPos();
	//QRect rec = geometry();
	//QRect rect(rec.x() + 1, rec.y() + 1, rec.width() - 2, rec.height() - 2);

	//if (geometry().contains(this->mapFromGlobal(pos)))
	////if (rect.contains(this->mapFromGlobal(pos)))
	//{
	//	//this->setStyleSheet("background-color:red");

	//	QPalette pal(this->palette());
	//	pal.setColor(QPalette::Background, Qt::blue);
	//	this->setAutoFillBackground(true);
	//	this->setPalette(pal);

	//	//this->setBackgroundRole
	//	isMouseInWgt = true;
	//}
	//else
	//{
	//	QPalette pal(this->palette());
	//	pal.setColor(QPalette::Background, Qt::red);
	//	this->setAutoFillBackground(true);
	//	this->setPalette(pal);

	//	isMouseInWgt = false;
	//}

}

void QPopupWgt::mousePressEvent(QMouseEvent * event)
{
	int i = 0;
}



void QPopupWgt::contextMenuEvent(QContextMenuEvent * event)
{
	auto pos = event->globalPos();
	if (geometry().contains(this->mapFromGlobal(pos)))
	{
		this->setStyleSheet("background-color:red");
		isMouseInWgt = true;
	}
	else
		isMouseInWgt = false;
}


void QPopupWgt::paintEvent(QPaintEvent * event)
{
	QPainter p(this);

	//p.setPen(Qt::NoPen);
	//p.setBrush(QBrush(Qt::red));
	//p.drawRect(rect());

	if (isMouseInWgt == true)
	{
		//p.setPen(Qt::NoPen);
		//QColor color(222, 222, 222, 222);
		////color.setAlpha(0.9);
		//p.setBrush(QBrush(color));
		////p.setBrush(QBrush(Qt::blue));
		//p.drawRect(rect());
	}
	else
	{
		//p.setPen(Qt::NoPen);
		//QColor color(255, 255, 255, 255);
		////color.setAlpha(0.9);
		//p.setBrush(QBrush(color));
		//p.drawRect(rect());
	}
	

	QPixmap qmap(":/LoginWgt/images/mainwindow/arrow_r.png");
	p.drawPixmap(QRect(5, (this->height() / 2) - (qmap.height() / 2), qmap.width(), qmap.height()), qmap);


	QFont qfont("ËÎÌו", fontSize, QFont::Bold);
	p.setFont(qfont);
	p.setPen(Qt::black);
	
	
	QString departName = listName + " " + QString::number(onlineCount) + "/" + QString::number(totalCount);
	p.drawText(18, height() /2 + fontSize/2, departName);
	//p.drawText(width() / 2 + 50, height() / 2, "retwter");


}
