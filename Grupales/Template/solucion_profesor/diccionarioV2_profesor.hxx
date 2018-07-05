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

/**
  
*/
defM & diccionario::operator[](const nombreM & s) {

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
   else { //No esta:
      diccionario::entrada aux(s,defM());
      auto it = dic.insert(dic.begin()+sup,aux);
      return (*it).second;
   }
}
	

/**
  
*/
const defM & diccionario::operator[](const nombreM & s) const{

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
    cerr<< "Error: const defM & diccionario::operator[](const nombreM & s) const;   \n ====> "<< s <<" no se encuentra en diccionario y no puede insertar "<<endl;
    exit(1);
  }
  
}


/**
  
*/
bool diccionario::insert(const diccionario::entrada & e) {

  if (dic.empty()){
    dic.insert(dic.begin(),e);
    return true;
  }
  else {
 //Paso1 busqueda de s
   int inf=0,  sup = dic.size()-1;
   int centro=0;
   bool enc=false;
   while(inf<sup && ! enc){
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
      dic.insert(dic.begin()+sup,e);
      cout << "tras insertar " << e<< endl<< *this<<endl;
      return true;
   }
   else return false;
  }
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
// Chequearemos puntos i) y iii), pues el 2 no se puede chequear

   
  for (int i=1; i<dic.size(); i++) {
    assert(dic[i].first!=""); //Nombre de meteorito valido
    if (i>2)
      assert(dic[i].first != dic[i-1].first); // Ordenados
  }
  return true;
}
  
/**
  
*/
ostream &  operator << ( ostream & sal, const diccionario & D){
  vector<diccionario::entrada>::const_iterator it;
  
  for (it = D.dic.cbegin(); it != D.dic.cend();++it)
    sal <<  (*it) << endl;
   return sal;
}


