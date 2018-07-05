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
    pair<int,T> celda;
    celda.first=p;
    celda.second=t;
	//Si se sale del tamaño del vector, no hace nada
	if (p>=0&&p<n_ele){
	    //cout << "Ha llegado el elemento " << t << " en la posicion" << p << endl;
	    //Si el valor dado no es nulo hay que insertarlo en el map
        //Comprobamos si hay ya una entrada para esa posición en el map
        typename list<pair<int,T> >::iterator prueba;
        bool encontrado=false;
        for ( prueba=vd.begin();prueba!=vd.end()&&!encontrado;prueba++ ){
            if((*prueba).first==celda.first)
                encontrado=true;
        }
            prueba--;//Porque al hacer la última comprobación se va a la posición siguiente de la que nos interesa
        if (t!=v_nulo){

            //Si la hay, hay que cambiar el valor en esa posición
            if(encontrado){
                (*prueba).second=t;
                //*prueba.second=t;   //Ni idea de si funciona xD
                cout << "Modificamos el valor en la posición" << p << " de la entrada del list ya existente"<< endl;
            }
            //Si no hay entrada en el map, la insertamos EN SU POSICIÓN CORRECTA
            else{
                auto it_list=vd.begin();
                bool zona_encontrada=false;
                for (it_list;it_list != vd.end() && !zona_encontrada;it_list++){
                    if ( p>(*it_list).first ){
                        zona_encontrada=true;
                        vd.insert(it_list, celda);
                    }
                }
                //Ordenamos el list
                cout << "Introducimos la posición "<< p << " en el list (que no existía)"<< endl;
            }
        }
        //Si el valor es nulo pero hay una entrada en el map para esa posición, la borramos
        else{
            if(encontrado){
                vd.erase(prueba);
                cout << "Como el valor "<< t <<" es el de por defecto, eliminamos la entrada del list de la posición "<< p << endl;
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
        cout << t << " no es un valor por defecto, luego se inserta en el list " << endl;
        //Insertamos en el list en el orden adecuado
        /*
        typename list<pair<int,T>>::iterator prueba;
        typename list<pair<int,T>>::iterator prueba2;
        bool encontrado=false;
        for ( prueba=vd.begin();prueba!=vd.end()&&!encontrado;prueba++ ){
            if(*prueba.first>*prueba2.first)
                encontrado=true;
            prueba2++;
        }
        prueba--;
        */

		pair<int,T> par;
		par.first=n_ele;
		par.second=t;

		vd.push_back(par);
	}
	else{
        cout << t <<" es un valor por defecto, luego no se inserta en el list" << endl;
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
        typename list<pair<int,T> >::iterator prueba;
        bool encontrado=false;
        for ( prueba=vd.begin();prueba!=vd.end()&&!encontrado;prueba++ ){
            if((*prueba).first==n_ele-1)
                encontrado=true;
        }
            prueba--;//Porque al hacer la última comprobación se va a la posición siguiente de la que nos interesa
	    if ( encontrado ){
            vd.erase(prueba);
            cout << "Se borra el último elemento del vector  del list"<< endl;
	    }
	    else{
	    cout << "Se borra el último elemento del vector, pero no del list (porque contenía valor nulo)"<< endl;
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
        auto prueba=vd.begin();
        bool encontrado=false;
        for ( prueba;prueba!=vd.end()&&!encontrado;prueba++ ){
            if((*prueba).first==c)
                encontrado=true;
        }
        prueba--;
		if(encontrado)
			return (*prueba).second;
		else
			return v_nulo;
	}
	else{
		return v_nulo;
	}

}
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes*/
/**
    @brief Devuelve el valor en la posición dada.
    @param[in] c Posición a buscar el valor.
    @pre Debe existir esa posición en el vector.
    @return El valor en esa posición.
*/
template <typename T>
const  T  & vectorD<T>::at(int c) const  {
	if (c>=0&&c<n_ele){
        auto prueba=vd.begin();
        bool encontrado=false;
        for ( prueba;prueba!=vd.end()&&!encontrado;prueba++ ){
            if((*prueba).first==c)
                encontrado=true;
        }
        prueba--;
		if(encontrado)
			return (*prueba).second;
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

    typename list<pair<int,T> >::iterator prueba;
    bool encontrado=false;
    for ( prueba=vd.begin();prueba!=vd.end()&&!encontrado;prueba++ ){
        if(*prueba.first==v_nulo)
            encontrado=true;
    }
   	if (encontrado)
        return 2;
   	}
   	//Caso 3 implementado en el assign (y en el push_back nunca podría ser menor a 0)
    //Caso 4 no se puede dar, porque no se puede cambiar el valor K que es la posición en el vector,
    //y con nuestro push_back también vas aumentando el valor K y se inserta al final del list

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
        //Si ite_rep se ha quedado atrás, adelántalo a la siguiente posición
        if (i_vect>(*ite_rep).first){
            ite_rep++;
        }

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
        //Si ite_rep se ha quedado atrás, adelántalo a la siguiente posición
        if (i_vect>(*ite_rep).first){
            ite_rep++;
        }
        //bool encontrado=false;
        //auto prueba=(*el_vect).vd.begin();
        //for ( prueba; prueba!=(*el_vect).vd.end()&&!encontrado; prueba++){
        //    if( (*prueba).first==i_vect ){
        //        ite_rep=prueba;
        //       encontrado=true;
        //    }
        //}
        return sal;
    }
    /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor T de la posición sobre todo el vector en la que se encuentra el iterador
    */
    template <typename T>
    const  T & vectorD<T>::iterator::operator *( ){
        if(i_vect!=(*ite_rep).first)
            return (*el_vect).v_nulo;
        else
            return (*ite_rep).second;

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
        i_vect++;
        //Si ite_rep se ha quedado atrás, adelántalo a la siguiente posición
        if (i_vect>(*ite_rep).first){
            ite_rep++;
        }

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
        //Si ite_rep se ha quedado atrás, adelántalo a la siguiente posición
        if (i_vect>(*ite_rep).first){
            ite_rep++;
        }
        //bool encontrado=false;
        //auto prueba=(*el_vect).vd.begin();
        //for ( prueba; prueba!=(*el_vect).vd.end()&&!encontrado; prueba++){
        //    if( (*prueba).first==i_vect ){
        //        ite_rep=prueba;
        //       encontrado=true;
        //    }
        //}
        return sal;
    }
    /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor T de la posición sobre todo el vector en la que se encuentra el iterador
    */
    template <typename T>
    const  T & vectorD<T>::const_iterator::operator *( ){
        if(i_vect!=(*ite_rep).first)
            return (*el_vect).v_nulo;
        else
            return (*ite_rep).second;

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
