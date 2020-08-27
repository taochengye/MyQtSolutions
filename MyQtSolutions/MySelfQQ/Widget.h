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
	void usrEnter(QString usrname, QString ipaddr);		//�������û�����
	void usrLeft(QString usrname, QString time);		//�����û��뿪
	void sndMsg(MsgType type, QString srvaddr = "");	//�㲥UDP��Ϣ

	QString getIP();			//��ȡIP��ַ
	QString getUsr();			//��ȡ�û���
	QString getMsg();			//��ȡ������Ϣ

private:
    Ui::WidgetClass ui;

	QUdpSocket *udpSocket;
	qint16 port;
	QString uName;


};
