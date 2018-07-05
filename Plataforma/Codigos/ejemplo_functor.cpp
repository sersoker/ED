#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>

using namespace std;
template <typename T> 
class igualdad {
public:
  bool operator()(const T & a, const T &  b){
    return a == b;
   }
    
};

template <typename T> 
class igualdadValorAbsoluto {
public:
  bool operator()(const T & a, const T &  b){
    return (abs(a) == abs(b));
   }
    
};


template <typename T> 
class igualdadAproximado4 {
public:
  bool operator()(const T & a, const T &  b){
    return ( (a-4 <=b) && (b<=a+4) ) ;
   }
    
};

template <typename T, typename comparar  >
int contar_cuantos (const vector<T> & V, const T& x, comparar cmp  ) {
int cont =0; 
 for (int i=0; i< V.size();i++)
   if (cmp(V[i],x)) cont++;
 return cont;
}


int main(){

  vector<int> V(10,5);
  
  for (int i=0;i<10;i++){
    V.push_back(i);
  }
  for (int i=0;i<10;i++){
    V.push_back(-i);
  }
  igualdad<int> ig;
  
  cout << "igualdad a 3 =" <<contar_cuantos(V,3,ig)<< endl;
  cout << "igualdad abs 3 = " <<contar_cuantos(V,3,igualdadValorAbsoluto<int>())<< endl;
  cout << "igualdad aprox a 3, dist 4 =" <<contar_cuantos(V,3,igualdadAproximado4<int>()) << endl;
  cout << "less 5=" << contar_cuantos(V,5,less<int>())<< endl;
  cout << "igualdad a 5 =" << contar_cuantos(V,5,equal_to<int>())<< endl;

  return 0;

  
} 
