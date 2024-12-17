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
        void graphAVL(NodoAVL* raizAVL, ofstream &f, bool graf_raiz);
        void printAVL(NodoAVL* raizAVL);
        void printAVLNoRentados(NodoAVL* raizAVL);
        bool rentarActivo(NodoAVL* raizAVL, string ID_activo, int diasParaRentar, bool OPvalida);
        void activoEditar(NodoAVL* raizAVL, string ID_activo, string NdescActivo);
        bool activoExistente(NodoAVL* raizAVL, string ID_activo, string Operacion, bool existente);
        NodoAVL* delNodoAVL(NodoAVL* raizAVL, string ID_activo);

    public:
        AVL();
        ~AVL();

        void insertarAVL(string ID_activo, string nomActivo, 
        string descActivo, int diasParaRentar, bool disponible);

        void graphAVL(string nomUsu);
        void PrintAVL();
        void PrintAVLNoRentados();
        bool rentarActivo(string ID_activo, int diasParaRentar);
        void activoEditar(string ID_activo, string NdescActivo);
        bool activoExistente(string ID_activo, string Operacion);
        void delNodoAVL(string ID_activo);
};