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

	//setAttribute(Qt::WA_DeleteOnClose);

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
	//on_quitBtn_clicked();
}


void Widget::processPendingDatagrams()
{
	while (udpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(udpSocket->pendingDatagramSize());
		udpSocket->readDatagram(datagram.data(), datagram.size());
		QDataStream in(&datagram, QIODevice::ReadOnly);
		int msgType;
		in >> msgType;
		QString usrName, ipAddr, msg;
		QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

		switch (msgType)
		{
		case Msg:
			in >> usrName >> ipAddr >> msg;
			ui.msgBrowser->setTextColor(Qt::blue);
			ui.msgBrowser->setCurrentFont(QFont("Times New Roman", 12));
			ui.msgBrowser->append("[ " + usrName + " ] " + time);
			ui.msgBrowser->append(msg);
			break;

		case UsrEnter:
			in >> usrName >> ipAddr;
			usrEnter(usrName, ipAddr);
			break;

		case UsrLeft:
			in >> usrName;
			usrLeft(usrName, time);

			break;

		case FileName:
			break;

		case Refuse:
			break;
		}
	}
}


void Widget::usrEnter(QString usrname, QString ipaddr)
{
	bool isEmpty = ui.usrTblWidget->findItems(usrname, Qt::MatchExactly).isEmpty();
	if (isEmpty)
	{
		QTableWidgetItem *usr = new QTableWidgetItem(usrname);
		QTableWidgetItem *ip = new QTableWidgetItem(ipaddr);

		ui.usrTblWidget->insertRow(0);
		ui.usrTblWidget->setItem(0, 0, usr);
		ui.usrTblWidget->setItem(0, 1, ip);
		ui.msgBrowser->setTextColor(Qt::gray);
		ui.msgBrowser->setCurrentFont(QFont("Times New Roman", 10));
		ui.msgBrowser->append(QString::fromLocal8Bit("%1 在线！").arg(usrname));
		ui.usrNumLbl->setText(QString::fromLocal8Bit("在线人数：%1").arg(ui.usrTblWidget->rowCount()));

		sndMsg(UsrEnter);
	}

}


void Widget::usrLeft(QString usrname, QString time)
{
	int rowNum = ui.usrTblWidget->findItems(usrname, Qt::MatchExactly).first()->row();
	ui.usrTblWidget->removeRow(rowNum);
	ui.msgBrowser->setTextColor(Qt::gray);
	ui.msgBrowser->setCurrentFont(QFont("Times New Roman", 10));
	ui.msgBrowser->append(QString::fromLocal8Bit("%1 于 %2 离开").arg(usrname).arg(time));
	ui.usrNumLbl->setText(QString::fromLocal8Bit("在线人数：%1").arg(ui.usrTblWidget->rowCount()));

}


void Widget::sndMsg(MsgType type, QString srvaddr)
{
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);
	QString address = getIP();
	out << type << getUsr();

	switch (type)
	{
	case Msg:
		if (ui.msgTextEdit->toPlainText() == "")
		{
			QMessageBox::warning(this, QString::fromLocal8Bit("警告"),
				QString::fromLocal8Bit("发送内容不能为空!"), QMessageBox::Ok);
			return;
		}
		out << address << getMsg();
		ui.msgBrowser->verticalScrollBar()->setValue(ui.msgBrowser->verticalScrollBar()->maximum());
		break;

	case UsrEnter:
		out << address;
		break;
		
	case UsrLeft:
		break;

	case FileName:
		break;

	case Refuse:
		break;

	}

	udpSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, port);
}

QString Widget::getIP()
{
	QList<QHostAddress> list = QNetworkInterface::allAddresses();
	foreach(QHostAddress addr, list)
	{
		if (addr.protocol() == QAbstractSocket::IPv4Protocol)
			return addr.toString();
	}
	return 0;
}

QString Widget::getUsr()
{
	return uName;
}

QString Widget::getMsg()
{
	QString msg = ui.msgTextEdit->toHtml();

	ui.msgTextEdit->clear();
	ui.msgTextEdit->setFocus();
	return msg;
}

void Widget::on_sendBtn_clicked()
{
	sndMsg(Msg);
}

void Widget::on_exitBtn_clicked()
{
	sndMsg(UsrLeft);
	close();
}
