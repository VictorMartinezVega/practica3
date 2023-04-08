#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <QString>
#include <vector>
#include <QFileDialog>
#include <iostream>
#include <QDialog>
#include <QStringList>
using namespace std;
class Algoritmo
{
public:
    Algoritmo(QString Origen, QString Destino);
    ~Algoritmo();

    void eliminarRep();

private:
    QString Origen;
    QString Destino;
    vector<QString> lista;
    vector<int> nums;
};

#endif // ALGORITMO_H
