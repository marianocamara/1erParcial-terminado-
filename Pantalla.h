#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED


typedef struct{
    int id;
    char nombrePantalla[51];
    char direccion[51];
    int tipoPantalla;
    float precio;
    int flagOcupado;
}sPantalla;


#endif // PANTALLA_H_INCLUDED

#define PANTALLA_LIBRE 0
#define PANTALLA_OCUPADO 1

#define PANTALLA_LCD 0
#define PANTALLA_LED 1

int pant_init (sPantalla* listaPantallas, int lenLista);
int pant_buscarPosicionLibre (sPantalla* listaPantallas,int lenLista);
int pant_alta(sPantalla* listaPantallas, int lenLista);
int pant_modificarPantalla (sPantalla* listaPantallas, int lenLista);
int pant_bajaPantalla(sPantalla* listaPantallas, int lenListaPantalla, int *idBaja);
int pant_buscarIndicePorId(sPantalla* listaPantallas, int lenLista, int id);
void pant_cargarDatosPrueba (sPantalla* listaPantallas, int lenListaPantallas);


