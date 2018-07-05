#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template<typename T>
ostream & operator<<(ostream & sal, const vector<T> & v){
for (int i=0; i< v.size(); i++)
  sal << v[i] <<' ';
return sal;
}

template< typename T>
void desplaza1( vector<T> & v, int p){
  // Usando vector auxiliar
vector<T> aux(v.size());
 int i=p;
 for ( ; i<v.size();i++)
   aux[i-p]=v[i];

 for (int j = 0; j<p;j++){
   aux[i-p]=v[j];
   i++;
 }
 v= aux;
}


template< typename T>
void desplaza2( vector<T> & v, int p){
//vector de tamaño p
vector<T> aux(v.begin(),v.begin()+p);
 int i=p;
 for ( ; i<v.size();i++)
   v[i-p]=v[i];
 for (int j = 0; j<p;j++){
   v[i-p]=aux[j];
   i++;
 
 }
}

template< typename T>
void desplaza3( vector<T> & v, int p){
//vector de tamaño p
vector<T> aux(v.begin(),v.begin()+p);
  copy(v.begin()+p,v.end(),v.begin());
  copy(aux.begin(),aux.end(),v.end()-p);

}

template< typename T>
int maximo2(const vector<T> & v,  int ini,  int fin){
  int maximo =  ini;
  for (int i=ini; i<=fin;i++){
    if (v[i]>maximo)
      maximo = i;
  }
  return maximo;
}

template< typename T>
int maximo1(const vector<T> & v,  int ini,  int fin){

int med;

while (ini != fin){
  med = (ini+fin)/2;
  if (v[ini] < v[med]) 
   ini  = med;
  else fin = med;
}
return med;
}

int main(){
  int tama=5000000;
vector<int> A(tama);

for(int i=0; i<tama; i++) 
  A[i] = i;

desplaza1(A,6);

cout << " maximo = " << A[maximo2(A,0,A.size()-1)]<<endl;

return 0;
} 
