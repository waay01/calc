#include "database.h"

void dataBase::connectDB()
{
    int countColumn = 0;
        int countRow = 0;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        QSqlQuery query;
        QStringList listColumn, itemForTable;
        db.setDatabaseName("History.db");

        db.open();

        query.exec("PRAGMA table_info('calc')");
        while (query.next()) {
            QString nameColumn = query.value(1).toString();
            listColumn.emplaceBack(nameColumn);
            ++countColumn;
        }

        query.exec("Select * from calc");
        while (query.next()) {
            QString showInfomation1 = query.value(1).toString(),
                    showInfomation2 = query.value(2).toString(),
                    showInfomation3 = query.value(3).toString(),
                    showInfomation4 = query.value(4).toString(),
                    showInfomation5 = query.value(5).toString();
            itemForTable.emplaceBack(showInfomation1);
            ++countRow;
        }

}

void dataBase::disconectDB() {

}

//int countColumn = 0;
//int countRow = 0;
//QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//QSqlQuery query;
//QStringList listColumn = {"Число", "Из какой", "В какую", "Результат"}, listResultQuery;
//db.setDatabaseName("History.db");

//db.open();
//query.exec("Select * from calc");

//while (query.next()) {
//    QString showInfomation1 = query.value(2).toString(),
//            showInfomation2 = query.value(3).toString(),
//            showInfomation3 = query.value(4).toString(),
//            showInfomation4 = query.value(5).toString();
//    listResultQuery.emplaceBack(showInfomation1);
//    listResultQuery.emplaceBack(showInfomation2);
//    listResultQuery.emplaceBack(showInfomation3);
//    listResultQuery.emplaceBack(showInfomation4);
//    ++countRow;
//}

//ui->tableWidget->setColumnCount(4);
//ui->tableWidget->setRowCount(countRow);

//ui->tableWidget->setHorizontalHeaderLabels(listColumn);

//int countResultQuery = 0;
//for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
//    for (int j = 0; j < ui->tableWidget->columnCount(); ++j) {
//        QTableWidgetItem *item = new QTableWidgetItem(listResultQuery[j+countResultQuery]);
//        ui->tableWidget->setItem(i, j, item);
//    }
//    countResultQuery += 4;
//}

//db.close();
