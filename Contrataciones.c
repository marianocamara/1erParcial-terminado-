#include <stdio.h>
#include <stdlib.h>
#include "Contrataciones.h"
#include <string.h>
#include "validar.h"
#include "Pantalla.h"
#include "informes.h"


int contra_init (sContrataciones* listaContrataciones, int lenlistaContrataciones)
{
    int retorno = -1;
    int i;
    if(listaContrataciones != NULL && lenlistaContrataciones > 0)
    {
        for(i=0; i<lenlistaContrataciones ; i++)
        {
            listaContrataciones[i].flagOcupado = CONTRATACIONES_LIBRE;
        }
    }
    return retorno;
}

/** \brief Genera un id(+1) a partir del ultimo generado
 * \param
 * \param
 * \return int el id generado
 */
static int ultimoValorIdAutoincrementable = -1;

int contra_generarProximoId (void)
{
    ultimoValorIdAutoincrementable ++ ;
    return ultimoValorIdAutoincrementable;
}

int contra_buscarPosicionLibre (sContrataciones* listaContrataciones,int lenlistaContrataciones)
{
    int retorno = -1;
    int i;
    if(listaContrataciones != NULL && lenlistaContrataciones > 0)
    {
        for(i=0; i<lenlistaContrataciones ; i++)
        {
            if(listaContrataciones[i].flagOcupado == CONTRATACIONES_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}


void contra_cargarDatosPrueba (sContrataciones* listaContrataciones, int lenListaContrataciones)
{
    int indexVacio = contra_buscarPosicionLibre(listaContrataciones,lenListaContrataciones);
    listaContrataciones[indexVacio].flagOcupado = CONTRATACIONES_OCUPADO;
    listaContrataciones[indexVacio].idContrataciones = contra_generarProximoId();
    strncpy(listaContrataciones[indexVacio].nombre,"Mariano",50);
    strncpy(listaContrataciones[indexVacio].cuitCliente,"20-2342342-2",50);
    listaContrataciones[indexVacio].dias = 12;
    strncpy(listaContrataciones[indexVacio].nombreVideo,"TrailerBladeRunner.mp4",50);
    listaContrataciones[indexVacio].idPantalla = 0;

    int indexVacio1 = contra_buscarPosicionLibre(listaContrataciones,lenListaContrataciones);
    listaContrataciones[indexVacio1].flagOcupado = CONTRATACIONES_OCUPADO;
    listaContrataciones[indexVacio1].idContrataciones = contra_generarProximoId();
    strncpy(listaContrataciones[indexVacio1].nombre,"Pablo",50);
    strncpy(listaContrataciones[indexVacio1].cuitCliente,"20-2432038-7",50);
    listaContrataciones[indexVacio1].dias = 8;
    strncpy(listaContrataciones[indexVacio1].nombreVideo,"TrailerMadMax2.avi",50);
    listaContrataciones[indexVacio1].idPantalla = 1;

    int indexVacio2 = contra_buscarPosicionLibre(listaContrataciones,lenListaContrataciones);
    listaContrataciones[indexVacio2].flagOcupado = CONTRATACIONES_OCUPADO;
    listaContrataciones[indexVacio2].idContrataciones = contra_generarProximoId();
    strncpy(listaContrataciones[indexVacio2].nombre,"Tiziana",50);
    strncpy(listaContrataciones[indexVacio2].cuitCliente,"20-234234-5",50);
    listaContrataciones[indexVacio2].dias = 28;
    strncpy(listaContrataciones[indexVacio2].nombreVideo,"Publicidad03Quilmes.mkv",50);
    listaContrataciones[indexVacio2].idPantalla = 2;

    int indexVacio3 = contra_buscarPosicionLibre(listaContrataciones,lenListaContrataciones);
    listaContrataciones[indexVacio3].flagOcupado = CONTRATACIONES_OCUPADO;
    listaContrataciones[indexVacio3].idContrataciones = contra_generarProximoId();
    strncpy(listaContrataciones[indexVacio3].nombre,"Mariano",50);
    strncpy(listaContrataciones[indexVacio3].cuitCliente,"20-2342342-2",50);
    listaContrataciones[indexVacio3].dias = 14;
    strncpy(listaContrataciones[indexVacio3].nombreVideo,"PublicidadAuto.mp4",50);
    listaContrataciones[indexVacio3].idPantalla = 1;
}


int contra_buscarIndicePorIdPantalla(sContrataciones* listaContrataciones,int lenlistaContrataciones,int id)
{
    int i;
    int retorno = -1;
    if(listaContrataciones != NULL && lenlistaContrataciones > 0 && id >= 0)
    {
        for(i=0; i<lenlistaContrataciones ; i++)
        {
            if(listaContrataciones[i].flagOcupado == CONTRATACIONES_OCUPADO)
            {
                if(id == listaContrataciones[i].idPantalla)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}


int contra_alta(sContrataciones* listaContrataciones, sPantalla* listaPantallas, int lenlistaContrataciones, int lenListaPantallas)
{
    int retorno = -1;
    int idNuevo;

    if(listaPantallas != NULL && lenListaPantallas > 0 && listaContrataciones != NULL && lenlistaContrataciones > 0 )
    {
        int indexVacio = contra_buscarPosicionLibre (listaContrataciones,lenlistaContrataciones);
        if (indexVacio >= 0)
        {
            char bufferAuxNombre[50];
            char bufferAuxCuit[50];
            char bufferDias[50];
            char bufferAuxNombreVideo[50];
            char bufferIdPantalla[50];

            if(val_getUnsignedInt(bufferIdPantalla,"\nIngrese ID de la pantalla que desea contratar \n","\nIngrese un numero valido\n",2,50)==0)
            {

                if (pant_buscarIndicePorId(listaPantallas,lenListaPantallas,atoi(bufferIdPantalla)) != -1)
                {

                    if (val_getNombre(bufferAuxNombre,"Ingrese su nombre:\n","\nIngrese un nombre valido:\n",2,50)!= -1)
                    {
                        if (val_getCuit(bufferAuxCuit,"Ingrese su CUIT (formato xx-documento-x):\n","\nIngrese un valor de CUIT valido:\n",2,50)!= -1)
                        {
                            if (val_getUnsignedInt(bufferDias,"Ingrese la cantidad de dias que desea contratar la pantalla:\n","\nIngrese un numero valido:\n",2,50)!= -1)
                            {
                                if (val_getNombreVideo(bufferAuxNombreVideo,"Ingrese el nombre del archivo de video (ej Video1.avi):\n","\nIngrese un nombre valido:\n",2,50)!= -1)
                                {
                                    idNuevo = contra_generarProximoId();
                                    listaContrataciones[indexVacio].flagOcupado = CONTRATACIONES_OCUPADO;
                                    listaContrataciones[indexVacio].idContrataciones = idNuevo;
                                    strncpy(listaContrataciones[indexVacio].nombre,bufferAuxNombre,50);
                                    strncpy(listaContrataciones[indexVacio].cuitCliente,bufferAuxCuit,50);
                                    listaContrataciones[indexVacio].dias = atoi(bufferDias);
                                    strncpy(listaContrataciones[indexVacio].nombreVideo,bufferAuxNombreVideo,50);
                                    listaContrataciones[indexVacio].idPantalla = atoi(bufferIdPantalla);
                                    printf("Se han cargado los datos exitosamente.");

                                    retorno = 0;
                                }
                            }
                        }
                    }


                }
                else
                {
                    printf("\nEl ID ingresado no corresponde a ninguna pantalla.");
                }
            }
        }
        else
        {
            printf("\nNo hay posiciones libres.");
        }
    }
    return retorno;
}

int contra_modificarDiasContratados (sContrataciones* listaContrataciones, sPantalla* listaPantallas, int lenListaContrataciones, int lenListaPantallas)
{
    int retorno = -1;

    if(listaPantallas != NULL && lenListaPantallas > 0 && listaContrataciones != NULL && lenListaContrataciones > 0 )
    {

        char bufferCuit[50];
        char bufferDias[50];
        char bufferIdModificar[50];


        if(val_getCuit(bufferCuit,"\nIngrese su CUIT (formato xx-documento-x): \n","\nIngrese un numero valido\n",2,50)==0)
        {
            if (inf_listarPantallasContratadas(listaPantallas,listaContrataciones,lenListaPantallas,lenListaContrataciones,bufferCuit) != -1)
            {
                if (val_getUnsignedInt(bufferIdModificar,"\nIngrese ID de la pantalla a modificar:\n","\nIngese un ID valido\n",2,50) != -1)
                {
                    int index = contra_buscarIndicePorIdPantalla(listaContrataciones,lenListaContrataciones,atoi(bufferIdModificar));
                    if(index >= 0)
                    {
                        if (val_getUnsignedInt(bufferDias,"Ingrese la nueva cantidad de dias que desea contratar la pantalla:\n","\nIngrese un numero valido:\n",2,50)!= -1)
                        {
                            listaContrataciones[index].dias = atoi(bufferDias);
                            printf("Se ha modificado la cantidad de dias de la contratacion.");
                            retorno = 0;
                        }
                    }
                    else
                    {
                        printf("\nEl ID ingresado no corresponde a ninguna pantalla.");
                    }
                }
            }
        }
    }
    return retorno;

}

int contra_bajaContratacion(sContrataciones* listaContrataciones, int lenListaContrataciones, int idBaja)
{
    int retorno = -1;
    int i;

    if(listaContrataciones != NULL && lenListaContrataciones > 0)
    {
        for (i=0; i<lenListaContrataciones; i++)
        {
            if(idBaja == listaContrataciones[i].idPantalla)
            {
                listaContrataciones[i].flagOcupado = CONTRATACIONES_LIBRE;
            }
        }
        printf("Se han dado de baja las contrataciones de la pantalla.\n");
        retorno = 0;

    }
    return retorno;

}

int contra_bajaContratacionPorCuit (sContrataciones* listaContrataciones, sPantalla* listaPantallas, int lenListaContrataciones, int lenListaPantallas)
    {
        int retorno = -1;

        if(listaPantallas != NULL && lenListaPantallas > 0 && listaContrataciones != NULL && lenListaContrataciones > 0 )
        {

            char bufferCuit[50];
            char bufferIdModificar[50];

            if(val_getCuit(bufferCuit,"\nIngrese su CUIT (formato xx-documento-x): \n","\nIngrese un numero valido\n",2,50)==0)
            {
                if (inf_listarPantallasContratadas(listaPantallas,listaContrataciones,lenListaPantallas,lenListaContrataciones,bufferCuit)!= -1)
                {
                    if (val_getUnsignedInt(bufferIdModificar,"\nIngrese ID de la pantalla cuya contratacion desea cancelar:\n","\nIngese un ID valido\n",2,50) != -1)
                    {
                        int index = contra_buscarIndicePorIdPantalla(listaContrataciones,lenListaContrataciones,atoi(bufferIdModificar));
                        if(index >= 0)
                        {

                            listaContrataciones[index].flagOcupado = CONTRATACIONES_LIBRE;
                            printf("\nSe ha cancelado la contratacion de la pantalla seleccionada.");
                            retorno = 0;
                        }

                        else
                        {
                            printf("\nEl ID ingresado no corresponde a ninguna pantalla.");
                        }
                    }
                }
            }
        }
        return retorno;

    }
