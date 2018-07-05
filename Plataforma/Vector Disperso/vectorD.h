#ifndef __VECTORDISPERSO_H
#define __VECTORDISPERSO_H

#include <list>
#include <utility> // clase pair


using namespace std;
template <typename  T >
class vectorD
{
public:
class stored_iterator; // iterador sobre elementos no nulos
class iterator; // iterador sobre todos los elementos del vector
class const_stored_iterator; //const iterador sobre elementos no nulos
class const_iterator; // const iterador sobre todos los elementos del vector
typedef unsigned int size_type;
//////////// constructores //////////////
  		
vectorD( const  T  & t=  T () );
// constructor por defecto. t hace referencia al valor por defecto del vector
      	
vectorD(  const vectorD< T > & b);    	
/** constructor primitivo que hace una copia del vector disperso b. */

vectorD( int numcomp, const  T  & t =  T () );
/** constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp deve ser mayor que cero.
t hace referencia al valor por defecto
 */


////////////// destructor ////////////  	
~vectorD();


/////////// Consultores ////////////
size_type size() const;
// Devuelve el tamaño del vectorD

T  default_value( ) const;

bool empty();
// el vectorD esta vacio

////////  MODIFICADORES //////////////////////
void assign(int p, const  T  & t);
// Cambia a el valor t el valor de la posicion p-esima del vector. No modifica el size del vector

void push_back( const  T  & t);
// Inserta un elemento al final del vectorD. Aumenta en 1 el tamanio

void pop_back(  );
// elimina un elemento del vectorD. Disminuye en 1 el tamanio

void clear(); 
// elimina todos los elementos del vectorD. Tamanio es 0

void resize(int s);
// cambia el tama~no del vector a "s" elementos. Si s es menor que el tama~no actual, elimina los restantes. Si es mayor,
//amplia la capacidad del vector asignando a todos los nuevos elementos el valor nulo. 

/////////////// operadores ///////////////////


vectorD & operator= (const vectorD & x);
// operador de asignacion


const  T  & operator[](int c) const  ;
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes*/

const  T  & at(int c) const  ;
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes
Hace comprobacion de rango */

bool operator==( const vectorD & x);
/** devuelve verdadero si tienen los mismos elementos y false en caso contrario */

bool operator!=( const vectorD & x);
/** devuelve verdadero si no tienen los mismos elementos y false en caso contrario */
////////////////////////////////////////




iterator begin();
/** iterador (read) al inicio sobre todos los elementos del vector */

iterator end();
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector */

const_iterator cbegin() const;
/** iterador  (read) inicio sobre todos los elementos del vector */

const_iterator cend() const;
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector */


stored_iterator sbegin(); 
/** iterador  (read) inicio sobre elementos no nulos */

stored_iterator send();
/** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */

const_stored_iterator csbegin() const; 
/** iterador  (read) inicio sobre elementos no nulos */

const_stored_iterator csend() const;
/** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */


private: // parte  privada

    list< pair<int, T > > vd; // lista que aloja el vector disperso (solo los != valor nulo)
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
    
    stored_iterator() {} 
    stored_iterator(const stored_iterator & d) : ite(d.ite) {}
    const pair<int, T > & operator *(  ) { return (*ite);}
    stored_iterator & operator++( ) {++ite; return *this;}  
    stored_iterator operator++(int ) {stored_iterator tmp(*this); ++ite; return tmp;}  
    bool operator == (const stored_iterator & d) {return ite == d.ite;}
    bool operator != (const stored_iterator & d) {return ite != d.ite; }
    
  private:
    
    typename list<pair<int, T > >::iterator ite;
};

class iterator{
  public:
    friend class vectorD;
    
    
    iterator() ;
    iterator(const iterator & d);
    const  T  & operator *(  ) ;
    iterator & operator++( );
    iterator operator++(int ) ; 
    bool operator == (const iterator & d) ;
    bool operator != (const iterator & d);
    iterator & operator=(const iterator & d);
  private:
    int i_vect; // indice sobre el vector abstracto
    typename list<pair<int, T > >::iterator ite_rep; //iterador a la representacion
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
    
    const_stored_iterator();
    const_stored_iterator(const const_stored_iterator & d) ;
     const_stored_iterator(const stored_iterator & d) ; // Conversion de iterator a const_iterator
    const pair<int, T > & operator *(  ) ;
    const_stored_iterator & operator++( ) ; 
    const_stored_iterator operator++(int ) ;
    bool operator == (const const_stored_iterator & d) ;
    bool operator != (const const_stored_iterator & d) ;
    const_stored_iterator & operator= (const const_stored_iterator & d) ;
 
  private:
    typename list<pair<int, T > >::const_iterator ite;
};

class const_iterator{
  public:
    friend class vectorD;
    
    const_iterator() ;
    const_iterator(const const_iterator & d) ;
    const_iterator(const iterator & d) ;
    const  T  &  operator *(  ) ;
    const_iterator & operator++( ) ;
    const_iterator operator++(int ) ;
    bool operator == (const const_iterator & d) ;
    bool operator != (const const_iterator & d) ;
    
  private:
    int i_vect; // indice sobre el vector abstracto
    typename list<pair<int, T > >::const_iterator ite_rep; //iterador a la representacion
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

#include "vectorD.hxx"

#endif
 
