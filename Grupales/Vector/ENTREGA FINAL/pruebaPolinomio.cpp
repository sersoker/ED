#include <vector>
#include <iostream>
#include <map>
#include "polinomio.h"

using namespace std;

int main(){

    Polinomio pol1;

    cout <<"Grado del pol1: "<< pol1.grado()<<endl;

    //Comprobar que no hace un assign si se sale de rango

	pol1.assign(0,1);

	//Comprobar assign si insertas un valor no nulo en una posición donde hay otro valor no nulo

	pol1.push_back(2);
	pol1.assign(0,1);

    Polinomio pol2(pol1);

	//Comprobar assign si insertas un valor no nulo en una posición donde hay un valor nulo

	pol1.push_back(0);
	pol1.assign(1,1);

	//Comprobar assign si insertas un valor nulo en una posición donde hay un valor no nulo

    pol1.push_back(1);
	pol1.assign(2,0);

	cout << "Mirando el contenido [] de la posicion 0, es :"<<pol1.coeficiente(0)<<endl;

    Polinomio pol3;
    pol3.push_back(1);

	//Prueba Stored Iterator
     Polinomio pol13;
	 pol13.push_back(4);
	 pol13.push_back(5);
	 pol13.push_back(2);

cout << endl;
cout << "Stored iterator"<<endl<<endl;
cout << "begin"<<endl;
	 auto itp1(pol13.sbegin());
	 cout << (*itp1) << endl;
cout << "++"<<endl;
	 itp1++;
	 cout << (*itp1) << endl;
cout << "++"<<endl;
	 itp1++;
     cout << (*itp1) << endl;
cout << "++"<<endl;
	 itp1++;
     cout << (*itp1) << endl;
cout << "end"<<endl;
	 auto itp3(pol13.send());
	 cout << (*itp3) << endl;

cout << endl;
cout << "Iterator"<<endl;
cout << "begin"<<endl;
	 auto itp2(pol13.begin());
	 cout << (*itp2) << endl;
cout << "++"<<endl;
	 itp2++;
	 cout << (*itp2) << endl;
cout << "++"<<endl;
	 itp2++;
     cout << (*itp2) << endl;
cout << "++"<<endl;
	 itp2++;
     cout << (*itp2) << endl;
cout << "end"<<endl;
	 auto itp4(pol13.end());
	 cout << (*itp4) << endl;

cout << endl;
	//Prueba const Stored Iterator
     Polinomio pol14;
	 pol14.push_back(9);
	 pol14.push_back(6);
	 pol14.push_back(48);

cout << endl;
cout << "const Stored iterator"<<endl<<endl;
cout << "begin"<<endl;
	 auto itp11(pol14.csbegin());
	 cout << (*itp11) << endl;
cout << "++"<<endl;
	 itp11++;
	 cout << (*itp11) << endl;
cout << "++"<<endl;
	 itp11++;
     cout << (*itp11) << endl;
cout << "++"<<endl;
	 itp11++;
     cout << (*itp11) << endl;
cout << "end"<<endl;
	 auto itp31(pol14.csend());
	 cout << (*itp31) << endl;

cout << endl;
cout << "const Iterator"<<endl;
cout << "begin"<<endl;
	 auto itp21(pol14.cbegin());
	 cout << (*itp21) << endl;
cout << "++"<<endl;
	 itp21++;
	 cout << (*itp21) << endl;
cout << "++"<<endl;
	 itp21++;
     cout << (*itp21) << endl;
cout << "++"<<endl;
	 itp21++;
     cout << (*itp21) << endl;
cout << "end"<<endl;
	 auto itp41(pol14.cend());
	 cout << (*itp41) << endl;

Polinomio polinomio1;
polinomio1.push_back(2);
polinomio1.push_back(0);
polinomio1.push_back(5);

cout << endl<<"Polinomio1: ";
int tamanio=polinomio1.grado();
for (int i = 0; i <= tamanio; i++){
    cout << polinomio1.coeficiente(i)<<"x^"<<i << " ";
}
cout << endl;

Polinomio polinomio2;
polinomio2.push_back(0);
polinomio2.push_back(3);
polinomio2.push_back(5);
polinomio2.push_back(7);

cout << endl<<"Polinomio2: ";
tamanio=polinomio2.grado();
for (int i = 0; i <= tamanio; i++){
    cout << polinomio2.coeficiente(i)<<"x^"<<i << " ";
}
cout << endl;

polinomio1+polinomio2;
cout << endl <<"Suma de polinomios"<<endl;
tamanio=polinomio1.grado();
for (int i = 0; i <= tamanio; i++){
    cout << polinomio1.coeficiente(i)<<"x^"<<i<<" ";
}

cout << endl;

Polinomio polinomio3;
polinomio3.push_back(5);
polinomio3.push_back(0);
polinomio3.push_back(0);
polinomio3.push_back(8);
polinomio3.push_back(2);

cout << endl<<"Polinomio3: ";
tamanio=polinomio3.grado();
for (int i = 0; i <= tamanio; i++){
    cout << polinomio3.coeficiente(i)<<"x^"<<i << " ";
}

cout << endl;

polinomio1-polinomio3;
cout << endl <<"Resta de polinomios"<<endl;
tamanio=polinomio1.grado();
for (int i = 0; i <= tamanio; i++){
    cout << polinomio1.coeficiente(i)<<"x^"<<i<<" ";
}
cout << endl;
}
