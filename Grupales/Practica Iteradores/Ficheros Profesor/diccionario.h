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

using namespace std;

//! Clase diccionario
 /*! diccionario:: diccionario, null, find, operator[], size, max_element
 * Tipos 
 \code
 * diccionario<K,D>::entrada, 
 * diccionario<K,D>::size_type
 * diccionario<K,D>::iterator   iterator,operator*, operator++, operator=, operator==, operator!=
 * diccionario<K,D>::const_iterator const_iterator,operator*, operator++, operator=, operator==, operator!=
 \endcode
 Descripción

* Un diccionario es un contenedor que permite almacenar un conjunto de pares de elementos, el primero será la clave que deber ser única y el segundo la definición.  En nuestro caso el diccionario va a tener un subconjunto restringido de métodos (inserción de elementos, consulta de un elemento por clave, además de la consulta del   elemento con mayor valor en la definición). Este diccionario "simulará" un diccionario de la stl, con algunas  diferencias.
 
* El número de elementos en el diccionario puede variar dinámicamente; la gestión de la memoria es automática. 
 

* Asociado al diccionario, tendremos el tipo  \code diccionario<K,D>::entrada \endcode que permite hacer referencia al par de elementos almacenados en cada una de las posiciones del diccionario. Así, el primer campo de una entrada, first, representa la clave y el segundo campo, second, representa la definición. En nuestra aplicación concreta, la clave será un string representando una palabra válida del diccionario y el segundo campo es un entero que hace referencia a la frecuencia de ocurrencia de la palabra en el lenguaje.

 Ademas, disponemos de dos iteradores, el iterator y el const_iterator que permiten recorrer los elementos del diccionario.
 */


template <typename Key, typename Def>
class diccionario;


/** @brief imprime todas las entradas del diccionario 
@post  No se modifica el diccionario.
@todo implementar esta funcion
	*/
template <typename Key, typename Def>
ostream &  operator <<  ( ostream & sal, const diccionario<Key,Def> & D);

template <typename Key, typename Def>
class diccionario
{  
public:
         
        typedef pair<Key, Def> entrada;
	typedef pair<const Key, Def> value_type;
	typedef unsigned int size_type;
	class iterator;
	class const_iterator;
	
	/** @brief constructor primitivo. 
	@post 
	*/
	diccionario( );
	

	/** @brief constructor de copia
	@param[in] d diccionario a copiar
	*/
	diccionario (const diccionario & d);

	/** @brief   
         @return Devuelve el iterador a la primera posición del diccionario.
	@post no modifica el diccionario
        */
	 iterator begin() ; 
	/** @brief  
         @return Devuelve el iterador a la ultima posición del diccionario.
	@post no modifica el diccionario
        */
	iterator end() ;
	
        /** @brief  
         @return Devuelve el const_iterator a la primera posición del diccionario.
	@post no modifica el diccionario
        */
	const_iterator cbegin() const;
	/** @brief entrada nula del diccionario
         @return Devuelve el iterador constante a la  posición final del diccionario.
	@post no modifica el diccionario
        */
	const_iterator cend() const;

	/** @brief class iterator
	 * forward iterador sobre el diccionario, Lectura y Escritura
	 *  iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
	 * */
	class iterator {
	public:
	  iterator();
	  iterator(const iterator & it);
	  value_type & operator*() const;
	  iterator operator++( int );
	  iterator & operator++();
	  bool operator==(const iterator & it);
	  bool operator!=(const iterator & it);
	private:
	  iterator (entrada * p);
	  iterator (vector<entrada>::iterator it);
	  friend class diccionario;
	  value_type * it_v;
	};

	/** @brief class const_iterator
	 * forward iterador constante sobre el diccionario, Lectura 
	 *  const_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
	 * */
	class const_iterator {
	public:
	  const_iterator();
	  const_iterator(const const_iterator & it);
          /** @brief Convierte iterator en const_iterator
          */
	  const_iterator(const iterator & it);
	  const value_type & operator*() const;
	  const_iterator operator++( int );
	  const_iterator & operator++();
	  bool operator==(const const_iterator & it);
	  bool operator!=(const const_iterator & it);
	private:
	  const_iterator (entrada * p);
	  const_iterator (vector<entrada>::const_iterator it);
	  friend class diccionario;
	  value_type * it_v;
	};
	
	/** @brief busca una cadena en el diccionario
	@param s cadena a buscar
	@return un iterador que apunta a la posicion del elemento en el diccionario, en caso contrario devuelve end.
	@post no modifica el diccionario.
	\verbatim Uso
	if (D.fin("hola")!=D.end()) cout << "Esta" ;
	else cout << "No esta";
	\endverbatim
	*/
	iterator  find( const Key & s) ;
	
	
/** @brief Consulta/Inserta una  entrada en el diccionario.

Busca la clave s en el diccionario, si la encuentra devuelve una referencia a su definición, en caso contrario la inserta, con el valor de la definición por defecto D() cero, devolviendo una referencia a este valor.
 
@param[in] s clave a insertar
@param[out]   referencia a la definicion asociada  a la entrada
@post  Si s no esta en el diccionario,  inserta y el size() sera incrementado en 1.
*/
	Def & operator[](const Key & s);
	
	
/** @brief Consulta  una   entrada en el diccionario.

Busca la clave s en el diccionario, si la encuentra devuelve una referencia constante a su definición, si no la encuentra da un mensaje de error.
 
@param[in] s clave a insertar
@param[out]   referencia constante a la definicion asociada  a la entrada
@post  No se modifica el diccionario.
*/
	 const Def & operator[](const Key & s) const;

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
   Chequea si el priority_queue esta vacio (size()==0)
*/
  bool empty() const;

	
      

	 
private:
        
	friend  ostream& operator<< <> ( ostream& sal, const diccionario<Key,Def>& D);
        friend class iterator;
        friend class const_iterator;
	      
	vector<entrada> dic; // vector que almacena los elementos del diccionario
	

  /** @brief Chequea el Invariante de la representacion 
      @return true si el invariante es correcto, falso en caso contrario
*/
  bool cheq_rep( ) const;
  
  
 

};


#if defined(DICC_V2)
  #include "diccionarioV2.hxx"
#elif defined(DICC_V1)
  #include "diccionarioV1.hxx"
#else
#error !!! HAY QUE INDICAR LA VERSION DE LA REPRESENTACION A COMPILAR DICC_V1 o DICC_V2
#error compila como: g++ -D version -std=c++0x -o ejecutable principal.ccp
#endif
	


#endif
