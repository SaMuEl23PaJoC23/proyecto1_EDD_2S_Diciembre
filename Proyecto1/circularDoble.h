#include "nodoCircular.h"

class CircularDoble{
    private:
        int largo;
        NodoCircular* primero_NodoC;

    public:
        CircularDoble();
        ~CircularDoble();

    
        void append(string ID_transaccion, string ID_activoRentado, string UsuRenta,
        string depUsuRenta, string empUsuRenta, string fechaRenta, int diasRenta);

        void graphCircular();
};