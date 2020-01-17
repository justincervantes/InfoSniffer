/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: application.cpp - This file acts as a GUI for the InfoSniffer application that will use Winsock 2
-- to do IP/Hostname lookups and Port Number/Protocol to Service Name (and vice-versa) lookups. All functions here
-- are implemented through Qt's slots system.
--
-- PROGRAM: InfoSniffer
--
-- FUNCTIONS:
-- void on_actionHost_Name_to_IP_triggered();
-- void on_actionIP_to_Host_Name_triggered();
-- void on_actionService_Name_Protocol_to_Port_Number_triggered();
-- void on_actionPort_Number_to_Service_Name_Protocol_triggered();
-- void on_actionAbout_triggered();
-- void on_pushButton_clicked();
-- void on_actionShow_Usage_triggered();
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- NOTES:
-- The program will enable users to lookup hostnames from IP addresses, IP addresses from hostnames, port number from
-- service name and protocol, and service name from port numbers and protocol.
--
----------------------------------------------------------------------------------------------------------------------*/

#include "application.h"
#include "ui_application.h"
#include "session.h"

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: Application
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: Application::Application(QWidget *parent)
-- QWidget *parent: the parent which called Application.
--
-- RETURNS:
-- N/A
--
-- NOTES:
-- This is the constructor.
----------------------------------------------------------------------------------------------------------------------*/
Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);
    this->setWindowTitle("InfoSniffer");
    // Fix the window size
    this->setFixedSize(800,600);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: ~Application
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: Application::~Application()
--
-- RETURNS:
-- N/A
--
-- NOTES:
-- Destructor.
----------------------------------------------------------------------------------------------------------------------*/
Application::~Application()
{
    delete ui;
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionHost_Name_to_IP_triggered
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: void Application::on_actionHost_Name_to_IP_triggered()
--
-- RETURNS:
-- N/A
--
-- NOTES:
-- Sets the Host name to IP menu option as checked, and de-selects all other options, ensuring only
-- one option has been selected.
----------------------------------------------------------------------------------------------------------------------*/
void Application::on_actionHost_Name_to_IP_triggered()
{
    ui->actionHost_Name_to_IP->setChecked(true);
    ui->actionIP_to_Host_Name->setChecked(false);
    ui->actionService_Name_Protocol_to_Port_Number->setChecked(false);
    ui->actionPort_Number_to_Service_Name_Protocol->setChecked(false);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionIP_to_Host_Name_triggered
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: void Application::on_actionIP_to_Host_Name_triggered()
--
-- RETURNS:
-- N/A
--
-- NOTES:
-- Sets the IP to Host Name menu option as checked, and de-selects all other options, ensuring only
-- one option has been selected.
----------------------------------------------------------------------------------------------------------------------*/
void Application::on_actionIP_to_Host_Name_triggered()
{
    ui->actionHost_Name_to_IP->setChecked(false);
    ui->actionIP_to_Host_Name->setChecked(true);
    ui->actionService_Name_Protocol_to_Port_Number->setChecked(false);
    ui->actionPort_Number_to_Service_Name_Protocol->setChecked(false);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionService_Name_Protocol_to_Port_Number_triggered
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: void Application::on_actionService_Name_Protocol_to_Port_Number_triggered()
--
-- RETURNS:
-- N/A
--
-- NOTES:
-- Sets the Service Name/Protocol to Port Number menu option as checked, and de-selects all other options,
-- ensuring only one option has been selected.
--
----------------------------------------------------------------------------------------------------------------------*/
void Application::on_actionService_Name_Protocol_to_Port_Number_triggered()
{
    ui->actionHost_Name_to_IP->setChecked(false);
    ui->actionIP_to_Host_Name->setChecked(false);
    ui->actionService_Name_Protocol_to_Port_Number->setChecked(true);
    ui->actionPort_Number_to_Service_Name_Protocol->setChecked(false);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionPort_Number_to_Service_Name_Protocol_triggered
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: void Application::on_actionPort_Number_to_Service_Name_Protocol_triggered()
--
-- RETURNS:
-- N/A
--
-- NOTES:
-- Sets the Port Number/Protocol to Service Name menu option as checked, and de-selects all other options,
-- ensuring only one option has been selected.
--
----------------------------------------------------------------------------------------------------------------------*/
void Application::on_actionPort_Number_to_Service_Name_Protocol_triggered()
{
    ui->actionHost_Name_to_IP->setChecked(false);
    ui->actionIP_to_Host_Name->setChecked(false);
    ui->actionService_Name_Protocol_to_Port_Number->setChecked(false);
    ui->actionPort_Number_to_Service_Name_Protocol->setChecked(true);
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionAbout_triggered
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: void Application::on_actionAbout_triggered()
--
-- RETURNS:
-- N/A
--
-- NOTES:
-- Sets the text browser widget to show information about InfoSniffer.
--
----------------------------------------------------------------------------------------------------------------------*/
void Application::on_actionAbout_triggered()
{
    ui->textBrowser->setHtml("<b><u>InfoSniffer</b></ul>");
    ui->textBrowser->append("\nDescription: A tool which uses Winsock 2 to explore IP, hostnames, services and ports. This is a primitive tool for finding more information about hosts and services.");
    ui->textBrowser->append("Written by: Justin Cervantes");
    ui->textBrowser->append("Date: January 16, 2020");
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_pushButton_clicked
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: void Application::on_pushButton_clicked()
--
-- RETURNS:
-- N/A
--
-- NOTES:
-- Sets the text browser widget to show information about the selected action item from the menu, based on the
-- input given. If no input is received, or if an empty QString is received, the UI's text browser will update
-- with an error message saying that the query field cannot be empty. This method checks the current menu action
-- selection by calling helper method getCurrentAction().
--
----------------------------------------------------------------------------------------------------------------------*/
void Application::on_pushButton_clicked()
{
    QString selectedAction = getCurrentAction();
    QString query = ui->lineEdit->text();

    if(query == "") {
        ui->textBrowser->setText("The query field cannot be empty!");
        return;
    }

    if(selectedAction == ui->actionHost_Name_to_IP->objectName()) {
        //ui->textBrowser->setText(hostNameToIP(query));
        ui->textBrowser->setText(hostNameToIP(query));
    } else if (selectedAction == ui->actionIP_to_Host_Name->objectName()) {
        ui->textBrowser->setText(ipToHostName(query));
    } else if (selectedAction == ui->actionService_Name_Protocol_to_Port_Number->objectName()) {
        ui->textBrowser->setText(serviceNameProtocolToPortNumber(query));
    } else if (selectedAction == ui->actionPort_Number_to_Service_Name_Protocol->objectName()) {
        ui->textBrowser->setText(PortNumberToServiceNameProtocol(query));
    } else {
        ui->textBrowser->setText("An action must be selected from the menu bar prior to querying");
    }
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: getCurrentAction
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: QString Application::getCurrentAction()
--
-- RETURNS:
-- Returns a QString of the name of the currently checked menu action item.
-- Returns an empty string if nothing is checked.
--
-- NOTES:
-- getCurrentAction is a helper method which checks the menu action items and returns the name of the
-- selected object. If no object is selected, it returns and empty string.
--
----------------------------------------------------------------------------------------------------------------------*/
QString Application::getCurrentAction() {
    if(ui->actionHost_Name_to_IP->isChecked()) {
        return ui->actionHost_Name_to_IP->objectName();
    } else if(ui->actionIP_to_Host_Name->isChecked()){
        return ui->actionIP_to_Host_Name->objectName();
    } else if(ui->actionService_Name_Protocol_to_Port_Number->isChecked()) {
        return ui->actionService_Name_Protocol_to_Port_Number->objectName();
    } else if(ui->actionPort_Number_to_Service_Name_Protocol->isChecked()){
        return ui->actionPort_Number_to_Service_Name_Protocol->objectName();
    } else {
        return "";
    }
}

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION: on_actionShow_Usage_triggered
--
-- DATE: January 16, 2020
--
-- REVISIONS: (Date and Description)
-- N/A
--
-- DESIGNER: Justin Cervantes
--
-- PROGRAMMER: Justin Cervantes
--
-- INTERFACE: void Application::on_actionShow_Usage_triggered()
--
-- RETURNS:
-- N/A
--
-- NOTES:
-- Sets the text browser widget to show information about InfoSniffer usage. The text mirrors the default
-- usage instructions that are displayed when first loaded.
--
----------------------------------------------------------------------------------------------------------------------*/
void Application::on_actionShow_Usage_triggered()
{
    ui->textBrowser->setHtml("<b><u>InfoSniffer</u></b>");
    ui->textBrowser->append("\nHow to use this program:\n");
    ui->textBrowser->append("1. Select an action");
    ui->textBrowser->append("2. Input something to query");
    ui->textBrowser->append("3. Click submit\n");
    ui->textBrowser->append("Usage:\n");
    ui->textBrowser->append("Host Name to IP - any valid website (eg www.telus.com)");
    ui->textBrowser->append("IP to Host Name - any valid IP address (eg 142.232.230.11)");
    ui->textBrowser->append("Service Name/Protocol to Port Number - service name, protocol (eg shell, tcp)");
    ui->textBrowser->append("Port Number to Service Name/Protocol -  port number, protocol (eg 22, tcp)\n");
    ui->textBrowser->append("<b>*If you want to come back to this, check Help->Show Usage</b>");
}
