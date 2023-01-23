#include "Examen_impresora.h"
#include "coladin.h"

Gestor::Gestor(){}

void Gestor::anadir_trabajo(int usu, bool urgen, char cod_trabajo[])
{
    usuarios x;
    bool p=false;
    Cola<usuarios> aux;

    while(!c.vacia()&&!p)
    {
        x=c.frente();
        if(x.id_usu==usu) p=true;
        aux.push(c.frente());
        c.pop();
    }
    if(p)
    {
        if(urgen)
        {
            x.urgente.push(cod_trabajo);
        }
        else
        {
            x.no_urgente.push(cod_trabajo);
        }
        aux.push(x);
        c.pop();
        while(!c.vacia())
        {
            aux.push(c.frente());
            c.pop();
        }
        c=aux;
    }
    else
    {
        usuarios y;
        y.id_usu= usu;
        if(urgen)
        {
            y.urgente.push(cod_trabajo);
        }
        else
        {
            y.no_urgente.push(cod_trabajo);
        }
        aux.push(y);
        c=aux;
    }
}

void Gestor::eliminar_trabajo()
{
    usuarios x;
    x=c.frente();

    if(!x.urgente.vacia())
    {
        x.urgente.pop();
    }
    else
    {
        if(!x.no_urgente.vacia())
        {
            x.no_urgente.pop();
        }
    }
    
    if(x.urgente.vacia() && x.no_urgente.vacia())
    {
        c.pop();
    }
    else
    {
        c.push(x);
        c.pop();
    }

}

void Gestor::cancelar_trabajos(int usu)
{
    usuarios t;
    Cola<usuarios> aux;
    bool p=false;
    while(!c.vacia()&&!p)
    {
        t=c.frente();
        if(t.id_usu==usu) p=true;
        aux.push(t);
        c.pop();
    }
    if(p)
    {
        c.pop();
        while(!c.vacia())
        {
            aux.push(c.frente());
            c.pop();
        }
    }
    c=aux;
}
