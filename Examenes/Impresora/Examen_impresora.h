#ifndef IMPRESORA
#define IMPRES0RA
#include <iostream>
#include "coladin.h"

class Gestor
{
public:

    Gestor();
    void anadir_trabajo (int usu, bool urgen, char cod_trabajo[]);
    void eliminar_trabajo();
    void cancelar_trabajos(int usu);

private:

    struct usuarios
    {
        int id_usu;
        Cola<char*> urgente;
        Cola<char*> no_urgente;
    };

    Cola<usuarios> c;
};

#endif
