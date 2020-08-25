/********************************************************************************
** Form generated from reading UI file 'PieView.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIEVIEW_H
#define UI_PIEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractItemView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_PieView
{
public:

    void setupUi(QAbstractItemView *PieView)
    {
        if (PieView->objectName().isEmpty())
            PieView->setObjectName(QStringLiteral("PieView"));
        PieView->resize(400, 300);

        retranslateUi(PieView);

        QMetaObject::connectSlotsByName(PieView);
    } // setupUi

    void retranslateUi(QAbstractItemView *PieView)
    {
        PieView->setWindowTitle(QApplication::translate("PieView", "PieView", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PieView: public Ui_PieView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIEVIEW_H
