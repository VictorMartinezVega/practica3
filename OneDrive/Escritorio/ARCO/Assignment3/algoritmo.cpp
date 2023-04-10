#include "algoritmo.h"

Algoritmo::Algoritmo(QString origen, QString destino)
{

}

void Algoritmo::eliminarRep(){
    QFile archivo;
    QFile archivoOrigen(origen);
    QFile archivoDestino(destino);
    if(!archivoOrigen.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }

    while(!archivo.atEnd()){
        QByteArray lectura = archivo.readLine();
        lista.push_back(lectura);
    }
    QStringList numeros;

    for(int i = 0; i<(int)lista.size();i++){
        numeros = lista[i].split(u' ', Qt::SkipEmptyParts);
        for(int j = 0; j<(int)numeros.size();j++){
            nums.push_back(numeros.at(j).toInt());
        }
    }
    clock_t inicio = clock();
    for(int i = 1; i<(int)nums.size();i++){
        nums.erase(std::remove(nums.begin()+i,nums.end(),nums[i-1]),nums.end());
    }
    clock_t fin = clock();
    double tiempoEjecucion = (double) (fin - inicio) / CLOCKS_PER_SEC;
    tiempo.push_back(tiempoEjecucion);
    if(!archivoDestino.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }

    for(int i = 1; i<(int)nums.size();i++){
        QTextStream salida(&destino);
        salida<<nums[i]<< " ";
    }

}

void Algoritmo::clear(){
    tiempo.clear();
}

double Algoritmo::media(){
    double media = 0;
    for(int i = 0; i<(int)tiempo.size();i++){
        media += tiempo[i];
    }
    media /= (int)tiempo.size();
    return media;
}

int Algoritmo::getLength(){
    return (int)tiempo.size();
}








