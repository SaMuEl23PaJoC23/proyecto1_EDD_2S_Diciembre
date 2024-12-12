#include "nodo.h"

class Matriz{
    private:
        Nodo *raiz;

        Nodo* buscarColumna(string i_dep);
        Nodo* buscarFila(string j_empresa);
        void insertarEnFila(Nodo *nuevo, Nodo *encabezadoColumna);
        void insertarEnColumna(Nodo *nuevo, Nodo *encabezadoFila);
        Nodo* insertarEncabezadoFila(string j_empresa);
        Nodo* insertarEncabezadoColumna(string i_dep);

    public:
        Matriz();
        ~Matriz();

        void insert(string i_dep, string j_empresa, string nomUsu, string password, string nomCompleto);
        bool existeNodo(Nodo *nuevo);
        void print();
        
        void graphMatriz();
};