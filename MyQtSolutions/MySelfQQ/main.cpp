#include "Widget.h"
#include <QtWidgets/QApplication>
#include "Drawer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	Drawer drawer;
	drawer.resize(250, 700);
	drawer.show();

    //Widget w;
    //w.show();
    return a.exec();
}
