#ifndef __POLINOMIO_H
#define __POLINOMIO_H

#include <list>
#include <utility> // clase pair
#include "vectorD.h"


using namespace std;

class Polinomio{
public:
class iterator; // iterador sobre todos los elementos del polinomio
class const_iterator; // const iterador sobre todos los elementos del polinomio
class stored_iterator;
class const_stored_iterator;
typedef unsigned int size_type;

//////////// constructores //////////////

Polinomio();
// constructor por defecto
Polinomio(  const Polinomio & p);
/** constructor de copia */

////////////// destructor ////////////


/////////// Consultores ////////////
int grado() const;

int coeficiente(int p)const;


////////  MODIFICADORES //////////////////////
void assign(int g, int c);

void push_back(int c);

/////////////// operadores ///////////////////


Polinomio & operator= (const Polinomio & p);
// operador de asignacion

Polinomio & operator+ (const Polinomio & p);

Polinomio & operator- (const Polinomio & p);

////////////////////////////////////////




iterator begin();
/** iterador (read) al inicio sobre todos los elementos del polinomio */

iterator end();
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */

const_iterator cbegin() const;
/** iterador  (read) inicio sobre todos los elementos del polinomio */

const_iterator cend() const;
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */

stored_iterator sbegin();
/** iterador  (read) inicio sobre elementos no nulos */

stored_iterator send();
/** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */

const_stored_iterator csbegin() const;
/** iterador  (read) inicio sobre elementos no nulos */

const_stored_iterator csend() const;
/** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */

private: // parte  privada

    vectorD<int> poli; // lista que aloja el polinomio (solo los distintos a 0)

  /* ITERADORES SOBRE POLINOMIO */
public:


  public:

class iterator{
  public:

    friend class Polinomio;


    iterator() ;
    iterator(const iterator & d);
    const  int & operator *( );
    iterator & operator++( );
    iterator operator++(int ) ;
    bool operator == (const iterator & d) ;
    bool operator != (const iterator & d);
    iterator & operator=(const iterator & d);
  private:

    vectorD<int>::iterator it;

};

class const_iterator{
  public:
    friend class Polinomio;

    const_iterator() ;
    const_iterator(const const_iterator & d) ;
    const_iterator(const iterator & d) ;
    const  int  &  operator *(  );
    const_iterator & operator++( ) ;
    const_iterator operator++(int ) ;
    bool operator == (const const_iterator & d) ;
    bool operator != (const const_iterator & d) ;

  private:

    vectorD<int>::const_iterator it;

};

class stored_iterator{
  public:
    friend class Polinomio;
    friend class Polinomio::const_stored_iterator;

    stored_iterator();
    stored_iterator(const stored_iterator & d) /*: ite(d.ite)*/;
    const int & operator *(  ) { return (*ite);}
    stored_iterator & operator++( ) {++ite; return *this;}
    stored_iterator operator++(int ) {stored_iterator tmp(*this); ++ite; return tmp;}
    bool operator == (const stored_iterator & d) {return ite == d.ite;}
    bool operator != (const stored_iterator & d) {return ite != d.ite; }

  private:

    vectorD<int>::stored_iterator ite;
};

class const_stored_iterator{
  public:
    friend class Polinomio;

    const_stored_iterator();
    const_stored_iterator(const const_stored_iterator & d) ;
    const_stored_iterator(const stored_iterator & d) ; // Conversion de iterator a const_iterator
    const int & operator *(  ) { return *ite;}
    const_stored_iterator & operator++( ) {++ite; return *this;}
    const_stored_iterator operator++(int ) {const_stored_iterator tmp(*this); ++ite; return tmp;}
    bool operator == (const const_stored_iterator & d) {return ite == d.ite;}
    bool operator != (const const_stored_iterator & d) {return ite != d.ite; }
    const_stored_iterator & operator= (const const_stored_iterator & d) ;//

  private:
    vectorD<int>::const_stored_iterator ite;
};

};

#include "polinomio.hxx"

#endif

