#include "Widget.h"
#include <QTableView>
#include "PieView.h"


Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);



	InitUI();

	createMenuBar();	//	生成菜单栏

	connectSlots();
}

Widget::~Widget()
{
	if(factoryModel != nullptr)
		delete(factoryModel);
}



void Widget::InitUI()
{
	this->setFixedSize(750, 500);
	ui.stackedWidget->setCurrentIndex(0);

	//QSqlQueryModel* factoryModel = new QSqlQueryModel(this);
	factoryModel = new QSqlQueryModel(this);
	factoryModel->setQuery("select name from factory");
	ui.sellFactoryComboBox->setModel(factoryModel);

	QSplitter *splitter = new QSplitter(ui.managePage);
	splitter->resize(700, 360);
	splitter->move(0, 50);
	splitter->addWidget(ui.toolBox);
	splitter->addWidget(ui.dailyList);
	splitter->setStretchFactor(0, 1);
	splitter->setStretchFactor(1, 1);

	showDailyList();

	//on_sellCancelBtn_clicked();
}

void Widget::createMenuBar()
{
	manageAction = new QAction(QString::fromLocal8Bit("品牌车管理"), this);
	chartAction = new QAction(QString::fromLocal8Bit("销售统计"), this);
	quitAction = new QAction(QString::fromLocal8Bit("退出"), this);

	manageAction->setShortcut(tr("Ctrl+M"));
	chartAction->setShortcut(tr("Ctrl+C"));
	quitAction->setShortcut(tr("Ctrl+Q"));

	manageMenu = menuBar()->addMenu(QString::fromLocal8Bit("销售管理"));
	manageMenu->addAction(manageAction);
	manageMenu->addAction(chartAction);
	manageMenu->addSeparator();
	manageMenu->addAction(quitAction);

	passwordMenu = menuBar()->addMenu(QString::fromLocal8Bit("修改密码"));
	
}


void Widget::connectSlots()
{
	connect(manageAction, SIGNAL(triggered()), this, SLOT(on_manageMenu_clicked()));
	connect(chartAction, SIGNAL(triggered()), this, SLOT(on_chartMenu_clicked()));
	connect(quitAction, SIGNAL(triggered()), this, SLOT(on_quitMenu_clicked()));
}

//读取xml文档
bool Widget::docRead()
{
	QFile file("data.xml");
	if (!file.open(QIODevice::ReadOnly))
		return false;
	if (!doc.setContent(&file))
	{
		file.close();
		return false;
	}

	file.close();
	return true;
}

//写入 xml 文档
bool Widget::docWrite()
{
	QFile file("data.xml");
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
		return false;
	QTextStream out(&file);
	doc.save(out, 4);
	file.close();
	return true;
}

void Widget::writeXml()
{
	//首先从文件读取
	if (docRead()) {
		QString currentDate = getDateTime(Date);
		QDomElement root = doc.documentElement();
		//根据是否有日期节点进行处理
		if (!root.hasChildNodes())
		{
			QDomElement date = doc.createElement(QString::fromLocal8Bit("日期"));
			QDomAttr curDate = doc.createAttribute("date");
			curDate.setValue(currentDate);
			date.setAttributeNode(curDate);
			root.appendChild(date);
			createNodes(date);
		}
		else {
			QDomElement date = root.lastChild().toElement();
			//根据是否已经有今天的日期节点进行处理
			if (date.attribute("date") == currentDate) {
				createNodes(date);
			}
			else
			{
				QDomElement date = doc.createElement(QString::fromLocal8Bit("日期"));
				QDomAttr curDate = doc.createAttribute("date");
				curDate.setValue(currentDate);
				date.setAttributeNode(curDate);
				root.appendChild(date);
				createNodes(date);
			}
		}
		//写入文件
		docWrite();
	}

}

//创建节点
void Widget::createNodes(QDomElement & date)
{
	QDomElement time = doc.createElement(QString::fromLocal8Bit("时间"));
	QDomAttr curTime = doc.createAttribute("time");
	curTime.setValue(getDateTime(Time));
	time.setAttributeNode(curTime);
	date.appendChild(time);
	QDomElement factory = doc.createElement(QString::fromLocal8Bit("厂家"));
	QDomElement brand = doc.createElement(QString::fromLocal8Bit("品牌"));
	QDomElement price = doc.createElement(QString::fromLocal8Bit("报价"));
	QDomElement num = doc.createElement(QString::fromLocal8Bit("数量"));
	QDomElement sum = doc.createElement(QString::fromLocal8Bit("金额"));

	QDomText text;
	text = doc.createTextNode(QString("%1").arg(ui.sellFactoryComboBox->currentText()));
	factory.appendChild(text);
	text = doc.createTextNode(QString("%1").arg(ui.sellBrandComboBox->currentText()));
	brand.appendChild(text);
	text = doc.createTextNode(QString("%1").arg(ui.sellPriceLineEdit->text()));
	price.appendChild(text);
	text = doc.createTextNode(QString("%1").arg(ui.sellNumSpinBox->value()));
	num.appendChild(text);
	text = doc.createTextNode(QString("%1").arg(ui.sellSumLineEdit->text()));
	sum.appendChild(text);
	time.appendChild(factory);
	time.appendChild(brand);
	time.appendChild(price);
	time.appendChild(num);
	time.appendChild(sum);

}

void Widget::showDailyList()
{
	ui.dailyList->clear();
	if (docRead()) {
		QDomElement root = doc.documentElement();
		QString title = root.tagName();
		QListWidgetItem * titleItem = new QListWidgetItem;
		titleItem->setText(QString("-----%1-----").arg(title));
		titleItem->setTextAlignment(Qt::AlignCenter);
		ui.dailyList->addItem(titleItem);
		if (root.hasChildNodes())
		{
			QString currentDate = getDateTime(Date);
			QDomElement dateElement = root.lastChild().toElement();
			QString date = dateElement.attribute("date");
			if (date == currentDate) {
				ui.dailyList->addItem("");
				ui.dailyList->addItem(QString::fromLocal8Bit("日期:%1").arg(date));
				ui.dailyList->addItem("");
				QDomNodeList children = dateElement.childNodes();
				//遍历当日销售的所有汽车
				for (int i = 0; i < children.count(); i++)
				{
					QDomNode node = children.at(i);
					QString time = node.toElement().attribute("time");
					QDomNodeList list = node.childNodes();
					QString factory = list.at(0).toElement().text();
					QString brand = list.at(1).toElement().text();
					QString price = list.at(2).toElement().text();
					QString num = list.at(3).toElement().text();
					QString sum = list.at(4).toElement().text();
					QString str = time + QString::fromLocal8Bit("出售") + brand + factory + " " + num + QString::fromLocal8Bit("辆，")
						+ QString::fromLocal8Bit("成交价：") + price + QString::fromLocal8Bit("万， 共") + sum + QString::fromLocal8Bit("万元");
					QListWidgetItem *tempItem = new QListWidgetItem;
					tempItem->setText("**********************");
					tempItem->setTextAlignment(Qt::AlignCenter);
					ui.dailyList->addItem(tempItem);
					ui.dailyList->addItem(str);
				}
			}
		}
	}
}

void Widget::createChartModelView()
{
	chartModel = new QStandardItemModel(this);
	chartModel->setColumnCount(2);
	chartModel->setHeaderData(0, Qt::Horizontal, QString("品牌"));
	chartModel->setHeaderData(1, Qt::Horizontal, QString("销售数量"));

	QSplitter *splitter = new QSplitter(ui.chartPage);
	splitter->resize(700, 320);
	splitter->move(0, 80);
	QTableView *table = new QTableView;
	PieView *pieChart = new PieView;
	splitter->addWidget(table);
	splitter->addWidget(pieChart);
	splitter->setStretchFactor(0, 1);
	splitter->setStretchFactor(1, 2);

	table->setModel(chartModel);
	pieChart->setModel(chartModel);

	QItemSelectionModel *selectionModel = new QItemSelectionModel(chartModel);
	table->setSelectionModel(selectionModel);
	pieChart->setSelectionModel(selectionModel);

}

void Widget::showChart()
{
	QSqlQuery query;
	query.exec(QString("select name, sell from brand where factory='%1'").arg(ui.factoryComboBox->currentText()));
	chartModel->removeRows(0, chartModel->rowCount(QModelIndex()), QModelIndex());
	int row = 0;

	while (query.next())
	{
		int r = qrand() % 256;
		int g = qrand() % 256;
		int b = qrand() % 256;

		chartModel->insertRows(row, 1, QModelIndex());
		chartModel->setData(chartModel->index(row, 0, QModelIndex()), query.value(0).toString());
		chartModel->setData(chartModel->index(row, 1, QModelIndex()), query.value(1).toInt());

		chartModel->setData(chartModel->index(row, 0, QModelIndex()), QColor(r, g, b), Qt::DecorationRole);
		row++;
	}

}



// ************************************************ SLOTS ********************************************
void Widget::on_manageMenu_clicked()
{
	ui.stackedWidget->setCurrentIndex(0);
}

QString Widget::getDateTime(DateTimeType type)
{
	QDateTime datetime = QDateTime::currentDateTime();
	QString date = datetime.toString("yyyy-MM-dd");
	QString time = datetime.toString("hh:mm");
	QString dateAndTime = datetime.toString("yyyy-MM-dd dddd hh:mm");
	if (type == Date)
		return date;
	else if (type == Time)
		return time;
	else
		return dateAndTime;

}

void Widget::on_chartMenu_clicked()
{
	ui.stackedWidget->setCurrentIndex(1);
}

void Widget::on_quitMenu_clicked()
{
	this->close();
}

void Widget::on_sellFactoryComboBox_currentIndexChanged(const QString & arg1)
{
	if (arg1 == QString::fromLocal8Bit("请选择厂家"))
	{
		//进行其他部件的状态设置
		on_sellCancelBtn_clicked();

	}
	else
	{
		ui.sellBrandComboBox->setEnabled(true);
		//QSqlQueryModel *model = new QSqlQueryModel(this);
		model = new QSqlQueryModel(this);
		model->setQuery(QString::fromLocal8Bit("select name from brand where factory = '%1'").arg(arg1));
		ui.sellBrandComboBox->setModel(model);
		ui.sellCancelBtn->setEnabled(true);
	}
}


void Widget::on_sellBrandComboBox_currentIndexChanged(const QString & arg1)
{
	ui.sellNumSpinBox->setValue(0);
	ui.sellNumSpinBox->setEnabled(false);
	ui.sellSumLineEdit->clear();
	ui.sellSumLineEdit->setEnabled(false);
	ui.sellOkBtn->setEnabled(false);

	if (arg1.size() == 0)
	{
		return;
	}


	QSqlQuery query;
	query.exec(QString("select price from brand where name = '%1' and factory= '%2'").arg(arg1).arg(ui.sellFactoryComboBox->currentText()));
	query.next();
	ui.sellPriceLineEdit->setEnabled(true);
	ui.sellPriceLineEdit->setReadOnly(true);
	ui.sellPriceLineEdit->setText(query.value(0).toString());

	query.exec(QString("select last from brand where name='%1' and factory= '%2'").arg(arg1).arg(ui.sellFactoryComboBox->currentText()));
	query.next();
	int num = query.value(0).toInt();
	if (num == 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("该品牌汽车已经售完!"), QMessageBox::Ok);
	}
	else
	{
		ui.sellNumSpinBox->setEnabled(true);
		ui.sellNumSpinBox->setMaximum(num);
		ui.sellLastNumLabel->setText(QString::fromLocal8Bit("剩余数量: %1").arg(num));
		ui.sellLastNumLabel->setVisible(true);
	}
}


void Widget::on_sellNumSpinBox_valueChanged(int arg1)
{
	if (arg1 == 0) {
		ui.sellSumLineEdit->clear();
		ui.sellSumLineEdit->setEnabled(false);
		ui.sellOkBtn->setEnabled(false);
	}
	else
	{
		ui.sellSumLineEdit->setEnabled(true);
		ui.sellSumLineEdit->setReadOnly(true);
		qreal sum = arg1 * ui.sellPriceLineEdit->text().toInt();
		ui.sellSumLineEdit->setText(QString::number(sum));
		ui.sellOkBtn->setEnabled(true);
	}
}


void Widget::on_sellOkBtn_clicked()
{
	QString factory = ui.sellFactoryComboBox->currentText();
	QString name = ui.sellBrandComboBox->currentText();
	int value = ui.sellNumSpinBox->value();
	//sellNumSpinBox的最大值就是以前的剩余量
	int last = ui.sellNumSpinBox->maximum() - value;

	QSqlQuery query;
	//获取以前的销售量
	query.exec(QString("select sell from brand where name='%1' and factory = '%2'").arg(name).arg(factory));
	query.next();
	int sell = query.value(0).toInt() + value;

	//事务操作
	QSqlDatabase::database().transaction();
	bool rtn = query.exec(QString("update brand set sell = %1, last = %2 where name = '%3' and factory = '%4'").arg(sell).arg(last).arg(name).arg(factory));
	if (rtn) {
		QSqlDatabase::database().commit();
		QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("购 车 成 功！"), QMessageBox::Ok);
		writeXml();
		showDailyList();
		on_sellCancelBtn_clicked();
	}
	else
	{
		QSqlDatabase::database().rollback();
	}


}


void Widget::on_sellCancelBtn_clicked()
{
	ui.sellFactoryComboBox->setCurrentIndex(0);

	//for (int i = 0; i < ui.sellBrandComboBox->count(); i++)
	//{
	//	ui.sellBrandComboBox->removeItem(i);
	//}

	ui.sellBrandComboBox->clear();
	
	//QSqlQueryModel *mode = new QSqlQueryModel(this);

	if (model != nullptr)
	{
		model->clear();
		model = nullptr;

		ui.sellPriceLineEdit->clear();
		ui.sellLastNumLabel->setText(QString::fromLocal8Bit("剩余数量: %1").arg(0));
		ui.sellNumSpinBox->setEnabled(false);


	}


}

void Widget::on_factoryComboBox_currentIndexChanged(const QString & arg1)
{
	if (arg1 != QString::fromLocal8Bit("请选择厂家"))
		showChart();
}

void Widget::on_updateBtn_clicked()
{
	if (ui.factoryComboBox->currentText() != QString::fromLocal8Bit("请选择厂家"))
		showChart();
}
