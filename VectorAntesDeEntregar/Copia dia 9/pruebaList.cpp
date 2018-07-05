#include <vector>
#include <iostream>
#include <map>
#include <list>
#include "vectorDList.h"

using namespace std;

int main(){

    vectorD<int> vector;
    vectorD<int> vector2(vector);

    cout <<"Tamaño del vector: "<< vector.size()<<endl;
//NO FUNCIONA+
	cout <<"El valor por defecto es:"<< vector2.default_value()<<endl;

	if(vector.empty())
		cout<< "Esta vacio"<<endl;
	else
		cout << "No esta vacio"<<endl;

    //Comprobar que no hace un assign si se sale de rango

	vector.assign(0,1);

	//Comprobar assign si insertas un valor no nulo en una posición donde hay otro valor no nulo

	vector.push_back(2);
	vector.assign(0,1);

	//Comprobar assign si insertas un valor no nulo en una posición donde hay un valor nulo

	vector.push_back(0);
	vector.assign(1,1);

	//Comprobar assign si insertas un valor nulo en una posición donde hay un valor no nulo

    vector.push_back(1);
	vector.assign(2,0);

    if(vector.empty())
		cout<< "Esta vacio"<<endl;
	else
		cout << "No esta vacio"<<endl;

	cout << "Mirando el contenido [] de la posicion 0, es :"<<vector[0]<<endl;
	cout << "Mirando el contenido [] de la posicion 9, es :"<<vector[9]<<endl;

	cout << "Mirando el contenido at de la posicion 2, es :"<<vector.at(2)<<endl;
	cout << "Mirando el contenido at de la posicion 8, es :"<<vector.at(8)<<endl;

	vector.pop_back();
	vector.pop_back();

	if(vector==vector2)
		cout << "Son iguales"<<endl;
	if(vector!=vector2)
		cout << "Son distintos"<<endl;


	cout << "Haciendo clear"<<endl;
	vector.clear();
	cout <<"Tamaño del vector: "<< vector.size()<<endl;


	if(vector==vector2)
		cout << "Son iguales"<<endl;
	if(vector!=vector2)
		cout << "Son distintos"<<endl;







}
