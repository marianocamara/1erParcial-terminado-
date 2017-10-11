#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "Contrataciones.h"
#include "validar.h"
#include "informes.h"

#define LEN_PANTALLAS 100
#define LEN_CONTRATACIONES 1000


int main()
{
    sPantalla listaPantallas[LEN_PANTALLAS];
    sContrataciones listaContrataciones[LEN_CONTRATACIONES];

    pant_init (listaPantallas,LEN_PANTALLAS);
    contra_init (listaContrataciones,LEN_CONTRATACIONES);

    char bufferOpcion[10];
    int idBaja;

    pant_cargarDatosPrueba(listaPantallas,LEN_PANTALLAS);
    contra_cargarDatosPrueba(listaContrataciones,LEN_CONTRATACIONES);

    do
    {
        val_getUnsignedInt(bufferOpcion,"\n\n1- Alta de pantalla\n2- Modificar datos de pantalla\n3- Baja de pantalla\n4- Contratar pubicidad\n5- Modificar dias contratados\n6- Cancelar contratacion\n7- Consulta factuacion\n8- Listar contrataciones\n9- Listar pantallas\n10- Informes\n11- Salir\n","\nIngrese una opcion valida.\n",3,10);

        switch(atoi(bufferOpcion))
            {
            case 1:
                pant_alta(listaPantallas,LEN_PANTALLAS);
                break;
            case 2:
                pant_modificarPantalla(listaPantallas,LEN_PANTALLAS);
                break;
            case 3:
                pant_bajaPantalla(listaPantallas,LEN_PANTALLAS, &idBaja);
                contra_bajaContratacion(listaContrataciones,LEN_CONTRATACIONES,idBaja);
                break;
            case 4:
                inf_listarPantallas(listaPantallas,LEN_PANTALLAS);
                contra_alta(listaContrataciones,listaPantallas,LEN_CONTRATACIONES,LEN_PANTALLAS);
                break;
            case 5:
                contra_modificarDiasContratados(listaContrataciones,listaPantallas,LEN_CONTRATACIONES,LEN_PANTALLAS);
                break;
            case 6:
                contra_bajaContratacionPorCuit(listaContrataciones,listaPantallas,LEN_CONTRATACIONES,LEN_PANTALLAS);
                break;
            case 7:
                inf_listarImportePantallasContratadasPorCuit(listaPantallas,listaContrataciones,LEN_PANTALLAS,LEN_CONTRATACIONES);
                break;
            case 8:
                inf_listarContrataciones(listaPantallas,listaContrataciones,LEN_PANTALLAS,LEN_CONTRATACIONES);
                break;
            case 9:
                inf_listarPantallas(listaPantallas,LEN_PANTALLAS);
                break;
            case 10:
                inf_listarClientesConImportes(listaPantallas,listaContrataciones,LEN_PANTALLAS,LEN_CONTRATACIONES);
                inf_listarClientesConMayorImporte(listaPantallas,listaContrataciones,LEN_PANTALLAS,LEN_CONTRATACIONES);
                break;
            case 11:
                printf("\nHasta luego\n");
                break;
            default:
                printf("\nIngrese un numero que se encuentre dentro de las opciones.\n");
                break;
            }
    }while( atoi(bufferOpcion) != 11);

    return 0;
}
