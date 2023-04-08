#include "algoritmo.h"

Algoritmo::Algoritmo(QString Origen, QString Destino)
{

}

void Algoritmo::eliminarRep(){
    QFile archivo;

    while(!archivo.atEnd()){
        QByteArray lectura = archivo.readLine();
        lista.push_back(lectura);
        QStringList numeros;

        for (int i = 0; i<(int)lista.size();i++){
            numeros = lista[i].split(u' ', Qt::SkipEmptyParts);
            for(int j = 0; j<(int)numeros.size();j++){
                nums.push_back(numeros.at(j).toInt());
            }
        }
        for(int i = 1; i<(int)nums.size();i++){
            nums.erase(std::remove(nums.begin()+i,nums.end(),nums[i-1]),nums.end());
        }
    }
}
