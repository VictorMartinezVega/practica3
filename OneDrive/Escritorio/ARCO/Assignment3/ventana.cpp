#include "ventana.h"
#include "ui_ventana.h"

ventana::ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ventana)
{
    ui->setupUi(this);
}

ventana::~ventana()
{
    delete ui;
}

void ventana::on_pushButton_3_clicked()
{
    //borrar
    this->ui->t1->setText("");
    this->ui->t2->setText("");
    this->ui->t3->setText("");
    this->ui->t4->setText("");
    this->ui->t5->setText("");

}


void ventana::on_pushButton_2_clicked()
{
    //seleccionar fichero

    QFileDialog directorio;
    this->origen = directorio.getOpenFileName(this, "Fichero origen");
    this->destino = directorio.getExistingDirectory(this, "Fichero destino");

    this->destino += "/EliminarNumerosRepetidos.txt";
    this->ui->t5_2->setText(this->origen);
    this->ui->t5_3->setText(this->destino);
}


void ventana::on_pushButton_clicked()
{
    //algoritmo de eliminar numeros repetidos en una lista


}

