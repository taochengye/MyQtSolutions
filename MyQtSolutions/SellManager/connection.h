#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql\qsqldatabase.h>
#include <QtSql\qsqlquery.h>
#include <QDebug>
#include "qdom.h"
#include <QtXML>


static bool createConnection()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

	//db.setHostName("192.168.1.12");
	db.setDatabaseName("test.db");
	//db.setUserName("root");
	//db.setPassword("12345");
	if (!db.open()) {
		//��ʾ����
		return false;
	}

	QSqlQuery query;
	bool ret;
	//�������ұ�
	ret = query.exec("create table if not exists factory(id varchar primary key, name varchar)");
	ret = query.exec(QString::fromLocal8Bit("insert into factory values('0', '��ѡ�񳧼�')"));
	ret = query.exec(QString::fromLocal8Bit("insert into factory values('01', 'һ������')"));
	ret = query.exec(QString::fromLocal8Bit("insert into factory values('03', '��������')"));
	ret = query.exec(QString::fromLocal8Bit("insert into factory values('02', '�Ϻ�����')"));

	//����Ʒ�Ʊ�
	ret = query.exec("create table brand(id varchar primary key, name varchar, factory varchar, price int, sum int, sell int, last int)");
	ret = query.exec(QString::fromLocal8Bit("insert into brand values('01', '�µ�A6', 'һ������', 36, 50, 10, 40)"));
	ret = query.exec(QString::fromLocal8Bit("insert into brand values('02', '�ݴ�', 'һ������', 34, 20, 5, 15)"));
	ret = query.exec(QString::fromLocal8Bit("insert into brand values('03', '����', 'һ������', 41,  80, 20, 60)"));
	ret = query.exec(QString::fromLocal8Bit("insert into brand values('04', '����', 'һ������', 83, 40, 15, 25)"));
	ret = query.exec(QString::fromLocal8Bit("insert into brand values('05', '�ϼ���', '��������', 39, 50, 15, 35)"));
	ret = query.exec(QString::fromLocal8Bit("insert into brand values('06', '����', '��������', 28, 60, 10, 50)"));
	ret = query.exec(QString::fromLocal8Bit("insert into brand values('07', '����307', '��������', 27, 70, 20, 50)"));
	ret = query.exec(QString::fromLocal8Bit("insert into brand values('08', 'ɣ����', '�Ϻ�����', 25, 75, 25, 50)"));
	ret = query.exec(QString::fromLocal8Bit("insert into brand values('09', '������', '�Ϻ�����', 27, 65, 20, 45)"));

	return true;
}



static bool createXml()
{
	QFile file("data.xml");
	if (file.exists())
		return true;
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
		return false;

	QDomDocument doc;
	QDomProcessingInstruction instruction;
	instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	QDomElement root = doc.createElement(QString::fromLocal8Bit("�������嵥"));
	doc.appendChild(root);
	QTextStream out(&file);
	doc.save(out, 4);
	file.close();
	return true;
}


#endif