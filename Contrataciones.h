
#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED
#include "Pantalla.h"

typedef struct{
    char cuitCliente[51];
    char nombre[50];
    char nombreVideo[50];
    int idContrataciones;
    int dias;
    int idPantalla;
    int flagOcupado;
}sContrataciones;

#endif // CONTRATACIONES_H_INCLUDED


#define CONTRATACIONES_LIBRE 0
#define CONTRATACIONES_OCUPADO 1


int contra_init (sContrataciones* listaContrataciones, int lenlistaContrataciones);
int contra_generarProximoId ();
int contra_buscarPosicionLibre (sContrataciones* listaContrataciones,int lenlistaContrataciones);
int contra_alta(sContrataciones* listaContrataciones, sPantalla* listaPantallas, int lenlistaContrataciones, int lenListaPantallas);
int contra_modificarDiasContratados (sContrataciones* listaContrataciones, sPantalla* listaPantallas, int lenListaContrataciones, int lenListaPantallas);
int contra_bajaContratacionPorCuit (sContrataciones* listaContrataciones, sPantalla* listaPantallas, int lenListaContrataciones, int lenListaPantallas);
void contra_cargarDatosPrueba (sContrataciones* listaContrataciones, int lenListaContrataciones);
int contra_bajaContratacion(sContrataciones* listaContrataciones, int lenListaContrataciones, int idBaja);
