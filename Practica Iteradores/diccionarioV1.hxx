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
pair<typename diccionario<K,D>::entrada,bool> diccionario<K,D>::find( const K & s) const{
  pair<typename diccionario<K,D>::entrada,bool> salida;
  typename vector<entrada>::const_iterator it;
  bool encontrado=false;
  for (it = dic.begin(); it!= dic.end() && !encontrado ;  )
  {
   if ((*it).first == s)
     encontrado = true;
   else ++it;
  }
  if (encontrado)
    salida.first = *it;
  salida.second = encontrado;
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
  typename vector<diccionario<K,D>::entrada>::iterator it;
  bool encontrado=false;
  for (it = dic.begin(); it!= dic.end() && !encontrado ;  )
  {
   if ((*it).first == s) encontrado = true;
   else ++it;
  }
  if (encontrado ) return (*it).second;
  else {
    typename diccionario<K,D>::entrada aux;
    aux.first = s;
    dic.push_back(aux);
    return dic.back().second;
  }
}




/** @brief Consulta  una   entrada en el diccionario.

Busca la cadena s en el diccionario, si la encuentra devuelve una referencia constante aa la definición de la misma, si no la encuentra da un mensaje de error.

@param[in] s cadena a insertar
@param[out] int & referencia constante a la definicion asociada  a la entrada
@post  No se modifica el diccionario.
*/
template <typename K, typename D> const D & diccionario<K,D>::operator[](const K & s) const{
typename vector<diccionario<K,D>::entrada>::const_iterator it;
  bool encontrado=false;
  for (it = dic.begin(); it!= dic.end() && !encontrado ;  )
  {
   if ((*it).first == s) encontrado = true;
   else ++it;
  }
  if (encontrado ) return (*it).second;
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
template <typename K, typename D> bool diccionario<K,D>::insert(const diccionario<K,D>::entrada & e) {
     pair<diccionario<K,D>::entrada,bool> esta;

    esta = find(e.first);

    if (esta.second == false)
      dic.push_back(e);
    return esta.second;

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

template <typename K, typename D>
typename diccionario<K,D>::size_type diccionario<K,D>::size() const {
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
template <typename K, typename D>
bool diccionario<K,D>::cheq_rep( ) const {
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



