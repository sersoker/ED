/* generador de codigos  electronicos de producto
*
*
*/

#include <iostream>
#include <random>
#include <string>
#include <map>

using namespace std;

int main (int argc, char *argv[])
{
if (argc!=2) {
  cout << "Uso: generador num_codigos" << endl;
  exit(0);
}
int cuantos = atoi(argv[1]);

map<int,pair<string,string> > IA;
IA[0]= pair<string,string>("00","Código Seriado de la Unidad de Envío (SSCC)");
IA[1]= pair<string,string>("01"," Código de agrupación");
IA[2]= pair<string,string>("02","Código del artículo / agrupación contenid");
IA[3]= pair<string,string>("37","Cantidades   ");
IA[4]= pair<string,string>("10"," Número de lote");

default_random_engine generator;
uniform_int_distribution<int> digitos(0,9); // Caracteres
uniform_int_distribution<int> longitud(7,14); //Longitud
uniform_int_distribution<int> nsubcodigos(2,5); //nsubocodigos
uniform_int_distribution<int> codigo(0,4); //Longitud



for (int i=0;i<cuantos;i++){
  int nsub = nsubcodigos(generator);
  for (int ns = 0; ns<nsub; ns++) {
    int c = codigo(generator);
    cout << "("<<IA[c].first<<")";
    int lg = longitud(generator);
    for (int l = 0; l< lg ; l++)
      cout << digitos(generator);
  }
 cout << endl;
}

return 0;
 
}