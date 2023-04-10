#include "imagen.h"
#include "qfiledialog.h"
#include "ui_imagen.h"

imagen::imagen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::imagen)
{
    ui->setupUi(this);
}

imagen::~imagen()
{
    delete ui;
}



void imagen::on_pushButton_clicked()
{

}


void imagen::on_pushButton_2_clicked()
{
    //seleccionar
    QFileDialog directorio;
    this->origen = directorio.getExistingDirectory(this, "Fichero origen");
    this->destino = directorio.getExistingDirectory(this, "Fichero destino");

    this->destino += "/EliminarNumerosRepetidos.txt";
    this->ui->t5_2->setText(this->origen);
    this->ui->t5_3->setText(this->destino);
}


void imagen::on_pushButton_3_clicked()
{
    //borrar
    this->ui->t1->setText("");
    this->ui->t2->setText("");
    this->ui->t3->setText("");
    this->ui->t4->setText("");
    this->ui->t5->setText("");
}

