/* vectorD.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aarón Rodríguez Bueno
 *
 */

/////////////////////////////////////////
//////////// constructores //////////////
/////////////////////////////////////////
template<typename T>
vectorD<T>::vectorD( const T  & t ){
    n_ele=0;
    v_nulo=t;
}
// constructor por defecto. t hace referencia al valor por defecto del vector

template<typename T>
vectorD<T>::vectorD(  const vectorD< T > & b){
    v_nulo=b.v_nulo;
    n_ele=b.n_ele;
    vd=b.vd;
}
/** constructor primitivo que hace una copia del vector disperso b. */

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
template<typename T>
vectorD<T>::~vectorD( ){
   //cout << "destructor " << endl;
}


////////////////////////////////////
/////////// Consultores ////////////
///////////////////////////////////

template <typename T>
typename vectorD<T>::size_type vectorD<T>::size() const{
	return n_ele;
}
// Devuelve el tamaño del vectorD


template <typename T>
T  vectorD<T>::default_value( ) const{

	return v_nulo;

}
//Devuelve el valor por defecto

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
template <typename T>
void vectorD<T>::clear(){
	n_ele=0;
	vd.clear();

}
// elimina todos los elementos del vectorD. Tamanio es 0
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
template <typename T>
vectorD<T> & vectorD<T>::operator= (const vectorD & x){
	v_nulo=x.v_nulo;
	n_ele=x.n_ele;
	vd=x.vd;

}
// operador de asignacion
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
/** devuelve la componente c-esima del vectorD. Siendo c mayor o igual que 0 y menor que NumComponentes*/

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

template <typename T>
bool vectorD<T>::operator==( const typename vectorD<T>::vectorD & x){
	if(x.vd==vd&&x.n_ele==n_ele&&x.v_nulo==v_nulo)
		return true;
	else
		return false;

}
/** devuelve verdadero si tienen los mismos elementos y false en caso contrario */


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

    template <typename T>
    typename vectorD<T>::iterator  vectorD<T>::begin(){
        typename vectorD<T>::iterator sal;
        sal.i_vect=0;
        sal.ite_rep=vd.begin();
        sal.el_vect=this;
        return sal;
    }
    /** iterador (read) al inicio sobre todos los elementos del vector */

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
    template <typename T>
    typename vectorD<T>::const_iterator vectorD<T>::cbegin() const{
        typename vectorD<T>::const_iterator sal;
        sal.i_vect=0;
        sal.ite_rep=vd.cbegin();
        sal.el_vect=this;
        return sal;
    }
    /** iterador  (read) inicio sobre todos los elementos del vector */
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
    template <typename T>
    typename vectorD<T>::stored_iterator  vectorD<T>::sbegin(){
        typename vectorD<T>::stored_iterator sal;
        sal.ite=vd.begin();
        return sal;
    }
    /** iterador  (read) inicio sobre elementos no nulos */
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
    template <typename T>
    typename vectorD<T>::const_stored_iterator  vectorD<T>::csbegin() const{
        typename vectorD<T>::const_stored_iterator sal;
        sal.ite=vd.cbegin();
        return sal;
    }
    /** iterador  (read) inicio sobre elementos no nulos */
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
    template <typename T>
    vectorD<T>::stored_iterator::stored_iterator() {

    }

    template <typename T>
    vectorD<T>::stored_iterator::stored_iterator(const typename vectorD<T>::stored_iterator & d) : ite(d.ite) {
        ite=d.ite;
    }

    ////////////////////////////////////////////////
    ///////////////////ITERATOR/////////////////////
    ////////////////////////////////////////////////
    template <typename T>
    vectorD<T>::iterator::iterator() {

    }

    template <typename T>
    vectorD<T>::iterator::iterator(const typename vectorD<T>::iterator::iterator & d){
        ite_rep=d.ite_rep;
        el_vect=d.el_vect;
        i_vect=d.i_vect;
    }

    template <typename T>
    typename vectorD<T>::iterator::iterator & vectorD<T>::iterator::operator++( ){
        i_vect++;
         if((*el_vect).vd.find(i_vect)!=(*el_vect).vd.end())
            ite_rep=vd.find(i_vect);

        return *this;
    }

    template <typename T>
    typename vectorD<T>::iterator vectorD<T>::iterator::operator++(int ) {
        typename vectorD<T>::iterator sal;
        sal = *this;

        i_vect++;
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            ite_rep=(*el_vect).vd.find(i_vect);

        return sal;
    }

    template <typename T>
    const  T & vectorD<T>::iterator::operator *( ){
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            return (*el_vect).v_nulo;
        else
            return (*(*el_vect).vd.find(i_vect)).second;

    }

    template <typename T>
    bool vectorD<T>::iterator::operator == (const typename vectorD<T>::iterator & d) {
        return d.ite_rep==ite_rep&&d.el_vect==el_vect&&i_vect==d.i_vect;
    }

    template <typename T>
    bool vectorD<T>::iterator::operator != (const  typename vectorD<T>::iterator & d){
        return d.ite_rep!=ite_rep||d.el_vect!=el_vect||i_vect!=d.i_vect;
    }

    template <typename T>
    typename vectorD<T>::iterator & vectorD<T>::iterator::operator=(const typename vectorD<T>::iterator & d){
        ite_rep=d.ite_rep;
        i_vect=d.i_vect;
        el_vect=d.el_vect;
    }

    ////////////////////////////////////////////////
    ////////////CONST_STORED_ITERATOR///////////////
    ////////////////////////////////////////////////
    template <typename T>
    vectorD<T>::const_stored_iterator::const_stored_iterator(){

    }
    template <typename T>
    vectorD<T>::const_stored_iterator::const_stored_iterator(const typename vectorD<T>::const_stored_iterator::const_stored_iterator & d) {
        ite=d.ite;
    }
    template <typename T>
    vectorD<T>::const_stored_iterator::const_stored_iterator(const stored_iterator & d) {
        ite=d.ite;
    }
    // Conversion de iterator a const_iterator

    template <typename T>
    typename vectorD<T>::const_stored_iterator & vectorD<T>::const_stored_iterator::operator= (const typename vectorD<T>::const_stored_iterator::const_stored_iterator & d) {
        ite=d.ite;
    }

    ////////////////////////////////////////////////
    /////////////////CONST_ITERATOR/////////////////
    ////////////////////////////////////////////////
    template <typename T>
    vectorD<T>::const_iterator::const_iterator() {
        i_vect=0;
    }
        template <typename T>
    vectorD<T>::const_iterator::const_iterator(const typename vectorD<T>::const_iterator::const_iterator & d) {
        ite_rep=d.ite_rep;
        i_vect=d.i_vect;
    }
        template <typename T>
    vectorD<T>::const_iterator::const_iterator(const typename vectorD<T>::iterator & d) {
        ite_rep=d.ite_rep;
        i_vect=d.i_vect;
    }
    // Conversion de iterator a const_iterator

    template <typename T>
    typename vectorD<T>::const_iterator & vectorD<T>::const_iterator::operator++( ) {
        typename vectorD<T>::const_iterator sal;


        i_vect++;
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            ite_rep=(*el_vect).vd.find(i_vect);
        return *this;
    }

    template <typename T>
    typename vectorD<T>::const_iterator vectorD<T>::const_iterator::operator++(int ) {
        typename vectorD<T>::const_iterator sal;
        sal = *this;

        i_vect++;
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            ite_rep=(*el_vect).vd.find(i_vect);

        return sal;
    }

    template <typename T>
    const  T & vectorD<T>::const_iterator::operator *( ){
        if((*el_vect).vd.find(i_vect)==(*el_vect).vd.end())
            return (*el_vect).v_nulo;
        else
            return (*(*el_vect).vd.find(i_vect)).second;

    }

    template <typename T>
    bool vectorD<T>::const_iterator::operator == (const typename vectorD<T>::const_iterator & d) {
        return d.ite_rep==ite_rep;
        }
    template <typename T>
    bool vectorD<T>::const_iterator::operator != (const typename vectorD<T>::const_iterator & d) {
        return d.ite_rep!=ite_rep;
    }



