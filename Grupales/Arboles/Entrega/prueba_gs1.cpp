#include <iostream>
#include <set>
#include <unordered_set>
#include <iostream>
#include "gs1Set.h"
#include <fstream>
#include<list>

/** @brief Carga el fichero en memoria
 * @param contenedor contenedor de salida
 * @param s nombre del fichero
 * @pre T debe tener el método insert(const string &)
 */
template <typename T>
void load(T  &  contenedor, const string & s) {
 ifstream fe;
 string cadena;
 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail())
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {

    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	 //  cout << "leo:: "<< cadena << endl;

	   contenedor.insert(cadena);
         }
     }

    } // else
  fe.close();
 }


 int main(int argc, char *argv[]){

    if (argc !=2) {
        cout << "formato: nombre_ejecutable datos.txt" << endl;
        exit(1);
    }
    list <string> codigos;
    list <string>::const_iterator it_lista;
    string nfichero = string(argv[1]), prueba;
    set<string> s;
    unordered_set<string> us_codigo;
    gs1Set gs1,gs2;
    /* Insercion de elementos en los tres ficheros */

    //load(us_codigo,nfichero);
    //load(s,nfichero);
    //load(gs1,nfichero);
    //Comprobamos empty
    if(gs1.empty())
        cout << "El arbol esta vacio"<<endl;
    else
        cout << "El arbol no esta vacio"<<endl;
    //Comprobación del insert
    gs1.insert("(00)4520669358005(37)3046598");
    gs1.insert("(00)4520669358005(37)3046597");
    gs1.insert("(00)4520669358005(36)3046597");
    gs1.insert("(00)4520669358005(36)3046597");
    //gs1.print();
    if(gs1.empty())
        cout << "El arbol esta vacio"<<endl;
    else
        cout << "El arbol no esta vacio"<<endl;
    //Comprobamos operator=
    gs2=gs1;
    gs2.print();
    //Comprobamos constructor de copia
    gs1Set gs3(gs1);
    gs3.print();
    //Comprobamos size
    cout <<"Tamaño del arbol antes del erase: "<< gs2.size()<<endl;
    //Comprobación del find
    auto pepe = gs1.find(prueba);
    prueba = "(00)45206693580";
    cout << "Hemos buscado: "<<prueba<<endl;
    cout << "find ha encontrado: "<<(*pepe)<<endl;
    prueba = "(08)21423";
    cout << "Hemos buscado: "<<prueba<<endl;
    cout << "find ha encontrado: "<<(*pepe)<<endl;
    //Comprobamos erase
    prueba = "(00)4520669358005(37)3046598";
    cout << "Eliminamos codigos con el subcodigo: "<<prueba<<endl;
    cout << "Nº elementos borrados: "<< gs2.erase(prueba)<<endl;
    gs2.print();
    cout <<"Tamaño del arbol después del erase: "<< gs2.size()<<endl;
    //Comprobamos codesWithPrefix
    prueba = "(00)452066935";
    cout << "Códigos con el prefijo: "<<prueba<<endl;
    codigos = gs2.codesWithPrefix(prueba);
    for (it_lista=codigos.cbegin();it_lista!=codigos.cend();it_lista++){
        cout << *it_lista<<endl;
    }

    //Comprobamos begin y end
    cout << "Begin: "<<*gs1.begin()<<endl;
    cout << "End: " << *gs1.end()<<endl;

    cout << "--------------------"<<endl;
    cout << "-----ITERADORES-----"<<endl;
    cout << "--------------------"<<endl;

    //Prueba constructor de copia
    gs1Set::const_iterator prueba_it(gs1.begin());
    cout <<(*prueba_it) <<endl;
    //Prueba constructor por defecto
    gs1Set::const_iterator prueba_it2;
    //Prueba operator == y !=
    if (prueba_it==prueba_it2)
        cout << "los dos iteradores son iguales"<<endl;
    else
        cout << "Los dos iteradores son diferentes"<<endl;

    if (prueba_it!=prueba_it2)
        cout << "los dos iteradores son diferentes"<<endl;
    else
        cout << "Los dos iteradores son iguales"<<endl;
    //Prueba operator=
    prueba_it2=prueba_it;
    if (prueba_it==prueba_it2)
        cout << "los dos iteradores son iguales"<<endl;
    else
        cout << "Los dos iteradores son diferentes"<<endl;

    if (prueba_it!=prueba_it2)
        cout << "los dos iteradores son diferentes"<<endl;
    else
        cout << "Los dos iteradores son iguales"<<endl;
    cout <<(*prueba_it2) <<endl;
    //Prueba operator++
    prueba_it++;
    cout <<(*prueba_it) <<endl;
    //Prueba el otro operator++
    ++prueba_it;
    cout <<(*prueba_it) <<endl;
    //Prueba upper_IA
    prueba_it.upper_IA();
    cout <<(*prueba_it) <<endl;
    prueba_it.upper_IA();
    cout <<(*prueba_it) <<endl;
    prueba_it.upper_IA();
    cout <<(*prueba_it) <<endl;
    prueba_it++;
    cout <<(*prueba_it) <<endl;
    ++prueba_it;
    cout <<(*prueba_it) <<endl;
    prueba_it++;
    cout <<(*prueba_it) <<endl;
    prueba_it++;
    //Comprobacion de si funcionan bien en el final
    cout <<(*prueba_it) <<endl;
    prueba_it++;
    cout <<(*prueba_it) <<endl;
    ++prueba_it;
    cout <<(*prueba_it) <<endl;
    //Puse el cheq_rep en public solo para probarlo, luego lo volvi a poner private
/*
    if (gs1.cheq_rep())
        cout << "El arbol está correcto"<<endl;
    else
        cout << "El arbol NO está correcto"<<endl;
*/
 }
