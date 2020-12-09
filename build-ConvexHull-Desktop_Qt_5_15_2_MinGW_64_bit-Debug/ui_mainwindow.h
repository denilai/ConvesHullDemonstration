/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *vertplotFLayoutWidget_3;
    QVBoxLayout *verticalLayout;
    QCustomPlot *plot;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *xVLayout;
    QLabel *xLabel;
    QDoubleSpinBox *xSpinBox;
    QVBoxLayout *yVLayout;
    QLabel *yLabel;
    QDoubleSpinBox *ySpinBox;
    QSpacerItem *horizontalSpacer;
    QPushButton *addPushButton;
    QPushButton *cleanPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(90, 10, 591, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget_3);
        plotFicalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plotFicalLayout->setContentsMargins(0, 0, 0, 0);
        plot = new QCustomPlot(verticalLayoutplotFet_3);
        plot->setObjectName(QString::fromUtf8("plot"));
        horizontalLayoutWidget = new QWidget(plot);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 325, 571, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        xVLayout = new QVBoxLayout();
        xVLayout->setObjectName(QString::fromUtf8("xVLayout"));
        xLabel = new QLabel(horizontalLayoutWidget);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));
        xLabel->setAlignment(Qt::AlignCenter);

        xVLayout->addWidget(xLabel);

        xSpinBox = new QDoubleSpinBox(horizontalLayoutWidget);
        xSpinBox->setObjectName(QString::fromUtf8("xSpinBox"));

        xVLayout->addWidget(xSpinBox);


        horizontalLayout->addLayout(xVLayout);

        yVLayout = new QVBoxLayout();
        yVLayout->setObjectName(QString::fromUtf8("yVLayout"));
        yLabel = new QLabel(horizontalLayoutWidget);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));
        yLabel->setAlignment(Qt::AlignCenter);

        yVLayout->addWidget(yLabel);

        ySpinBox = new QDoubleSpinBox(horizontalLayoutWidget);
        ySpinBox->setObjectName(QString::fromUtf8("ySpinBox"));

        yVLayout->addWidget(ySpinBox);


        horizontalLayout->addLayout(yVLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        addPushButton = new QPushButton(horizontalLayoutWidget);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout->addWidget(addPushButton);

        cleanPushButton = new QPushButton(horizontalLayoutWidget);
        cleanPushButton->setObjectName(QString::fromUtf8("cleanPushButton"));

        horizontalLayout->addWidget(cleanPushButton);


        verticalLayout->addWidgeplotFot);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        xLabel->setText(QCoreApplication::translate("MainWindow", "X:", nullptr));
        yLabel->setText(QCoreApplication::translate("MainWindow", "Y:", nullptr));
        addPushButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        cleanPushButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
