#include "circularDoble.h"
//-------------------------------------------------------------------
CircularDoble::CircularDoble(){
    largo = 0;
    primero_NodoC = nullptr;
}
//-------------------------------------------------------------------
CircularDoble::~CircularDoble(){
    NodoCircular* temp = primero_NodoC->getDrchaCircular();
    NodoCircular* aux;

    while(temp != primero_NodoC){
        aux = temp->getDrchaCircular();
        delete temp;
        temp = aux;
    }

    //dado que vuelve al nodo inicio, se elimina
    delete temp;
}
//-------------------------------------------------------------------
void CircularDoble::append(string ID_transaccion, string ID_activoRentado, string UsuRenta, string depUsuRenta, string empUsuRenta, string fechaRenta, int diasRenta){
    NodoCircular* nuevo = new NodoCircular(ID_transaccion, ID_activoRentado, UsuRenta, depUsuRenta, empUsuRenta, fechaRenta, diasRenta);
    NodoCircular* temp;

    if(primero_NodoC != nullptr){
        temp = primero_NodoC;
        while (temp->getDrchaCircular() != primero_NodoC){
            temp = temp->getDrchaCircular();
        }

        if(largo == 1){
            temp->setDrchaCircular(nuevo);
            temp->setIzqCircular(nuevo);//

            nuevo->setDrchaCircular(primero_NodoC);
            nuevo->setIzqCircular(temp);
        }
        if(largo > 1){
            temp->setDrchaCircular(nuevo);
            nuevo->setDrchaCircular(primero_NodoC);
            nuevo->setIzqCircular(temp);
            primero_NodoC->setIzqCircular(nuevo);
        }
    }
    else{//Si no existe nodos en lista, se crea el primer nodo
        nuevo->setDrchaCircular(nuevo);
        nuevo->setIzqCircular(nuevo);
        primero_NodoC = nuevo;
    }
    largo++; //Permite llevar el control de cuantos nodos contiene lista CIRCULA
}
//-------------------------------------------------------------------
void CircularDoble::graphCircular(){
    ofstream outfile("listaCircular.dot");
    string conexiones, conexion = "";
    string numeroNodo, tableStruture;
    NodoCircular* temp = primero_NodoC;
    string trO = "<tr><td>";
    string trC = "</tr></td>";

    int index = 0;

    outfile << "digraph G { " << endl;
    if(primero_NodoC != nullptr){
        do{
            numeroNodo = to_string(index);
            tableStruture = "< <table border=\"0\" cellborder=\"1\" cellspacing=\"0\">";
            outfile << "NodoC" + numeroNodo + " [label ="+ tableStruture 
                +trO+ temp->getIDtransaccion() +trC
                +trO+ temp->getIDactivoRentado() +trC
                +trO+ temp->getUsuRenta() +trC
                +trO+ temp->getDepUsuRenta() +trC
                +trO+ temp->getEmpusuRenta() +trC
                +trO+ temp->getFechaRenta() +trC+
                trO+ to_string(temp->getDiasRenta()) +trC+ "</table> >];" <<endl;

            conexion = "NodoC" + numeroNodo + "->";
            if(temp->getDrchaCircular() != primero_NodoC){
                conexion = conexion + "NodoC" + to_string(index + 1);
                conexiones = conexiones + conexion + "\n";
                conexiones = conexiones + conexion + "[dir = back] \n";
            }
            temp = temp->getDrchaCircular();
            index++;
        } while (temp != primero_NodoC);
        
        if(largo == 1){conexiones = "NodoC0->NodoC0\n NodoC0->NodoC0 [dir = back] \n";}
        else{
            conexiones = conexiones + conexion + "NodoC0";
            conexiones = conexiones + "->"+ "NodoC" + to_string(index-1);
            }
    }

    outfile << conexiones << endl;
    outfile << "rankdir = LR" << endl;
    outfile << "}" << endl;
    outfile.close();

    int returnCodeC = system("dot -Tpng ./listaCircular.dot -o ./listaCircular.png");
    if(returnCodeC == 0){cout<<"Se genero Dot de lista circular !!"<<endl;}
    else{cout<<"Ocurrio un error al generar Dot de lista Circular -codigo: " << returnCodeC <<endl;}
}
//-------------------------------------------------------------------