#include "meteorito.h"

#include <algorithm>

defM::defM(){
    codes =vector<string>();
     mass=0.0;
     fall =false;
     year="";
     lat=0;
     longi=0;
}

defM::defM(const defM & x){
 codes = x.codes;
 mass = x.mass;
 fall = x.fall;
 year = x.year;
 lat = x.lat;
 longi = x.longi;

}
  
  bool defM::setCode(const string & s){
    if (find(codes.begin(),codes.end(),s) == codes.end())
    { codes.push_back(s);
      return true;
    } else return false;
  }
  
  void defM::setMas(const double &  m){
   mass = m; 
  }
  void defM::setFall(bool f){
    fall = f;
  }
  void defM::setYear(const string & y){
    year = y;
  }
  void defM::setLat(double & l){
    lat =l;
  }
  void defM::setLong(double & l){
    longi = l;
  }
  vector<string> defM::getCodes( )const{
    return codes;
  }
  double defM::getMas( ) const{
    return mass;
  }
  bool defM::getFall( ) const {
    return fall;
  }
  string defM::getYear( ) const {
    return year;
  }
  double defM::getLat( ) const{
    return lat;
  }
  
  double defM::getLong( ) const{
    return longi;
  }
    
 
 ostream& operator<< ( ostream& os, const defM & d){
   vector<string>::const_iterator it=d.codes.begin();
   if (it !=d.codes.end()){
     os << *it;
     for ( ++it; it!= d.codes.end();++it)
        os << ","<<*it;
   } 
   os << ";" << d.mass << ";" ;
   if (!d.fall)
     os << "Fell";
   else os <<"Found";
   os << ";" << d.year << ";" << d.lat << ";" << d.longi  ;
   return os;
 }
   
   
  
ostream & operator<< ( ostream& os , const meteorito & m){
  os << m.first << ";" <<m.second;

  return os;
}
