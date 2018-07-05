#include "diccionario.h"
#include <iostream>
#include "meteorito.h"
#include <fstream>

using namespace std;
 


using namespace std;

/** @brief Convierte una fila del fichero de datos en un meteorito
 * @param m meteorito de salida
 * @param s cadena representando una entrada del fichero meteorites_all
 * El formato de la linea de entrada es un csv, donde los campos se separan por ;
 * \code
name;recclass;mass;fall;year;reclat;reclong
Aachen;L5,H6;21;Fell;1880;50,775;6,08333
Aarhus;H6;720;Fell;1951;56,18333;10,23333
Abee;EH4;107000;Fell;1952;54,21667;-113
Acapulco;Acapulcoite;1914;Fell;1976;16,88333;-99,9
\endcode
 */

meteorito string2meteorito( const string  & s){
string::size_type pyc,ini=0;
string::size_type coma, cini;
string codigos;
double valor=0.0;
bool fin;
meteorito m;

 pyc = s.find_first_of (";"); //Nombre
 m.first = s.substr(ini,pyc-ini); 
// cout <<"nombre "<< ini << " " << pyc<< ":: "<< m.first << endl;

 ini = pyc+1;
 pyc = s.find_first_of(";",ini); //Codigos
 
 codigos = s.substr(ini,pyc-ini);
 cini=0;
 fin = false;
 coma = codigos.find_first_of(",",cini );
 do {
   m.second.setCode(codigos.substr(cini,coma-cini));
   if (coma!=string::npos){  
      cini = coma+1;
      coma = codigos.find_first_of(",",cini);
   } else fin =true;
  
 } while (!fin);
 

 ini =pyc+1;
 pyc = s.find_first_of(";",ini); //masa
 string masa = s.substr(ini,pyc-ini);
 if (masa!="") {// No es ;;    
    cini = masa.find_first_of(","); // Cambio coma  por punto decimal
    if (cini!=string::npos)
      masa[cini]='.';
    valor =stod(masa);
   }
 m.second.setMas(valor);
 
 
 ini =pyc+1;
 pyc = s.find_first_of(";",ini); //Fell

 if (s.substr(ini,pyc-ini) == "Found")
   m.second.setFall(true);
 else m.second.setFall(false);
		    

 ini =pyc+1;
 pyc = s.find_first_of(";",ini); //año
 
 m.second.setYear(s.substr(ini,pyc-ini));
 
 valor =0.0;

 ini =pyc+1;
 pyc = s.find_first_of(";",ini); //latitud
 string lat = s.substr(ini,pyc-ini);
 if (lat!=""){
 cini = lat.find_first_of(","); // Cambio coma  por punto decimal
 if (cini!=string::npos)
    lat[cini]='.';
  valor = stod(lat);
 }
 m.second.setLat(valor);
 
 valor =0.0;
 ini =pyc+1;
 pyc = s.find_first_of(";",ini); //longitud

 string longitud = s.substr(ini,pyc-ini);
 if (longitud!="") {
  cini = longitud.find_first_of(","); // Cambio coma  por punto decimal
  if (cini!=string::npos) longitud[cini]='.';
  valor = stod(longitud);
 }
 m.second.setLong(valor);	

return m;
}


/** @brief Carga el diccionario en memoria
 * @param d diccionario de salida
 * @param s nombre del fichero 
 */
void load(diccionario &  D, const string & s) {
 ifstream fe;
 string cadena;
 meteorito m;
 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail())    
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   cout << cadena << endl;
    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	   cout << "leo:: "<< cadena << endl;
	   m = string2meteorito(cadena);
	   D.insert(m);
         }
     }
   
    } // else
  fe.close();
 }
 
 void nada(const diccionario & d){
   cout << "Entro en nada "<< endl;
   cout << d["Coleman"]<< endl;
   cout << d["Murcia"]<< endl;
 }


int main()
{int x;

  diccionario D, MET;
  
  
    
   load(MET,"meteorito_breve.csv");
    cout << MET << endl;
    cout << "Hay " << MET.size() << " elementos"<<endl;

    cout << MET["Bununu"] << endl;
    
    cout << MET["Granada"] <<endl;
    
    cout << "Hay " << MET.size() << " elementos"<<endl;

    nada(MET);
   return 0;
}
