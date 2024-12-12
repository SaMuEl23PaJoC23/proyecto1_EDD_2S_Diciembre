#include "nodo.h"

Nodo::Nodo(int i, int j,string i_dep, string j_empresa){
    this->i_dep = i_dep;
    this->j_empresa = j_empresa;
    this->i = i;
    this->j = j;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;
}

Nodo::Nodo(int i, int j, string i_dep, string j_empresa, string nomUsu, string password, string nomCompleto){
    this->i_dep = i_dep;
    this->j_empresa = j_empresa;
    this->i = i;
    this->j = j;
    this->nomUsu = nomUsu;
    this->password = password;
    this->nomCompleto = nomCompleto;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->izq = nullptr;
    this->dcha = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}

//Setter
void Nodo::setNomUsu(string nomUsu){
    this->nomUsu = nomUsu;
}

void Nodo::setPassword(string password){
    this->password = password;
}

void Nodo::setI(int i){
    this->i = i;
}

void Nodo::setJ(int j){
    this->j = j;
}

void Nodo::setIdep(string i_dep){
    this->i_dep = i_dep;
}

void Nodo::setJempresa(string j_empresa){
    this->j_empresa = j_empresa;
}

void Nodo::setArriba(Nodo *arriba){
    this->arriba = arriba;
}

void Nodo::setAbajo(Nodo *abajo){
    this->abajo = abajo;
}

void Nodo::setIzq(Nodo *izq){
    this->izq = izq;
}

void Nodo::setDcha(Nodo *dcha){
    this->dcha = dcha;
}

void Nodo::setAdelante(Nodo *adelante){
    this->adelante = adelante;
}

void Nodo::setAtras(Nodo *atras){
    this->atras = atras;
}

void Nodo::setNomCompleto(string nomCompleto){
    this->nomCompleto = nomCompleto;
}

//Getters
string Nodo::getNomUsu(){
    return nomUsu;
}

string Nodo::getNomCompleto(){
    return nomCompleto;
}

string Nodo::getPassword(){
    return password;
}

int Nodo::getI(){
    return i;
}

int Nodo::getJ(){
    return j;
}

string Nodo::getIdep(){
    return i_dep;
}

string Nodo::getJempresa(){
    return j_empresa;
}

Nodo* Nodo::getArriba(){
    return arriba;
}

Nodo* Nodo::getAbajo(){
    return abajo;
}

Nodo* Nodo::getIzq(){
    return izq;
}

Nodo* Nodo::getDcha(){
    return dcha;
}

Nodo* Nodo::getAdelante(){
    return adelante;
}

Nodo* Nodo::getAtras(){
    return atras;
}