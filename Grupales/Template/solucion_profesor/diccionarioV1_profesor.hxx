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
  @todo incluir funcion de abstracción 
=====================================================================================
Invariante de la Representación:

  @todo incluir invariante dela representación 
=====================================================================================
*/
#include <assert.h>


/**

*/
diccionario::diccionario(){ 

}

/**
  
*/
diccionario::diccionario (const diccionario & d){
dic = d.dic;
}


/**
  
*/
pair<diccionario::entrada,bool>   diccionario::find( const nombreM & s) const{
  pair<diccionario::entrada,bool> salida;
  vector<entrada>::const_iterator it;
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

/**
  
*/
defM & diccionario::operator[](const nombreM & s) {
  vector<entrada>::iterator it;
  bool encontrado=false;
  for (it = dic.begin(); it!= dic.end() && !encontrado ;  )
  {
   if ((*it).first == s) encontrado = true;
   else ++it;
  }
  if (encontrado ) return (*it).second;
  else {
    diccionario::entrada aux;
    aux.first = s;
    dic.push_back(aux);    
    return dic.back().second;
  }
}
	

/**
  
*/
const defM & diccionario::operator[](const nombreM & s) const{
vector<entrada>::const_iterator it;
  bool encontrado=false;
  for (it = dic.begin(); it!= dic.end() && !encontrado ;  )
  {
   if ((*it).first == s) encontrado = true;
   else ++it;
  }
  if (encontrado ) return (*it).second;
  else {
    cerr<< "Error: const defM & diccionario::operator[](const nombreM & s) const;   \n ====> "<< s <<" no se encuentra en diccionario y no puede insertar "<<endl;
    exit(1);
  }
  
}


/**
  
*/
bool diccionario::insert(const diccionario::entrada & e) {
pair<entrada,bool> esta;

esta = find(e.first);

if (esta.second == false)
  dic.push_back(e);
return esta.second;
}

/**
  
*/
diccionario & diccionario::operator=( const diccionario & org){
if (this!=&org)
   dic = org.dic;
return *this;
}

/** 
 
*/

diccionario::size_type diccionario::size() const {
return dic.size();
}

/** 
*/
bool diccionario::empty() const{
return dic.empty();
}
   
	 
/**
 
*/
bool diccionario::cheq_rep( ) const {

}
  
/**
  
*/
ostream &  operator << ( ostream & sal, const diccionario & D){
  vector<diccionario::entrada>::const_iterator it;
  
  for (it = D.dic.cbegin(); it != D.dic.cend();++it)
    sal <<  (*it) << endl;
   return sal;
}


