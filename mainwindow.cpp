#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "QMessageBox"


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

void MainWindow::on_ingresar_clicked()
{

    QString nombre = ui->nombre_h->text();
    int level = ui->level_h->text().toInt();
    int atk = ui->atk_h->text().toInt();
    QString resultado;

    if(nombre == "" || level < 0 || atk < 0 || std::isnan(level) || std::isnan(atk)) {

        QMessageBox::warning(this, "Warning", "No Data");

        ui->nombre_h->setText("");
        ui->level_h->setText("");
        ui->atk_h->setText("");

    }//if
    else {

        resultado = "\nHero Name: " + nombre + "\nLevel: " + QString::number(level) + "\nAtack: " + QString::number(atk);
        ui->mostrar->appendPlainText(resultado);

        //Limpiar los textfields
        ui->nombre_h->setText("");
        ui->level_h->setText("");
        ui->atk_h->setText("");

    }//else

}//ingresar_clicked

