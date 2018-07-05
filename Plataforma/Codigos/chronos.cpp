#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <list>
#include <deque>

using namespace std;
using namespace std::chrono;


template <typename C, typename T>
duration<double> insertarFinal(C & V, const T & x, int max){
high_resolution_clock::time_point t1,t2;
duration<double> time_span;
   t1 = high_resolution_clock::now();
	for (int i =0; i<max; i++)
           V.push_back(x);
  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  return time_span;
}


template <typename T>
duration<double> insertarInicio(vector<T> & V, const T & x, int max){
high_resolution_clock::time_point t1,t2;
duration<double> time_span;
   t1 = high_resolution_clock::now();
	for (int i =0; i<max; i++)
           V.insert(V.begin(),x);
  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  return time_span;
}

template <typename T>
duration<double> insertarInicio(deque<T> & D, const T & x, int max){
high_resolution_clock::time_point t1,t2;
duration<double> time_span;
   t1 = high_resolution_clock::now();
	for (int i =0; i<max; i++)
           D.push_front(x);
  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  return time_span;
}


template <typename T>
duration<double> insertarInicio(list<T> & L, const T & x, int max){
high_resolution_clock::time_point t1,t2;
duration<double> time_span;
   t1 = high_resolution_clock::now();
	for (int i =0; i<max; i++)
           L.push_front(x);
  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  return time_span;
}

template <typename T, typename El >
duration<double> insertarMedio(T & C, const El & x, int max){
high_resolution_clock::time_point t1,t2;
typename T::iterator it;
typename T::difference_type mitad;
duration<double> time_span;
   t1 = high_resolution_clock::now();
	for (int i =0; i<max; i++){
	   mitad = (C.end()-C.begin())/2;
           C.insert(C.begin()+mitad,x);
	}
  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  return time_span;
}

template <typename T >
duration<double> Consutla_Corchete( T & C, int max){
high_resolution_clock::time_point t1,t2;
typename T::iterator it;
typename T::difference_type mitad;
duration<double> time_span;
   t1 = high_resolution_clock::now();
	for (int i =0; i<max; i++){
	   C[i];
	}
  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  return time_span;
}


template <typename T >
duration<double> Consutla_at( T & C, int max){
high_resolution_clock::time_point t1,t2;
typename T::iterator it;
typename T::difference_type mitad;
duration<double> time_span;
   t1 = high_resolution_clock::now();
	for (int i =0; i<max; i++){
	   C.at(i);
	}
  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  return time_span;
}


template <typename T >
duration<double> Consutla_iterator( T & C, int max){
high_resolution_clock::time_point t1,t2;
typename T::iterator it;
typename T::difference_type mitad;
duration<double> time_span;
   t1 = high_resolution_clock::now();
	for (it=C.begin(); it!=C.end();  it++){
	   *it;
	}
  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  return time_span;
}
void generar_aleatorio(vector<int> & V){
  int x,s,i;
  for ( i=0; i<V.size();i++){
    x=i;
    if ( (rand()%2)==0 ) x = -x;
    V[i]=x;
  }
   random_shuffle(V.begin(),V.end());
}

int main(int argc, char * argv[]){



high_resolution_clock::time_point t1,t2;
duration<double> tiempo,time_span;

vector<int> V;
deque<int> D;
list<int> L;

int max = 20000;

struct E {
  int x;
  double y;
  double X[100];
};


vector<E> VE;
deque<E> DE;

srand(0);
cout <<"Comparativa sobre int "<<max << " elementos" << endl;

  
  
  tiempo = insertarFinal(V, 3,max); 
  cout << tiempo.count() <<  " PushBack Vector " << endl;

  V.clear();



  tiempo = insertarFinal(D,3, max);
  cout  << tiempo.count() <<  " PushBack Deque " << endl;

  D.clear();

 tiempo = insertarFinal(L,3, max);
  cout << tiempo.count() <<  " PushBack List "  << endl;
L.clear();

// ===================================
  
  tiempo = insertarInicio(V,3, max); 
  cout << tiempo.count()<<  " Insert Incio Vector "<< tiempo.count() << endl;

  V.clear();



  tiempo = insertarInicio(D,3, max);
  cout<< tiempo.count() <<  " Insert Inicio Deque " << tiempo.count() << endl;

  D.clear();


 tiempo = insertarInicio(L,3, max);
  cout << tiempo.count() <<  " Insertar Inicio List "  << endl;
L.clear();

//=================================


  
  tiempo = insertarMedio(V,3,max); 
  cout << tiempo.count()<<  " Insert Medio  Vector "<< tiempo.count() << endl;

  tiempo = insertarMedio(D,3,max);
  cout << tiempo.count()<<  " Insert Medio Deque " << tiempo.count() << endl;

  cout << "Consulta de Elementos " << endl;

 tiempo = Consutla_Corchete(V,max);
cout<< tiempo.count() <<  " Consulta Corchete  Vector "<< tiempo.count() << endl;
  tiempo = Consutla_Corchete(D,max);
cout << tiempo.count()<<  " Consulta Corchete Deque "<< tiempo.count() << endl;


 tiempo = Consutla_at(V,max);
cout<< tiempo.count() <<  " Consulta at  Vector "<< tiempo.count() << endl;
  tiempo = Consutla_at(D,max);
cout << tiempo.count()<<  " Consulta at Deque "<< tiempo.count() << endl;

 tiempo = Consutla_iterator(V,max);
cout<< tiempo.count() <<  " Consulta Iterator  Vector "<< tiempo.count() << endl;
  tiempo = Consutla_iterator(D,max);
cout << tiempo.count()<<  " Consulta Iterator Deque "<< tiempo.count() << endl;

 tiempo = Consutla_iterator(L,max);
  cout << tiempo.count()<<  " Consutal Iterator List " << tiempo.count() << endl;

  L.clear();
D.clear();
V.clear();
//=================================
  

max = 20000;

cout <<"Comparativa sobre Estructura  "<<max << " elementos" << endl;

  struct E el;
  
  tiempo = insertarFinal(VE,el,max); 
  cout<< tiempo.count() <<  " PushBack Vector "<< tiempo.count() << endl;

  VE.clear();



  tiempo = insertarFinal(DE,el,max);
  cout<< tiempo.count() <<  " PushBack Deque " << tiempo.count() << endl;

  DE.clear();
// ===================================
  
  tiempo = insertarInicio(VE,el,max); 
  cout<< tiempo.count() <<  " Insert Incio Vector "<< tiempo.count() << endl;

  VE.clear();



  tiempo = insertarInicio(DE,el,max);
  cout<< tiempo.count() <<  " Insert Inicio Deque " << tiempo.count() << endl;

  DE.clear();
//=================================


  
  tiempo = insertarMedio(VE,el,max); 
  cout << tiempo.count()<<  " Insert Medio  Vector "<< tiempo.count() << endl;

  tiempo = insertarMedio(DE,el,max);
  cout << tiempo.count()<<  " Insert Medio Deque " << tiempo.count() << endl;


//=================================
  

cout << "Consulta de Elementos " << endl;



 tiempo = Consutla_Corchete(VE,max);
cout << tiempo.count()<<  " Consulta Corchete  Vector "<< tiempo.count() << endl;
  tiempo = Consutla_Corchete(DE,max);
cout << tiempo.count()<<  " Consulta Corchete Deque "<< tiempo.count() << endl;


 tiempo = Consutla_at(VE,max);
cout<< tiempo.count() <<  " Consulta at  Vector "<< tiempo.count() << endl;
  tiempo = Consutla_at(DE,max);
cout << tiempo.count()<<  " Consulta at Deque "<< tiempo.count() << endl;

 tiempo = Consutla_iterator(VE,max);
cout << tiempo.count() <<  " Consulta Iterator  Vector "<< tiempo.count() << endl;
  tiempo = Consutla_iterator(DE,max);
cout << tiempo.count()<<  " Consulta Iterator Deque "<< tiempo.count() << endl;

DE.clear();
VE.clear();
//=================================



cout << "Vector de Vectores" << endl;

vector<int> bloque(2000,1);
vector<vector<int> > A;
vector<vector<int> *> B;
list<vector<int> > C;
// ===================================
  
  tiempo = insertarInicio(A,bloque,1000); 
  cout<< tiempo.count() <<  " Insert Incio Vector de Vector "<< tiempo.count() << endl;

  A.clear();

 tiempo = insertarInicio(B,&bloque,1000); 
  cout<< tiempo.count() <<  " Insert Incio Vector de Vector * "<< tiempo.count() << endl;

  B.clear();

 tiempo = insertarInicio(C,bloque,1000); 
  cout << tiempo.count()<<  " Insert Incio Lista de Vector "<< tiempo.count() << endl;

 L.clear();
//=================================



return 0;

} 
