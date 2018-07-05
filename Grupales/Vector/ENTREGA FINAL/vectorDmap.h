#ifndef __VECTORDISPERSO_H
#define __VECTORDISPERSO_H

#include <map>
#include <utility> // clase pair

using namespace std;
template <typename  T >
class vectorD{
public:
class stored_iterator; // iterador sobre elementos no nulos
class iterator; // iterador sobre todos los elementos del vector
class const_stored_iterator; //const iterador sobre elementos no nulos
class const_iterator; // const iterador sobre todos los elementos del vector
typedef unsigned int size_type;

//////////// constructores //////////////

	/** @brief constructor primitivo.
        @post se crea un contenedor que es un dato miembro de la clase vectorD.
	*/
vectorD( const  T  & t=  T () );
// constructor por defecto. t hace referencia al valor por defecto del vector

	/** @brief constructor de copia.
        @post se crea un contenedor que es un dato miembro de la clase vectorD.
	*/
vectorD(  const vectorD< T > & b);

/** @brief constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp deve ser mayor que cero.
t hace referencia al valor por defecto
    @post se crea un contenedor que es un dato miembro de la clase vectorD.
 */
vectorD( int numcomp, const  T  & t );



////////////// destructor ////////////
	/** @brief destructor.
	@post se destruye el objeto de la clase vectorD
	*/
~vectorD();


/////////// Consultores ////////////

/** @brief Devuelve el tamaño del vector.
    @return el tamaño del vector.
*/

size_type size() const;
// Devuelve el tamaño del vectorD

/**
    @brief Devuelve el valor por defecto del vectorD.
    @return un el valor nulo tipo T.

*/

T  default_value( ) const;

/**
    @brief Devuelve si el vectorD está vacío.
    @return un booleano.

*/

bool empty();
// el vectorD esta vacio

////////  MODIFICADORES //////////////////////

/**
    @brief Asigna a una posición dada un valor de T dado.
    @param[in] p La posición en el vectorD.
    @param[in] t El valor a insertar en el vector en la posición p.
    @pre la posición dada debe estar dentro del tamaño del vector.
    @post La posición p del vector es modificada. Internamente, puede crearse una nueva posición, eliminarse
    o modificarse, dependiendo del valor anterior y del valor nuevo dado.
*/

void assign(int p, const  T  & t);
// Cambia a el valor t el valor de la posicion p-esima del vector. No modifica el size del vector

/**
    @brief Inserta en la posición siguiente a la última del vector el valor dado.
    @param[in] t el valor a insertar.
    @post el tamaño del vector se incrementa en 1 y si es un valor no nulo, se inserta en el contenedor interno vd.
*/

void push_back( const  T  & t);
// Inserta un elemento al final del vectorD. Aumenta en 1 el tamanio

/**
    @brief Elimina del vector la última posición.
    @pre El vector no puede estar vacío.
    @post El tamaño del vector se decrementa en 1 y si era un valor no nulo en la última posición,
    se elimina también del contenedor interno.
*/

void pop_back(  );
// elimina un elemento del vectorD. Disminuye en 1 el tamanio

/**
    @brief Elimina todo el contenido del vector.
    @post el tamaño del vector es 0 y se elimina todo el contenido del contenedor interno.
*/

void clear();
// elimina todos los elementos del vectorD. Tamanio es 0

/**
    @brief Redimensiona el vector
    @param[in] s El nuevo tamaño del vector
    @post si fuera menor, se eliminan las posiciones que superen el parámetro dado,
    y si fuera mayor, se insertan en todas las posiciones nuevas el valor nulo
*/

void resize(int s);
// cambia el tama~no del vector a "s" elementos. Si s es menor que el tama~no actual, elimina los restantes. Si es mayor,
//amplia la capacidad del vector asignando a todos los nuevos elementos el valor nulo.

/////////////// operadores ///////////////////

/**
    @brief Asigna el comportamiento del operador =
    @param[in] x Vector con el que hay que igualar el actual
    @return el vector actual modificado
    @post Iguala los datos miembros del vector actual con los del dado
*/

vectorD & operator= (const vectorD & x);
// operador de asignacion

/**
    @brief Asigna el comportamiento del operador []
    @param[in] c Posición a buscar el valor a devolver
    @return el valor a devolver en esa posición
*/

const  T  & operator[](int c) const  ;

/**
    @brief Devuelve el valor en la posición dada.
    @param[in] c Posición a buscar el valor.
    @pre Debe existir esa posición en el vector.
    @return El valor en esa posición.
*/

const  T  & at(int c) const  ;

/**
    @brief devuelve si los datos miembros de los dos objetos son iguales o no
    @param[in] x Vector con el que comprobar
    @return verdadero si tienen los mismos elementos y false en caso contrario
*/

bool operator==( const vectorD & x);

/**
    @brief devuelve si los datos miembros de los dos objetos son distintos o no
    @param[in] x Vector con el que comprobar
    @return falso si tienen los mismos elementos y verdadero en caso contrario
*/

bool operator!=( const vectorD & x);

////////////////////////////////////////


/**
    @brief Devuelve un iterador al principio del vectorD
    @return iterador (read) al inicio sobre todos los elementos del vector
*/

iterator begin();

/**
    @brief Devuelve un iterador al final del vectorD
    @return iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector
*/

iterator end();

/**
    @brief Devuelve un iterador constante al principio del vectorD
    @return iterador  (read) inicio sobre todos los elementos del vector
*/

const_iterator cbegin() const;

/**
    @brief Devuelve un iterador constante al final del vectorD
    @return iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector
*/

const_iterator cend() const;

/**
    @brief Devuelve un stored_iterator al principio del vectorD
    @return iterador  (read) inicio sobre elementos no nulos
*/

stored_iterator sbegin();

/**
    @brief Devuelve un stored_iterator al final del vectorD
    @return iterador  (read) final (siguiente al ultimo) sobre elementos no nulos
*/

stored_iterator send();

/**
    @brief Devuelve un const_stored_iterator al principio del vectorD
    @return iterador  (read) inicio sobre elementos no nulos
*/

const_stored_iterator csbegin() const;

/**
    @brief Devuelve un const_stored_iterator al final del vectorD
    @return iterador  (read) final (siguiente al ultimo) sobre elementos no nulos
*/

const_stored_iterator csend() const;



private: // parte  privada

    map<int,T> vd; // lista que aloja el vector disperso (solo los != valor nulo)
    int n_ele; // numero de elementos totals
    T   v_nulo; //valor nulo del vector

    /* FA e IR*/
    /* FA(rep): rep -- > vector
      (vd,n_ele,v_nulo):
         vd=[ (a,v1), (b,v2), ..., (n,vn) ]
         n_ele = M
         v_nulo = t
      --------->
      pos: 0 1 2 ... a-1 a ... x .... b....  ... n-1 n  n+1 ..... M-1
      val: t t t ....t  v1 ... t .... v2 ..  ... t   vn  t  ...... t
      */

    /**
    @brief Verifica si los datos miembro están correctos
    @return entero, 0 si no hay error, otro número indica que hay un error y en qué
    */

    int checkRep();
    /* devuelve el tipo de fallo segun indica el IR */

    /* IR :
      IR(rep): rep ---> bool
     (vd,n_ele,v_nulo) :
      0 <= vd.size() < n_ele;  //Fallo tipo 1
      vd[i].second != v_nulo, para todo i = 0, ..., vd.size()-1; // Fallo tipo 2
      vd[i].first >=0, para todo i = 0, ..., vd.size()-1; // Fallo tipo 3
      vd[i].first < vd[j].first si i<j // Fallo tipo 4
     */

  /* ITERADORES SOBRE VECTOR DISPERSO */
public:


  public:


class stored_iterator{
  public:

    friend class vectorD;
    friend class vectorD< T >::const_stored_iterator;

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
    @return valor T de la posición sobre vd en la que se encuentra el iterador
    */

    const T & operator *(  ) { return (*ite).second;}

    /**
    @brief devuelve el iterador hacia la siguiente posición en vd
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre vd de ite
    */

    stored_iterator & operator++( ) {++ite; return *this;}

    /**
    @brief devuelve una copia de la posición actual del iterador, pero incrementa la posición del actual
    @return una copia del iterador en la posición actual
    @post se incrementa la posición del iterador ite sobre vd
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

    typename map<int, T >::iterator ite;
};

class iterator{
  public:
    friend class vectorD;

  /**
    @brief constructor por defecto
    @post se crea un iterador que actúa sobre todas las posiciones del vector
  */

    iterator() ;

    /**
    @brief constructor de copia
    @post se crea un iterador con el mismo valor para los datos miembros que el iterador dado
  */

    iterator(const iterator & d);

    /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor T de la posición sobre todo el vector en la que se encuentra el iterador
    */

    const  T & operator *( );

    /**
    @brief devuelve el iterador hacia la siguiente posición en el vector
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre el vector disperso. Si el iterador de la stl se ha quedado atrás,
    se actualiza a la siguiente posición sobre vd
    */

    iterator & operator++( );

    /**
    @brief devuelve una copia del iterador en la posición actual, y el iterador avanza hacia la siguiente posición en el vector
    @return la copia del iterador con la posición antes de actualizarla
    @post se incrementa la posición sobre el vector disperso. Si el iterador de la stl se ha quedado atrás,
    se actualiza a la siguiente posición sobre vd
    */

    iterator operator++(int ) ;

    /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre todo el vector
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */

    bool operator == (const iterator & d) ;

    /**
    @brief identifica si el iterador actual está apuntando a distinto sitio que el dado
    @param[in] d iterador sobre todo el vector
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */

    bool operator != (const iterator & d);

    /**
    @brief iguala los datos miembro de este objeto con los del dado
    @param[in] d iterador sobre todo el vector
    @return este objeto con los datos miembro actualizados
    @post se actualizan los datos miembros del objeto
    */

    iterator & operator=(const iterator & d);
  private:
    int i_vect; // indice sobre el vector abstracto
    typename map<int, T >::iterator ite_rep; //iterador a la representacion
    vectorD *el_vect; // ptro al vector para obtener el valor nulo del vector
    /* FA e IR*/
    /* FA(rep): rep -- > iterador sobre vector abstracto
      (i_vect, ite_rep, el_vec):
      i_vect = k
      ite_rep = p
      el_vect = v
       --------->
      iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
       */

      /* IR :
       IR(rep): rep ---> bool
     (i_vect, ite_rep):
       --------->
       0 <= i_vect <=n_ele
       i_vect <= (*ite_rep).first
       */

};

class const_stored_iterator{
  public:
    friend class vectorD;

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
    @return valor T de la posición sobre todo el vector en la que se encuentra el iterador
    */


    const T & operator *(  ) { return (*ite).second;}

    /**
    @brief devuelve el iterador hacia la siguiente posición en vd
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre vd de ite
    */

    const_stored_iterator & operator++( ) {++ite; return *this;}

/**
    @brief devuelve una copia de la posición actual del iterador, pero incrementa la posición del actual
    @return una copia del iterador en la posición actual
    @post se incrementa la posición del iterador ite sobre vd
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
    typename map<int, T >::const_iterator ite;
};

class const_iterator{
  public:
    friend class vectorD;

  /**
    @brief constructor por defecto
    @post se crea un iterador constante que actúa sobre todas las posiciones del vector
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
    @return valor T de la posición sobre todo el vector en la que se encuentra el iterador
    */

    const  T  &  operator *(  );

    /**
    @brief devuelve el iterador hacia la siguiente posición en el vector
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre el vector disperso. Si el iterador de la stl se ha quedado atrás,
    se actualiza a la siguiente posición sobre vd
    */

    const_iterator & operator++( ) ;

    /**
    @brief devuelve una copia del iterador en la posición actual, y el iterador avanza hacia la siguiente posición en el vector
    @return la copia del iterador con la posición antes de actualizarla
    @post se incrementa la posición sobre el vector disperso. Si el iterador de la stl se ha quedado atrás,
    se actualiza a la siguiente posición sobre vd
    */

    const_iterator operator++(int ) ;

    /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre el contenedor interno
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */

    bool operator == (const const_iterator & d) ;

    /**
    @brief identifica si el iterador actual está apuntando a distinto sitio que el dado
    @param[in] d iterador sobre todo el vector
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */

    bool operator != (const const_iterator & d) ;

  private:
    int i_vect; // indice sobre el vector abstracto
    typename map<int, T >::const_iterator ite_rep; //iterador a la representacion
    const vectorD *el_vect; // ptro al vector para obtener el valor nulo del vector
    /* FA e IR*/
    /* FA(rep): rep -- > iterador sobre vector abstracto
      (i_vect, ite_rep, el_vec):
      i_vect = k
      ite_rep = p
      el_vect = v
       --------->
      iterador a la posicion k-esima del vector abstracto con valor nulo (*v).v_nulo
       */

      /* IR :
       IR(rep): rep ---> bool
     (i_vect, ite_rep):
       --------->
       0 <= i_vect <=n_ele
       i_vect <= (*ite_rep).first
       */

};


};

#include "vectorDmap.hxx"

#endif

