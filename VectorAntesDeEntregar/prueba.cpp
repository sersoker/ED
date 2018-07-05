#include <vector>
#include <iostream>
#include <map>
#include "vectorD.h"

using namespace std;

int main(){

    vectorD<int> vector;
    vectorD<int> vector2(vector);

    cout <<"Tamaño del vector: "<< vector.size()<<endl;
//NO FUNCIONA+
	cout << "El valor por defecto "<<vector2.default_value()<<endl;

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
cout << endl;
	//Prueba Stored Iterator
     vectorD<int> vector3;
	 vector3.push_back(4);
	 vector3.push_back(5);
	 vector3.push_back(2);

cout << endl;
cout << "Stored iterator"<<endl<<endl;
cout << "begin"<<endl;
	 auto it1(vector3.sbegin());
	 cout << (*it1) << endl;
cout << "++"<<endl;
	 it1++;
	 cout << (*it1) << endl;
cout << "++"<<endl;
	 it1++;
     cout << (*it1) << endl;
cout << "++"<<endl;
	 it1++;
     cout << (*it1) << endl;
cout << "end"<<endl;
	 auto it3(vector3.send());
	 cout << (*it3) << endl;
	 
cout << endl;
cout << "Iterator"<<endl;
cout << "begin"<<endl;
	 auto it2(vector3.begin());
	 cout << (*it2) << endl;
cout << "++"<<endl;
	 it2++;
	 cout << (*it2) << endl;
cout << "++"<<endl;
	 it2++;
     cout << (*it2) << endl;
cout << "++"<<endl;
	 it2++;
     cout << (*it2) << endl;
cout << "end"<<endl;
	 auto it4(vector3.end());
	 cout << (*it4) << endl;

cout << endl;
	//Prueba const Stored Iterator
     vectorD<int> vector4;
	 vector4.push_back(9);
	 vector4.push_back(6);
	 vector4.push_back(48);

cout << endl;
cout << "const Stored iterator"<<endl<<endl;
cout << "begin"<<endl;
	 auto it11(vector4.csbegin());
	 cout << (*it11) << endl;
cout << "++"<<endl;
	 it11++;
	 cout << (*it11) << endl;
cout << "++"<<endl;
	 it11++;
     cout << (*it11) << endl;
cout << "++"<<endl;
	 it11++;
     cout << (*it11) << endl;
cout << "end"<<endl;
	 auto it31(vector4.csend());
	 cout << (*it31) << endl;
	 
cout << endl;
cout << "const Iterator"<<endl;
cout << "begin"<<endl;
	 auto it21(vector4.cbegin());
	 cout << (*it21) << endl;
cout << "++"<<endl;
	 it21++;
	 cout << (*it21) << endl;
cout << "++"<<endl;
	 it21++;
     cout << (*it21) << endl;
cout << "++"<<endl;
	 it21++;
     cout << (*it21) << endl;
cout << "end"<<endl;
	 auto it41(vector4.cend());
	 cout << (*it41) << endl;



}
