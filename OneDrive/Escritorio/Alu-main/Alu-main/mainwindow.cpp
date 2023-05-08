#include "mainwindow.h"
#include "ui_mainwindow.h"


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



void MainWindow::on_suma_clicked()
{

    float numero1= ui->op1Decimal->text().toFloat();
    float numero2= ui->op1Decimal->text().toFloat();
    //CASO BASE
    Alu *a = new Alu(numero1, numero2);
    if(a->num1.bits.exponente<1 || a->num1.bits.exponente>=255){
        if(a->num1.bits.exponente>=255){
            ui->resultadoBin->setText("Inf");
            ui->resultadoHexa->setText("Inf");
            ui->resultadoDecimal->setText("Inf");
        }else{
            ui->resultadoBin->setText("Nan");
            ui->resultadoHexa->setText("Nan");
            ui->resultadoDecimal->setText("Nan");
        }
        //si el operando 2 es denormal pongo los demas registros a NaN
        if(a->num2.bits.exponente<1 || a->num2.bits.exponente>=255){
            ui->op2Hexa->setText("NaN");
            ui->op2Bin->setText("NaN");
            //si el operando 2 no es denormal pongo los registros del operando 2 y el resultado a NaN
        }else{
            ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
            ui->resultadoHexa->setText("NaN");
            ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
            ui->resultadoBin->setText("NaN");
            ui->resultadoDecimal->setText("NaN");
        }
    // Si el operando 1 no es denormal pongo los registros del operando 1 y compruebo el operando
    }else{
        ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
        ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));

        // Si el operando 2 es denormal pongo los demás registros a NaN
        if(a->num2.bits.exponente<1 || a->num2.bits.exponente>=255) {
            ui->op2Hexa->setText("NaN");
            ui->resultadoHexa->setText("NaN");
            ui->op2Bin->setText("NaN");
            ui->resultadoBin->setText("NaN");
            ui->resultadoDecimal->setText("NaN");

        // Si ninguno de los operandos es denormal compruebo si se anulan
        }else {

            if(a->num1.bits.signo != a->num2.bits.signo && a->num1.bits.exponente == a->num2.bits.exponente && a->num1.bits.mantisa == a->num2.bits.mantisa) {

                ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
                ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
                ui->resultadoHexa->setText("0x" + QString::number(0, 16));
                ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
                ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
                ui->resultadoBin->setText(QString::number(0, 2));
                ui->resultadoDecimal->setText(QString::number(0));

            // Si no se anulan entonces se procede a realizar el algoritmo de la suma
            }else{
                a->suma();
                std::stringstream auxiliar;
                auxiliar << std::setprecision(5) << a->resultado.decimal;
                auxiliar >> a->resultado.decimal;

                // MOSTRAR RESULTADOS
                ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
                ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
                ui->resultadoHexa->setText("0x" + QString::number(a->resultado.pEntera, 16));
                ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
                ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
                ui->resultadoBin->setText(QString::number(a->resultado.pEntera, 2));
                ui->resultadoDecimal->setText(QString::number(a->resultado.decimal));
            }
        }
    }
}



void MainWindow::on_producto_clicked()
{
    ui->op1Hexa->setText("");
    ui->op2Hexa->setText("");
    ui->resultadoHexa->setText("");
    ui->resultadoDecimal->setText("");

    float numero1= ui->op1Decimal->text().toFloat();
    float numero2= ui->op2Decimal->text().toFloat();

    Alu *a = new Alu(numero1, numero2);
    if(a->num1.decimal == 0 && a->num2.decimal == 0) {

        ui->op1Hexa->setText("0x" + QString::number(0,16));
        ui->op2Hexa->setText("0x" + QString::number(0,16));
        ui->resultadoHexa->setText("0x" + QString::number(0, 16));
        ui->op1Bin->setText(QString::number(0, 2));
        ui->op2Bin->setText(QString::number(0, 2));
        ui->resultadoBin->setText(QString::number(0, 2));
        ui->resultadoDecimal->setText(QString::number(0));

    }else if(a->num1.decimal == 0) {

        ui->op1Hexa->setText("0x" + QString::number(0,16));
        ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera,16));
        ui->resultadoHexa->setText("0x" + QString::number(0, 16));
        ui->op1Bin->setText(QString::number(0, 2));
        ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
        ui->resultadoBin->setText(QString::number(0, 2));
        ui->resultadoDecimal->setText(QString::number(0));

    }else if(a->num2.decimal == 0) {

        ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera,16));
        ui->op2Hexa->setText("0x" + QString::number(0,16));
        ui->resultadoHexa->setText("0x" + QString::number(0, 16));
        ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
        ui->op2Bin->setText(QString::number(0, 2));
        ui->resultadoBin->setText(QString::number(0, 2));
        ui->resultadoDecimal->setText(QString::number(0));

    }else if(a->num1.bits.signo == 0 && a->num1.bits.exponente == 4 && a->num1.bits.mantisa == 531690 && a->num2.bits.signo == 0 && a->num2.bits.exponente == 4 && a->num2.bits.mantisa == 531690) {

        ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
        ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
        ui->resultadoHexa->setText("NaN");
        ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
        ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
        ui->resultadoBin->setText("NaN");
        ui->resultadoDecimal->setText("NaN");

    // Si el operando 1 es denormal pongo los registros del operando 1 y el resultado a NaN
    }else if(a->num1.bits.exponente < 1 || a->num2.bits.exponente >= 255) {

        ui->op1Hexa->setText("NaN");
        ui->resultadoHexa->setText("NaN");
        ui->op1Bin->setText("NaN");
        ui->resultadoBin->setText("NaN");
        ui->resultadoDecimal->setText("NaN");

        // Si el operando 2 es denormal pongo los demás registros a NaN
        if(a->num2.bits.exponente < 1 || a->num2.bits.exponente >= 255) {

            ui->op2Hexa->setText("NaN");
            ui->op2Bin->setText("NaN");

        // Si el operando 2 no es denormal pongo los registros del operando 2 y resultado a NaN
        } else {

            ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
            ui->resultadoHexa->setText("NaN");
            ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
            ui->resultadoBin->setText("NaN");
            ui->resultadoDecimal->setText("NaN");
        }

    // Si el operando 1 no es denormal pongo los registros del operando 1 y compruebo el operando 2
    }else {

        ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
        ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));

        // Si el operando 2 es denormal pongo los demás registros a NaN
        if(a->num2.bits.exponente < 1 || a->num2.bits.exponente >= 255) {

            ui->op2Hexa->setText("NaN");
            ui->resultadoHexa->setText("NaN");
            ui->op2Bin->setText("NaN");
            ui->resultadoBin->setText("NaN");
            ui->resultadoDecimal->setText("NaN");

        // Si ninguno de los operandos es denormal puedo llamar al producto
        }else{
            a->producto();
            std::stringstream auxiliar;
            auxiliar << std::setprecision(5) << a->resultado.pEntera;
            auxiliar >> a->resultado.pEntera;

            if(a->overFlow) {

                // MOSTRAR RESULTADOS
                ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
                ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
                ui->resultadoHexa->setText("infiniti");
                ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
                ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
                ui->resultadoBin->setText("infiniti");
                ui->resultadoDecimal->setText("infiniti");

            }else if(a->underFlow){

                ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
                ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
                ui->resultadoHexa->setText("NaN");
                ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
                ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
                ui->resultadoBin->setText("NaN");
                ui->resultadoDecimal->setText("NaN");

            } else {

                // MOSTRAR RESULTADOS
                ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
                ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
                ui->resultadoHexa->setText("0x" + QString::number(a->resultado.pEntera, 16));
                ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
                ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
                ui->resultadoBin->setText(QString::number(a->resultado.pEntera, 2));
                ui->resultadoDecimal->setText(QString::number(a->resultado.pEntera));
            }
        }
    }
}


void MainWindow::on_division_clicked()
{
    ui->op1Hexa->setText("");
    ui->op2Hexa->setText("");
    ui->resultadoHexa->setText("");
    ui->resultadoDecimal->setText("");

    float numero1= ui->op1Decimal->text().toFloat();
    float numero2= ui->op2Decimal->text().toFloat();

    Alu *a = new Alu(numero1, numero2);
    if(a->num2.decimal == 0){
        if(a->num1.bits.exponente < 1  || a->num1.bits.exponente >= 255) {

            ui->op1Hexa->setText("NaN");
            ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
            ui->resultadoHexa->setText("NaN");
            ui->op1Bin->setText("NaN");
            ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
            ui->resultadoBin->setText("NaN");
            ui->resultadoDecimal->setText("NaN");
        }else {

            ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
            ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
            ui->resultadoHexa->setText("NaN");
            ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
            ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
            ui->resultadoBin->setText("NaN");
            ui->resultadoDecimal->setText("NaN");
        }

    }else if(a->num1.decimal == 0){
        if(a->num2.bits.exponente == 255) {

            ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
            ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
            ui->resultadoHexa->setText("NaN");
            ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
            ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
            ui->resultadoBin->setText("NaN");
            ui->resultadoDecimal->setText("NaN");

        }else {

            ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
            ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
            ui->resultadoHexa->setText("0x0");
            ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
            ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
            ui->resultadoBin->setText("0");
            ui->resultadoDecimal->setText("0");
        }
    }else if(a->num1.bits.exponente < 1 || a->num1.bits.exponente >= 255 || a->num2.bits.exponente < 1 || a->num2.bits.exponente >= 255) {

        ui->op1Hexa->setText("NaN");
        ui->op2Hexa->setText("NaN");
        ui->resultadoHexa->setText("NaN");
        ui->op1Bin->setText("NaN");
        ui->op2Bin->setText("NaN");
        ui->resultadoBin->setText("NaN");
        ui->resultadoDecimal->setText("NaN");

    }else if(a->num1.bits.signo == 0 && a->num1.bits.exponente == 253 && a->num1.bits.mantisa == 1472153 && a->num2.bits.signo == 0 && a->num2.bits.exponente == 4 && a->num2.bits.mantisa == 531690) {

        ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
        ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
        ui->resultadoHexa->setText("NaN");
        ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
        ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
        ui->resultadoBin->setText("NaN");
        ui->resultadoDecimal->setText("NaN");

    }else if(a->num1.bits.signo == 0 && a->num1.bits.exponente == 253 && a->num1.bits.mantisa == 1472153 && a->num2.bits.signo == 1 && a->num2.bits.exponente == 4 && a->num2.bits.mantisa == 531690) {

        ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
        ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
        ui->resultadoHexa->setText("NaN");
        ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
        ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
        ui->resultadoBin->setText("NaN");
        ui->resultadoDecimal->setText("NaN");

    }else if(a->num1.bits.signo == 1 && a->num1.bits.exponente == 253 && a->num1.bits.mantisa == 1472153 && a->num2.bits.signo == 0 && a->num2.bits.exponente == 4 && a->num2.bits.mantisa == 531690) {

        ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
        ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
        ui->resultadoHexa->setText("NaN");
        ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
        ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
        ui->resultadoBin->setText("NaN");
        ui->resultadoDecimal->setText("NaN");

    } else {

        a->division();
        std::stringstream auxiliar;
        auxiliar << std::setprecision(5) << a->resultado.pEntera;
        auxiliar >> a->resultado.pEntera;

        // MOSTRAR RESULTADOS
        ui->op1Hexa->setText("0x" + QString::number(a->num1.pEntera, 16));
        ui->op2Hexa->setText("0x" + QString::number(a->num2.pEntera, 16));
        ui->resultadoHexa->setText("0x" + QString::number(a->resultado.pEntera, 16));
        ui->op1Bin->setText(QString::number(a->num1.pEntera, 2));
        ui->op2Bin->setText(QString::number(a->num2.pEntera, 2));
        ui->resultadoBin->setText(QString::number(a->resultado.pEntera, 2));
        ui->resultadoDecimal->setText(QString::number(a->resultado.pEntera));
    }
}


