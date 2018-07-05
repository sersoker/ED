/*
 * meteorito.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aaron Rodríguez Bueno
*/

#ifndef __METEORITO_H
#define __METEORITO_H

#include <string>
#include <iostream>
#include <vector>


using namespace std;
//! Clase defM, asociada a la definición de un meteorito
/*! defM::defM .....
 * Descripción contiene toda la información asociada a un meteorito.

* Un meteorito es un contenedos que permite almacenar un conjunto de pares de elementos
, el primero será el nombre del meteorito y el segundo la definición (que contiene todos los datos del meteorito)
 Va a tener un subconjunto de métodos (inserción de elementos, consulta de un elemento ).


 */

class defM {
 public:
 	/** @brief constructor primitivo.
	*/
  defM();

  	/** @brief constructor de copia
	@param[in] x diccionario a copiar
	*/
  defM(const defM & x);

  /** @brief Define la entrada "code"
@param s entrada a definir
@return true si la entrada se ha podido insertar con éxito. False en caso contrario
@post 	 El valor sera cambiado por el nuevo.
*/
  bool setCode(const string & s);

   /** @brief Define la entrada "masa"
@param m entrada a definir
@post 	 El valor sera cambiado por el nuevo.
*/
  void setMas(const double &  m);

    /** @brief Define la entrada "fall"
@param f entrada a definir
@post 	 El valor sera cambiado por el nuevo.
*/
  void setFall(bool f);

     /** @brief Define la entrada "year"
@param y referencia de entrada a definir
@post 	 El valor sera cambiado por el nuevo.
*/
  void setYear(const string & y);

      /** @brief Define la entrada "latitud"
@param lat referencia de entrada a definir
@post 	 El valor sera cambiado por el nuevo.
*/
  void setLat(const double & lat);

      /** @brief Define la entrada "longitud"
@param longi referencia de  entrada a definir
@post 	 El valor sera cambiado por el nuevo.
*/
  void setLong(const double & longi);

    /** @brief Devuelve los codigos
@return Vector de codigos de meteoritos.
*/
  vector<string> getCodes( );

/** @brief Devuelve la masa del meteorito
@post  No se modifica la masa.
*/
  double getMas( );

	/** @brief Devuelve si ha caido el meteorito
	@return true si ha caido. False en caso contrario
	@post  No se modifica el valro.
*/
  bool getFall( );

  	/** @brief Devuelve el año
	@return string con la fecha
	@post  No se modifica el año.
*/
  string getYear( );

    /** @brief Devuelve el latitud
	@post  No se modifica la latitud.
*/
  double getLat( );

    /** @brief Devuelve el longitud
	@post  No se modifica la longitud.
*/
  double getLong( );
 private:
 /** @brief imprime todas las entradas de la definicion de meteorito
@post  No se modifica el meteorito.

	*/
    friend  ostream& operator<< ( ostream& , const defM & );
    vector<string> codigo;
    double masa;
    bool caida;
    string anio;
    double latitud;
    double longitud;

};

/** @brief definicion del tipo de dato nombreM
	*/

typedef string nombreM;
/** @brief definicion del tipo par nombreM y defM
	*/

typedef pair<nombreM,defM> meteorito;
/** @brief imprime todas las entradas de un meteorito
@post  No se modifica el meteorito.

	*/
ostream & operator<< ( ostream& , const meteorito & );

#include "meteorito.hxx"
#endif
