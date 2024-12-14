#include "avl.h"
//-------------------------------------------------------------------
AVL::AVL(){
    this->raizAVL = nullptr;
}
//-------------------------------------------------------------------
AVL::~AVL(){
    postOrden(this->raizAVL);
}
//-------------------------------------------------------------------
void AVL::postOrden(NodoAVL* raizAVL){
    if(raizAVL != nullptr){
        postOrden(raizAVL->getIzqAVL());
        postOrden(raizAVL->getDrchaAVL());
        delete raizAVL;
    }
}
//-------------------------------------------------------------------
void AVL::insertarAVL(string ID_activo, string nomActivo, string descActivo, int diasParaRentar, bool disponible){
    this->raizAVL = insertarAVL(this->raizAVL, ID_activo, nomActivo, 
    descActivo, diasParaRentar, disponible);
}
//-------------------------------------------------------------------
//llamada metodo ELIMINAR
//-------------------------------------------------------------------
void AVL::graphAVL(){
    ofstream outfile ("AVL.dot");
    outfile <<" digraph G{" <<endl;

    if(raizAVL != nullptr){
        graphAVL(raizAVL, outfile);//Aca se crea el dot
    }

    outfile << "}" << endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./AVL.dot -o ./AVL.png");//Permite convertir el .dot en png
    if(returnCode == 0){cout<<"\nDot generado exitosamente...!\n";}
    else{cout<<"Ocurrio un error al general Dot" << returnCode << endl;}
}
//-------------------------------------------------------------------
NodoAVL* AVL::insertarAVL(NodoAVL* raizAVL, string ID_activo, string nomActivo, string descActivo, int diasParaRentar, bool disponible){
    if(raizAVL == nullptr){raizAVL = new NodoAVL(ID_activo, nomActivo, descActivo, diasParaRentar, disponible);}//si raiz es vacia, se le asigna un nodo 'nuevo'
    else if(ID_activo < raizAVL->getID_activo()){raizAVL->setIzqAVL(insertarAVL(raizAVL->getIzqAVL(), ID_activo, nomActivo, descActivo, diasParaRentar, disponible));}
    else if(ID_activo > raizAVL->getID_activo()){raizAVL->setDrchaAVL(insertarAVL(raizAVL->getDrchaAVL(), ID_activo, nomActivo, descActivo, diasParaRentar, disponible));}

    raizAVL->setAltura(alturaMaxima(obtenerAltura(raizAVL->getIzqAVL()), obtenerAltura(raizAVL->getDrchaAVL())) + 1);

    if(getBalance(raizAVL) > 1){
        if(getBalance(raizAVL->getDrchaAVL()) < 0){
            raizAVL->setDrchaAVL(rotacionDrcha(raizAVL->getDrchaAVL()));
            raizAVL = rotacionIzq(raizAVL);
        }
        else{
            raizAVL = rotacionIzq(raizAVL);
        }
    }

    if(getBalance(raizAVL) < -1){
        if(getBalance(raizAVL->getIzqAVL()) > 0){
            raizAVL->setIzqAVL(rotacionIzq(raizAVL->getIzqAVL()));
            raizAVL = rotacionDrcha(raizAVL);
        }
        else{
            raizAVL = rotacionDrcha(raizAVL);
        }
    }
    return raizAVL;
}
//-------------------------------------------------------------------
int AVL::alturaMaxima(int izqAVL, int drchaAVL){
    if(izqAVL >= drchaAVL) return izqAVL;
    return drchaAVL;
}
//-------------------------------------------------------------------
int AVL::obtenerAltura(NodoAVL* raizAVL){
    if(raizAVL == nullptr) return 0;
    return raizAVL->getAltura();
}
//-------------------------------------------------------------------
int AVL::getBalance(NodoAVL* raizAVL){
    return (obtenerAltura(raizAVL->getDrchaAVL()) - obtenerAltura(raizAVL->getIzqAVL()));//Balance = Drcha - Izq
}
//-------------------------------------------------------------------
NodoAVL* AVL::getMayorDeMenores(NodoAVL* raizAVL){
    while (raizAVL->getDrchaAVL() != nullptr){
        raizAVL = raizAVL->getDrchaAVL();
    }
    return raizAVL;
}
//-------------------------------------------------------------------
NodoAVL* AVL::rotacionIzq(NodoAVL* raizAVL){
    NodoAVL* raizDrcha = raizAVL->getDrchaAVL();
    NodoAVL* temp = raizDrcha->getIzqAVL();

    raizDrcha->setIzqAVL(raizAVL);
    raizAVL->setDrchaAVL(temp);

    raizAVL->setAltura(alturaMaxima(obtenerAltura(raizAVL->getIzqAVL()), obtenerAltura(raizAVL->getDrchaAVL())) + 1);
    raizDrcha->setAltura(alturaMaxima(obtenerAltura(raizDrcha->getIzqAVL()), obtenerAltura(raizDrcha->getDrchaAVL())) + 1);

    return raizDrcha;
}
//-------------------------------------------------------------------
NodoAVL* AVL::rotacionDrcha(NodoAVL* raizAVL){
    NodoAVL* raizIzq = raizAVL->getIzqAVL();
    NodoAVL* temp = raizIzq->getDrchaAVL();

    raizIzq->setDrchaAVL(raizAVL);
    raizAVL->setIzqAVL(temp);

    raizAVL->setAltura(alturaMaxima(obtenerAltura(raizAVL->getIzqAVL()), obtenerAltura(raizAVL->getDrchaAVL())) + 1);
    raizIzq->setAltura(alturaMaxima(obtenerAltura(raizIzq->getIzqAVL()), obtenerAltura(raizIzq->getDrchaAVL())) + 1);

    return raizIzq;
}
//-------------------------------------------------------------------
//FUNCION ELIMINAR

//-------------------------------------------------------------------
void AVL::graphAVL(NodoAVL* raizAVL, ofstream &f){
    if(raizAVL != nullptr){
        stringstream oss;//se crea una variable de tipo flujo de datos de strings
        oss << raizAVL;// Se asigna la direccion de memoria a la variable de flujo de strings
        string nombre = oss.str();//Se usa la direccion de memoria (puntero), para dar nombre a los nodos del grafo

        f << "NodoAVL" + nombre + "[label = \""+ raizAVL->getNomActivo() + "\"]" << endl;

        if(raizAVL->getIzqAVL() != nullptr){//Se crea enlace de nodo hacia la IZQUIERDA
            oss.str("");//Se limpia la variable de flujo de datos
            oss << raizAVL->getIzqAVL();
            string izquierda = oss.str();
            f <<"NodoAVL" << nombre + "->NodoAVL" + izquierda << endl;
            //enalce: NodoAVL<nombre_raiz> -> NodoAVL<izquierda>;
        }

        if(raizAVL->getDrchaAVL() != nullptr){//Se crea enlace de nodo hacia la DERECHA
            oss.str("");
            oss << raizAVL->getDrchaAVL();
            string derecha = oss.str();
            f << "NodoAVL" << nombre + "->NodoAVL" + derecha << endl;
            //enlace: NodoAVL<nombre_raiz> -> NodoAVL<derecha>;
        }

        graphAVL(raizAVL->getIzqAVL(), f);
        graphAVL(raizAVL->getDrchaAVL(), f);
    }
}
//-------------------------------------------------------------------
void AVL::printAVL(NodoAVL* raizAVL){//Recorrido de acuerdo a estructura InOrden
    if(raizAVL != nullptr){
        printAVL(raizAVL->getIzqAVL());
        cout<<raizAVL->getNomActivo()<<endl;
        printAVL(raizAVL->getDrchaAVL());
    }
}
