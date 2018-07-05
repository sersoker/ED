/* vectorD.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aarón Rodríguez Bueno
 *
 */

/////////////////////////////////////////
//////////// constructores //////////////
/////////////////////////////////////////

	/** @brief constructor primitivo.
        @post se crea un contenedor polinomioD que es un dato miembro de la clase Polinomio.
	*/
Polinomio::Polinomio(){
    poli=vectorD<int>(0);

}
/** @brief constructor de copia.
        @post se crea un contenedor polinomioD que es un dato miembro de la clase Polinomio.
	*/
Polinomio::Polinomio(const Polinomio & p){
    poli=p.poli;
}

////////////////////////////////////
/////////// Consultores ////////////
////////////////////////////////////
/** @brief Devuelve el grado del polinomio
    @return el tamaño del polinomio menos 1
*/

int Polinomio::grado() const{
    if (poli.size()!=0)
        return poli.size()-1;
    else
        return 0;
}
/**
    @brief Devuelve el coeficiente en el grado dado
    @param[in] p posición donde hay que mirar el coeficiente
    @return El valor del grado en esa posición.
*/

int Polinomio::coeficiente(int p)const{
    return poli[p];
}

////////  MODIFICADORES //////////////////////
/**
    @brief Asigna a una posición dada un coeficiente dado.
    @param[in] g La posición en el polinomio.
    @param[in] c El valor a insertar en el polinomio.
    @pre la posición dada debe estar dentro del tamaño del polinomio.
    @post La posición p del polinomio es modificada
    */
void Polinomio::assign(int g, int c){
    poli.assign(g,c);
}
/**
    @brief Inserta un grado mayor al mayor actual del polinomio con el valor dado.
    @param[in] t el valor a insertar.
    @post el grado del polinomio se incrementa en 1 y se inserta en el contenedor interno polinomioD.
*/
void Polinomio::push_back(int c){
    poli.push_back(c);
}

/////////////// operadores ///////////////////
/**
    @brief Asigna el comportamiento del operador =
    @param[in] p Polinomio con el que hay que igualar el actual
    @return el polinomio actual modificado
    @post Iguala los datos miembros del polinomio actual con los del dado
*/
Polinomio & Polinomio::operator= (const Polinomio & p){
    poli=p.poli;
}
/**
    @brief suma al polinomio actual el dado
    @param[in] el polinomio a sumar al actual
    @return este polinomio
    @post los valores del polinomioD se actualizan con la suma del campo actual
    mas el campo en la misma posición del polinomio dado

*/
Polinomio & Polinomio::operator+ (const Polinomio & p){
    int suma;
    for (int i = 0; i <= p.grado(); i++){
        if(i<=(*this).grado()){
            suma = poli[i]+p.poli[i];
            poli.assign(i, suma);
        }
        else{
            suma = p.poli[i];
            poli.push_back(suma);
        }
    }
}
/**
    @brief resta al polinomio actual el dado
    @param[in] el polinomio a sumar al actual
    @return este polinomio
    @post los valores del polinomioD se actualizan con la resta del campo actual
    el campo en la misma posición del polinomio dado

*/
Polinomio & Polinomio::operator- (const Polinomio & p){
    int resta;
    for (int i = 0; i <= p.grado(); i++){
        if(i<=(*this).grado()){
            resta = poli[i]-p.poli[i];
            poli.assign(i, resta);
        }
        else{
            resta = 0-p.poli[i];
            poli.push_back(resta);
        }
    }
}

////////////////////////////////////////
/**
    @brief Devuelve un iterador al principio del polinomio
    @return iterador (read) al inicio sobre todos los elementos del polinomio
*/
Polinomio::iterator Polinomio::begin(){
    vectorD<int>::iterator aux=poli.begin();
    Polinomio::iterator sal;
    sal.it=aux;
    return sal;
}
/** iterador (read) al inicio sobre todos los elementos del polinomio */
/**
    @brief Devuelve un iterador al final del polinomio
    @return iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio
*/
Polinomio::iterator Polinomio::end(){
    vectorD<int>::iterator aux=poli.end();
    Polinomio::iterator sal;
    sal.it=aux;
    return sal;
}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */

/**
    @brief Devuelve un iterador constante al principio del polinomio
    @return iterador  (read) inicio sobre todos los elementos del polinomio
*/
Polinomio::const_iterator Polinomio::cbegin() const{
    vectorD<int>::const_iterator aux=poli.cbegin();
    Polinomio::const_iterator sal;
    sal.it=aux;
    return sal;
}
/** iterador  (read) inicio sobre todos los elementos del polinomio */
/**
    @brief Devuelve un iterador constante al final del polinomio
    @return iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio
*/
Polinomio::const_iterator Polinomio::cend() const{
    vectorD<int>::const_iterator aux=poli.cend();
    Polinomio::const_iterator sal;
    sal.it=aux;
    return sal;
}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */


/**
    @brief Devuelve un stored_iterator al principio del polinomio
    @return iterador  (read) inicio sobre elementos no nulos
*/
Polinomio::stored_iterator Polinomio::sbegin(){
    vectorD<int>::stored_iterator aux=poli.sbegin();
    Polinomio::stored_iterator sal;
    sal.ite=aux;
    return sal;
}
/** iterador (read) al inicio sobre todos los elementos del polinomio */
/**
    @brief Devuelve un stored_iterator al final del polinomio
    @return iterador  (read) final (siguiente al ultimo) sobre elementos no nulos
*/
Polinomio::stored_iterator Polinomio::send(){
    vectorD<int>::stored_iterator aux=poli.send();
    Polinomio::stored_iterator sal;
    sal.ite=aux;
    return sal;
}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */


/**
    @brief Devuelve un const_stored_iterator al principio del polinomio
    @return iterador  (read) inicio sobre elementos no nulos
*/
Polinomio::const_stored_iterator Polinomio::csbegin() const{
    vectorD<int>::const_stored_iterator aux=poli.csbegin();
    Polinomio::const_stored_iterator sal;
    sal.ite=aux;
    return sal;
}
/** iterador  (read) inicio sobre todos los elementos del polinomio */
/**
    @brief Devuelve un const_stored_iterator al final del polinomio
    @return iterador  (read) final (siguiente al ultimo) sobre elementos no nulos
*/
Polinomio::const_stored_iterator Polinomio::csend() const{
    vectorD<int>::const_stored_iterator aux=poli.csend();
    Polinomio::const_stored_iterator sal;
    sal.ite=aux;
    return sal;
}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */

    ////////////////////////////////////////////////
    ///////////////////ITERATOR/////////////////////
    ////////////////////////////////////////////////
  /**
    @brief constructor por defecto
    @post se crea un iterador que actúa sobre todas las posiciones del polinomio
  */
    Polinomio::iterator::iterator() {

    }

	/**
    @brief constructor de copia
    @post se crea un iterador con el mismo valor para los datos miembros que el iterador dado
  */
    Polinomio::iterator::iterator(const Polinomio::iterator & p){
        it=p.it;
    }

       /**
    @brief devuelve el iterador hacia la siguiente posición en el polinomio
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre el polinomio.
    */
    Polinomio::iterator & Polinomio::iterator::operator++( ){
        it++;
        return *this;
    }
    /**
    @brief devuelve una copia del iterador en la posición actual, y el iterador avanza hacia la siguiente posición en el polinomio
    @return la copia del iterador con la posición antes de actualizarla
    @post se incrementa la posición sobre el polinomio.
    */
    Polinomio::iterator Polinomio::iterator::operator++(int ) {
        Polinomio::iterator sal;
        sal = *this;
        it++;
        return sal;
    }

	/**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor del coeficiente de la posición sobre todo el polinomio en la que se encuentra el iterador
    */
    const  int & Polinomio::iterator::operator *( ){
        return *it;

    }
    /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre todo el polinomio
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */
    bool Polinomio::iterator::operator == (const Polinomio::iterator & p) {
        return it==p.it;
    }
    /**
    @brief identifica si el iterador actual está apuntando a distinto sitio que el dado
    @param[in] d iterador sobre todo el polinomio
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */
    bool Polinomio::iterator::operator != (const  Polinomio::iterator & p){
        return it!=p.it;
    }
    /**
    @brief iguala los datos miembro de este objeto con los del dado
    @param[in] d iterador sobre todo el polinomio
    @return este objeto con los datos miembro actualizados
    @post se actualizan los datos miembros del objeto
    */
    Polinomio::iterator & Polinomio::iterator::operator=(const Polinomio::iterator & p){
        it=p.it;
    }

    ////////////////////////////////////////////////
    ///////////////////CONST_ITERATOR///////////////
    ////////////////////////////////////////////////
  /**
    @brief constructor por defecto
    @post se crea un iterador constante que actúa sobre todas las posiciones del polinomio
  */
    Polinomio::const_iterator::const_iterator() {

    }
   /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador constante dado
  */
    Polinomio::const_iterator::const_iterator(const Polinomio::const_iterator & p){
        it=p.it;
    }
 /**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador dado
  */
    Polinomio::const_iterator::const_iterator(const Polinomio::iterator & p){
        it=p.it;
    }
    /**
    @brief devuelve el iterador hacia la siguiente posición en el polinomio
    @return el iterador con la nueva posición a la que se ha movido
    @post se incrementa la posición sobre el polinomio
    */
    Polinomio::const_iterator & Polinomio::const_iterator::operator++( ){
        it++;
        return *this;
    }
        /**
    @brief devuelve una copia del iterador en la posición actual, y el iterador avanza hacia la siguiente posición en el polinomio
    @return la copia del iterador con la posición antes de actualizarla
    @post se incrementa la posición sobre el polinomio
    */
    Polinomio::const_iterator Polinomio::const_iterator::operator++(int ) {
        Polinomio::const_iterator sal;
        sal = *this;
        it++;
        return sal;
    }
    /**
    @brief devuelve el valor adonde está apuntando el iterador
    @return valor del coeficiente en la posición sobre todo el polinomio en la que se encuentra el iterador
    */
    const  int & Polinomio::const_iterator::operator *( ){
        return *it;
    }
    /**
    @brief identifica si el iterador actual está apuntando al mismo sitio que el dado
    @param[in] d iterador sobre el polinomio
    @return verdadero si los datos miembro de los dos son iguales y falso en caso contrario
    */
    bool Polinomio::const_iterator::operator == (const Polinomio::const_iterator & p) {
        return it==p.it;
    }
    /**
    @brief identifica si el iterador actual está apuntando a distinto sitio que el dado
    @param[in] d iterador sobre todo el polinomio
    @return verdadero si los datos miembro de los dos son distintos y falso en caso contrario
    */

    bool Polinomio::const_iterator::operator != (const  Polinomio::const_iterator & p){
        return it!=p.it;
    }

    ////////////////////////////////////////////////
    //////////////STORED_ITERATOR///////////////////
    ////////////////////////////////////////////////
  /**
    @brief constructor por defecto
    @post se crea un iterador sobre el contenedor interno
  */
    Polinomio::stored_iterator::stored_iterator() {

    }
   /**
    @brief constructor de copia
    @post se crea un iterador con el mismo valor para los datos miembros que el iterador dado
  */
    Polinomio::stored_iterator::stored_iterator(const Polinomio::stored_iterator & d) : ite(d.ite) {
        ite=d.ite;
    }

    ////////////////////////////////////////////////
    ////////////CONST_STORED_ITERATOR///////////////
    ////////////////////////////////////////////////
  /**
    @brief constructor por defecto
    @post se crea un iterador constante sobre el contenedor interno
  */
    Polinomio::const_stored_iterator::const_stored_iterator(){

    }
	/**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador constante dado
  */
    Polinomio::const_stored_iterator::const_stored_iterator(const Polinomio::const_stored_iterator & d) {
        ite=d.ite;
    }
	/**
    @brief constructor de copia
    @post se crea un iterador constante con el mismo valor para los datos miembros que el iterador dado
  */
    Polinomio::const_stored_iterator::const_stored_iterator(const stored_iterator & d) {
        ite=d.ite;
    }
    // Conversion de iterator a const_iterator
	/**
    @brief Iguala los datos miembro del iterador a los del dado
    @param[in] d iterador al que se va a igualar
    @return este iterador con los datos miembro ya igualados
    */
    Polinomio::const_stored_iterator & Polinomio::const_stored_iterator::operator= (const Polinomio::const_stored_iterator & d) {
        ite=d.ite;
    }
