#ifndef IMAGEN_H
#define IMAGEN_H

#include <QMainWindow>
#include <QFileDialog>
#include <iostream>
#include <QString>

namespace Ui {
class imagen;
}

class imagen : public QMainWindow
{
    Q_OBJECT

public:
    explicit imagen(QWidget *parent = nullptr);
    ~imagen();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::imagen *ui;
    QString origen;
    QString destino;
};

#endif // IMAGEN_H
