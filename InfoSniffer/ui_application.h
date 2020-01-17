/********************************************************************************
** Form generated from reading UI file 'application.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICATION_H
#define UI_APPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Application
{
public:
    QAction *actionHost_Name_to_IP;
    QAction *actionIP_to_Host_Name;
    QAction *actionService_Name_Protocol_to_Port_Number;
    QAction *actionPort_Number_to_Service_Name_Protocol;
    QAction *actionAbout;
    QAction *actionShow_Usage;
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuActions;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Application)
    {
        if (Application->objectName().isEmpty())
            Application->setObjectName(QString::fromUtf8("Application"));
        Application->resize(800, 600);
        actionHost_Name_to_IP = new QAction(Application);
        actionHost_Name_to_IP->setObjectName(QString::fromUtf8("actionHost_Name_to_IP"));
        actionHost_Name_to_IP->setCheckable(true);
        actionIP_to_Host_Name = new QAction(Application);
        actionIP_to_Host_Name->setObjectName(QString::fromUtf8("actionIP_to_Host_Name"));
        actionIP_to_Host_Name->setCheckable(true);
        actionService_Name_Protocol_to_Port_Number = new QAction(Application);
        actionService_Name_Protocol_to_Port_Number->setObjectName(QString::fromUtf8("actionService_Name_Protocol_to_Port_Number"));
        actionService_Name_Protocol_to_Port_Number->setCheckable(true);
        actionPort_Number_to_Service_Name_Protocol = new QAction(Application);
        actionPort_Number_to_Service_Name_Protocol->setObjectName(QString::fromUtf8("actionPort_Number_to_Service_Name_Protocol"));
        actionPort_Number_to_Service_Name_Protocol->setCheckable(true);
        actionAbout = new QAction(Application);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionShow_Usage = new QAction(Application);
        actionShow_Usage->setObjectName(QString::fromUtf8("actionShow_Usage"));
        centralwidget = new QWidget(Application);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 500, 25));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(510, 10, 112, 25));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 40, 780, 490));
        Application->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Application);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
        menuActions = new QMenu(menubar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Application->setMenuBar(menubar);
        statusbar = new QStatusBar(Application);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Application->setStatusBar(statusbar);

        menubar->addAction(menuActions->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuActions->addAction(actionHost_Name_to_IP);
        menuActions->addAction(actionIP_to_Host_Name);
        menuActions->addAction(actionService_Name_Protocol_to_Port_Number);
        menuActions->addAction(actionPort_Number_to_Service_Name_Protocol);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionShow_Usage);

        retranslateUi(Application);

        QMetaObject::connectSlotsByName(Application);
    } // setupUi

    void retranslateUi(QMainWindow *Application)
    {
        Application->setWindowTitle(QCoreApplication::translate("Application", "Application", nullptr));
        actionHost_Name_to_IP->setText(QCoreApplication::translate("Application", "Host Name to IP", nullptr));
        actionIP_to_Host_Name->setText(QCoreApplication::translate("Application", "IP to Host Name", nullptr));
        actionService_Name_Protocol_to_Port_Number->setText(QCoreApplication::translate("Application", "Service Name/Protocol to Port Number", nullptr));
        actionPort_Number_to_Service_Name_Protocol->setText(QCoreApplication::translate("Application", "Port Number/Protocol to Service Name", nullptr));
        actionAbout->setText(QCoreApplication::translate("Application", "About", nullptr));
        actionShow_Usage->setText(QCoreApplication::translate("Application", "Show Usage", nullptr));
        pushButton->setText(QCoreApplication::translate("Application", "Query", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Application", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-weight:600; text-decoration: underline;\">InfoSniffer</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">How to use this program:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-t"
                        "op:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">1. Select an action</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">2. Input something to query</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">3. Click submit</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-righ"
                        "t:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">Usage:</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">Host Name to IP</span><span style=\" font-family:'MS Shell Dlg 2'; font-style:italic;\"> -</span><span style=\" font-family:'MS Shell Dlg 2';\"> any valid website (eg www.telus.com)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">IP to Host Name - any valid IP address (eg 142.232.230.11)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-inden"
                        "t:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">Service Name/Protocol to Port Number - service name, protocol (eg shell, tcp)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2';\">Port Number to Service Name/Protocol -  port number, protocol (eg 22, tcp)</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-weight:600;\">*If you want to come back to this, check Help-&gt;Show Usage</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell "
                        "Dlg 2';\"><br /></p></body></html>", nullptr));
        menuActions->setTitle(QCoreApplication::translate("Application", "Actions", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("Application", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Application: public Ui_Application {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICATION_H
