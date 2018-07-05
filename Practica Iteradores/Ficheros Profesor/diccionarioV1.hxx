/* 
 * diccionario.h
 * 
 * Copyright  (C) Juan F. Huete
 * 
 * diccionario:: diccionario, end, find, operator[], size, max_element
 * tipos diccionario::entrada, diccionario::size_type
 * 
 *
===================================================================================
Funcion de Abstraccion:
AF: Rep => Abs
   
  dado Rep=(vector<entrada>  dic, int mayor) ==> Diccionario Dic;
  
Un objeto abstracto, Dic, representando una colección de pares (string,int) se instancia en la
clase diccionario como un vector de entradas, definidas como  diccionario::entrada. 
Dada una entrada, x, en Rep,  x.first representa a una palabra válida (clave) y x.second 
representa el número de veces que ocurre x (definición). 

Un diccionario debe tener definido el valor de la entrada nula, Dic.null(), que se almacena 
en la primera posicion del vector, esto es,  Rep.dic[0]== Dic.null();


=====================================================================================
Invariante de la Representación:

Dic es el objeto abstracto diccionario, Rep seria su representacion

i) Dic.size() == Rep.dic.size()-1;
ii) Rep.dic[0]== Dic.null();
iii) Para todo i, 1 <= i <= D.dic.size() se cumple
	Rep.dic[i].second >= 0;
	Rep.dic[i].first != Dic.null().first;
	Rep.dic[i].fisrt != Rep.dic[j].first, para todo j!=i.


=====================================================================================
*/
#include <assert.h>


template <typename Key, typename Def>
 diccionario<Key,Def>::diccionario(){ 
 typename diccionario<Key,Def>::entrada nula;
  nula.first = Key(); //Constructor por defecto de la clave
  nula.second = Def(); //Constructor por defecto de la definicion.
  dic.push_back(nula);
  pos_max =0;
}


template <typename Key, typename Def>
diccionario<Key,Def>::diccionario( const typename diccionario<Key,Def>::entrada  & nula ){ 
  dic.push_back(nula);
  pos_max =0;

}

template <typename Key, typename Def>
diccionario<Key,Def>::diccionario (const diccionario<Key,Def> & d){
  dic = d.dic;
  pos_max = d.pos_max;
}


/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
typename  diccionario<Key,Def>::iterator   diccionario<Key,Def>::find( const Key & s) {
typename  diccionario<Key,Def>::iterator	 sal;
  
}


template <typename Key, typename Def>
Def & diccionario<Key,Def>::operator[](const Key & s) {
  bool encontrado = false;
  int i;
  for (i=1;i<dic.size() && ! encontrado ;  ){
    if (dic[i].first == s)
      encontrado = true;
    else i++;
  }
  if (!encontrado) {

       typename diccionario<Key,Def>::entrada ent;
       ent.first = s;
       ent.second = Def();
       dic.push_back(ent);

       i = dic.size()-1;
  }

  return dic[i].second;
}
	


template <typename Key, typename Def>
const Def & diccionario<Key,Def>::operator[](const Key & s) const{
 bool encontrado = false;
 int i;
  for (i=0;i<dic.size() && ! encontrado ;  ){
    if (dic[i].first == s)
      encontrado = true;
   else i++;
   }
  assert (encontrado == true);
  return dic[i].second;
}



template <typename Key, typename Def>
diccionario<Key,Def> & diccionario<Key,Def>::operator=( const diccionario<Key,Def> & org){
if (this!=&org){
  dic = org.dic;
  pos_max =org.pos_max;
}
return *this;
}


template <typename Key, typename Def>
typename diccionario<Key,Def>::size_type diccionario<Key,Def>::size() const {
 return dic.size()-1;
}


template <typename Key, typename Def>
bool diccionario<Key,Def>::empty() const{
  return (dic.size()==1);
}

	 
/**

*/
template <typename Key, typename Def>
bool diccionario<Key,Def>::cheq_rep( ) const {
  // Chequearemos puntos i) y iii), pues el 2 no se puede chequear

  assert( size() == dic.size()-1);
  for (int i=1; i<dic.size(); i++) {
    assert(dic[i].second >=0); //Valores >= que 0
    for (int j=0; j<dic.size(); j++)
        if (j!=i) 
	   assert(dic[i].first != dic[j].first); // No se repite clave, incluido la nula
  }
  return true;
}
  
/**

*/

template <typename Key, typename Def>
ostream &  operator <<  ( ostream & sal, const diccionario<Key,Def> & D){
   sal << "size : "<< D.size() <<" => [";
   for (int i=0; i< D.dic.size(); i++)
    sal << "("<< i << ":: " <<D.dic[i].first << "," << D.dic[i].second<<")";
   sal<<"]";
  return sal;
}

/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
typename diccionario<Key,Def>::iterator diccionario<Key,Def>::begin()  {
typename diccionario<Key,Def>::iterator sal;
  
}

/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
typename diccionario<Key,Def>::iterator diccionario<Key,Def>::end()  {
  
}

/**
 @todo implementa esta función
*/	
template <typename Key, typename Def>
diccionario<Key,Def>::iterator::iterator( ){
}

/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
diccionario<Key,Def>::iterator::iterator(const typename diccionario<Key,Def>::iterator & it) {
 
}

/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
diccionario<Key,Def>::iterator::iterator(typename diccionario<Key,Def>::entrada * p_e) {

  
}

/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
diccionario<Key,Def>::iterator::iterator(typename vector<pair<Key,Def> >::iterator itv) {
  
}
/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
 typename diccionario<Key,Def>::entrada & diccionario<Key,Def>::iterator::operator*() const {
 
}

/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
typename diccionario<Key,Def>::iterator diccionario<Key,Def>::iterator::operator++(int a){
 
}

/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
typename diccionario<Key,Def>::iterator  & diccionario<Key,Def>::iterator::operator++(){
  it_v++;
  return *this;
}

/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
bool diccionario<Key,Def>::iterator::operator==(const typename diccionario<Key,Def>::iterator & it){
 
}

/**
 @todo implementa esta función
*/
template <typename Key, typename Def>
bool diccionario<Key,Def>::iterator::operator!=(const typename diccionario<Key,Def>::iterator & it){

  
}
