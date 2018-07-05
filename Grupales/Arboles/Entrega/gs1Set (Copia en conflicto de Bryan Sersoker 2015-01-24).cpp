#include "gs1Set.h"

using namespace std;

/**
     @brief Constructor primitivo
     crea un gs1Set  con el pair <"gs1",0> en el nodo raiz.
  */
gs1Set::gs1Set (){
  pair<string,int> aux("gs1",0);
  arbol.setroot(aux);
  tama = 0;
}

  /**
     @brief Constructor de copia.

     @param[in] x gs1Set  que se copia

  */
gs1Set::gs1Set (const gs1Set  & x){
  arbol = x.arbol;
  tama = x.tama;
}

/** @brief insercion del string, cada caracter en una posicion independiente
@todo implementar este metodo correctamente
OJO ESTE METODO SOLO SIRVE PARA DAR UNA IDEA DEL PROCESO DE INSERCION,
HAY QUE IMPLEMENTARLO CORRECTAMENTE
*/


bool gs1Set::insert(const string& s){
tree<pair<string,int> >::node n, aux;
string::const_iterator it;
string cadena;
bool hay_que_insertar = false, encontrado;
pair <string, int> par;


  n = arbol.root();
  for (it = s.begin(); it!=s.end(); ++it) { // Para cada caracter del string
        cadena.clear();
        if ((*it)=='('){ //es IA
            while ((*it) != ')'){ //guardamos en aux el IA entero
                cadena = cadena + (*it);
                it++;
            }
            cadena = cadena + (*it); //metemos el ')'
            par.first = cadena;
            par.second = -1;  //Negativo para los codigos IA
        }
        else{ //no es IA
            cadena = (*it);
            par.first = cadena;
            par.second = 0;
        }

        aux = n.left();
        if (!hay_que_insertar){
            if (aux.null()){
                hay_que_insertar=true;
                if (n.parent().null()){
                    //cout << "Primer insert"<<endl;
                    tama++;
                }
                n= arbol.insert_left(n,par);
            }
            else if ( (*aux).first == cadena ){
                n=aux;
            }
            else if ( (*aux).first > cadena ){
                tama++;
                arbol.insert_left(n,par);
                n=n.left();
                hay_que_insertar=true;
            }
            else {
                n=aux;
                aux = n.next_sibling();
                encontrado = false;
                while( !aux.null() && !hay_que_insertar && !encontrado ){
                    if((*aux).first > cadena ){
                        hay_que_insertar = true;
                        tama++;
                        arbol.insert_right_sibling( n, par );
                    }
                    else if ((*aux).first == cadena )
                        encontrado = true;
                    n=aux;
                    aux = aux.next_sibling();
                }
            }
        }
        else{
            arbol.insert_left(n,par);
            n = n.left();

        }

  }
  //Una vez insertado el código, tenemos que actualizar los nodos (en el caso de que se hubiera insertado)
   if(hay_que_insertar)
        while ( !(n.parent().parent().null()) ){
            if( (*n).second >= 0 )
                (*n).second = (*n).second + 1;
            n=n.parent();
        }
        //cout << "salimos while"<<endl;
}

/** @brief elimina  el codigo de un gs1Set

@param[in] s elemento a borrar. Este elemento puede identificar a un prefijo, por ejemplo el codigo asociado a un producto, por lo que todos los codigos que contienen dicho prefijo seran eliminados.
@return el numero de codigos que se han borrado, cero si el borrado no se ha podido realizar con exito
@post  el size() sera decrementado.

*/
int gs1Set::erase( const string &s){
    int codigos_eliminados;
    gs1Set::const_iterator it = find(s);
    //cout << *it<<endl;
    tree<pair<string,int> >::node aux, padre;
    tree<pair<string,int> > eliminado;

    if(tama==0){
        return 0;
    }

    if (it != end()){
        //cout << "1"<<endl;
        if ((*it.act).second <0){//Es IA{
            //cout << "1.1"<<endl;
            for(aux = it.act.left();!aux.next_sibling().null();aux=aux.next_sibling())
                //cout << "1.0.1"<<endl;
                codigos_eliminados += (*aux).second;
        }
        else{
            //cout << "1.2"<<endl;
            aux = it.act;
            codigos_eliminados = (*aux).second;
        }
        while (aux.parent().left().next_sibling().null()&&!arbol.is_root(aux.parent())){ //Si el padre tiene un solo hijo, subimos para cortar más arriba
            //cout << "1.1.1"<<endl;
            aux = aux.parent();
        }
        padre = aux.parent();
        if (padre.left()==aux){
            //cout << "1.1.2"<<endl;
            arbol.prune_left(padre,eliminado);
            eliminado.clear();
        }
        else{
            //cout << "1.1.3"<<endl;
            padre = padre.left();
            while(!padre.next_sibling().null()&&padre.next_sibling()!=aux){
                //cout << "1.1.4"<<endl;
                padre = padre.next_sibling();
            }
            arbol.prune_right_sibling(padre,eliminado);
            eliminado.clear();
            padre = padre.parent();
        }

        //Actualizamos los campos second

        while(!arbol.is_root(padre)){
            //cout << "2"<<endl;
            if((*padre).second>=0){
                //cout << "2.1"<<endl;
                (*padre).second=(*padre).second - codigos_eliminados;
            }
            padre = padre.parent();
        }
        //cout << "3"<<endl;
        tama-=codigos_eliminados;
        return codigos_eliminados;
    }
    else
        return 0;
}

/** @brief busca un codigo
@param[in] s nombre del codigo (o prefijo) a buscar
@return un iterador que apunta al codigo o end() si el codigo (prefijo) no existe.
*/
gs1Set::const_iterator gs1Set::find( const string & s){
    gs1Set::const_iterator sal;
    tree<pair<string,int> >::node n, aux;
    string::const_iterator it, compara1, compara2;
    string cadena;
    bool encontrado = true, para = false, iguales;
    pair <string, int> par;
    int compara_cadenas;


  n = arbol.root();

  for (it = s.begin(); it!=s.end()&&encontrado; ++it) { // Para cada caracter del string
      cadena.clear();
        if ((*it)=='('){ //es IA
            while ((*it) != ')'){ //guardamos en aux el IA entero
                cadena = cadena + (*it);
                it++;
            }
            cadena = cadena + (*it); //metemos el ')'
            par.first = cadena;
            par.second = -1;  //Negativo para los codigos IA
        }
        else{ //no es IA
            cadena = (*it);
            par.first = cadena;
            par.second = 0;
        }

        aux = n.left();

            if (aux.null()){
                encontrado = false;
            }
            else{
                compara_cadenas=cadena.compare((*aux).first);
                //cout <<"Cadena: "<<cadena<<" Nodo: "<<(*aux).first<<endl;
                if ( compara_cadenas==0 ){
                    //cout <<"cadena == nodo"<<endl;
                    n=aux;
                }
                else if ( compara_cadenas<0 ){
                    //cout <<"cadena < nodo"<<endl;
                    encontrado = false;
                }
                else {
                    //cout <<"cadena > nodo"<<endl;
                    n=aux;
                    aux = n.next_sibling();
                    while( !aux.null() && encontrado && !para ){
                        //cout << "Entro en el while"<< endl;
                        compara_cadenas=cadena.compare((*aux).first);
                        if( compara_cadenas<0 ){
                            //cout << "Entro en el if"<< endl;
                            encontrado = false;
                        }
                        else if (compara_cadenas==0 ){
                            para = true;
                            //cout <<"Me paro en el hermando: "<<(*aux).first<<endl;
                        }
                        n=aux;
                        aux = aux.next_sibling();
                    }
                }
            }

  }
  if (encontrado){
    sal.ptr=this;
    sal.act=n;
  }
  else{
            sal = end();//sal.act = arbol.root().parent();
        }
  return sal;
}

/** @brief obtiene todos los codigos que tienen la misma secuencia prefijo
@param[in] pr   prefijo  a buscar
@return una lista con todos los codigos epc que contienen el mismo prefijo
*/
list<string> gs1Set::codesWithPrefix( const string & pr){
    list<string> sal;
    gs1Set::const_iterator it = find(pr);
    //cout << (*it)<<endl;
    gs1Set::const_iterator busca = it;
    tree<pair<string,int> >::node aux;
    aux = it.act;
    //cout << "1"<<endl;

    if(it==end())
        return sal;

    while(!aux.parent().null()&&aux.next_sibling().null()){
        //cout << "2"<<endl;
        aux = aux.parent();
    }
    //cout << (*aux).first<<endl;
    if (arbol.is_root(aux)){
        //cout << "3"<<endl;
        aux = tree<pair <string, int> >::node();
    }
    else{
        //cout << "4"<<endl;
        aux = aux.next_sibling();
        //cout << "hola"<<endl;
        while(!aux.left().null()&&(*(aux.left())).second >= 0 ){
            //cout << "5"<<endl;
            aux = aux.left();
        }
        //cout << (*aux).first<<endl;
    }
    //cout << "6"<<endl;
    while (busca.act!=aux){
        //cout<<"bucle"<<endl;
        if( busca.act.left().null() ){
            //cout <<(*busca)<<endl;
            sal.push_back(*busca);
            //cout << "codigo insertado"<<endl;
        }
        //cout << "antes de ++"<<endl;
        busca++;
    }
    return sal;
}

/** @brief  imprime todos los codigos almacenados
*/

void gs1Set::print( ) const {
  tree<pair<string,int> >::const_preorderiterator it;
  tree<pair<string,int> >::const_leveliterator itn;
   cout << "preorden " << endl;

  for (it= arbol.beginPreorder(); it!= arbol.endPreorder();++it)
    cout << (*it).first << " "<< (*it).second << endl;

   cout << "Nivel " << endl;
  for (itn= arbol.beginlevel(); itn!= arbol.endlevel();++itn)
    cout << (*itn).first << " "<< (*itn).second << endl;

}


/**
@todo implementar este metodo correctamente
OJO ESTE METODO OS SIRVE PARA PODER CONSTRUIR UN ARBOL
NO TIENE EN CUENTA EL INVARIANTE DE LA REPRESENTACION
AL NO CONSIDERAR EL CAMPO INT DEL NODO!!!!!
DEBEIS MODIFICARLO PARA QUE LO HAGA DE FORMA CORRECTA
*/

void gs1Set::reading_gs1Set ( ) {

  tree<pair<string,int> >::node n, h;
  queue< tree<pair<string,int> >::node > Q;

  pair<string,int> aux;

  n = arbol.root();
  Q.push(n);
  while (!Q.empty() ){
    n = Q.front();
    Q.pop();
    cout << "Hijo Izq de " << (*n).first << "/ si no tiene hijos "<< endl;
    cin >> aux.first;
    if (aux.first != "/") {
      h= arbol.insert_left(n,aux);
      Q.push(h);
      cout << "Hermano Dhc de " << (*h).first<< "/ si no tiene hermano "<< endl;
      cin >> aux.first;
      while (aux.first != "/") {
        h= arbol.insert_right_sibling(h,aux);
        Q.push(h);
        cout << "Hermano Dhc de " << (*h).first<< "/ si no tiene hermano"<< endl;
        cin >> aux.first;
      }
    }

  }
}
/*
//Intento de implementado (hasta que nos enteramos que no hacía falta implementarlo si nos funciona el insert)
void gs1Set::reading_gs1Set ( ) {

  tree<pair<string,int> >::node n, h;
  queue< tree<pair<string,int> >::node > Q;
  int hermanos_derechos;

  pair<string,int> aux;

  n = arbol.root();
  Q.push(n);
  while (!Q.empty() ){
    n = Q.front();
    Q.pop();
    cout << "Hijo Izq de " << (*n).first << "/ si no tiene hijos "<< endl;
    cin >> aux.first;
    if (aux.first != "/") {
        if ( aux.first[0]=='(' ){
            aux.second = -1;
            if ( (*n).second >= 0 && !arbol.is_root(n)) //Por si el anterior tambien fuera IA (aunque no debería), no modificarlo
            (*n).second = (*n).second + 1 ;
        }
        else
            aux.second = 0;
      h= arbol.insert_left(n,aux);
      Q.push(h);
      cout << "Hermano Dch de " << (*h).first<< "/ si no tiene hermano "<< endl;
      cin >> aux.first;
      hermanos_derechos = 0;
      while (aux.first != "/") {
        hermanos_derechos++;
            if ( aux.first[0]=='(' ){
                aux.second = -1;
                if ( (*n).second == 0 )
                    (*n).second = 1;
            }
            else
                aux.second = 0;
            h= arbol.insert_right_sibling(h,aux);
            Q.push(h);
            cout << "Hermano Dch de " << (*h).first<< "/ si no tiene hermano"<< endl;
            cin >> aux.first;
      }

    //Actualizamos el campo second de los nodos z

    h = h.parent();
    while (!(arbol.is_root(h))){ //Recorremos hacia arriba el arbol
        if ( (*h).second > 0 )  //Es nodo z
            (*h).second = (*h).second + hermanos_derechos;
        h = h.parent();
    }

  }
  else
    aux.second=1;
 }
}
*/
  /** @brief operador de asignacion
@param[in] org gs1Set  a copiar.
 Crea un gs1Set   duplicado exacto a org.
*/

gs1Set & gs1Set::operator= ( const gs1Set & org ){
    arbol = org.arbol;
    tama = org.tama;
}

/** @brief tamanioo
 * @return delvuelve el numero de palabras del gs1Set
*/

gs1Set::size_type gs1Set::size() const{
    return tama;
}

/** @brief   Chequea si el gs1Set  esta vacio (size()==0)
*/
  bool gs1Set::empty() const{
    return tama==0;
  }

/** @brief  iterador a la primera palabra del conjunto.

Este iterador debe apuntar al nodo en el que se encuentra el ultimo caracter de
la primera palabra en el conjunto.

*/
gs1Set::const_iterator gs1Set::begin() const{
    gs1Set::const_iterator aux;
    aux.ptr=this;
    aux.act = arbol.root();
    aux.act = aux.act.left();
    while ((*(aux.act.left())).second > 0){
        aux.act=aux.act.left();
    }
    return aux;
}

/** @brief  iterador al fin del conjunto
*/
gs1Set::const_iterator gs1Set::end() const{//PREGUNTAR
    gs1Set::const_iterator aux;
    aux.ptr=this;
    aux.act = tree<pair<string,int> >::node();
    return aux;
}
/** @brief   Representacion.
El gs1Set  se representa mediante un arbol general (tree) donde en cada nodo  n, de tipo tree< pair<string,int> >::node, tenemos que (*n) es una referencia al par que almacena, cuyo primer elemento , esto es (*n).first,  es un string que representa un indentificador de aplicación IA, o un caracter aislado del código, en cuyo caso (*n).first.size()==0. En este último caso, necesariamente debe tomar valores en {0123456789}. Por otro lado, el segundo elemento del par, (*n).second,  es un entero que se utiliza para:

- identificar si el nodo es un IA, en cuyo caso debe verificarse que ((*n).second < 0)
 -identificar si el nodo contiene el caracter final de subcódigo (representado por z en el ejemplo anterior), donde  (*n).second > 0. En este caso, el valor será el número total de  codigos completos que cuelgan del mismo. Destacar que este valor NO corresponde con el número de hijos directos, sino con el número total de hojas que cuelgan del subárbol con raiz en n.

Los hijos de un nodo deben estar NECESARIAMENTE ORDENADOS de menor a mayor.

*/
bool gs1Set::cheq_rep(){
    tree<pair<string, int> >::node n, aux;
    n = arbol.root();
    int suma;

    if (aux.null()){
        if ((*n).first=="gs1"&&(*n).second==0)
            return true;
        else
            return false;
    }
    while ( n != tree<pair<string,int> >::node() ){

       //Comprobamos si en el nodo actual:
            //1) Los hijos que cuelgan están ordenados por su campo first
            //2) El campo second del nodo actual es la suma del de sus hijos

        aux = n.left();
        suma = 0;

        if (aux.null()){//Si el nodo actual es hoja
            if((*n).second!=1) //FALLO (no contemplo que el ultimo campo sea un IA)
                return false;
            else{   //Nos movemos al siguiente nodo
                if (!n.next_sibling().null()){//Si el nodo tiene un hermano
                    if ( (*n).first>=(*(n.next_sibling())).first ) return false;    //Comprobamos que estén en orden
                    n=n.next_sibling();
                }
                else{
                    while(!arbol.is_root(n)&&n.next_sibling().null()){//Subimos hasta encontrar un hermano
                        n=n.parent();
                    }
                    if(arbol.is_root(n))//Si no tiene hermanos, hemos terminado
                        n == tree<pair<string,int> >::node();
                    else{
                        if ( (*n).first>=(*(n.next_sibling())).first ) return false;    //Comprobamos que estén en orden
                        n=n.next_sibling();
                    }

                    //miramos si el campo second de n es igual a la suma del second de sus hijos
                    if ((*n).second!=suma && (*n).second>0 && !arbol.is_root(n))
                        return false;
                }
            }
        }
        else{//Si el nodo actual no es hoja, comprobamos el campo second
            if((*n).first[0]=='('){//Si el nodo es IA, el second debe ser negativo
                if((*n).second>=0)
                    return false;
            }
            else{//No es un nodo IA. Comprobamos que el second sea la suma de sus hijos
                aux = n.left();
                while(!aux.null()){
                    suma = suma + (*aux).second;
                    aux=aux.next_sibling();
                }
                if(suma != (*n).second)
                    return false;
            }
            n=n.left();//Bajamos en el arbol
        }
    }
    return true;
}

///////////////////////////////
////////CONST_ITERATOR/////////
///////////////////////////////

/**
     @brief Constructor primitivo
  */
gs1Set::const_iterator::const_iterator(){//PREGUNTAR
}

/**
   @brief Constructor de copia
*/
gs1Set::const_iterator::const_iterator( const gs1Set::const_iterator & it){
    act = it.act;
    ptr = it.ptr;
}

/**
    @brief devuelve el codigo completo al que apunta el
    iterador.
    Nota: Se encuentra en el camino que hay desde el nodo hacia la raiz.
*/
string  gs1Set::const_iterator::operator*(){
    tree<pair<string,int> >::node aux = act;
    string sal;
    if (!act.null())
        while ( !(*ptr).arbol.is_root(aux) ){
            sal = (*aux).first + sal;
            aux=aux.parent();
        }
    //cout << sal;
    else
        sal=" ";
    return sal;
}

/**
    @brief avanza hacia el siguiente final de (sub)codigo en preorden en el gs1Set .
    Nota: Avanza por el arbol  hasta el siguiente nodo que
    es final de (sub)codigo.
*/

gs1Set::const_iterator & gs1Set::const_iterator::operator++(){
  if (act.null())
    return *this;
    //cout << "dentro de busca"<<endl;
    if (!act.left().null()){
        //cout << "dentro de if"<<endl;
        act = act.left();//Nos posicionamos en el IA
        while(!act.left().null()&&(*(act.left())).second >= 0){
            //cout << "dentro de while"<<endl;
            act = act.left();
            //cout << "al otro lado del while"<<endl;
        }
        //cout << "fuera de while"<<endl;
    }
    else{
        //cout << "dentro de else"<<endl;
        while(act.next_sibling().null()&&!act.parent().null()){
            act = act.parent();
        }
        if ((*ptr).arbol.is_root(act)){
            act = tree<pair <string, int> >::node();
        }
        else{
            act = act.next_sibling();
            while(!act.left().null()&&(*(act.left())).second >= 0 ){
                act = act.left();
                //cout <<"no entro"<<endl;
            }
            //cout <<"estoy aqui"<<endl;
        }
    }
    return *this;
}

/**
    @brief avanza hacia  el siguiente final de (sub)codigo en preorden en el gs1Set.
    Nota: Avanza por el arbol  hasta el siguiente nodo que
    es final de (sub)codigo.
*/
gs1Set::const_iterator gs1Set::const_iterator::operator++(int){
  gs1Set::const_iterator aux(*this);
  ++(*this);
  return aux;
}

/**
    @brief sube hacia  el identificador de aplicacion (IA) anterior en el codigo.
*/
gs1Set::const_iterator & gs1Set::const_iterator::upper_IA(){
    tree<pair<string,int> >::node aux;
    aux = act;
    aux = aux.parent();
    while(!aux.parent().null()&&(*aux).second>0)
        aux=aux.parent();
    //Si el siguiente subcodigo es el root, no hace nada
    if (!(*ptr).arbol.is_root(aux))
        act=aux;
    return (*this);
}
/**
    @brief hacer copia del iterador pasado
    return el iterador copiado
*/
gs1Set::const_iterator & gs1Set::const_iterator::operator=(const const_iterator & it){
    act=it.act;
    ptr=it.ptr;
}
/**
    @brief compara los datos miembro de los dos iteradores
    return true si son iguales, false si no lo son
*/
bool gs1Set::const_iterator::operator==(const gs1Set::const_iterator & it) const{
    bool sal;
    if( act == it.act && ptr == it.ptr )
        sal = true;
    else
        sal = false;
    return sal;
}
/**
    @brief compara los datos miembro de los dos iteradores
    return false si son iguales, true si no lo son
*/
bool gs1Set::const_iterator::operator!=(const gs1Set::const_iterator & it) const{
    bool sal;
    if( act == it.act && ptr == it.ptr )
        sal = false;
    else
        sal = true;
    return sal;
}
