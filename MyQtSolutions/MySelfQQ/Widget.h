#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"
//#include <QUdpSocket>
#include <QtNetwork/qudpsocket.h>
//#include <qsocketnotifier.h>



enum MsgType {
	Msg,
	UsrEnter,
	UsrLeft,
	FileName,
	Refuse
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(int , QString, QWidget *parent = Q_NULLPTR);
	~Widget();

	void InitUI();
	void connectSlots();

signals:
	void closeWindow(QString windowFlag);

private slots:
	void processPendingDatagrams();
	void on_sendBtn_clicked();
	void on_exitBtn_clicked();

protected:
	void closeEvent(QCloseEvent* event);
	void usrEnter(QString usrname, QString ipaddr);		//处理新用户加入
	void usrLeft(QString usrname, QString time);		//处理用户离开
	void sndMsg(MsgType type, QString srvaddr = "");	//广播UDP消息

	QString getIP();			//获取IP地址
	QString getUsr();			//获取用户名
	QString getMsg();			//获取聊天信息

private:
    Ui::WidgetClass ui;

	QUdpSocket *udpSocket;
	qint16 port;
	QString uName;


};
