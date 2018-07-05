/* vectorD.h
 *
 * Copyright  (C) Bryan Moreno Picamán & Aarón Rodríguez Bueno
 *
 */

/////////////////////////////////////////
//////////// constructores //////////////
/////////////////////////////////////////

#include "polinomio.h"
#include "vectorD.h"

Polinomio::Polinomio(){
    poli=vectorD<int>(0);

}

Polinomio::Polinomio(const Polinomio & p){
    poli=p.poli;
}

////////////////////////////////////
/////////// Consultores ////////////
////////////////////////////////////

int Polinomio::grado() const{
    if (poli.size()!=0)
        return poli.size()-1;
    else
        return 0;
}

int Polinomio::coeficiente(int p)const{
    return poli[p];
}

////////  MODIFICADORES //////////////////////
void Polinomio::assign(int g, int c){
    poli.assign(g,c);
}

void Polinomio::push_back(int c){
    poli.push_back(c);
}

/////////////// operadores ///////////////////


Polinomio & Polinomio::operator= (const Polinomio & p){
    poli=p.poli;
}

Polinomio & Polinomio::operator+ (const Polinomio & p){
    int suma;
    for (int i = 0; i <= p.grado(); i++){
        if(i<=(*this).grado()){
            suma = poli[i]+p.poli[i];
            poli.assign(i, suma);
        }
        else{
            suma = p.poli[i];
            poli.push_back(suma);
        }
    }
}

Polinomio & Polinomio::operator- (const Polinomio & p){
    int resta;
    for (int i = 0; i <= p.grado(); i++){
        if(i<=(*this).grado()){
            resta = poli[i]-p.poli[i];
            poli.assign(i, resta);
        }
        else{
            resta = 0-p.poli[i];
            poli.push_back(resta);
        }
    }
}

////////////////////////////////////////




Polinomio::iterator Polinomio::begin(){
    vectorD<int>::iterator aux=poli.begin();
    Polinomio::iterator sal;
    sal.it=aux;
    return sal;
}
/** iterador (read) al inicio sobre todos los elementos del polinomio */

Polinomio::iterator Polinomio::end(){
    vectorD<int>::iterator aux=poli.end();
    Polinomio::iterator sal;
    sal.it=aux;
    return sal;
}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */



Polinomio::const_iterator Polinomio::cbegin() const{
    vectorD<int>::const_iterator aux=poli.cbegin();
    Polinomio::const_iterator sal;
    sal.it=aux;
    return sal;
}
/** iterador  (read) inicio sobre todos los elementos del polinomio */

Polinomio::const_iterator Polinomio::cend() const{
    vectorD<int>::const_iterator aux=poli.cend();
    Polinomio::const_iterator sal;
    sal.it=aux;
    return sal;
}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */



Polinomio::stored_iterator Polinomio::sbegin(){
    vectorD<int>::stored_iterator aux=poli.sbegin();
    Polinomio::stored_iterator sal;
    sal.ite=aux;
    return sal;
}
/** iterador (read) al inicio sobre todos los elementos del polinomio */

Polinomio::stored_iterator Polinomio::send(){
    vectorD<int>::stored_iterator aux=poli.send();
    Polinomio::stored_iterator sal;
    sal.ite=aux;
    return sal;
}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */



Polinomio::const_stored_iterator Polinomio::csbegin() const{
    vectorD<int>::const_stored_iterator aux=poli.csbegin();
    Polinomio::const_stored_iterator sal;
    sal.ite=aux;
    return sal;
}
/** iterador  (read) inicio sobre todos los elementos del polinomio */

Polinomio::const_stored_iterator Polinomio::csend() const{
    vectorD<int>::const_stored_iterator aux=poli.csend();
    Polinomio::const_stored_iterator sal;
    sal.ite=aux;
    return sal;
}
/** iterador  (read) final (siguiente al ultimo)  sobre todos los elementos del polinomio */

    ////////////////////////////////////////////////
    ///////////////////ITERATOR/////////////////////
    ////////////////////////////////////////////////

    Polinomio::iterator::iterator() {

    }

    Polinomio::iterator::iterator(const Polinomio::iterator & p){
        it=p.it;
    }

    Polinomio::iterator & Polinomio::iterator::operator++( ){
        it++;
        return *this;
    }

    Polinomio::iterator Polinomio::iterator::operator++(int ) {
        Polinomio::iterator sal;
        sal = *this;
        it++;
        return sal;
    }

    const  int & Polinomio::iterator::operator *( ){
        return *it;

    }

    bool Polinomio::iterator::operator == (const Polinomio::iterator & p) {
        return it==p.it;
    }

    bool Polinomio::iterator::operator != (const  Polinomio::iterator & p){
        return it!=p.it;
    }

    Polinomio::iterator & Polinomio::iterator::operator=(const Polinomio::iterator & p){
        it=p.it;
    }

    ////////////////////////////////////////////////
    ///////////////////CONST_ITERATOR///////////////
    ////////////////////////////////////////////////

    Polinomio::const_iterator::const_iterator() {

    }

    Polinomio::const_iterator::const_iterator(const Polinomio::const_iterator & p){
        it=p.it;
    }

    Polinomio::const_iterator::const_iterator(const Polinomio::iterator & p){
        it=p.it;
    }

    Polinomio::const_iterator & Polinomio::const_iterator::operator++( ){
        it++;
        return *this;
    }

    Polinomio::const_iterator Polinomio::const_iterator::operator++(int ) {
        Polinomio::const_iterator sal;
        sal = *this;
        it++;
        return sal;
    }

    const  int & Polinomio::const_iterator::operator *( ){
        return *it;

    }

    bool Polinomio::const_iterator::operator == (const Polinomio::const_iterator & p) {
        return it==p.it;
    }

    bool Polinomio::const_iterator::operator != (const  Polinomio::const_iterator & p){
        return it!=p.it;
    }

    ////////////////////////////////////////////////
    //////////////STORED_ITERATOR///////////////////
    ////////////////////////////////////////////////

    Polinomio::stored_iterator::stored_iterator() {

    }

    Polinomio::stored_iterator::stored_iterator(const Polinomio::stored_iterator & d) : ite(d.ite) {
        ite=d.ite;
    }

    ////////////////////////////////////////////////
    ////////////CONST_STORED_ITERATOR///////////////
    ////////////////////////////////////////////////

    Polinomio::const_stored_iterator::const_stored_iterator(){

    }

    Polinomio::const_stored_iterator::const_stored_iterator(const Polinomio::const_stored_iterator & d) {
        ite=d.ite;
    }

    Polinomio::const_stored_iterator::const_stored_iterator(const stored_iterator & d) {
        ite=d.ite;
    }
    // Conversion de iterator a const_iterator

    Polinomio::const_stored_iterator & Polinomio::const_stored_iterator::operator= (const Polinomio::const_stored_iterator & d) {
        ite=d.ite;
    }
