/*
 * diccionario.h
 *
 * Copyright  (C) Juan F. Huete
  * Editado por Bryan Moreno Picamán & Aarón Rodríguez Bueno
*/

#ifndef __DICCIONARIO_H
#define __DICCIONARIO_H
#include <string>
#include <vector>
#include <iostream>


using namespace std;


//! Clase diccionario
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



template <typename K, typename D>
class diccionario;

/** @brief imprime todas las entradas del diccionario
@post  No se modifica el diccionario.
@todo implementar esta funcion
	*/
template <typename K, typename D>
ostream &  operator << ( ostream & sal, const diccionario<K,D> & d);

template <typename K, typename D>
class diccionario
{
public:
	typedef pair<K,D> entrada;
	typedef unsigned int size_type;
	////////////////////////////////////////////////
    typedef pair<const K,D> value_type;
	class iterator;
	class const_iterator;
	/////////////////////////////////////////////////
	/** @brief constructor primitivo.
	@post define la entrada nula como el par ("",-1)
	*/
	diccionario( );


	/** @brief constructor de copia
	@param[in] d diccionario a copiar
	*/
	diccionario (const diccionario <K, D> & d);

	//////////////////////////////////////////////////////
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
    /** @brief constructor por defecto
        */
	  iterator();
    /** @brief constructor de copia
        @param[in] it iterator a copiar
        */
	  iterator(const iterator & it);
    /** @brief operador *
        @return Devuelve el valor de la dirección a la que apunta el iterador
        */
	  value_type & operator*() const;
    /** @brief operador ++ (postcondición)
        @param[out] El objeto iterator
        @return Incrementa el iterador en 1 su posición sobre dic
        */
	  iterator operator++( int );
    /** @brief operador ++ (precondición)
        @param[out] Una copia del iterador en la posición actual
        @return Incrementa el iterador en 1 su posición sobre dic
        */
	  iterator & operator++();
    /** @brief operador ==
        @param[in] Un objeto iterator
        @param[out] Un bool
        @return True si el iterator dado apunta al mismo sitio que nuestro iterator
        */
	  bool operator==(const iterator & it);
    /** @brief operador !=
        @param[in] Un objeto iterator
        @param[out] Un bool
        @return True si el iterator dado apunta a un sitio distinto que nuestro iterator
        */
	  bool operator!=(const iterator & it);
	private:

    /** @brief Constructor a partir de una dirección
        @param[in] Un puntero a un tipo entrada
        */
	  iterator (entrada * p);
    /** @brief Constructor de un iterador a partir de un vector de entradas
        @param[in] Vector<entrada>
        */
	  iterator (typename vector<entrada>::iterator it);
	  friend class diccionario;
	  value_type * it_v;
	};

	/** @brief class const_iterator
	 * forward iterador constante sobre el diccionario, Lectura
	 *  const_iterator ,operator*, operator++, operator++(int) operator=, operator==, operator!=
	 * */
	class const_iterator {
	public:
    /** @brief constructor por defecto
        */
	  const_iterator();
    /** @brief constructor de copia
        @param[in] it const_iterator a copiar
        */
	  const_iterator(const const_iterator & it);
          /** @brief Convierte iterator en const_iterator (creando un const_iterator a partir del iterator)
          */

      const_iterator(const iterator & it);
    /** @brief operador *
        @return Devuelve el valor de la dirección (no modificable) a la que apunta el iterador
        */
	  const value_type & operator*() const;
    /** @brief operador ++ (postcondición)
        @param[out] El objeto const_iterator
        @return Incrementa el iterador en 1 su posición sobre dic
        */
	  const_iterator operator++( int );
    /** @brief operador ==
        @param[in] Un objeto const_iterator
        @param[out] Un bool
        @return True si el iterator dado apunta al mismo sitio que nuestro iterator
        */
	  const_iterator & operator++();
    /** @brief operador ==
        @param[in] Un objeto const_iterator
        @param[out] Un bool
        @return True si el iterator dado apunta al mismo sitio que nuestro iterator
        */
	  bool operator==(const const_iterator & it);
    /** @brief operador !=
        @param[in] Un objeto const_iterator
        @param[out] Un bool
        @return True si el iterator dado apunta a un sitio distinto que nuestro iterator
        */
	  bool operator!=(const const_iterator & it);
	private:
    /** @brief Constructor a partir de una dirección
        @param[in] Un puntero a un tipo entrada
        */
	  const_iterator (entrada * p);
    /** @brief Constructor de un iterador a partir de un vector de entradas
        @param[in] Vector<entrada>
        */
	  const_iterator (typename vector<entrada>::const_iterator it);
	  friend class diccionario;
	  value_type * it_v;
	};


	 ////////////////////////////////////////////////////////////////////////////////

	/** @brief busca una meteorito en el diccionario
	@param s cadena a buscar
	@return una copia de la entrada en el diccionario. Si  no se encuentra devuelve la entrada con la definicion por defecto
	@post no modifica el diccionario.
	\verbatim Uso


	if (D.find("aaa").second ==true) cout << "Esta" ;
	else cout << "No esta";
	\endverbatim
	*/
	iterator find( const K & s) const;

/** @brief Inserta una entrada en el diccionario
@param e entrada a insertar
@return true si la entrada se ha podido insertar con éxito, esto es, no existe un meteorito con igual nombre en el diccionario. False en caso contrario
@post 	 Si e no esta en el diccionario, el size() sera incrementado en 1.
*/
	bool insert( const diccionario<K,D>::entrada & e);      //Aquí

/** @brief Consulta/Inserta una  entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia a la definición de la misma
en caso contrario la inserta, con una definición por defecto, devolviendo una referencia a este valor.

@param[in] s cadena a insertar
@param[out] defM & referencia a la definicion asociada  a la entrada, nos permite modificar la definición
@post  Si s no esta en el diccionario, el size() sera incrementado en 1.
*/
	D & operator[](const K & s);


/** @brief Consulta  una   entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia constante aa la definición de la misma, si no la encuentra da un mensaje de error.

@param[in] s cadena a insertar
@param[out] int & referencia constante a la definicion asociada  a la entrada
@post  No se modifica el diccionario.
*/
	 const D & operator[](const K & s) const;

/** @brief operador de asignación
@param[in] org diccionario  a copiar.
 Crea un diccionario duplicado exacto de org.
*/
  diccionario<K,D> & operator=( const diccionario<K,D> & org);    //Aquí

	/** @brief numero de entradas en el diccionario
@post  No se modifica el diccionario.
*/
	diccionario <K,D>::size_type size() const ;


/** @brief vacia
   Chequea si el diccionario esta vacio (size()==0)
*/
  bool empty() const;






private:

	friend  ostream& operator<< <> ( ostream& , const diccionario<K,D>& );                  //Aquí
//////////////////////////////////////////////////////////////////
		friend class iterator;
        friend class const_iterator;
/////////////////////////////////////////////////////////////////

	vector<entrada> dic; // vector que almacena los elementos del diccionario       //Aquí

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
#error compila como: g++ -D version -o ejecutable principal.ccp
#endif



#endif
