#include "nodoAVL.h"

class AVL{
    private:
        NodoAVL* raizAVL;

        //estos metodos permiten manejar los nodos AVL,
        //son recursivos, y ademas necesitan de un nodo raiz
        NodoAVL* insertarAVL(NodoAVL* raizAVL, string ID_activo, 
        string nomActivo, string descActivo, int diasParaRentar, bool disponible);

        NodoAVL* rotacionIzq(NodoAVL* raizAVL);
        NodoAVL* rotacionDrcha(NodoAVL* raizAVL);
        NodoAVL* getMayorDeMenores(NodoAVL* raizAVL);

        int alturaMaxima(int izq, int drcha);
        int obtenerAltura(NodoAVL* raizAVL);//Devuelve 0 si el nodo no existe, sino devuelve su correspondiente altura
        int getBalance(NodoAVL* raizAVL);

        void postOrden(NodoAVL* raizAVL);//Se utiliza para que el destructor recorra todos los nodos
        void graphAVL(NodoAVL* raizAVL, ofstream &f);

    public:
        AVL();
        ~AVL();

        void insertarAVL(string ID_activo, string nomActivo, 
        string descActivo, int diasParaRentar, bool disponible);

        void graphAVL();
        void printAVL(NodoAVL* raizAVL);


};