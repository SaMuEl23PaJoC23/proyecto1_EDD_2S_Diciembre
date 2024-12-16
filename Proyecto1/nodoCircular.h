#include "lib_globales.h"

class NodoCircular{
    private:
        string ID_transaccion, ID_activoRentado;
        string UsuRenta, depUsuRenta, empUsuRenta, fechaRenta;
        int diasRenta;
        
        NodoCircular* drchaCircular;
        NodoCircular* izqCircular;

    public:
        NodoCircular(string ID_transaccion, string ID_activoRentado, string UsuRenta,
        string depUsuRenta, string empUsuRenta, string fechaRenta, int diasRenta);

        void setIDtransaccion(string ID_transaccion);
        void setIDactivoRentado(string ID_activoRentado);
        void setUsuRenta(string usuRenta);
        void setDepUsuRenta(string depUsuRenta);
        void setEmpUsuRenta(string empUsuRenta);
        void setFechaRenta(string fechaRenta);
        void setDiasRenta(int diasRenta);
        void setDrchaCircular(NodoCircular* drchaCircular);
        void setIzqCircular(NodoCircular* izqCircular);

        string getIDtransaccion();
        string getIDactivoRentado();
        string getUsuRenta();
        string getDepUsuRenta();
        string getEmpusuRenta();
        string getFechaRenta();
        int getDiasRenta();
        NodoCircular* getDrchaCircular();
        NodoCircular* getIzqCircular();
};
/*
Un ID único para la transacción (un código alfanumérico de 15 caracteres)
- El ID del activo que se rento
- El usuario que realizó la renta
- El departamento y empresa pertenecientes al usuario que realizó la renta
- La fecha en que se realizó la renta
- Por cuánto tiempo se rentó
*/