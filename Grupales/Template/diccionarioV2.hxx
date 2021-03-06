/*
 * diccionario.h
 *
 * Copyright  (C) Juan F. Huete
 * Editado por Bryan Moreno Picamán & Aarón Rodríguez Bueno
 *
 * diccionario:: diccionario, end, find, operator[], size, max_element
 * tipos diccionario::entrada, diccionario::size_type
 *
 *
===================================================================================
Funcion de Abstraccion:
  @todo incluir funcion de abstracción
=====================================================================================
Invariante de la Representación:

  @todo incluir invariante dela representación
=====================================================================================
*/
#include <assert.h>


	/** @brief constructor primitivo.
	@post define la entrada nula como el par ("",-1)
	*/
template <typename K, typename D> diccionario<K,D>::diccionario(){

}

	/** @brief constructor de copia
	@param[in] d diccionario a copiar
	*/
template <typename K, typename D> diccionario<K,D>::diccionario (const diccionario<K,D> & d){
dic = d.dic;
}


	/** @brief busca una meteorito en el diccionario
	@param s cadena a buscar
	@return una copia de la entrada en el diccionario. Si  no se encuentra devuelve la entrada con la definicion por defecto
	@post no modifica el diccionario.
	\verbatim Uso


	if (D.find("aaa").second ==true) cout << "Esta" ;
	else cout << "No esta";
	\endverbatim
	*/
template <typename K, typename D>
pair<typename diccionario<K,D>::entrada,bool>   diccionario<K,D>::find( const K & s) const{
   pair<typename diccionario<K,D>::entrada,bool> salida;
  typename vector<diccionario<K,D>::entrada>::const_iterator it;

   int inf=0; int sup = dic.size()-1;
   int centro;

   while(inf<=sup){
     centro=(sup+inf)/2;
     if(dic[centro].first==s)
     {
       salida.first = dic[centro];
       salida.second = true;
       return salida;
     }
     else if(s < dic[centro].first ){
        sup=centro-1;
     }
     else {
       inf=centro+1;
     }
   }
   // si no encontrado
   salida.second = false;
   return salida;
}


/** @brief Consulta/Inserta una  entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia a la definición de la misma
en caso contrario la inserta, con una definición por defecto, devolviendo una referencia a este valor.

@param[in] s cadena a insertar
@param[out] defM & referencia a la definicion asociada  a la entrada, nos permite modificar la definición
@post  Si s no esta en el diccionario, el size() sera incrementado en 1.
*/
template <typename K, typename D> D & diccionario<K,D>::operator[](const K & s) {

 //Paso1 busqueda de s
   int inf=0,  sup = dic.size()-1;
   int centro;
   bool enc=false;
   while(inf<sup && ! enc){
     centro=(sup+inf)/2;
     if(dic[centro].first==s)
       enc = true;
     else if(s < dic[centro].first ){
        sup=centro-1;
     }
     else {
       inf=centro+1;
     }
   }
   //Paso2 si esta devuelve la ref y si no lo inserta.
   if (enc) return dic[centro].second;
   else { //No esta
     diccionario<K,D>::entrada aux(s,D());
      auto it = dic.insert(dic.begin()+sup,aux);
      return (*it).second;
   }
}

/** @brief Consulta  una   entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia constante aa la definición de la misma, si no la encuentra da un mensaje de error.

@param[in] s cadena a insertar
@param[out] int & referencia constante a la definicion asociada  a la entrada
@post  No se modifica el diccionario.
*/

template <typename K, typename D> const D & diccionario<K,D>::operator[](const K & s) const{

 //Paso1 busqueda de s
   int inf=0,  sup = dic.size()-1;
   int centro;
   bool enc=false;
   while(inf<=sup && ! enc){
     centro=(sup+inf)/2;
     if(dic[centro].first==s)
       enc = true;
     else if(s < dic[centro].first ){
        sup=centro-1;
     }
     else {
       inf=centro+1;
     }
   }

  if (enc) return dic[centro].second;
  else {
    cerr<< "Error: const D & diccionario::operator[](const K & s) const;   \n ====> "<< s <<" no se encuentra en diccionario y no puede insertar "<<endl;
    exit(1);
  }

}

    /** @brief Inserta una entrada en el diccionario
    @param e entrada a insertar
    @return true si la entrada se ha podido insertar con éxito, esto es, no existe un meteorito con igual nombre en el diccionario. False en caso contrario
    @post 	 Si e no esta en el diccionario, el size() sera incrementado en 1.
    */

template <typename K, typename D>
bool diccionario<K,D>::insert(const typename diccionario<K,D>::entrada & e) {
    cout << e.first << endl;
  if (dic.empty()){
    dic.insert(dic.begin(),e);
    return true;
  }
  else {
 //Paso1 busqueda de s
   int inf=0,  sup = dic.size()-1;
   int centro=0;
   bool enc=false;
   while(inf<=sup && ! enc){
     centro=(sup+inf)/2;
     if(dic[centro].first==e.first)
       enc = true;
     else if(e.first < dic[centro].first ){
        sup=centro-1;
     }
     else {
       inf=centro+1;
     }
   }
   cout << "size " << size() << "Inf "<< inf<< "Centro " << centro<< "Sup "<< sup<<endl;
   //Paso2 si no esta  lo inserta.
   if (!enc) {
      dic.insert(dic.begin()+inf,e);
      //cout << "tras insertar " << e << endl<< *this<<endl;
      return true;
   }
   else return false;
  }
}

/** @brief operador de asignación
@param[in] org diccionario  a copiar.
 Crea un diccionario duplicado exacto de org.
*/

template <typename K, typename D> diccionario<K,D> & diccionario<K,D>::operator=( const diccionario<K,D> & org){
if (this!=&org)
   dic = org.dic;
return *this;
}

/** @brief numero de entradas en el diccionario
@post  No se modifica el diccionario.
*/


template <typename K, typename D> typename diccionario<K,D>::size_type diccionario<K,D>::size() const {
return dic.size();
}

/** @brief vacia
   Chequea si el diccionario esta vacio (size()==0)
*/
template <typename K, typename D> bool diccionario<K,D>::empty() const{
return dic.empty();
}


/** @brief Chequea el Invariante de la representacion
    @return true si el invariante es correcto, falso en caso contrario
*/


template <typename K, typename D> bool diccionario<K,D>::cheq_rep( ) const {
// Chequearemos puntos i) y iii), pues el 2 no se puede chequear


  for (int i=1; i<dic.size(); i++) {
    assert(dic[i].first!=""); //Nombre valido
    if (i>2)
      assert(dic[i].first != dic[i-1].first); // Ordenados
  }
  return true;
}

/** @brief imprime todas las entradas del diccionario
@post  No se modifica el diccionario.
	*/


template <typename K, typename D>
ostream &  operator << ( ostream & sal, const diccionario<K,D> & d){
  typename  vector<typename diccionario<K,D>::entrada>::const_iterator it;

  for (it = d.dic.cbegin(); it != d.dic.cend();++it)
    sal <<  (*it).first << endl;
   return sal;
}



