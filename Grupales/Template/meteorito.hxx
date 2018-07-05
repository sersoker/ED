/*
 * meteorito.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aaron Rodríguez Bueno

 *
 * meteorito:: meteorito, end, find, operator[], size, max_element
 * tipos meteorito::entrada, meteorito::size_type
 *
 *

*/
#include <assert.h>

 	/** @brief constructor primitivo.
	*/
  defM::defM(){

}

  	/** @brief constructor de copia
	@param[in] x diccionario a copiar
	*/
  defM::defM(const defM & x){
      codigo=x.codigo;
      masa=x.masa;
      caida=x.caida;
      anio=x.anio;
      latitud=x.latitud;
      longitud=x.longitud;
  }

  /** @brief Define la entrada "code"
@param s entrada a definir
@return true si la entrada se ha podido insertar con éxito. False en caso contrario
@post 	 El valor sera cambiado por el nuevo.
*/
bool defM::setCode(const string & s){
    string aux;
    for (int i=0;i<s.size();i++){
        if (s[i]!=',')
            aux=aux+s[i];
        else{
            codigo.push_back(aux);
            aux.clear();
            }
    }
    return true;
}

   /** @brief Define la entrada "masa"
    @param m entrada a definir
    @post 	 El valor sera cambiado por el nuevo.
    */
void defM::setMas(const double &  m){
    masa=m;
}

    /** @brief Define la entrada "fall"
@param f entrada a definir
@post 	 El valor sera cambiado por el nuevo.
*/
  void defM::setFall(bool f){
      caida=f;
  }

     /** @brief Define la entrada "year"
    @param y referencia de entrada a definir
    @post 	 El valor sera cambiado por el nuevo.
    */
  void defM::setYear(const string & y){
      anio=y;
  }

      /** @brief Define la entrada "latitud"
    @param lat referencia de entrada a definir
    @post 	 El valor sera cambiado por el nuevo.
    */
  void defM::setLat(const double & lat){
      latitud=lat;
  }

      /** @brief Define la entrada "longitud"
@param longi referencia de  entrada a definir
@post 	 El valor sera cambiado por el nuevo.
*/
  void defM::setLong(const double & longi){
      longitud=longi;
  }

    /** @brief Devuelve los codigos
@return Vector de codigos de meteoritos.
*/
  vector<string> defM::getCodes( ){
    return codigo;
  }

/** @brief Devuelve la masa del meteorito
@post  No se modifica la masa.
*/
  double defM::getMas( ){
      return masa;
  }

	/** @brief Devuelve si ha caido el meteorito
	@return true si ha caido. False en caso contrario
	@post  No se modifica el valro.
*/
  bool defM::getFall( ){
      return caida;
  }

  	/** @brief Devuelve el año
	@return string con la fecha
	@post  No se modifica el año.
*/
  string defM::getYear( ){
      return anio;
  }

    /** @brief Devuelve el latitud
	@post  No se modifica la latitud.
*/
  double defM::getLat( ){
      return latitud;
  }

    /** @brief Devuelve el longitud
	@post  No se modifica la longitud.
*/
  double defM::getLong( ){
    return longitud;
  }

ostream& operator<< ( ostream& sal , const defM & definicion){
    for ( int i = 0; i < definicion.codigo.size(); i++ ){
        sal << definicion.codigo[i] << ", ";
    }
    sal << definicion.masa << "; ";
    sal << definicion.caida << "; ";
    sal << definicion.anio << "; ";
    sal << definicion.latitud << "; ";
    sal << definicion.longitud << "; ";
    sal << endl;

    return sal;
}

ostream & operator<< ( ostream& sal , const meteorito & meteo ){
    sal << meteo.first;
    sal << meteo.second;

    return sal;
}
