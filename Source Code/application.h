#ifndef APPLICATION_H
#define APPLICATION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Application; }
QT_END_NAMESPACE

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();
    QString getCurrentAction();

private slots:
    void on_actionHost_Name_to_IP_triggered();
    void on_actionIP_to_Host_Name_triggered();
    void on_actionService_Name_Protocol_to_Port_Number_triggered();
    void on_actionPort_Number_to_Service_Name_Protocol_triggered();
    void on_actionAbout_triggered();
    void on_pushButton_clicked();
    void on_actionShow_Usage_triggered();

private:
    Ui::Application *ui;
};
#endif // APPLICATION_H
