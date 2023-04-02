#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <QString>

using namespace std;

namespace Ui {
class ventana;
}

class ventana : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventana(QWidget *parent = nullptr);
    ~ventana();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ventana *ui;
    QString origen;
    QString destino;
};

#endif // VENTANA_H
