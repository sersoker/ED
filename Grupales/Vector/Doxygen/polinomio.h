#ifndef __POLINOMIO_H
#define __POLINOMIO_H

#include <list>
#include <utility> // clase pair
#include "vectorD.h"

/* vectorD.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aarón Rodríguez Bueno
 *
 */

using namespace std;

class Polinomio{
public:
class iterator; // iterador sobre todos los elementos del polinomio
class const_iterator; // const iterador sobre todos los elementos del polinomio
class stored_iterator;
class const_stored_iterator;
typedef unsigned int size_type;

//////////// constructores //////////////

	/** @brief constructor primitivo.
        @post se crea un contenedor vectorD que es un dato miembro de la clase Polinomio.
	*/

Polinomio();
// constructor por defecto

/** @brief constructor de copia.
        @post se crea un contenedor vectorD que es un dato miembro de la clase Polinomio.
	*/

Polinomio(  const Polinomio & p);


////////////// destructor ////////////


/////////// Consultores ////////////

/** @brief Devuelve el grado del polinomio
    @return el tamaño del polinomio menos 1
*/

int grado() const;

/**
    @brief Devuelve el coeficiente en el grado dado
    @param[in] p posición donde hay que mirar el coeficiente
    @return El valor del grado en esa posición.
*/

int coeficiente(int p)const;


////////  MODIFICADORES //////////////////////

/**
    @brief Asigna a una posición dada un coeficiente dado.
    @param[in] g La posición en el polinomio.
    @param[in] c El valor a insertar en el polinomio.
    @pre la posición dada debe estar dentro del tamaño del polinomio.
    @post La posición p del polinomio es modificada
    */

void assign(int g, int c);

/**
    @brief Inserta un grado mayor al mayor actual del polinomio con el valor dado.
    @param[in] t el valor a insertar.
    @post el grado del polinomio se incrementa en 1 y se inserta en el contenedor interno vectorD.
*/

void push_back(int c);

/////////////// operadores ///////////////////

/**
    @brief Asigna el comportamiento del operador =
    @param[in] p Polinomio con el que hay que igualar el actual
    @return el polinomio actual modificado
    @post Iguala los datos miembros del polinomio actual con los del dado
*/

Polinomio & operator= (const Polinomio & p);
// operador de asignacion

/**
    @brief suma al polinomio actual el dado
    @param[in] el polinomio a sumar al actual
    @return este polinomio
    @post los valores del vectorD se actualizan con la suma del campo actual
    mas el campo en la misma posición del polinomio dado

*/

Polinomio & operator+ (const Polinomio & p);

/**
    @brief resta al polinomio actual el dado
    @param[in] el polinomio a sumar al actual
    @return este polinomio
    @post los valores del vectorD se actualizan con la resta del campo actual
    el campo en la misma posición del polinomio dado

*/

Polinomio & operator- (const Polinomio & p);

////////////////////////////////////////

/**
    @brief Devuelve un iterador al principio del polinomio
    @return iterador (read) al inicio sobre todos los elementos del polinomio
*/

iterator begin();

/**
    @brief Devuelve un iterador al final del polinomio
    @return iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio
*/

iterator end();

/**
    @brief Devuelve un iterador constante al principio del polinomio
    @return iterador  (read) inicio sobre todos los elementos del polinomio
*/

const_iterator cbegin() const;

/**
    @brief Devuelve un iterador constante al final del polinomio
    @return iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio
*/

const_iterator cend() const;

/**
    @brief Devuelve un stored_iterator al principio del polinomio
    @return iterador  (read) inicio sobre elementos no nulos
*/

stored_iterator sbegin();

/**
    @brief Devuelve un stored_iterator al final del polinomio
    @return iterador  (read) final (siguiente al ultimo) sobre elementos no nulos
*/

stored_iterator send();

/**
    @brief Devuelve un const_stored_iterator al principio del polinomio
    @return iterador  (read) inicio sobre elementos no nulos
*/

const_stored_iterator csbegin() const;

/**
    @brief Devuelve un const_stored_iterator al final del polinomio
    @return iterador  (read) final (siguiente al ultimo) sobre elementos no nulos
*/

const_stored_iterator csend() const;


private: // parte  privada

    vectorD<int> poli; // lista que aloja el polinomio (solo los distintos a 0)

  /* ITERADORES SOBRE POLINOMIO */
public:


  public:

class iterator{
  public:

    friend class Polinomio;

  /**
    @brief constructor por defecto
    @post se crea un iterador que actúa sobre todas las posiciones del polinomio
  */

    iterator() ;

      /**
    @brief constructor de copia
    @post se crea un iterador con el mismo valor para los datos miembros que el iterador dado
  */

    iterator(const iterator & d);

        /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor del coeficiente de la posición sobre todo el polinomio en la que se encuentra el iterador
    */

    const  int & operator *( );

       /**
    @brief devuelve el iterador hacia la siguiente posición en el polinomio
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre el polinomio.
    */

    iterator & operator++( );

        /**
    @brief devuelve una copia del iterador en la posición actual, y el iterador avanza hacia la siguiente posición en el polinomio
    @return la copia del iterador con la posición antes de actualizarla
    @post se incrementa la posición sobre el polinomio.
    */

    iterator operator++(int ) ;

    /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre todo el polinomio
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */

    bool operator == (const iterator & d) ;

    /**
    @brief identifica si el iterador actual está apuntando a distinto sitio que el dado
    @param[in] d iterador sobre todo el polinomio
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */

    bool operator != (const iterator & d);

    /**
    @brief iguala los datos miembro de este objeto con los del dado
    @param[in] d iterador sobre todo el polinomio
    @return este objeto con los datos miembro actualizados
    @post se actualizan los datos miembros del objeto
    */

    iterator & operator=(const iterator & d);
  private:

    vectorD<int>::iterator it;

};

class const_iterator{
  public:
    friend class Polinomio;

  /**
    @brief constructor por defecto
    @post se crea un iterador constante que actúa sobre todas las posiciones del polinomio
  */

    const_iterator() ;

        /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador constante dado
  */

    const_iterator(const const_iterator & d) ;

    /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador dado
  */

    const_iterator(const iterator & d) ;

    /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor del coeficiente en la posición sobre todo el polinomio en la que se encuentra el iterador
    */

    const  int  &  operator *(  );

    /**
    @brief devuelve el iterador hacia la siguiente posición en el polinomio
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre el polinomio
    */

    const_iterator & operator++( ) ;

        /**
    @brief devuelve una copia del iterador en la posición actual, y el iterador avanza hacia la siguiente posición en el polinomio
    @return la copia del iterador con la posición antes de actualizarla
    @post se incrementa la posición sobre el polinomio
    */

    const_iterator operator++(int ) ;

        /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre el polinomio
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */

    bool operator == (const const_iterator & d) ;

        /**
    @brief identifica si el iterador actual está apuntando a distinto sitio que el dado
    @param[in] d iterador sobre todo el polinomio
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */


    bool operator != (const const_iterator & d) ;

  private:

    vectorD<int>::const_iterator it;

};

class stored_iterator{
  public:
    friend class Polinomio;
    friend class Polinomio::const_stored_iterator;

  /**
    @brief constructor por defecto
    @post se crea un iterador sobre el contenedor interno
  */

    stored_iterator();

        /**
    @brief constructor de copia
    @post se crea un iterador con el mismo valor para los datos miembros que el iterador dado
  */

    stored_iterator(const stored_iterator & d) /*: ite(d.ite)*/;

        /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor del coeficiente en la posición sobre poli en la que se encuentra el iterador
    */

    const int & operator *(  ) { return (*ite);}

        /**
    @brief devuelve el iterador hacia la siguiente posición en poli
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre poli de ite
    */

    stored_iterator & operator++( ) {++ite; return *this;}

        /**
    @brief devuelve una copia de la posición actual del iterador, pero incrementa la posición del actual
    @return una copia del iterador en la posición actual
    @post se incrementa la posición del iterador ite sobre poli
    */

    stored_iterator operator++(int ) {stored_iterator tmp(*this); ++ite; return tmp;}

        /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre el contenedor interno
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */

    bool operator == (const stored_iterator & d) {return ite == d.ite;}

    /**
    @brief identifica si el iterador actual está apuntando al distinto sitio que el dado
    @param[in] d iterador sobre el contenedor interno
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */

    bool operator != (const stored_iterator & d) {return ite != d.ite; }

  private:

    vectorD<int>::stored_iterator ite;
};

class const_stored_iterator{
  public:
    friend class Polinomio;

  /**
    @brief constructor por defecto
    @post se crea un iterador constante sobre el contenedor interno
  */

    const_stored_iterator();

        /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador constante dado
  */

    const_stored_iterator(const const_stored_iterator & d) ;

        /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador dado
  */

    const_stored_iterator(const stored_iterator & d) ; // Conversion de iterator a const_iterator

    /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor T de la posición sobre poli en la que se encuentra el iterador
    */

    const int & operator *(  ) { return *ite;}

    /**
    @brief devuelve el iterador hacia la siguiente posición en poli
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre poli de ite
    */

    const_stored_iterator & operator++( ) {++ite; return *this;}

    /**
    @brief devuelve una copia de la posición actual del iterador, pero incrementa la posición del actual
    @return una copia del iterador en la posición actual
    @post se incrementa la posición del iterador ite sobre poli
    */

    const_stored_iterator operator++(int ) {const_stored_iterator tmp(*this); ++ite; return tmp;}

        /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre el contenedor interno
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */

    bool operator == (const const_stored_iterator & d) {return ite == d.ite;}

        /**
    @brief identifica si el iterador actual está apuntando al distinto sitio que el dado
    @param[in] d iterador sobre el contenedor interno
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */

    bool operator != (const const_stored_iterator & d) {return ite != d.ite; }

        /**
    @brief Iguala los datos miembro del iterador a los del dado
    @param[in] d iterador al que se va a igualar
    @return este iterador con los datos miembro ya igualados
    */

    const_stored_iterator & operator= (const const_stored_iterator & d) ;//

  private:
    vectorD<int>::const_stored_iterator ite;
};

};

#include "polinomio.hxx"

#endif

