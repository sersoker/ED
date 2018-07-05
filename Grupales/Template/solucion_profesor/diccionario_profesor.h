/* 
 * diccionario.h
 * 
 * Copyright  (C) Juan F. Huete
*/

#ifndef __DICCIONARIO_H
#define __DICCIONARIO_H
#include <string>
#include <vector>
#include <iostream> 

#include "meteorito.h"

using namespace std;


//! Clase diccionario
 /*! diccionario:: diccionario, find, operator[], size,  
 * Tipos diccionario::entrada, diccionario::size_type
 * Descripción

* Un diccionario es un contenedor que permite almacenar un conjunto de pares de elementos, el primero será la clave que deber ser única y el segundo la definición.  En nuestro caso el diccionario va a tener un subconjunto restringido de métodos (inserción de elementos, consulta de un elemento por clave, además de la consulta del   elemento con mayor valor en la definición). Este diccionario "simulará" un diccionario de la stl, con algunas claras diferencias pue, entre otros,  no estará dotado de la capacidad de iterar (recorrer) a través de sus elementos.

* Asociado al diccionario, tendremos el tipo  \code diccionario::entrada \endcode que permite hacer referencia al par de elementos almacenados en cada una de las posiciones del diccionario. Así, el primer campo de una entrada, first, representa la clave y el segundo campo, second, representa la definición. En nuestra aplicación concreta, la clave será un string representando una palabra válida del diccionario y el segundo campo es un entero que hace referencia a la frecuencia de ocurrencia de la palabra en el lenguaje.

* El número de elementos en el diccionario puede variar dinámicamente; la gestión de la memoria es automática. 
 
 */





class diccionario
{  
public:
	typedef pair<nombreM,defM> entrada;
	typedef unsigned int size_type;
	/** @brief constructor primitivo. 
	@post define la entrada nula como el par ("",-1)
	*/
	diccionario( );
	

	/** @brief constructor de copia
	@param[in] d diccionario a copiar
	*/
	diccionario (const diccionario & d);
		
	/** @brief busca una meteorito en el diccionario
	@param s cadena a buscar
	@return una copia de la entrada en el diccionario. Si  no se encuentra devuelve la entrada con la definicion por defecto
	@post no modifica el diccionario.
	\verbatim Uso
       

	if (D.find("aaa").second ==true) cout << "Esta" ;
	else cout << "No esta";
	\endverbatim
	*/
	pair<diccionario::entrada,bool>  find( const nombreM & s) const;

/** @brief Inserta una entrada en el diccionario
@param e entrada a insertar
@return true si la entrada se ha podido insertar con éxito, esto es, no existe un meteorito con igual nombre en el diccionario. False en caso contrario
@post 	 Si e no esta en el diccionario, el size() sera incrementado en 1.
*/
	bool insert( const entrada & e);

/** @brief Consulta/Inserta una  entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia a la definición de la misma
en caso contrario la inserta, con una definición por defecto, devolviendo una referencia a este valor.
 
@param[in] s cadena a insertar
@param[out] defM & referencia a la definicion asociada  a la entrada, nos permite modificar la definición
@post  Si s no esta en el diccionario, el size() sera incrementado en 1.
*/
	defM & operator[](const nombreM & s);
	
	
/** @brief Consulta  una   entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia constante aa la definición de la misma, si no la encuentra da un mensaje de error.
 
@param[in] s cadena a insertar
@param[out] int & referencia constante a la definicion asociada  a la entrada
@post  No se modifica el diccionario.
*/
	 const defM & operator[](const nombreM & s) const;

/** @brief operador de asignación
@param[in] org diccionario  a copiar.
 Crea un diccionario duplicado exacto de org.
*/
  diccionario & operator=( const diccionario & org);

	/** @brief numero de entradas en el diccionario
@post  No se modifica el diccionario.
*/
	size_type size() const ;


/** @brief vacia
   Chequea si el diccionario esta vacio (size()==0)
*/
  bool empty() const;

	
	 
	 
	   
	 
private:

	friend  ostream& operator<< ( ostream& , const diccionario& );
    

  
	vector<entrada> dic; // vector que almacena los elementos del diccionario
	
  /** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
*/
  bool cheq_rep( ) const;
  
  
 

};


/** @brief imprime todas las entradas del diccionario 
@post  No se modifica el diccionario.
@todo implementar esta funcion
	*/
ostream &  operator << ( ostream & sal, const diccionario & D);

#if defined(DICC_V2)
  #include "diccionarioV2.hxx"
#elif defined(DICC_V1)
  #include "diccionarioV1.hxx"
#else
#error !!! HAY QUE INDICAR LA VERSION DE LA REPRESENTACION A COMPILAR DICC_V1 o DICC_V2
#error compila como: g++ -D version -o ejecutable principal.ccp
#endif
	


#endif
