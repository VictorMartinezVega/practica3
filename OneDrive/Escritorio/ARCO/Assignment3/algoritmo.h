#ifndef ALGORITMO_H
#define ALGORITMO_H

#include <QString>
#include <vector>
#include <QFileDialog>
#include <iostream>
#include <QDialog>
#include <QStringList>
#include <QTextStream>
#include <time.h>

using namespace std;
class Algoritmo
{
public:
    Algoritmo(QString origen, QString destino);
    ~Algoritmo();

    void eliminarRep();
    double media();
    void clear();
    int  getLength();

private:
    QString origen;
    QString destino;
    vector<QString> lista;
    vector<int> nums;
    vector<double> tiempo;


};

#endif // ALGORITMO_H
