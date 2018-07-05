// constructor // empty // size
// top // push_back // pop_back // swap
//
#ifndef __stack.h
#define __stack.h

template <typename T> 
class stack{
private:
	T * datos;
	int maximo;
	int tamanio;

private2:
     vector <T> datos;

public:
	stack();
	~stack();
	stack(const stack<T> & pila);
	bool empty();
	int size();
	&T top();
     const &T top () const;
	void push_back(const T & dato);
	void pop_back();
	void swap(stack<T> & dato);
}
#include stack.hxx
#endif

// Implementacion

//constructor
template<typename T> stack<T>::stack(){
	datos = new T[10];
	maximo = 10;
	tamanio = 0;
}
//destructor
template<typename  T> stack<T>::~stack(){
	delete[] datos;
}

//constructor de copia
template <typename T> stack<T>::stack(const stack <T> & pila){
	max =  pila.maximo;
	tamanio = pila.tamanio;
	datos = new T[maximo]
	for (int i=0;i<tamanio;i++)
		T[i]=pila.datos[i];
}
/ / constructor copia 2
template < typename T > stack < T > : : stack ( const stack < T > & pila ) {
        datos= pila.datos;
}

//empty
template <typename T> bool stack<T>::empty(){
	if (tamanio==0)
		return true;
	else
		return false;
}


//size
template <typename T> int stack<T>::size(){
	return tamanio;
}
//top
template <typename T> T stack<T>::top(){
	return datos[tamanio-1];
}
/ / top2
template < typename> T stack < T > : : top ( ){
    return datos. back ()

}
template < typename> const T stack < T > : : top ( )const{
    return datos. back ()

}

//PushBack
template <typename T> void stack<T>::push_back(const T & dato){
	if (!tamanio>=maximo){
		dato[tamanio]=dato;
		tamanio++;
	}
	else{
		maximo=maximo*2;
		T * auxiliar = new T[maximo];
			for (int i=0;i<maximo/2;i++){
				auxiliar[i]= datos[i];
			}
				delete[] datos;
				datos=auxiliar;
				dato[tamanio]=dato;
				tamanio++;
					
	}
	
}
/ / PushBack 2
void stack < T > : : push_back (const T & dato ) {
       datos.push_back (dato);
}

//Popback
template <typename T> void stack<T>::pop_back(){
		tamanio--;
}

//swap	void swap(stack<T> & dato);
template <typename T> void stack<T>::push_back(stack<T> & dato){
	T * auxiliar = new T[dato.size()];
	
		for (int i=0;i<dato.size();i++){
				auxiliar[i]= datos[i];
		
		delete [] dato;
		for (int j=0;j<tamanio;j++)
			dato.push_back(datos[j]);
		
		delete [] datos;
		for  (int k=0;k<auxiliar.size();k++)
			datos.push_back(auxiliar[k]);

}

/ / swap 2
template < typename T > void stack < T > : : stack ( stack < T > & dato){
       datos,.swap (dato.datos);
}









