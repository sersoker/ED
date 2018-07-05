/* vectorD.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aarón Rodríguez Bueno
 *
 */

/////////////////////////////////////////
//////////// constructores //////////////
/////////////////////////////////////////
	/** @brief constructor primitivo.
        @post se crea un contenedor que es un dato miembro de la clase vectorD.
	*/
template<typename T>
vectorD<T>::vectorD( const T  & t ){
    n_ele=0;
    v_nulo=t;
}
// constructor por defecto. t hace referencia al valor por defecto del vector
	/** @brief constructor de copia.
        @post se crea un contenedor que es un dato miembro de la clase vectorD.
	*/
template<typename T>
vectorD<T>::vectorD(  const vectorD< T > & b){
    v_nulo=b.v_nulo;
    n_ele=b.n_ele;
    vd=b.vd;
}
/** constructor primitivo que hace una copia del vector disperso b. */

/** @brief constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp deve ser mayor que cero.
t hace referencia al valor por defecto
    @post se crea un contenedor que es un dato miembro de la clase vectorD.
 */
 template<typename T>
vectorD<T>::vectorD( int numcomp, const  T  & t){
    n_ele=numcomp;
    v_nulo=t;
}
/** constructor primitivo que crea un vectorD con numcomp componentes, todas ellas iguales a t. numcomp deve ser mayor que cero.
t hace referencia al valor por defecto
 */


///////////////////////////////////////
/////////////// destructor ////////////
///////////////////////////////////////
	/** @brief destructor.
	@post se destruye el objeto de la clase vectorD
	*/
template<typename T>
vectorD<T>::~vectorD( ){
   //cout << "destructor " << endl;
}


////////////////////////////////////
/////////// Consultores ////////////
///////////////////////////////////
/** @brief Devuelve el tamaño del vector.
    @return el tamaño del vector.
*/

template <typename T>
typename vectorD<T>::size_type vectorD<T>::size() const{
	return n_ele;
}
// Devuelve el tamaño del vectorD

/**
    @brief Devuelve el valor por defecto del vectorD.
    @return un el valor nulo tipo T.

*/
template <typename T>
T  vectorD<T>::default_value( ) const{

	return v_nulo;

}
//Devuelve el valor por defecto
/**
    @brief Devuelve si el vectorD está vacío.
    @return un booleano.

*/
template <typename T>
bool vectorD<T>::empty(){
	if(n_ele==0)
		return true;
	else
		return false;
}
// el vectorD esta vacio


///////////////////////////////////////////////
///////////// MODIFICADORES //////////////////
/////////////////////////////////////////////
/**
    @brief Asigna a una posición dada un valor de T dado.
    @param[in] p La posición en el vectorD.
    @param[in] t El valor a insertar en el vector en la posición p.
    @pre la posición dada debe estar dentro del tamaño del vector.
    @post La posición p del vector es modificada. Internamente, puede crearse una nueva posición, eliminarse
    o modificarse, dependiendo del valor anterior y del valor nuevo dado.
*/

template <typename T>
void vectorD<T>::assign(int p, const  T  & t){

	//Si se sale del tamaño del vector, no hace nada
	if (p<n_ele&&p>=0){
	    //cout << "Ha llegado el elemento " << t << " en la posicion" << p << endl;
	    //Si el valor dado no es nulo hay que insertarlo en el map
        if (t!=v_nulo){
            //Comprobamos si hay ya una entrada para esa posición en el map
            typename map<int,T>::iterator prueba = vd.find(p);
            //Si la hay, hay que cambiar el valor en esa posición
            if(prueba!=vd.end()){
                //*prueba.second=t;   //Ni idea de si funciona xD
                cout << "Modificamos el valor en la posición" << p << " de la entrada del map ya existente"<< endl;
                vd.at(p)=t;
            }
            //Si no hay entrada en el map, la insertamos
            else{
                pair<int,T> par;
                par.first=p;
                par.second=t;

                vd.insert(par);
                cout << "Introducimos la posición "<< p << " en el map (que no existía)"<< endl;
            }
        }
        //Si el valor es nulo pero hay una entrada en el map para esa posición, la borramos
        else{
            typename map<int,T>::iterator prueba = vd.find(p);
            if(prueba!=vd.end()){
                vd.erase(prueba);
                cout << "Como el valor "<< t <<" es nulo, eliminamos la entrada del map de la posición "<< p << endl;
            }
        }
    }
    else{
        cout << "Se sale de rango del vector la posicion " << p << endl;
    }
}

// Cambia a el valor t el valor de la posicion p-esima del vector. No modifica el size del vector
/**
    @brief Inserta en la posición siguiente a la última del vector el valor dado.
    @param[in] t el valor a insertar.
    @post el tamaño del vector se incrementa en 1 y si es un valor no nulo, se inserta en el contenedor interno vd.
*/

template <typename T>
void vectorD<T>::push_back( const  T  & t){
	//cout << "Ha llegado el elemento " << t << " añadiendo en la posicion " << n_ele << endl;
	if ( t != v_nulo ){
	    cout << t << " es un valor no nulo, luego se inserta en el map " << endl;
		pair<int,T> par;
		par.first=n_ele;
		par.second=t;

		vd.insert(par);
	}
	else{
        cout << t <<" es un valor no nulo, luego no se inserta en el map" << endl;
	}
    n_ele++;
}

// Inserta un elemento al final del vectorD. Aumenta en 1 el tamanio
/**
    @brief Elimina del vector la última posición.
    @pre El vector no puede estar vacío.
    @post El tamaño del vector se decrementa en 1 y si era un valor no nulo en la última posición,
    se elimina también del contenedor interno.
*/

template <typename T>
void vectorD<T>::pop_back(  ){


	if(n_ele>0){
        typename map<int,T>::iterator prueba = vd.find(n_ele-1);
	    if ( prueba!=vd.end() ){
            vd.erase(n_ele-1);
            cout << "Se borra el último elemento del vector  del map"<< endl;
	    }
	    else{
	    cout << "Se borra el último elemento del vector, pero no del map (porque contenía valor nulo)"<< endl;
	    }
		n_ele--;
	}

}
// elimina un elemento del vectorD. Disminuye en 1 el tamanio
/**
    @brief Elimina todo el contenido del vector.
    @post el tamaño del vector es 0 y se elimina todo el contenido del contenedor interno.
*/
template <typename T>
void vectorD<T>::clear(){
	n_ele=0;
	vd.clear();

}
// elimina todos los elementos del vectorD. Tamanio es 0
/**
    @brief Redimensiona el vector
    @param[in] s El nuevo tamaño del vector
    @post si fuera menor, se eliminan las posiciones que superen el parámetro dado,
    y si fuera mayor, se insertan en todas las posiciones nuevas el valor nulo
*/
template <typename T>
void vectorD<T>::resize(int s){
	if (s!=n_ele && s>=0){
		if(s>n_ele){
			n_ele=s;
		}
		else{
			do{
			this.pop_back(); //Como llama al método nuestro y él mismo comprueba si está el último elemento del map, lo dejo tal cual
			}while(n_ele!=s);
		}


	}

}
// cambia el tama~no del vector a "s" elementos. Si s es menor que el tama~no actual, elimina los restantes. Si es mayor,
//amplia la capacidad del vector asignando a todos los nuevos elementos el valor nulo.





///////////////////////////////////////////////
/////////////// operadores ///////////////////
/////////////////////////////////////////////
/**
    @brief Asigna el comportamiento del operador =
    @param[in] x Vector con el que hay que igualar el actual
    @return el vector actual modificado
    @post Iguala los datos miembros del vector actual con los del dado
*/

template <typename T>
vectorD<T> & vectorD<T>::operator= (const vectorD & x){
	v_nulo=x.v_nulo;
	n_ele=x.n_ele;
	vd=x.vd;

}
// operador de asignacion
/**
    @brief Asigna el comportamiento del operador []
    @param[in] c Posición a buscar el valor a devolver
    @return el valor a devolver en esa posición
*/
template <typename T>
const  T  & vectorD<T>::operator[](int c) const  {
	if (c>=0&&c<n_ele){
		if(vd.count(c)>0)
			return vd.at(c);
		else
			return v_nulo;

	}
	else{
		return v_nulo;
	}

}
/**
    @brief Devuelve el valor en la posición dada.
    @param[in] c Posición a buscar el valor.
    @pre Debe existir esa posición en el vector.
    @return El valor en esa posición.
*/
template <typename T>
const  T  & vectorD<T>::at(int c) const  {
	if (c>=0&&c<n_ele){
		if(vd.count(c)>0)
			return vd.at(c);
		else
			return v_nulo;

	}
	else{
	    cout << "LA POSICIÓN "<<c<<" ESTÁ FUERA DEL RANGO DEL VECTOR!!!" <<endl;
        //class out_of_range : public logic_error {
        //public:
        //  explicit out_of_range (const string& what_arg);
        //  explicit out_of_range (const char* what_arg);
        //};
		return v_nulo;
	}

}
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes
Hace comprobacion de rango */
/**
    @brief devuelve si los datos miembros de los dos objetos son iguales o no
    @param[in] x Vector con el que comprobar
    @return verdadero si tienen los mismos elementos y false en caso contrario
*/
template <typename T>
bool vectorD<T>::operator==( const typename vectorD<T>::vectorD & x){
	if(x.vd==vd&&x.n_ele==n_ele&&x.v_nulo==v_nulo)
		return true;
	else
		return false;

}
/** devuelve verdadero si tienen los mismos elementos y false en caso contrario */
/**
    @brief devuelve si los datos miembros de los dos objetos son distintos o no
    @param[in] x Vector con el que comprobar
    @return falso si tienen los mismos elementos y verdadero en caso contrario
*/
template <typename T>
bool vectorD<T>::operator!=( const typename vectorD<T>::vectorD & x){
	if(x.vd==vd&&x.n_ele==n_ele&&x.v_nulo==v_nulo)
		return false;
	else
		return true;

}
/** devuelve verdadero si no tienen los mismos elementos y false en caso contrario */


//////////////////////////////////////////
///////////////Invariante////////////////
/////////////////////////////////////////
    /**
    @brief Verifica si los datos miembro están correctos
    @return entero, 0 si no hay error, otro número indica que hay un error y en qué
    */

template <typename T>
   int vectorD<T>::checkRep(){
   	if(!(0<=vd.size()&&vd.size()<n_ele))
   		return 1;

   	for(int i=0;i<vd.size()-1;i++) {
   		if (vd[i]==v_nulo)
   			return 2;
   	}
   	//Los casos 3 y 4 no se pueden dar por la forma de implementar el assign y el push
   }

     /* IR :
      IR(rep): rep ---> bool
     (vd,n_ele,v_nulo) :
      0 <= vd.size() < n_ele;  //Fallo tipo 1
      vd[i].second != v_nulo, para todo i = 0, ..., vd.size()-1; // Fallo tipo 2
      vd[i].first >=0, para todo i = 0, ..., vd.size()-1; // Fallo tipo 3
      vd[i].first < vd[j].first si i<j // Fallo tipo 4
     */



//////////////////////////////////////////
///////////////ITERADORES////////////////
/////////////////////////////////////////

    //////////////////////////////////////////
    ///////////////iterator////////////////
    /////////////////////////////////////////
/**
    @brief Devuelve un iterador al principio del vectorD
    @return iterador (read) al inicio sobre todos los elementos del vector
*/
    template <typename T>
    typename vectorD<T>::iterator  vectorD<T>::begin(){
        typename vectorD<T>::iterator sal;
        sal.i_vect=0;
        sal.ite_rep=vd.begin();
        sal.el_vect=this;
        return sal;
    }
    /** iterador (read) al inicio sobre todos los elementos del vector */
/**
    @brief Devuelve un iterador al final del vectorD
    @return iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector
*/
    template <typename T>
    typename vectorD<T>::iterator  vectorD<T>::end(){
        typename vectorD<T>::iterator sal;
        sal.ite_rep=vd.end();
        sal.i_vect=n_ele;
        sal.el_vect=this;
        return sal;
    }
    /** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector */

    //////////////////////////////////////////
    ///////////////citerator////////////////
    /////////////////////////////////////////
/**
    @brief Devuelve un iterador constante al principio del vectorD
    @return iterador  (read) inicio sobre todos los elementos del vector
*/
    template <typename T>
    typename vectorD<T>::const_iterator vectorD<T>::cbegin() const{
        typename vectorD<T>::const_iterator sal;
        sal.i_vect=0;
        sal.ite_rep=vd.cbegin();
        sal.el_vect=this;
        return sal;
    }
    /** iterador  (read) inicio sobre todos los elementos del vector */
/**
    @brief Devuelve un iterador constante al final del vectorD
    @return iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector
*/
    template <typename T>
    typename  vectorD<T>::const_iterator  vectorD<T>::cend() const{
        typename vectorD<T>::const_iterator sal;
        sal.ite_rep=vd.cend();
        sal.i_vect=n_ele;
        sal.el_vect=this;
        return sal;
    }
    /** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del vector */

    //////////////////////////////////////////
    ///////////////siterator////////////////
    /////////////////////////////////////////
/**
    @brief Devuelve un stored_iterator al principio del vectorD
    @return iterador  (read) inicio sobre elementos no nulos
*/
    template <typename T>
    typename vectorD<T>::stored_iterator  vectorD<T>::sbegin(){
        typename vectorD<T>::stored_iterator sal;
        sal.ite=vd.begin();
        return sal;
    }
    /** iterador  (read) inicio sobre elementos no nulos */
/**
    @brief Devuelve un stored_iterator al final del vectorD
    @return iterador  (read) final (siguiente al ultimo) sobre elementos no nulos
*/
    template <typename T>
    typename  vectorD<T>::stored_iterator  vectorD<T>::send(){
        typename vectorD<T>::stored_iterator sal;
        sal.ite=vd.end();
        return sal;
    }
    /** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */

    //////////////////////////////////////////
    ///////////////csiterator////////////////
    /////////////////////////////////////////
/**
    @brief Devuelve un const_stored_iterator al principio del vectorD
    @return iterador  (read) inicio sobre elementos no nulos
*/
    template <typename T>
    typename vectorD<T>::const_stored_iterator  vectorD<T>::csbegin() const{
        typename vectorD<T>::const_stored_iterator sal;
        sal.ite=vd.cbegin();
        return sal;
    }
    /** iterador  (read) inicio sobre elementos no nulos */
/**
    @brief Devuelve un const_stored_iterator al final del vectorD
    @return iterador  (read) final (siguiente al ultimo) sobre elementos no nulos
*/
    template <typename T>
    typename vectorD<T>::const_stored_iterator  vectorD<T>::csend() const{
        typename vectorD<T>::const_stored_iterator sal;
        sal.ite=vd.cend();
        return sal;
    }
    /** iterador  (read) final (siguiente al ultimo) sobre elementos no nulos */


////////////////////////////////////////////////////////////////////
//////////////////OPERADORES/CONSTRUCTORES ITERADORES////////////////
////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////
    //////////////STORED_ITERATOR///////////////////
    ////////////////////////////////////////////////
 /**
    @brief constructor por defecto
    @post se crea un iterador sobre el contenedor interno
  */
    template <typename T>
    vectorD<T>::stored_iterator::stored_iterator() {
    }
    /**
    @brief constructor de copia
    @post se crea un iterador con el mismo valor para los datos miembros que el iterador dado
  */
    template <typename T>
    vectorD<T>::stored_iterator::stored_iterator(const typename vectorD<T>::stored_iterator & d) : ite(d.ite) {
        ite=d.ite;
    }
	

    ////////////////////////////////////////////////
    ///////////////////ITERATOR/////////////////////
    ////////////////////////////////////////////////
  /**
    @brief constructor por defecto
    @post se crea un iterador que actúa sobre todas las posiciones del vector
  */
    template <typename T>
    vectorD<T>::iterator::iterator() {

    }
    /**
    @brief constructor de copia
    @post se crea un iterador con el mismo valor para los datos miembros que el iterador dado
  */
    template <typename T>
    vectorD<T>::iterator::iterator(const typename vectorD<T>::iterator::iterator & d){
        ite_rep=d.ite_rep;
        el_vect=d.el_vect;
        i_vect=d.i_vect;
    }
    /**
    @brief devuelve el iterador hacia la siguiente posición en el vector
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre el vector disperso. Si el iterador de la stl se ha quedado atrás,
    se actualiza a la siguiente posición sobre vd
    */
    template <typename T>
    typename vectorD<T>::iterator::iterator & vectorD<T>::iterator::operator++( ){
        i_vect++;
         if((*el_vect).vd.find(i_vect)!=(*el_vect).vd.end())
            ite_rep=vd.find(i_vect);

        return *this;
    }
    /**
    @brief devuelve una copia del iterador en la posición actual, y el iterador avanza hacia la siguiente posición en el vector
    @return la copia del iterador con la posición antes de actualizarla
    @post se incrementa la posición sobre el vector disperso. Si el iterador de la stl se ha quedado atrás,
    se actualiza a la siguiente posición sobre vd
    */
    template <typename T>
    typename vectorD<T>::iterator vectorD<T>::iterator::operator++(int ) {
        typename vectorD<T>::iterator sal;
        sal = *this;

        i_vect++;
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            ite_rep=(*el_vect).vd.find(i_vect);

        return sal;
    }
    /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor T de la posición sobre todo el vector en la que se encuentra el iterador
    */
    template <typename T>
    const  T & vectorD<T>::iterator::operator *( ){
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            return (*el_vect).v_nulo;
        else
            return (*(*el_vect).vd.find(i_vect)).second;

    }
    /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre todo el vector
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */

    template <typename T>
    bool vectorD<T>::iterator::operator == (const typename vectorD<T>::iterator & d) {
        return d.ite_rep==ite_rep&&d.el_vect==el_vect&&i_vect==d.i_vect;
    }
    /**
    @brief identifica si el iterador actual está apuntando a distinto sitio que el dado
    @param[in] d iterador sobre todo el vector
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */
    template <typename T>
    bool vectorD<T>::iterator::operator != (const  typename vectorD<T>::iterator & d){
        return d.ite_rep!=ite_rep||d.el_vect!=el_vect||i_vect!=d.i_vect;
    }
    /**
    @brief iguala los datos miembro de este objeto con los del dado
    @param[in] d iterador sobre todo el vector
    @return este objeto con los datos miembro actualizados
    @post se actualizan los datos miembros del objeto
    */
    template <typename T>
    typename vectorD<T>::iterator & vectorD<T>::iterator::operator=(const typename vectorD<T>::iterator & d){
        ite_rep=d.ite_rep;
        i_vect=d.i_vect;
        el_vect=d.el_vect;
    }

    ////////////////////////////////////////////////
    ////////////CONST_STORED_ITERATOR///////////////
    ////////////////////////////////////////////////
  /**
    @brief constructor por defecto
    @post se crea un iterador constante sobre el contenedor interno
  */
	template <typename T>
    vectorD<T>::const_stored_iterator::const_stored_iterator(){
    }
  /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador constante dado
  */
    template <typename T>
    vectorD<T>::const_stored_iterator::const_stored_iterator(const typename vectorD<T>::const_stored_iterator::const_stored_iterator & d) {
        ite=d.ite;
    }
  /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador dado
  */
    template <typename T>
    vectorD<T>::const_stored_iterator::const_stored_iterator(const stored_iterator & d) {
        ite=d.ite;
    }
    // Conversion de iterator a const_iterator
    /**
    @brief Iguala los datos miembro del iterador a los del dado
    @param[in] d iterador al que se va a igualar
    @return este iterador con los datos miembro ya igualados
    */
    template <typename T>
    typename vectorD<T>::const_stored_iterator & vectorD<T>::const_stored_iterator::operator= (const typename vectorD<T>::const_stored_iterator::const_stored_iterator & d) {
        ite=d.ite;
    }

    ////////////////////////////////////////////////
    /////////////////CONST_ITERATOR/////////////////
    ////////////////////////////////////////////////
	  /**
    @brief constructor por defecto
    @post se crea un iterador constante que actúa sobre todas las posiciones del vector
  */

    template <typename T>
    vectorD<T>::const_iterator::const_iterator() {
        i_vect=0;
    }
 /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador constante dado
  */
    template <typename T>
    vectorD<T>::const_iterator::const_iterator(const typename vectorD<T>::const_iterator::const_iterator & d) {
        ite_rep=d.ite_rep;
        i_vect=d.i_vect;
    }
    /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador dado
  */	
        template <typename T>
    vectorD<T>::const_iterator::const_iterator(const typename vectorD<T>::iterator & d) {
        ite_rep=d.ite_rep;
        i_vect=d.i_vect;
    }
    // Conversion de iterator a const_iterator
    /**
    @brief devuelve el iterador hacia la siguiente posición en el vector
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre el vector disperso. Si el iterador de la stl se ha quedado atrás,
    se actualiza a la siguiente posición sobre vd
    */
    template <typename T>
    typename vectorD<T>::const_iterator & vectorD<T>::const_iterator::operator++( ) {
        typename vectorD<T>::const_iterator sal;


        i_vect++;
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            ite_rep=(*el_vect).vd.find(i_vect);
        return *this;
    }
    /**
    @brief devuelve una copia del iterador en la posición actual, y el iterador avanza hacia la siguiente posición en el vector
    @return la copia del iterador con la posición antes de actualizarla
    @post se incrementa la posición sobre el vector disperso. Si el iterador de la stl se ha quedado atrás,
    se actualiza a la siguiente posición sobre vd
    */
    template <typename T>
    typename vectorD<T>::const_iterator vectorD<T>::const_iterator::operator++(int ) {
        typename vectorD<T>::const_iterator sal;
        sal = *this;

        i_vect++;
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            ite_rep=(*el_vect).vd.find(i_vect);

        return sal;
    }
    /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor T de la posición sobre todo el vector en la que se encuentra el iterador
    */
    template <typename T>
    const  T & vectorD<T>::const_iterator::operator *( ){
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            return (*el_vect).v_nulo;
        else
            return (*(*el_vect).vd.find(i_vect)).second;

    }
    /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre el contenedor interno
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */
    template <typename T>
    bool vectorD<T>::const_iterator::operator == (const typename vectorD<T>::const_iterator & d) {
        return d.ite_rep==ite_rep;
        }
    /**
    @brief identifica si el iterador actual está apuntando a distinto sitio que el dado
    @param[in] d iterador sobre todo el vector
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */
		
    template <typename T>
    bool vectorD<T>::const_iterator::operator != (const typename vectorD<T>::const_iterator & d) {
        return d.ite_rep!=ite_rep;
    }



