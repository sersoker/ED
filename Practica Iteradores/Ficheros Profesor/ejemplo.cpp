#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main(){

vector<pair<string,int> > V; 
pair<string,int> aux("Hola",2);
pair<string,int> * p_e;
pair<const string,int> * p_vt;

V.push_back(aux);

p_e = &V[0]; // tomamos la direccion del primer elemento del vector
cout << (*p_e).first << (*p_e).second<< endl;
(*p_e).first = "XXXX"; //Correcto 

p_vt = (pair<const string,int> *) &V[0];
cout << (*p_vt).first << (*p_vt).second<< endl;
(*p_vt).second = 234;
cout << (*p_vt).first << (*p_vt).second<< endl;
(*p_vt).first = "XXXX"; //INCORRECTO
}
