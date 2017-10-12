#include <stdio.h>
#include <stdlib.h>
#include "Contrataciones.h"
#include <string.h>
#include "validar.h"
#include "Pantalla.h"
#include "informes.h"

/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en 0
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 */
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

/** \brief busca el proximo index libre donde cargar la entidad
 * \param puntero array listaContrataciones de estructura contrataciones
 * \param lenListaContrataciones int Longitud del array
 * \return int el primer index libre encontrado // -1 Error en parametros pasados o no hay posicion libre
 *
 */

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

/** \brief carga datos de prueba en la estructura contrataciones
 *
 * \param array de estructura contrataciones
 * \param longitud array pantalla
 * \return
 *
 */
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
    strncpy(listaContrataciones[indexVacio2].cuitCliente,"10-9375628-1",50);
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


    int indexVacio4 = contra_buscarPosicionLibre(listaContrataciones,lenListaContrataciones);
    listaContrataciones[indexVacio4].flagOcupado = CONTRATACIONES_OCUPADO;
    listaContrataciones[indexVacio4].idContrataciones = contra_generarProximoId();
    strncpy(listaContrataciones[indexVacio4].nombre,"Tiziana",50);
    strncpy(listaContrataciones[indexVacio4].cuitCliente,"10-9375628-1",50);
    listaContrataciones[indexVacio4].dias = 2;
    strncpy(listaContrataciones[indexVacio4].nombreVideo,"Mensaje.mov",50);
    listaContrataciones[indexVacio4].idPantalla = 0;
}

/** \brief Se pide un ID de pantalla a contratar y carga todos los campos de la entidad contrataciones en un index vacio y genera su id, validando datos ingresados en cada caso
 *
 * \param puntero array listaContrataciones de entidad
 * \param puntero array listaPantallas de entidad
 * \param lenListaContrataciones int Longitud del listaContrataciones
 * \param lenListaPantallas int Longitud del listaPantallas
 * \return 0 si pudo cargar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

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

/** \brief Pide CUIT, lista pantallas contratadas y permite modificar cantidad de dias contratados
 *
 * \param puntero array listaContrataciones de entidad
 * \param puntero array listaPantallas de entidad
 * \param lenListaContrataciones int Longitud del listaContrataciones
 * \param lenListaPantallas int Longitud del listaPantallas
 * \return 0 si pudo cargar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

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

                        if (val_getUnsignedInt(bufferDias,"Ingrese la nueva cantidad de dias que desea contratar la pantalla:\n","\nIngrese un numero valido:\n",2,50)!= -1)
                        {
                            int i;
                            for(i=0;i<lenListaContrataciones;i++)
                            {
                            if (strcmp(bufferCuit, listaContrataciones[i].cuitCliente)==0 && listaContrataciones[i].idPantalla == atoi(bufferIdModificar))
                            {
                            listaContrataciones[i].dias = atoi(bufferDias);
                            printf("Se ha modificado la cantidad de dias de la contratacion.");
                            retorno = 0;
                            }
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

/** \brief realiza baja de contratacion colocando el flag estado en libre (0)
 *
 * \param puntero array listaContrataciones de entidad
 * \param lenListaContrataciones int Longitud del listaContrataciones
 * \param int id de la pantalla cuyas contrataciones desea dar de baja
 * \return 0 si pudo cargar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */
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
/** \brief Pide el CUIT, lista sus pantallas contratadas, pide ID pantalla y realiza baja de contratacion colocando el flag estado en libre (0)
 *
 * \param puntero array listaContrataciones de entidad
 * \param puntero array listaPantallas de entidad
 * \param lenListaContrataciones int Longitud del listaContrataciones
 * \param lenListaPantallas int Longitud del listaPantallas
 * \return 0 si pudo cargar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */
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
                        int i;
                        for(i=0;i<lenListaContrataciones;i++)
                        {
                            if (strcmp(bufferCuit, listaContrataciones[i].cuitCliente)==0 && listaContrataciones[i].idPantalla == atoi(bufferIdModificar))
                            {
                                listaContrataciones[i].flagOcupado = CONTRATACIONES_LIBRE;
                                printf("\nSe ha cancelado la contratacion de la pantalla seleccionada.");
                                retorno = 0;
                            }
                        }
                    }
                }
            }
        }
        return retorno;

    }
