#include "mainwindow.h"
#include "./ui_mainwindow.h"

const int BIN = 2;
const int OCT = 8;
const int DEC = 10;
const int HEX = 16;
const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if ((ui->lineEdit->text().length() > 10) || (ui->lineEdit->text().isEmpty())) {
        ui->label_6->setText("Error");
    }
    else {
        string str;

        map <int, int> st = {{0,2},
                        {1,8},
                        {2,10},
                        {3,16}};

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        QSqlQuery query;
        db.setDatabaseName("History.db");

        db.open();
        calcMethods calcA;
        switch(ui->comboBox_2->currentIndex()){
            case 0: //2
                str = calcA.toBin((ui->lineEdit->text()).toStdString(), st[ui->comboBox->currentIndex()]);
                ui->label_6->setText(QString::fromStdString(str));
                query.exec(QString("insert into calc(time_, num, systemIn, systemOut, result) "
                                   "values (datetime(\"now\", \"localtime\"), %1, %2, %3, %4)")
                                    .arg(ui->lineEdit->text())
                                    .arg(st[ui->comboBox->currentIndex()])
                                    .arg(st[ui->comboBox_2->currentIndex()])
                                    .arg(QString::fromStdString(str)));
                break;
            case 1: // 8
                str = calcA.toOct((ui->lineEdit->text()).toStdString(), st[ui->comboBox->currentIndex()]);
                ui->label_6->setText(QString::fromStdString(str));
                break;
            case 2: //10
                str = calcA.toDec((ui->lineEdit->text()).toStdString(), st[ui->comboBox->currentIndex()]);
                ui->label_6->setText(QString::fromStdString(str));
                break;
            case 3: //16
                str = calcA.toHex((ui->lineEdit->text()).toStdString(), st[ui->comboBox->currentIndex()]);
                ui->label_6->setText(QString::fromStdString(str));
                break;
        }
        db.close();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    calcLogical calcL;
    string str;
    switch (ui->lineEdit_4->text().toInt())
    {
        case 0:
            str = calcL.logicalNot(ui->lineEdit_2->text().toStdString());
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;

        case 1:
            str = calcL.logicalOr(ui->lineEdit_2->text().toStdString(), ui->lineEdit_3->text().toStdString());
            str = calcL.logicalNot(str);
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;

        case 10:
            str = calcL.logicalNot(ui->lineEdit_2->text().toStdString());
            str = calcL.logicalAnd(str, ui->lineEdit_3->text().toStdString());
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;

        case 11:
            str = calcL.logical(0);
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;

        case 100:
            str = calcL.logicalAnd(ui->lineEdit_2->text().toStdString(), ui->lineEdit_3->text().toStdString());
            str = calcL.logicalNot(str);
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 101:
            str = calcL.logicalNot(ui->lineEdit_3->text().toStdString());
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 110:
            str = calcL.logicalXor(ui->lineEdit_2->text().toStdString(), ui->lineEdit_3->text().toStdString());
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 111:
            str = calcL.logicalNot(ui->lineEdit_3->text().toStdString());
            str = calcL.logicalAnd(ui->lineEdit_2->text().toStdString(), str);
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 1000:
            str = calcL.logicalNot(ui->lineEdit_2->text().toStdString());
            str = calcL.logicalOr(str, ui->lineEdit_3->text().toStdString());
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 1001:
            str = calcL.logicalXor(ui->lineEdit_2->text().toStdString(), ui->lineEdit_3->text().toStdString());
            str = calcL.logicalNot(str);
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 1010:
            str = calcL.justNum(ui->lineEdit_3->text().toStdString());
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 1011:
            str = calcL.logicalAnd(ui->lineEdit_2->text().toStdString(), ui->lineEdit_3->text().toStdString());
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 1100:
            str = calcL.logical(1);
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 1101:
            str = calcL.logicalNot(ui->lineEdit_3->text().toStdString());
            str = calcL.logicalOr(ui->lineEdit_2->text().toStdString(), str);
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 1110:
            str = calcL.logicalOr(ui->lineEdit_2->text().toStdString(), ui->lineEdit_3->text().toStdString());
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
        case 1111:
            str = calcL.justNum(ui->lineEdit_2->text().toStdString());
            ui->label_12->setText(QString::fromStdString(str));
            str = "";
        break;
    }

}

void MainWindow::on_pushButton_3_clicked()
{
    calcArifmet calcA;
    string str;

    if (!ui->checkBox->checkState()) {
        switch (ui->lineEdit_8->text().toInt())
        {
            case 0:
                str = calcA.justNum(ui->lineEdit_6->text().toStdString());
                ui->label_23->setText(QString::fromStdString(str));
                str = "";
            break;
            case 1:
                str = calcA.logicalOr(ui->lineEdit_6->text().toStdString(), ui->lineEdit_7->text().toStdString());
                ui->label_23->setText(QString::fromStdString(str));
                str = "";
            break;
            case 10:
                str = calcA.logicalNot(ui->lineEdit_7->text().toStdString());
                str = calcA.logicalOr(ui->lineEdit_6->text().toStdString(), str);
                ui->label_23->setText(QString::fromStdString(str));
                str = "";
            break;
            case 11:

            break;
            case 100:
                str = calcA.logicalNot(ui->lineEdit_7->text().toStdString());
                str = calcA.logicalAnd(ui->lineEdit_6->text().toStdString(), str);
                str = calcA.calcPlus(ui->lineEdit_6->text().toStdString(), str);
                ui->label_23->setText(QString::fromStdString(str));
                str = "";
            break;
        }
    }
    else {
        ui->label_23->setText("#23");
    }
}

void MainWindow::on_listWidget_itemActivated(QListWidgetItem *item)
{
    string nameDB = "";
    switch(ui->listWidget->currentRow()) {
        case 0:
            nameDB = "calc";
            break;
        case 1:
            nameDB = "calcLogical";
            break;
    }

    int countColumn = 0;
    int countRow = 0;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
    QStringList listColumn = {"Число", "Из какой", "В какую", "Результат"}, listResultQuery;
    db.setDatabaseName("History.db");

    db.open();
    if(db.isOpen()){
        if(query.exec("Select * from " + QString::fromStdString(nameDB))){
            while (query.next()) {
                QString showInfomation1 = query.value(2).toString(),
                        showInfomation2 = query.value(3).toString(),
                        showInfomation3 = query.value(4).toString(),
                        showInfomation4 = query.value(5).toString();
                listResultQuery << showInfomation1
                                << showInfomation2
                                << showInfomation3
                                << showInfomation4;
                ++countRow;
            }
        } else {
            qDebug() << "Error query: " << query.lastError().text();
        }
        db.close();
    } else {
        qDebug() << "Error open db: " << db.lastError().text();
        return;
    }

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(countRow);

    ui->tableWidget->setHorizontalHeaderLabels(listColumn);

    int countResultQuery = 0;
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        for (int j = 0; j < ui->tableWidget->columnCount(); ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(listResultQuery[j+countResultQuery]);
            ui->tableWidget->setItem(i, j, item);
        }
        countResultQuery += 4;
    }

    db.close();


    //очистка 1-го калькулятора
    ui->lineEdit->setText("");
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(2);
    ui->label_6->setText("");

    //очистка 2-го калькулятора
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->label_12->setText("");

    //очистка 3-го калькулятора
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->checkBox->setChecked(false);
    ui->lineEdit_8->setText("");
    ui->label_23->setText("");

    ui->groupBox_3->setTitle(ui->listWidget->currentItem()->text());
    ui->stackedWidget->setCurrentIndex(ui->listWidget->currentRow());
}
