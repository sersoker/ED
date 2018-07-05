//-*-Mode: C++;-*-

/**
  @file gs1Set .h
  @brief TDA gs1Set

 */

#ifndef __gs1Set_H__
#define __gs1Set_H__


#include <iostream>
#include <string>
#include "tree.h"

using namespace std;

/** \class gs1Set  gs1Set.h

gs1Set :gs1Set , operator=, size, empty,  insert, erase, find,

Descripcion

(las tildes han sido omitidas deliberadamente, debido a fallos en la generacion de documentacion con doxygen)

Un objeto de la clase gs1Set  representara un contenedor que permite almacenar un
codigo electronico de producto, en concreto consideraremos la normativa gs1-128

El gs1-128 es un sistema estandar de identificacion mediante codigo de barras
utilizado internacionalmente para la identificacion de mercancias en entornos
logisticos y no detallistas. Este sistema se utiliza principalmente para la identificacion de unidades de
expedicion.


En esta practica consideraremos codigos correctos, aquellos obtenidos segun la siguiente definicion:
 Una codigo  correcto solo puede contener   digitos (del 0 al 9)  junto con  parentesis de apertura y cierre.
 Por tanto, no debe  tener espacios ni delimitadores del tipo comillas, llaves, comas, puntos, etc.

El codigo gs1-128 vendra se representara mediante un  string, ejemplos de codigos validos son:
* (01)18456789012342
* (02)18456789012359(37)1234(00)384567890123456782

En la practica NO nos preocuparemos de generar codigos correctos, sino que consideraremos como correcto cualquier codigo que tenga

En el codigo podemos distinguir dos partes, encerrados entre parentesis los identificadores de aplicacion, IA, que son unos prefijos numericos creados para dar significado inequivoco a los elementos de datos estandarizados que se encuentran situados a continuacion (son subcodigos dentro el codigo gs1). Cada prefijo identifica el significado y el formato de los subcadigos que le siguen.

En la actualidad, existen mas de 100 identificadores de aplicacion estandarizados internacionalmente. Por ejemplo,

- 00 Codigo Seriado de la Unidad de Envio (SSCC)
- 01 Codigo de agrupacion
- 02 Codigo del articulo / agrupacion contenido
- 37 Cantidades (va junto al IA 02)
- 10 Numero de lote
- 11 Fecha de fabricacion
- 13 Fecha de envasado
- 15 Fecha de consumo preferente
- 17 Fecha de caducidad
etc.

En la practica NO nos preocuparemos de generar codigos correctos, sino que consideraremos como correcto cualquier codigo que tenga el formato (yy)xxxxz(yyy)xxxxxxxz(yy)xxxxxz, donde yyy e  xxxxxz  son digitos del 0 al 9 representando el IA y el codigo  asociado. (El alumno interesado puede consultar como se construyen los codigos enel enlace http://www.aecoc.es/BAJAR/.php?id_doc=1178&id=GS1%20128.pdf&folder=documento_socio


Veamos un ejemplo simple,
podemos considerar los siguientes codigos

(02)8423(10)0980(11)141215
(02)8423(10)0981(11)141215
(02)8324(10)0982(13)141010
(03)842442(10)211(73)0120(11)12334


El objetivo de la practica es construir un contenedor de codigos gs1, donde el objetivo principal es permitir el acceso lo mas rapido posible a un determinado codigo,  asumiendo que cada uno de los codigos que han sido obtenidos (por ejemplo, leidos de un codigo de barras del productos) es correcto.

@todo  Tareas a realizar: El alumno debera implementar la clase gs1Set , junto con el codigo de prueba de los distintos
 metodos.


*/

class gs1Set  {
public:

/** @typedef typedef size_type
Hace referencia al tipo asociado al numero de elementos en el codigo.

*/
  typedef unsigned int size_type;

  class const_iterator;


 /**
     @brief Constructor primitivo
     crea un gs1Set  con el el pair <"gs1",0> en el nodo raiz.
  */
  gs1Set ();
  /**
     @brief Constructor de copia.

     @param[in] x gs1Set  que se copia

  */
  gs1Set ( const gs1Set  & x);

  /**
     @brief Lectura de un gs1Set  por teclado.
     Se genera el gs1Set  utilizando un recorrido por nivel.

  */
   void reading_gs1Set (  );

  /** @brief operador de asignacion
@param[in] org gs1Set  a copiar.
 Crea un gs1Set   duplicado exacto a org.
*/
  gs1Set  & operator=( const gs1Set  & org);





/** @brief Inserta una nuevo codigo  dentro del  gs1Set

@param[in] s elemento a insertar
@return bool true si la insercion se ha podido realizar con exito, esto es,
el codigo  no pertenecia al gs1Set
@post  el size() sera incrementado
*/
  bool insert (const string & s);


/** @brief elimina  el codigo de un gs1Set

@param[in] s elemento a borrar. Este elemento puede identificar a un prefijo, por ejemplo el codigo asociado a un producto, por lo que todos los codigos que contienen dicho prefijo seran eliminados.
@return el numero de codigos que se han borrado, cero si el borrado no se ha podido realizar con exito
@post  el size() sera decrementado.

*/
  int erase( const string &s);

/** @brief busca un codigo
@param[in] s nombre del codigo (o prefijo) a buscar
@return un iterador que apunta al codigo o end() si el codigo (prefijo) no existe.
*/
const_iterator find( const string & s);

/** @brief obtiene todos los codigos que tienen la misma secuencia prefijo
@param[in] pr   prefijo  a buscar
@return una lista con todos los codigos epc que contienen el mismo prefijo
*/
list<string> codesWithPrefix( const string & pr);



/** @brief tamanioo
 * @return delvuelve el numero de palabras del gs1Set
*/
  size_type size() const;

/** @brief   Chequea si el gs1Set  esta vacio (size()==0)
*/
  bool empty() const;

/** @brief  iterador a la primera palabra del conjunto.

Este iterador debe apuntar al nodo en el que se encuentra el ultimo caracter de
la primera palabra en el conjunto.

*/
   const_iterator begin() const;

/** @brief  iterador al fin del conjunto
*/
 const_iterator end() const;

/** @brief  imprime todos los codigos almacenados
*/
  void print( ) const;


/************************************************************************/

/** \class gs1Set::const_iterator gs1Set .h

const_iterator: const_iterator, operator*, operator++

Descripcion


Un objeto de la clase gs1Set::const_iterator representara un iterador sobre el
conjunto de  codigos en el gs1Set .

Nota: Solo itera sobre (subcodigos) y no sobre los elementos individuales


*/
class const_iterator {
        public:

 /**
     @brief Constructor primitivo
  */
               const_iterator();
	       /**
	           @brief Constructor de copia
		   */
               const_iterator( const const_iterator & it);
	       /**
	            @brief devuelve el codigo completo al que apunta el
		     iterador.
		     Nota: Se encuentra en el camino que hay desde el nodo hacia la raiz.
		     */
               string  operator*();
	       /**
	            @brief avanza hacia el siguiente final de (sub)codigo en preorden en el gs1Set .
		     Nota: Avanza por el arbol  hasta el siguiente nodo que
		     es final de (sub)codigo.
		     */

               const_iterator & operator++();
	       /**
	            @brief avanza hacia  el siguiente final de (sub)codigo en preorden en el gs1Set.
		     Nota: Avanza por el arbol  hasta el siguiente nodo que
		     es final de (sub)codigo.
		     */
	       const_iterator operator++(int);
               /**
	            @brief sube hacia  el identificador de aplicacion (IA) anterior en el codigo.
		     */
            const_iterator & upper_IA();
            /**
                @brief hacer copia del iterador pasado
                return el iterador copiado
            */
            const_iterator & operator=(const const_iterator & it);
            /**
                @brief compara los datos miembro de los dos iteradores
                return true si son iguales, false si no lo son
            */
            bool operator==(const const_iterator & it) const;
            /**
                @brief compara los datos miembro de los dos iteradores
                return false si son iguales, true si no lo son
            */
            bool operator!=(const const_iterator & it) const;
        private:
	       friend class gs1Set ;

	       tree<pair<string,int> >::node act;
	       const gs1Set  *ptr; // Puntero al gs1Set  que apunta act;
               };




private:
/** @brief   Representacion.
El gs1Set  se representa mediante un arbol general (tree) donde en cada nodo  n, de tipo tree< pair<string,int> >::node, tenemos que (*n) es una referencia al par que almacena, cuyo primer elemento , esto es (*n).first,  es un string que representa un indentificador de aplicación IA, o un caracter aislado del código, en cuyo caso (*n).first.size()==0. En este último caso, necesariamente debe tomar valores en {0123456789}. Por otro lado, el segundo elemento del par, (*n).second,  es un entero que se utiliza para:

- identificar si el nodo es un IA, en cuyo caso debe verificarse que ((*n).second < 0)
 -identificar si el nodo contiene el caracter final de subcódigo (representado por z en el ejemplo anterior), donde  (*n).second > 0. En este caso, el valor será el número total de  codigos completos que cuelgan del mismo. Destacar que este valor NO corresponde con el número de hijos directos, sino con el número total de hojas que cuelgan del subárbol con raiz en n.

Los hijos de un nodo deben estar NECESARIAMENTE ORDENADOS de menor a mayor.

*/
  tree<pair<string,int> > arbol;
  unsigned int tama;

  bool cheq_rep();
};

#endif

