#include "LoginWgt.h"




LoginWgt::LoginWgt(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

	//setAttribute(Qt::WA_DeleteOnClose);

	InitUI();
	connectSlots();
}

void LoginWgt::InitUI()
{

}

void LoginWgt::connectSlots()
{
	//bool ret = connect(ui.loginBtn, SIGNAL(clicked()), this, SLOT(on_loginBtn_clicked()));

}


void LoginWgt::on_loginBtn_clicked()
{
	if (1)
	{
		FriendListWgt *fWgt = new FriendListWgt;
		fWgt->show();
		close();
	}

}