/* 
 * meteorito.h
 * 
 * Copyright  (C) Juan F. Huete
*/
#ifndef __METEORITO_H
#define __METEORITO_H

#include <string>
#include <iostream> 
#include <vector>

//! Clase defM, asociada a la definición de un meteorito 
/*! defM::defM .....
 * Descripción que toda la información asociada a un meteorito.


\invariant 
mass >=0
codes[i]!=codes[j], para todo i!=j
...

*/
using namespace std;

class defM {
 public:
  defM();
  defM(const defM & x);
  bool setCode(const string & s);
  void setMas(const double &  m);
  void setFall(bool f);
  void setYear(const string & y);
  void setLat(double & lat);
  void setLong(double & longi);
  vector<string> getCodes( ) const;
  double getMas( ) const;
  bool getFall( ) const;
  string getYear( ) const;
  double getLat( ) const;
  double getLong( ) const;
 private:
    friend  ostream& operator<< ( ostream& , const defM & );
   vector<string> codes; /**<Vector de codigos */
   double mass; /**< masa */
   bool fall; /**< true si Found, false si Fell */
   string year; /**< añi de caida, string */
   double lat; /**< coordenada de latitud */
   double longi;/**< coordenada de longitud */
};

/** @brief nombreM representa a un nombre de meteorito
 * 
 * 
 */
typedef string nombreM;

/** @brief meteorito representa a un nombre de meteorito
 * 
 * 
 */
typedef pair<nombreM,defM> meteorito;

ostream & operator<< ( ostream& , const meteorito & );

#include "meteorito.hxx"

#endif
