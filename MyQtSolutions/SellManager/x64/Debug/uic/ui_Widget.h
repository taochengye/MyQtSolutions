/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetClass
{
public:
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *managePage;
    QLabel *label;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *sellPriceLineEdit;
    QLabel *label_8;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *sellFactoryComboBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *sellBrandComboBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *sellSumLineEdit;
    QLabel *label_9;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSpinBox *sellNumSpinBox;
    QLabel *sellLastNumLabel;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *sellOkBtn;
    QPushButton *sellCancelBtn;
    QWidget *page_3;
    QListWidget *dailyList;
    QWidget *chartPage;
    QLabel *label_10;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *factoryComboBox;
    QPushButton *updateBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *WidgetClass)
    {
        if (WidgetClass->objectName().isEmpty())
            WidgetClass->setObjectName(QStringLiteral("WidgetClass"));
        WidgetClass->resize(800, 566);
        WidgetClass->setMinimumSize(QSize(800, 500));
        verticalLayout_3 = new QVBoxLayout(WidgetClass);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        stackedWidget = new QStackedWidget(WidgetClass);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(750, 500));
        managePage = new QWidget();
        managePage->setObjectName(QStringLiteral("managePage"));
        label = new QLabel(managePage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 26, 680, 35));
        label->setMinimumSize(QSize(680, 35));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(""));
        label->setFrameShape(QFrame::StyledPanel);
        label->setAlignment(Qt::AlignCenter);
        toolBox = new QToolBox(managePage);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(10, 80, 340, 351));
        toolBox->setMinimumSize(QSize(340, 0));
        toolBox->setMaximumSize(QSize(340, 16777215));
        toolBox->setFrameShape(QFrame::WinPanel);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 336, 295));
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 120, 195, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        sellPriceLineEdit = new QLineEdit(layoutWidget);
        sellPriceLineEdit->setObjectName(QStringLiteral("sellPriceLineEdit"));

        horizontalLayout_3->addWidget(sellPriceLineEdit);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_3->addWidget(label_8);

        layoutWidget1 = new QWidget(page);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 30, 144, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        sellFactoryComboBox = new QComboBox(layoutWidget1);
        sellFactoryComboBox->setObjectName(QStringLiteral("sellFactoryComboBox"));
        sellFactoryComboBox->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(sellFactoryComboBox);

        layoutWidget2 = new QWidget(page);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 80, 117, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        sellBrandComboBox = new QComboBox(layoutWidget2);
        sellBrandComboBox->setObjectName(QStringLiteral("sellBrandComboBox"));

        horizontalLayout_2->addWidget(sellBrandComboBox);

        layoutWidget3 = new QWidget(page);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(30, 220, 195, 22));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget3);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        sellSumLineEdit = new QLineEdit(layoutWidget3);
        sellSumLineEdit->setObjectName(QStringLiteral("sellSumLineEdit"));

        horizontalLayout_5->addWidget(sellSumLineEdit);

        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        layoutWidget4 = new QWidget(page);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(30, 170, 168, 22));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget4);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        sellNumSpinBox = new QSpinBox(layoutWidget4);
        sellNumSpinBox->setObjectName(QStringLiteral("sellNumSpinBox"));

        horizontalLayout_4->addWidget(sellNumSpinBox);

        sellLastNumLabel = new QLabel(layoutWidget4);
        sellLastNumLabel->setObjectName(QStringLiteral("sellLastNumLabel"));

        horizontalLayout_4->addWidget(sellLastNumLabel);

        layoutWidget5 = new QWidget(page);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(77, 260, 201, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        sellOkBtn = new QPushButton(layoutWidget5);
        sellOkBtn->setObjectName(QStringLiteral("sellOkBtn"));

        horizontalLayout_6->addWidget(sellOkBtn);

        sellCancelBtn = new QPushButton(layoutWidget5);
        sellCancelBtn->setObjectName(QStringLiteral("sellCancelBtn"));

        horizontalLayout_6->addWidget(sellCancelBtn);

        toolBox->addItem(page, QString::fromUtf8("\345\207\272\345\224\256\350\275\246\350\276\206"));
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        page_3->setGeometry(QRect(0, 0, 336, 295));
        toolBox->addItem(page_3, QString::fromUtf8("\345\267\262\346\234\211\346\226\260\350\275\246\345\205\245\345\272\223"));
        dailyList = new QListWidget(managePage);
        dailyList->setObjectName(QStringLiteral("dailyList"));
        dailyList->setGeometry(QRect(370, 80, 321, 351));
        stackedWidget->addWidget(managePage);
        chartPage = new QWidget();
        chartPage->setObjectName(QStringLiteral("chartPage"));
        label_10 = new QLabel(chartPage);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 30, 680, 35));
        label_10->setMinimumSize(QSize(680, 35));
        label_10->setFont(font);
        label_10->setStyleSheet(QStringLiteral(""));
        label_10->setFrameShape(QFrame::StyledPanel);
        label_10->setAlignment(Qt::AlignCenter);
        widget = new QWidget(chartPage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 70, 681, 25));
        horizontalLayout_8 = new QHBoxLayout(widget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        factoryComboBox = new QComboBox(widget);
        factoryComboBox->setObjectName(QStringLiteral("factoryComboBox"));
        factoryComboBox->setMinimumSize(QSize(150, 0));

        horizontalLayout_8->addWidget(factoryComboBox);

        updateBtn = new QPushButton(widget);
        updateBtn->setObjectName(QStringLiteral("updateBtn"));

        horizontalLayout_8->addWidget(updateBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        stackedWidget->addWidget(chartPage);

        verticalLayout_3->addWidget(stackedWidget);


        retranslateUi(WidgetClass);

        stackedWidget->setCurrentIndex(1);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WidgetClass);
    } // setupUi

    void retranslateUi(QWidget *WidgetClass)
    {
        WidgetClass->setWindowTitle(QApplication::translate("WidgetClass", "\346\261\275\350\275\246\351\224\200\345\224\256\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label->setText(QApplication::translate("WidgetClass", "\345\223\201\347\211\214\350\275\246\347\256\241\347\220\206", Q_NULLPTR));
        label_4->setText(QApplication::translate("WidgetClass", "\346\212\245\344\273\267\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("WidgetClass", "\344\270\207", Q_NULLPTR));
        label_2->setText(QApplication::translate("WidgetClass", "\345\216\202\345\256\266\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("WidgetClass", "\345\223\201\347\211\214\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("WidgetClass", "\351\207\221\351\242\235\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("WidgetClass", "\344\270\207", Q_NULLPTR));
        label_5->setText(QApplication::translate("WidgetClass", "\346\225\260\351\207\217\357\274\232", Q_NULLPTR));
        sellLastNumLabel->setText(QApplication::translate("WidgetClass", "\345\211\251\344\275\231\346\225\260\351\207\217\357\274\232000", Q_NULLPTR));
        sellOkBtn->setText(QApplication::translate("WidgetClass", "\347\241\256\345\256\232", Q_NULLPTR));
        sellCancelBtn->setText(QApplication::translate("WidgetClass", "\345\217\226\346\266\210", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("WidgetClass", "\345\207\272\345\224\256\350\275\246\350\276\206", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_3), QApplication::translate("WidgetClass", "\345\267\262\346\234\211\346\226\260\350\275\246\345\205\245\345\272\223", Q_NULLPTR));
        label_10->setText(QApplication::translate("WidgetClass", "\351\224\200\345\224\256\347\273\237\350\256\241", Q_NULLPTR));
        updateBtn->setText(QApplication::translate("WidgetClass", "\346\233\264\346\226\260\346\230\276\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetClass: public Ui_WidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
