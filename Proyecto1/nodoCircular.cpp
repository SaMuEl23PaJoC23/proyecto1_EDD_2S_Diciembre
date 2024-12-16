#include "nodoCircular.h"

NodoCircular::NodoCircular(string ID_transaccion, string ID_activoRentado, string UsuRenta,
        string depUsuRenta, string empUsuRenta, string fechaRenta, int diasRenta){
    this->ID_transaccion = ID_transaccion;
    this->ID_activoRentado = ID_activoRentado;
    this->UsuRenta = UsuRenta;
    this->depUsuRenta = depUsuRenta;
    this->empUsuRenta = empUsuRenta;
    this->fechaRenta = fechaRenta;
    this->diasRenta = diasRenta;
    drchaCircular = nullptr;
    izqCircular = nullptr;
}
//Getters
string NodoCircular::getIDtransaccion(){
    return ID_transaccion;
}

string NodoCircular::getIDactivoRentado(){
    return ID_activoRentado;
}

string NodoCircular::getUsuRenta(){
    return UsuRenta;
}

string NodoCircular::getDepUsuRenta(){
    return depUsuRenta;
}

string NodoCircular::getEmpusuRenta(){
    return empUsuRenta;
}

string NodoCircular::getFechaRenta(){
    return fechaRenta;
}

int NodoCircular::getDiasRenta(){
    return diasRenta;
}

NodoCircular* NodoCircular::getDrchaCircular(){
    return drchaCircular;
}

NodoCircular* NodoCircular::getIzqCircular(){
    return izqCircular;
}

//Setters
void NodoCircular::setIDtransaccion(string ID_transaccion){
    this->ID_transaccion = ID_transaccion;
}

void NodoCircular::setIDactivoRentado(string ID_activoRentado){
    this->ID_activoRentado = ID_activoRentado;
}

void NodoCircular::setUsuRenta(string usuRenta){
    this->UsuRenta = usuRenta;
}

void NodoCircular::setDepUsuRenta(string depUsuRenta){
    this->depUsuRenta = depUsuRenta;
}

void NodoCircular::setEmpUsuRenta(string empUsuRenta){
    this->empUsuRenta = empUsuRenta;
}

void NodoCircular::setFechaRenta(string fechaRenta){
    this->fechaRenta = fechaRenta;
}

void NodoCircular::setDiasRenta(int diasRenta){
    this->diasRenta = diasRenta;
}

void NodoCircular::setDrchaCircular(NodoCircular* drchaCircular){
    this->drchaCircular = drchaCircular;
}

void NodoCircular::setIzqCircular(NodoCircular* izqCircular){
    this->izqCircular = izqCircular;
}