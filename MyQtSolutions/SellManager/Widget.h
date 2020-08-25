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

	QMenu *manageMenu;		//	“销售管理”主菜单
	QMenu *passwordMenu;		//	"修改密码"主菜单

	//动作Action定义
	QAction *manageAction;
	QAction *chartAction;
	QAction *quitAction;

	QString getDateTime(DateTimeType type);

private slots:
	void on_manageMenu_clicked();		//	实现“品牌车管理”子菜单功能函数
	void on_chartMenu_clicked();		//	实现“销售统计”子菜单功能函数
	void on_quitMenu_clicked();			//	实现“退出子菜单功能函数
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
