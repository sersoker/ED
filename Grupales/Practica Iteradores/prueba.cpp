#include <vector>
#include <iostream>
#include <map>
#include "diccionario.h"

using namespace std;

int main(){

diccionario<string,int> dicci;
pair<string,int> entry1;
entry1.first="Hola";
entry1.second=1;

pair<string,int> entry2;
entry2.first="Que tal";
entry2.second=2;

pair<string,int> entry3;
entry3.first="Adios";
entry3.second=3;

dicci.insert(entry1);
dicci.insert(entry2);
dicci.insert(entry3);

diccionario<string,int>::iterator it1 (dicci.begin());
diccionario<string,int>::iterator it2 (dicci.end());
diccionario<string,int>::const_iterator it3;

cout << (*it1).first << (*it1).second << endl;
it2=it1++;
if( it2==it2)
    cout << "Son el mismo" << endl;
if( it2!=it1)
    cout << "Son distintos" << endl;

it2=++it1;
if( it2==it1)
    cout << "Son el mismo 2" << endl;

cout << (*it2).first << (*it2).second << endl ;
(*it2).second = 5;
cout << (*it2).first << (*it2).second << endl ;

it3=diccionario<string,int>::const_iterator(it1);
cout << (*it3).first << (*it3).second << endl ;
//(*it3).second=6;   //Sale error

}







