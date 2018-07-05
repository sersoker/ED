/*
 * meteorito.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aaron Rodríguez Bueno

*/

#include "diccionario.h"
#include <iostream>
#include "meteorito.h"
#include <fstream>
#include <list>
#include <string>
#include <map>

using namespace std;

/** @brief Dada una línea, obtiene el campo año (en nuestro caso, el 5ª campo delimitado por ;)
@param[in] string que contiene la línea
@param[out] string del campo año
@return el campo año
*/

string sacaAnios(const string  & s){
string::size_type pyc,ini=0;
string::size_type coma, cini;
string codigos;
double valor=0.0;
bool fin;
string m;

 pyc = s.find_first_of (";"); //Nombre
 ini = pyc+1;
 pyc = s.find_first_of(";",ini); //Codigos
 ini =pyc+1;
 pyc = s.find_first_of(";",ini); //masa
 ini =pyc+1;
 pyc = s.find_first_of(";",ini); //fall
 ini =pyc+1;
 pyc = s.find_first_of(";",ini); //año

 //cout << s.substr(ini,pyc-ini);

return s.substr(ini,pyc-ini);

}




/** @brief Obtiene el diccionario teniendo en cuenta el año de caida del meteorito
@param[in] nombre_fichero que contiene el conjunto de meteoritos
@param[out] met_anio número de meteoritos clasificados por año de caida.
@return el año con más caidas.
*/
string caidos_por_anio(const string & nombre_fichero, diccionario<string,int> & met_anio){
 ifstream fe;
 string cadena;
 list<string> mimapa;
 string cuentaAnios;
 string compara;
 int cantidad=0;

cout << "Abrimos "<< nombre_fichero << endl;

 fe.open(nombre_fichero.c_str(), ifstream::in);
 if (fe.fail())
 {
   cerr << "Error al abrir el fichero " << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   cout << cadena << endl;
    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {

        compara = sacaAnios(cadena);
        //cout << compara << " entra \n";
        mimapa.push_back(compara);

     }

    }
  fe.close();
}
for(auto it = mimapa.begin(); it != mimapa.end(); ++it ) {
        int contador=0;

        for (auto it2 = mimapa.begin(); it2 != mimapa.end(); ++it2){
            if (*it==*it2){
                contador++;
            }
        if (contador>=cantidad){
            cantidad=contador;
            cuentaAnios=*it;
        }
    }
}
return cuentaAnios;
}



/** @brief Obtiene una línea (string) y un diccionario<string,list<nombreM>>.
Mira el string: si está en el diccionario, inserta el nombre en list<nombreM> en la zona de dicho string
                si no está, crea una nueva entrada en el diccionario e inserta el nombre en la lista
@param[in] const string & s es la línea del archivo
@param[in] diccionario<string,list<nombreM>> & tipos es el diccionario en el que se inserta el nombre o la entrada completa
*/

// el insert no funciona para V2, y no se por que.
void string2par(const string & s, diccionario<string,list<nombreM> > & tipos){
string::size_type pyc,ini=0;
string::size_type coma, cini;
string codigos;
double valor=0.0;
bool fin;
pair<string,list<nombreM>> m;
string aux;
string nombre;

// Busco el nombre
 pyc = s.find_first_of (";"); //Nombre
 nombre=s.substr(ini,pyc-ini);
 ini = pyc+1;
 pyc = s.find_first_of(";",ini); //Codigos

 codigos = s.substr(ini,pyc-ini);
 cini=0;
 fin = false;
 coma = codigos.find_first_of(",",cini );

 do {
       aux= codigos.substr(cini,coma-cini);

       //cout << "codigo: " << aux << " nombre: "<< nombre<<endl;
       auto encontrado= tipos.find(aux);
       //cout << "encontrado es: " << encontrado.second << endl;

       if (!encontrado.second){
        m.first=aux;
        m.second.push_back(nombre);
        tipos.insert(m);
        cout << "No existe referencia, se añade: " << aux << " Y se añade nombre: " << nombre << endl;
       }
       else{
            encontrado.first.second.push_back(aux);
            cout << "Ya existe referencia, se añade nombre: " << nombre<< endl;
       }

       if (coma!=string::npos){
          cini = coma+1;
          coma = codigos.find_first_of(",",cini);
       } else fin =true;


 } while (!fin);
}


/** @brief organiza el conjunto de meteoritos por tipologia
@param[in] nombre_fichero que contiene el conjunto de meteoritos
@param[out] tipos un diccionario donde para cada tipo de meteorito se almacena la lista de todos los nom
Recordemos que el diccionario tiene clave unica, por tanto no puede haber elementos con clave repetida.
Por este motivo, y dado que la tipologia del meteorito se repite por las distintas entradas del fichero,
se tendrá para cada una de las mismas una lista con los nombres de meteoritos.
*/
void listaTipos( const string & nombre_fichero, diccionario<string,list<nombreM> > & tipos){
 ifstream fe;
 string cadena;
 pair<string,list<nombreM>> m;
 cout << "Abrimos "<< nombre_fichero << endl;

 fe.open(nombre_fichero.c_str(), ifstream::in);
 if (fe.fail())
 {
   cerr << "Error al abrir el fichero " << nombre_fichero << endl;
 } else {
   getline(fe,cadena,'\n'); //leo la cabecera del fichero
   cout << cadena << endl;
    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
        //cout << "leo:: "<< cadena << endl;
        string2par(cadena, tipos);
         }
     }

    } // else
  fe.close();


}
/** @brief Obtiene el diccionario teniendo en cuenta el año de caida del meteorito
*/


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
void load(diccionario<nombreM,defM> &  D, const string & s) {
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


void tipos() {
    cout <<"entra en tipos" << endl;
    list <nombreM> ejemplo1;
    string s1="clave";

    nombreM nombre1,nombre2,nombre3;

    nombre1="meteo1";
    nombre2="meteo2";
    nombre3="meteo3";

    ejemplo1.push_back(nombre1);
    ejemplo1.push_back(nombre2);
    ejemplo1.push_back(nombre3);


    diccionario<string,list<nombreM>> exa;

    pair <string,list<nombreM>> par;

    par.first=s1;
    par.second=ejemplo1;

    exa.insert(par);
    cout << exa.empty() << endl;
    cout << exa.size() << endl;
        cout <<"completa tipos" << endl;

}

void met_anio(){
    cout <<"entra en met anio" << endl;
    diccionario<string,int> anio;
    string s1="me1", s2="me2", s3="me3";
    int i1=1991,i2=2009,i3=2003;

    pair <string, int> par;

    par.first=s1; par.second=i1;
    anio.insert(par);
    par.first=s2; par.second=i2;
    anio.insert(par);
    par.first=s3; par.second=i3;
    anio.insert(par);

    cout << anio.empty()<< endl;
    cout << anio.size() << endl;
        cout <<"completa met anio" << endl;
}


int main(){

//tipos();
//met_anio();

diccionario<string,list<nombreM>> LTipo;
diccionario<string,int> CPAnio;

listaTipos("listatipos.csv",LTipo);
cout << "Se han insertado en orden: " << endl << LTipo << endl;

auto caidos=caidos_por_anio("listatipos.csv",CPAnio);

cout << "El año que mas han caido ha sido: "<<caidos << endl;;


/*
diccionario<nombreM,defM> MET;

   load(MET,"meteorites_all.csv");

   cout << MET.size();
*/

}
