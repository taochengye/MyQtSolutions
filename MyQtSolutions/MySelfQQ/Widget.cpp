#include "Widget.h"
#include <QtNetwork/qhostinfo.h>
#include <qmessagebox.h>
#include <QScrollBar>
#include <QDateTime>
#include <QtNetwork/QNetWorkInterface>
#include <QProcess>


Widget::Widget(int i, QString qstr, QWidget *parent)
    :uName(qstr), QWidget(parent)
{
    ui.setupUi(this);

	setAttribute(Qt::WA_DeleteOnClose);

	InitUI();
	connectSlots();
}

Widget::~Widget()
{
	//emit closeWindow(windowTitle);
}


void Widget::InitUI()
{
	//uName = usrname
	udpSocket = new QUdpSocket(this);
	port = 23232;
	udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
	sndMsg(UsrEnter);

}

void Widget::connectSlots()
{
	connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}


void Widget::closeEvent(QCloseEvent * event)
{
	Q_UNUSED(event);
	emit closeWindow(uName);
}


void Widget::processPendingDatagrams()
{

}


void Widget::usrEnter(QString usrname, QString ipaddr)
{
}

void Widget::usrLeft(QString usrname, QString time)
{
}

void Widget::sndMsg(MsgType type, QString srvaddr)
{


}

QString Widget::getIP()
{
	return QString();
}

QString Widget::getUsr()
{
	return QString();
}

QString Widget::getMsg()
{
	return QString();
}


