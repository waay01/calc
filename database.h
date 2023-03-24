#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <QtSql>
#include <QSqlQuery>

using namespace std;

class dataBase
{
public:
    void connectDB();
    void disconectDB();
};

#endif // DATABASE_H
