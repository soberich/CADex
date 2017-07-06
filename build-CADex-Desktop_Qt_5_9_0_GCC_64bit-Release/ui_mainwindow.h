/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mainwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnHexsaedr;
    QPushButton *btnTetraedr;
    QPushButton *btnOctaedr;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    MainWidget *stageWidget;
    QTextBrowser *textBrowser;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(626, 573);
        MainWindow->setMinimumSize(QSize(0, 500));
        MainWindow->setMaximumSize(QSize(800, 800));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(16777215, 16777215));
        centralWidget->setAutoFillBackground(true);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        btnHexsaedr = new QPushButton(centralWidget);
        btnHexsaedr->setObjectName(QStringLiteral("btnHexsaedr"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnHexsaedr->sizePolicy().hasHeightForWidth());
        btnHexsaedr->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/scr/hexsaedr.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btnHexsaedr->setIcon(icon);
        btnHexsaedr->setIconSize(QSize(158, 140));
        btnHexsaedr->setFlat(true);

        verticalLayout_2->addWidget(btnHexsaedr);

        btnTetraedr = new QPushButton(centralWidget);
        btnTetraedr->setObjectName(QStringLiteral("btnTetraedr"));
        sizePolicy.setHeightForWidth(btnTetraedr->sizePolicy().hasHeightForWidth());
        btnTetraedr->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/scr/tetraedr.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        btnTetraedr->setIcon(icon1);
        btnTetraedr->setIconSize(QSize(160, 172));
        btnTetraedr->setFlat(true);

        verticalLayout_2->addWidget(btnTetraedr);

        btnOctaedr = new QPushButton(centralWidget);
        btnOctaedr->setObjectName(QStringLiteral("btnOctaedr"));
        sizePolicy.setHeightForWidth(btnOctaedr->sizePolicy().hasHeightForWidth());
        btnOctaedr->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/scr/parallelepiped.gif"), QSize(), QIcon::Normal, QIcon::Off);
        btnOctaedr->setIcon(icon2);
        btnOctaedr->setIconSize(QSize(182, 140));
        btnOctaedr->setFlat(true);

        verticalLayout_2->addWidget(btnOctaedr);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stageWidget = new MainWidget(centralWidget);
        stageWidget->setObjectName(QStringLiteral("stageWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stageWidget->sizePolicy().hasHeightForWidth());
        stageWidget->setSizePolicy(sizePolicy1);
        stageWidget->setMinimumSize(QSize(400, 291));
        stageWidget->setMaximumSize(QSize(700, 700));

        verticalLayout->addWidget(stageWidget);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);
        textBrowser->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(textBrowser);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 626, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        btnHexsaedr->setText(QString());
        btnTetraedr->setText(QString());
        btnOctaedr->setText(QString());
        textBrowser->setPlaceholderText(QApplication::translate("MainWindow", "Tetraedr. Number of triangles: 4", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
