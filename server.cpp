#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    QSettings config("config.ini",QSettings::IniFormat);
    QString dbServer=config.value("database/server").toString();
    QString dbDatabase=config.value("database/database").toString();
    QString dbUsername=config.value("database/username").toString();
    QString dbPassword=config.value("database/password").toString();
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QMYSQL");
    mydb.setHostName(dbServer);
    mydb.setDatabaseName(dbDatabase);
    mydb.setUserName(dbUsername);
    mydb.setPassword(dbPassword);
    //QMessageBox::warning(this,"warning",dbServer+dbDatabase+dbUsername+dbPassword);
    if(!mydb.open())
        QMessageBox::warning(this,"warning",mydb.lastError());
    else
        QMessageBox::information(this,"info","success to connect.");
    mydb.close();
}

Server::~Server()
{
    delete ui;
}
