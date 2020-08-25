#include "LoginDialog.h"
#include <QMessageBox>
#include "connection.h"

LoginDialog::LoginDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	InitUI();
	connectSlots();
}

LoginDialog::~LoginDialog()
{
}

void LoginDialog::InitUI()
{
	setFixedSize(400, 300);
	setWindowTitle(QString::fromLocal8Bit("µÇÂ¼"));
	ui.pwdLineEdit->setFocus();
	ui.loginBtn->setDefault(true);
}

void LoginDialog::connectSlots()
{

}


void LoginDialog::on_loginBtn_clicked()
{
	if (ui.pwdLineEdit->text().isEmpty())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("ÃÜÂë´íÎó"),
			QString::fromLocal8Bit("ÇëÊäÈëÕýÈ·ÃÜÂë"), QMessageBox::Ok);
		ui.pwdLineEdit->setFocus();
	}
	else
	{
		QSqlQuery query;
		query.exec("select pwd from password");
		query.next();
		if (query.value(0).toString() == ui.pwdLineEdit->text())
		{
			QDialog::accept();
		}
		else
		{
			QMessageBox::information(this, QString::fromLocal8Bit("ÃÜÂë´íÎó"),
				QString::fromLocal8Bit("ÇëÊäÈëÕýÈ·ÃÜÂë"), QMessageBox::Ok);
			ui.pwdLineEdit->clear();
			ui.pwdLineEdit->setFocus();
		}
	}
}


void LoginDialog::on_quitBtn_clicked()
{
	QDialog::reject();
}
