#include "nodoAVL.h"

NodoAVL::NodoAVL(string ID_activo, string nomActivo, 
    string descActivo, int diasParaRentar, bool disponible){
    this->ID_activo = ID_activo;
    this->nomActivo = nomActivo;
    this->descActivo = descActivo;
    this->diasParaRentar = diasParaRentar;
    this->disponible = disponible;

    altura = 1;
    this->izqAVL = nullptr;
    this->drchaAVL = nullptr;
}

//Setter
void NodoAVL::setID_activo(string ID_activo){
    this->ID_activo = ID_activo;
}

void NodoAVL::setNomActivo(string nomActivo){
    this->nomActivo = nomActivo;
}

void NodoAVL::setDescActivo(string descActivo){
    this->descActivo = descActivo;
}

void NodoAVL::setDiasParaRentar(int diasParaRentar){
    this->diasParaRentar = diasParaRentar;
}

void NodoAVL::setDisponible(bool disponible){
    this->disponible = disponible;
}

void NodoAVL::setAltura(int altura){
    this->altura = altura;
}

void NodoAVL::setIzqAVL(NodoAVL* izqAVL){
    this->izqAVL = izqAVL;
}

void NodoAVL::setDrchaAVL(NodoAVL* drchaAVL){
    this->drchaAVL = drchaAVL;
}

//Getters
bool NodoAVL::esHoja(){
    return (izqAVL == nullptr && drchaAVL == nullptr);//retorna true o false
}

bool NodoAVL::tieneUnHijo(){
    return(izqAVL != nullptr && drchaAVL == nullptr) || (izqAVL == nullptr && drchaAVL != nullptr);//retorna true o false
}

bool NodoAVL::tieneDosHijos(){
    return (izqAVL != nullptr && drchaAVL != nullptr);//retorna true o false
}

NodoAVL* NodoAVL::getHijoUnico(){
    if(this->tieneUnHijo()){//this, permite utilizar un metodo dentro de otro
        return (this->izqAVL != nullptr) ? this->izqAVL : this->drchaAVL;
    }
    return nullptr;
}

string NodoAVL::getID_activo(){
    return ID_activo;
}

string NodoAVL::getNomActivo(){
    return nomActivo;
}

string NodoAVL::getDescActivo(){
    return descActivo;
}

int NodoAVL::getDiasParaRentar(){
    return diasParaRentar;
}

bool NodoAVL::getDisponible(){
    return disponible;
}

NodoAVL* NodoAVL::getIzqAVL(){
    return izqAVL;
}

NodoAVL* NodoAVL::getDrchaAVL(){
    return drchaAVL;
}

int NodoAVL::getAltura(){
    return altura;
}