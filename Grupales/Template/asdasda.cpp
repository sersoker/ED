/*
 * meteorito.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aaron Rodríguez Bueno

*/

#include "diccionario.h"
#include <iostream>
#include<fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

void load(diccionario & d, const string & s){
    //cargamos el fichero y lo metemos en una variable
    ifstream fin("meteorites_all.csv");
    //declaramos las variables string necesarias para crear los meteoritos
    string dato;
    string name,recclass,mass,fall,year,reclat,reclong;
    int valor=0;
    char aux;
    //bucle mientras existan datos
    while (fin.good())
    {

        aux=fin.get();

       if (aux!=';'&&aux!='\n')
            dato=dato+aux;

        else{
              switch ( valor ) {
              case 0:
                name=dato;
                dato.clear();
                valor++;
                break;
              case 1:
                recclass=dato;
                dato.clear();
                valor++;
                break;
              case 2:
                mass=dato;
                dato.clear();
                valor++;
                break;
              case 3:
                fall=dato;
                dato.clear();
                valor++;
                break;
              case 4:
                year=dato;
                dato.clear();
                valor++;
                break;
              case 5:
                reclat=dato;
                dato.clear();
                valor++;
                break;
              case 6:
                reclong=dato;
                dato.clear();
                valor=0;
                //creamos el meteorito
                for (int i=0;i<reclong.length();i++){
                    if (reclong[i]==',')
                        reclong[i]='.';
                }
                for (int i=0;i<reclat.length();i++){
                    if (reclat[i]==',')
                        reclat[i]='.';
                }
                cout << "Nombre:"<<name<<"Reclass:" <<recclass<<"Mass:" << mass<<"Fall:" << fall<<"Year:" << year<<"Reclat:" << reclat<< "Reclong:" << reclong<<endl;
                string cosa="Fell";
                bool caida = false;
                if (fall==cosa) caida=true;


                defM meteoro;
                    meteoro.setCode(recclass); meteoro.setMas(atof(mass.c_str()));
                    meteoro.setFall(caida);meteoro.setYear(year);
                    meteoro.setLat(atof(reclat.c_str()));meteoro.setLong(atof(reclong.c_str()));
                nombreM nombreMeteoro=name;
                meteorito m;
                m.first=nombreMeteoro; m.second=meteoro;
                d.insert(m);
                break;
              }
        }

    }
}

int main()
{

    diccionario<int,int> Meteoritos;
    //load(Meteoritos, "meteorites_all.csv");


}
