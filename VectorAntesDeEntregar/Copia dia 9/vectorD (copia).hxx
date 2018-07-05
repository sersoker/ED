/* vectorD.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aarón Rodríguez Bueno
 *
 */

/////////////////////////////////////////
//////////// constructores //////////////
/////////////////////////////////////////
template<typename T>
vectorD<T>::vectorD( const  T  & t=  T () ){

}
// constructor por defecto. t hace referencia al valor por defecto del vector

template<typename T>
vectorD<T>::vectorD(  const vectorD< T > & b){

}
/** constructor primitivo que hace una copia del vector disperso b. */

 template<typename T>
vectorD<T>::vectorD( int numcomp, const  T  & t =  T () ){

}
/** constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp deve ser mayor que cero.
t hace referencia al valor por defecto
 */


///////////////////////////////////////
/////////////// destructor ////////////
///////////////////////////////////////
  template<typename T>
vectorD<T>::~vectorD(){

}


////////////////////////////////////
/////////// Consultores ////////////
///////////////////////////////////
template <typename T>
typename vectorD<T>::size_type vectorD<T>::size() const{

}
// Devuelve el tamaño del vectorD

template <typename T>
typename vectorD<T>::T  default_value( ) const;

//Devuelve el valor por defecto

template <typename T>
bool vectorD<T>::empty(){

}
// el vectorD esta vacio



///////////////////////////////////////////////
///////////// MODIFICADORES //////////////////
/////////////////////////////////////////////
template <typename T>
void vectorD<T>::assign(int p, const  T  & t){

}
// Cambia a el valor t el valor de la posicion p-esima del vector. No modifica el size del vector
template <typename T>
void vectorD<T>::push_back( const  T  & t){

}
// Inserta un elemento al final del vectorD. Aumenta en 1 el tamanio
template <typename T>
void vectorD<T>::pop_back(  ){

}
// elimina un elemento del vectorD. Disminuye en 1 el tamanio
template <typename T>
void vectorD<T>::clear(){

}
// elimina todos los elementos del vectorD. Tamanio es 0
template <typename T>
void vectorD<T>::resize(int s){

}
// cambia el tama~no del vector a "s" elementos. Si s es menor que el tama~no actual, elimina los restantes. Si es mayor,
//amplia la capacidad del vector asignando a todos los nuevos elementos el valor nulo.




///////////////////////////////////////////////
/////////////// operadores ///////////////////
/////////////////////////////////////////////
template <typename T>
vectorD<T> & vectorD<T>::operator= (const vectorD & x);
// operador de asignacion
template <typename T>
const  T  & vectorD<T>::operator[](int c) const  ;
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes*/
template <typename T>
const  T  & vectorD<T>::at(int c) const  ;
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes
Hace comprobacion de rango */
template <typename T>
bool vectorD<T>::operator==( const typename vectorD<T>::vectorD & x);
/** devuelve verdadero si tienen los mismos elementos y false en caso contrario */
template <typename T>
bool vectorD<T>::operator!=( const typename vectorD<T>::vectorD & x);
/** devuelve verdadero si no tienen los mismos elementos y false en caso contrario */


//////////////////////////////////////////
///////////////ITERADORES////////////////
/////////////////////////////////////////
template <typename T>
typename vectorD<T>::iterator  vectorD<T>::begin(){}
/** iterador (read) al inicio sobre todos los elementos del vector */
template <typename T>
typename vectorD<T>::iterator  vectorD<T>::end(){}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector */
template <typename T>
typename vectorD<T>::const_iterator vectorD<T>::cbegin() const{}
/** iterador  (read) inicio sobre todos los elementos del vector */
template <typename T>
typename  vectorD<T>::const_iterator  vectorD<T>::cend() const{}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector */
template <typename T>
typename vectorD<T>::stored_iterator  vectorD<T>::sbegin(){}
/** iterador  (read) inicio sobre elementos no nulos */
template <typename T>
typename  vectorD<T>::stored_iterator  vectorD<T>::send(){}
/** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */
template <typename T>
typename vectorD<T>::const_stored_iterator  vectorD<T>::csbegin() const{}
/** iterador  (read) inicio sobre elementos no nulos */
template <typename T>
typename vectorD<T>::const_stored_iterator  vectorD<T>::csend() const{}
/** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */


//////////////////////////////////////////
///////////////Invariante////////////////
/////////////////////////////////////////
template <typename T>
   int vectorD<T>::checkRep(){

   }


////////////////////////////////////////////////////////////////////
//////////////////OPERADORES/CONSTRUCTORES ITERADORES////////////////
////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////
	//////////////STORED_ITERATOR///////////////////
	////////////////////////////////////////////////
    template <typename T>
	vectorD<T>::stored_iterator::stored_iterator() {}
    template <typename T>
	vectorD<T>::stored_iterator::stored_iterator(const typename vectorD<T>::stored_iterator & d) : ite(d.ite) {}
    template <typename T>
	const typename vectorD<T>::pair<int, T > & vectorD<T>::stored_iterator::operator *(  ) {
		return (*ite);
	}
    template <typename T>
	typename vectorD<T>::stored_iterator & vectorD<T>::stored_iterator::operator++( ) {++ite; return *this;}
    template <typename T>
	typename vectorD<T>::stored_iterator::stored_iterator vectorD<T>::stored_iterator operator++(int ) {
		stored_iterator tmp(*this); ++ite; return tmp;
	}
    template <typename T>
	bool vectorD<T>::stored_iterator::operator == (const typename vectorD<T>::stored_iterator & d) {return ite == d.ite;}
    template <typename T>
	bool vectorD<T>::stored_iterator::operator != (const typename vectorD<T>::stored_iterator & d) {return ite != d.ite; }

	////////////////////////////////////////////////
	///////////////////ITERATOR/////////////////////
	////////////////////////////////////////////////
	template <typename T>
	vectorD<T>::iterator::iterator() {}
	template <typename T>
    vectorD<T>::iterator::iterator(const typename vectorD<T>::iterator::iterator & d){}
	template <typename T>
    const typename vectorD<T>::T  & vectorD<T>::iterator::operator *(  ) {}
	template <typename T>
    typename vectorD<T>::iterator::iterator & vectorD<T>::iterator::operator++( ){}
	template <typename T>
    typename vectorD<T>::iterator vectorD<T>::iterator::operator++(int ) {}
	template <typename T>
    bool vector<T>::iterator::operator == (const typename vectorD<T>::iterator & d) {}
	template <typename T>
    bool vectorD<T>::iterator::operator != (const  typename vectorD<T>::iterator & d){}
	template <typename T>
    typename vectorD<T>::iterator & vectorD<T>::iterator::operator=(const vector<T>::iterator & d){}

	////////////////////////////////////////////////
	////////////CONST_STORED_ITERATOR///////////////
	////////////////////////////////////////////////
	template <typename T>
	vectorD<T>::const_stored_iterator::const_stored_iterator(){}
    template <typename T>
	vectorD<T>::const_stored_iterator::const_stored_iterator(const typename vectorD<T>::const_stored_iterator::const_stored_iterator & d) {}
    template <typename T>
	vectorD<T>::const_stored_iterator::const_stored_iterator(const stored_iterator & d) {}
	// Conversion de iterator a const_iterator
    template <typename T>
    const typename vectorD<T>::pair<int, T > & vectorD<T>::const_stored_iterator::operator *(  ) {}
	template<typename T>
    typename vectorD<T>::const_stored_iterator & vectorD<T>::const_stored_iterator::operator++( ) {}
	template <typename T>
    typename vectorD<T>::const_stored_iterator vectorD<T>::const_stored_iterator::operator++(int ) {}
	template <typename T>
    bool vectorD<T>::const_stored_iterator::operator == (const typename vectorD<T>::const_stored_iterator & d) {}
	template <typename T>
    bool vectorD<T>::const_stored_iterator::operator != (const typename vectorD<T>::const_stored_iterator & d) {}
    template <typename T>
	typename vectorD<T>::const_stored_iterator & vectorD<T>::const_stored_iterator::operator= (typename 	vectorD<T>::const_iterator::const_iterator & d) {}

	////////////////////////////////////////////////
	/////////////////CONST_ITERATOR/////////////////
	////////////////////////////////////////////////
	template <typename T>
	vectorD<T>::const_iterator::const_iterator() {}
        template <typename T>
	vectorD<T>::const_iterator::const_iterator(const typename vectorD<T>::const_iterator::const_iterator & d) {}
        template <typename T>
	vectorD<T>::const_iterator::const_iterator(const iterator & d) {}
	// Conversion de iterator a const_iterator
	template <typename T>
	const  typename vectorD<T>::T  &  vectorD<T>::const_iterator::operator *(  ) {}
	template <typename T>
	typename vectorD<T>::const_iterator & vectorD<T>::const_iterator::operator++( ) {}
	template <typename T>
	typename vectorD<T>::const_iterator vectorD<T>::const_iterator::operator++(int ) {}
	template <typename T>
        bool vectorD<T>::const_iterator::operator == (const typename vectorD<T>::const_iterator & d) {}
	template <typename T>
        bool vectorD<T>::const_iterator::operator != (const typename vectorD<T>::const_iterator & d) {}

