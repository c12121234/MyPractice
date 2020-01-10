#include "myconnection.h"

static bool Connection()
{
    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlDatabase db = QSqlDatabase::database("my.db");
    //db.setDatabaseName("my.db");
    if(!db.open())
    {
        QMessageBox::critical(0,"cannot open database.","Unable to establish a database connection."
                              ,QMessageBox::Cancel);
        return false;
    }
    /*
    QSqlQuery query;
    query.exec("CREATE TABLE student(id int primary key,name varchar,course int)");
    query.exec("INSERT INTO student values(1,'小明',11)");
    query.exec("INSERT INTO student values(2,'大強',11)");
    query.exec("INSERT INTO student values(3,'中坡',12)");

    query.exec("CREATE TABLE course(id int primary key,name varchar,teacher varchar)");
    query.exec("INSERT INTO course values(10,'數學','王老師')");
    query.exec("INSERT INTO course values(11,'英文','陳老師')");
    query.exec("INSERT INTO course values(12,'計算機概論','林老師')");
    */
    return true;
}
