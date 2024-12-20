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
void AVL::delNodoAVL(string ID_activo){
    this->raizAVL = delNodoAVL(this->raizAVL, ID_activo);
}
//-------------------------------------------------------------------
void AVL::graphAVL(string nomUsu){
    ofstream outfile ("AVL.dot");
    outfile <<" digraph AVLTree{" <<endl;
    outfile <<"root [shape=box, label=\""+ nomUsu +"\"];"<<endl;

    if(raizAVL != nullptr){
        graphAVL(raizAVL, outfile, true);//Aca se crea el dot
    }

    outfile << "}" << endl;
    outfile.close();

    int returnCode = system("dot -Tpng ./AVL.dot -o ./AVL.png");//Permite convertir el .dot en png
    if(returnCode == 0){cout<<"\nDot generado exitosamente...!\n";}
    else{cout<<"Ocurrio un error al general Dot" << returnCode << endl;}
}
//-------------------------------------------------------------------
void AVL::PrintAVL(){
    printAVL(this->raizAVL);
}
//-------------------------------------------------------------------
void AVL::PrintAVLNoRentados(){
    printAVLNoRentados(this->raizAVL);
}
//-------------------------------------------------------------------
void AVL::activoEditar(string ID_activo, string NdescActivo){
    activoEditar(this->raizAVL, ID_activo, NdescActivo);
}
//-------------------------------------------------------------------
bool AVL::activoExistente(string ID_activo, string Operacion){
    return (activoExistente(this->raizAVL, ID_activo, Operacion, false));
}
//-------------------------------------------------------------------
bool AVL::rentarActivo(string ID_activo, int diasParaRentar){
    return (rentarActivo(this->raizAVL, ID_activo, diasParaRentar, false));
}
//-------------------**********************--------------------------
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
NodoAVL* AVL::delNodoAVL(NodoAVL* raizAVL, string ID_activo){
    if(raizAVL == nullptr) return raizAVL;
    else if(ID_activo < raizAVL->getID_activo()){raizAVL->setIzqAVL(delNodoAVL(raizAVL->getIzqAVL(), ID_activo));}
    else if(ID_activo > raizAVL->getID_activo()){raizAVL->setDrchaAVL(delNodoAVL(raizAVL->getDrchaAVL(), ID_activo));}
    else{
        //muestra datos antes de ser eliminados
        cout << "ID: " << raizAVL->getID_activo() << endl;
        cout << "Nombre Activo: " << raizAVL->getNomActivo() << endl;
        cout << "Descripcion: " << raizAVL->getDescActivo() << endl;

        if(raizAVL->esHoja()){
            delete raizAVL;// raizAVL al ser del tipo NodoAVL, se elimina un nodoAVL
            raizAVL = nullptr;
        
        }else if (raizAVL->tieneUnHijo()){
            raizAVL = raizAVL->getHijoUnico();

        }else if (raizAVL->tieneDosHijos()){
            NodoAVL *temp = getMayorDeMenores(raizAVL->getIzqAVL());
            //Se intercambian datos entre el nodo RAIZ a eliminar y el nodo Mayor de menores
            raizAVL->setID_activo(temp->getID_activo());
            raizAVL->setNomActivo(temp->getNomActivo());
            raizAVL->setDescActivo(temp->getDescActivo());
            raizAVL->setDiasParaRentar(temp->getDiasParaRentar());
            raizAVL->setDisponible(temp->getDisponible());
            
            //luego se elimina la posicion (nodo) antigua del nodo mayor de menores
            raizAVL->setIzqAVL(delNodoAVL(raizAVL->getIzqAVL(), temp->getID_activo()));
        }
    }

    if(raizAVL == nullptr) return raizAVL;

    raizAVL->setAltura(alturaMaxima(obtenerAltura(raizAVL->getIzqAVL()), obtenerAltura(raizAVL->getDrchaAVL())) + 1);//establece nueva altura, de acuerdo al nivel donde se encuentre (nodos hoja nivel 1)

    if(getBalance(raizAVL) > 1){
        if(getBalance(raizAVL->getDrchaAVL()) < 0){
            raizAVL->setDrchaAVL(rotacionDrcha(raizAVL->getDrchaAVL()));
            raizAVL = rotacionIzq(raizAVL);
        
        }else{
            raizAVL = rotacionIzq(raizAVL);
        }
    } 

    if(getBalance(raizAVL) < -1){
        if(getBalance(raizAVL->getIzqAVL()) > 0){
            raizAVL->setIzqAVL(rotacionIzq(raizAVL->getIzqAVL()));
            raizAVL = rotacionDrcha(raizAVL);
        }else{
            raizAVL = rotacionDrcha(raizAVL);
        }
    }

    return raizAVL; 
}
//-------------------------------------------------------------------
void AVL::graphAVL(NodoAVL* raizAVL, ofstream &f, bool graf_raiz){
    if(raizAVL != nullptr){
        stringstream oss;//se crea una variable de tipo flujo de datos de strings
        oss << raizAVL;// Se asigna la direccion de memoria a la variable de flujo de strings
        string nombre = oss.str();//Se usa la direccion de memoria (puntero), para dar nombre a los nodos del grafo

        if(graf_raiz){
            f <<"root->NodoAVL" + nombre+";" << endl;
            graf_raiz = false;
        }
        if(raizAVL->getDisponible()){
            f << "NodoAVL" + nombre + "[shape=circle, label = \""+ raizAVL->getNomActivo() + "\", style=filled, fillcolor=lightgreen, width=1.0, height=1.0, fixedsize=true];" << endl;
        }else{f << "NodoAVL" + nombre + "[shape=circle, label = \""+ raizAVL->getNomActivo() + "\", style=filled, fillcolor=red, width=1.0, height=1.0, fixedsize=true];" << endl;}
            

        if(raizAVL->getIzqAVL() != nullptr){//Se crea enlace de nodo hacia la IZQUIERDA
            oss.str("");//Se limpia la variable de flujo de datos
            oss << raizAVL->getIzqAVL();
            string izquierda = oss.str();
            f <<"NodoAVL" << nombre + "->NodoAVL" + izquierda + ";" << endl;
            //enalce: NodoAVL<nombre_raiz> -> NodoAVL<izquierda>;
        }

        if(raizAVL->getDrchaAVL() != nullptr){//Se crea enlace de nodo hacia la DERECHA
            oss.str("");
            oss << raizAVL->getDrchaAVL();
            string derecha = oss.str();
            f << "NodoAVL" << nombre + "->NodoAVL" + derecha + ";" << endl;
            //enlace: NodoAVL<nombre_raiz> -> NodoAVL<derecha>;
        }

        graphAVL(raizAVL->getIzqAVL(), f, graf_raiz);
        graphAVL(raizAVL->getDrchaAVL(), f, graf_raiz);
    }
}
//-------------------------------------------------------------------
void AVL::printAVL(NodoAVL* raizAVL){//Recorrido de acuerdo a estructura InOrden, datos de un solo usuario
    if(raizAVL != nullptr){
        printAVL(raizAVL->getIzqAVL());
        cout<<"ID: " << raizAVL->getID_activo()<<";  ";
        cout<<"Nombre: " << raizAVL->getNomActivo()<<endl;
        printAVL(raizAVL->getDrchaAVL());
    }
}
//-------------------------------------------------------------------
void AVL::printAVLNoRentados(NodoAVL* raizAVL){//Recorrido de acuerdo a estructura InOrden
    if(raizAVL != nullptr){
        printAVL(raizAVL->getIzqAVL());
        if(raizAVL->getDisponible() == true){
            cout<<"ID: " << raizAVL->getID_activo()<<";  ";
            cout<<"Nombre: " << raizAVL->getNomActivo()<<"; ";
            cout<<"Tiempo de renta: " << raizAVL->getDiasParaRentar()<<endl;
        }
        printAVL(raizAVL->getDrchaAVL());
    }
}
//-------------------------------------------------------------------
void AVL::activoEditar(NodoAVL* raizAVL, string ID_activo, string NdescActivo){
    if(ID_activo < raizAVL->getID_activo()){activoEditar(raizAVL->getIzqAVL(), ID_activo, NdescActivo);}
    else if(ID_activo > raizAVL->getID_activo()){activoEditar(raizAVL->getDrchaAVL(), ID_activo, NdescActivo);}
    else{
        raizAVL->setDescActivo(NdescActivo);
        cout<<"ID: " << raizAVL->getID_activo()<<endl;
        cout<<"Nombre: " << raizAVL->getNomActivo()<<endl;
        cout<<"Descripcion: " << raizAVL->getDescActivo()<<"\n\n";
    }
}
//-------------------------------------------------------------------
bool AVL::activoExistente(NodoAVL* raizAVL, string ID_activo, string Operacion ,bool existente){
    if (raizAVL == nullptr){
        cout << "\nID no existente...!"<<endl;
        return (false);
    } 
    else if(ID_activo < raizAVL->getID_activo()){existente = activoExistente(raizAVL->getIzqAVL(), ID_activo, Operacion, existente);}
    else if(ID_activo > raizAVL->getID_activo()){existente = activoExistente(raizAVL->getDrchaAVL(), ID_activo, Operacion, existente);}
    else{
        if(Operacion == "ELIMINAR"){
            if(raizAVL->getDisponible()){
                return (true);
            }
            cout<<"Deben devolver Activo primero...\n";
            return false;
        }
        else{return (true);}
    } 
    return existente;
}
//-------------------------------------------------------------------
bool AVL::rentarActivo(NodoAVL* raizAVL, string ID_activo, int diasParaRentar, bool OPvalida){
    if(ID_activo < raizAVL->getID_activo()){ OPvalida = rentarActivo(raizAVL->getIzqAVL(), ID_activo, diasParaRentar, OPvalida);}
    else if(ID_activo > raizAVL->getID_activo()){OPvalida = rentarActivo(raizAVL->getDrchaAVL(), ID_activo, diasParaRentar, OPvalida);}
    else{
        if(raizAVL->getDisponible()){
            if(diasParaRentar <= raizAVL->getDiasParaRentar()){
                cout<<"\n>> Activo Rentado <<\n";
                cout<<"ID: " << raizAVL->getID_activo()<<endl;
                cout<<"Nombre: " << raizAVL->getNomActivo()<<endl;
                cout<<"Descripcion: " << raizAVL->getDescActivo()<<"\n\n";
                raizAVL->setDisponible(false);
                return true;
            }
            else{cout<<"\nDias ingresados no permiten rentar activo...\n";}
        }
        else{cout<<"\nActivo Ya rentado...!!\n";}
    }
    return OPvalida;
}
