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
    dataBase db;
    db.showDataBase();

    if ((ui->lineEdit->text().length() > 10) || (ui->lineEdit->text().isEmpty())) {
        ui->label_6->setText("Error");
    }
    else {
        string str;

        map <int, int> st = {{0,2},
                        {1,8},
                        {2,10},
                        {3,16}};

        calcMethods calcA;
        switch(ui->comboBox_2->currentIndex()){
            case 0: //2
                str = calcA.toBin((ui->lineEdit->text()).toStdString(), st[ui->comboBox->currentIndex()]);
                ui->label_6->setText(QString::fromStdString(str));
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
