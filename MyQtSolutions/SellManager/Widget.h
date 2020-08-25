#pragma once


#include <QMainWindow>
#include "ui_Widget.h"
#include <QMenuBar>
#include <QMessageBox>
#include <QSplitter>
#include <QtSql\qsqlquerymodel.h>
#include <QDateTime>
#include "connection.h"
#include <QStandardItemModel>

enum DateTimeType {
	Time,
	Date,
	DateTime
};

//class QStandardItemModel;

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = Q_NULLPTR);
	~Widget();

	QMenu *manageMenu;		//	�����۹������˵�
	QMenu *passwordMenu;		//	"�޸�����"���˵�

	//����Action����
	QAction *manageAction;
	QAction *chartAction;
	QAction *quitAction;

	QString getDateTime(DateTimeType type);

private slots:
	void on_manageMenu_clicked();		//	ʵ�֡�Ʒ�Ƴ������Ӳ˵����ܺ���
	void on_chartMenu_clicked();		//	ʵ�֡�����ͳ�ơ��Ӳ˵����ܺ���
	void on_quitMenu_clicked();			//	ʵ�֡��˳��Ӳ˵����ܺ���
	void on_sellFactoryComboBox_currentIndexChanged(const QString &arg1);
	void on_sellBrandComboBox_currentIndexChanged(const QString &arg1);
	void on_sellNumSpinBox_valueChanged(int arg1);

	void on_sellOkBtn_clicked();
	void on_sellCancelBtn_clicked();

	void on_factoryComboBox_currentIndexChanged(const QString &arg1);
	void on_updateBtn_clicked();

private:
    Ui::WidgetClass ui;

	QDomDocument doc;

	void InitUI();
	void createMenuBar();

	void connectSlots();

	bool docRead();
	bool docWrite();
	void writeXml();
	void createNodes(QDomElement &date);
	void showDailyList();

	void createChartModelView();
	void showChart();

	QSqlQueryModel *factoryModel = nullptr;
	QSqlQueryModel *model = nullptr;
	QStandardItemModel *chartModel;
};
