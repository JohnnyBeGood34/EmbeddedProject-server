/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *grantAccessButton;
    QPushButton *denieAccess;
    QListView *listView;
    QLabel *label;
    QPushButton *startServerButton;
    QLabel *label_2;
    QLabel *codeReceived;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(755, 458);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 371, 281));
        grantAccessButton = new QPushButton(centralWidget);
        grantAccessButton->setObjectName(QStringLiteral("grantAccessButton"));
        grantAccessButton->setGeometry(QRect(440, 320, 131, 51));
        denieAccess = new QPushButton(centralWidget);
        denieAccess->setObjectName(QStringLiteral("denieAccess"));
        denieAccess->setGeometry(QRect(610, 320, 121, 51));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(400, 40, 341, 171));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(454, 0, 231, 31));
        label->setLineWidth(1);
        startServerButton = new QPushButton(centralWidget);
        startServerButton->setObjectName(QStringLiteral("startServerButton"));
        startServerButton->setGeometry(QRect(10, 320, 141, 51));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 220, 261, 20));
        label_2->setAlignment(Qt::AlignCenter);
        codeReceived = new QLabel(centralWidget);
        codeReceived->setObjectName(QStringLiteral("codeReceived"));
        codeReceived->setGeometry(QRect(510, 250, 121, 17));
        codeReceived->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 755, 27));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        grantAccessButton->setText(QApplication::translate("MainWindow", "Autoriser l'access", 0));
        denieAccess->setText(QApplication::translate("MainWindow", "Refuer l'acces", 0));
        label->setText(QApplication::translate("MainWindow", "Liste des codes et personnes autoris\303\251es", 0));
        startServerButton->setText(QApplication::translate("MainWindow", "Lancer le serveur", 0));
        label_2->setText(QApplication::translate("MainWindow", "Code re\303\247ut", 0));
        codeReceived->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
