#include <stdio.h>
#include <stdlib.h>
#include "Pantalla.h"
#include "Contrataciones.h"
#include <string.h>
#include "validar.h"


/** \brief  Se marcan todas las posiciones del array como libres
 *          colocando en cada elmento el flag de flagEstado en 0
 * \param puntero array de entidad
 * \param lenArray int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (0) si Ok
 */
int pant_init (sPantalla* listaPantallas, int lenLista)
{
    int retorno = -1;
    int i;
    if(listaPantallas != NULL && lenLista > 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            listaPantallas[i].flagOcupado = PANTALLA_LIBRE;
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

int pant_generarProximoId (void)
{
    ultimoValorIdAutoincrementable ++ ;
    return ultimoValorIdAutoincrementable;
}

/** \brief busca el proximo index libre donde cargar la entidad
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \return int el primer index libre encontrado // -1 Error en parametros pasados o no hay posicion libre
 *
 */

int pant_buscarPosicionLibre (sPantalla* listaPantallas,int lenLista)
{
    int retorno = -1;
    int i;
    if(listaPantallas != NULL && lenLista > 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            if(listaPantallas[i].flagOcupado == PANTALLA_LIBRE)
            {
                retorno =  i;
                break;
            }
        }
    }
    return retorno;
}


void pant_cargarDatosPrueba (sPantalla* listaPantallas, int lenListaPantallas)
{
                            int indexVacio = pant_buscarPosicionLibre (listaPantallas,lenListaPantallas);
                            listaPantallas[indexVacio].id = pant_generarProximoId();
                            listaPantallas[indexVacio].flagOcupado = PANTALLA_OCUPADO;
                            strncpy(listaPantallas[indexVacio].nombrePantalla,"Sony Bravia",50);
                            strncpy(listaPantallas[indexVacio].direccion,"Callao 345",50);
                            listaPantallas[indexVacio].precio = 210.5;
                            listaPantallas[indexVacio].tipoPantalla = PANTALLA_LCD;

                            int indexVacio2 = pant_buscarPosicionLibre (listaPantallas,lenListaPantallas);
                            listaPantallas[indexVacio2].id = pant_generarProximoId();
                            listaPantallas[indexVacio2].flagOcupado = PANTALLA_OCUPADO;
                            strncpy(listaPantallas[indexVacio2].nombrePantalla,"Samsung OLED",50);
                            strncpy(listaPantallas[indexVacio2].direccion,"Libertador 2207",50);
                            listaPantallas[indexVacio2].precio = 325;
                            listaPantallas[indexVacio2].tipoPantalla = PANTALLA_LED;

                            int indexVacio3 = pant_buscarPosicionLibre (listaPantallas,lenListaPantallas);
                            listaPantallas[indexVacio3].id = pant_generarProximoId();
                            listaPantallas[indexVacio3].flagOcupado = PANTALLA_OCUPADO;
                            strncpy(listaPantallas[indexVacio3].nombrePantalla,"LG Gram",50);
                            strncpy(listaPantallas[indexVacio3].direccion,"Mitre 3440",50);
                            listaPantallas[indexVacio3].precio = 115;
                            listaPantallas[indexVacio3].tipoPantalla = PANTALLA_LCD;
}


/** \brief Carga todos los campos de la entidad en un index vacio y genera su id, validando datos ingresados en cada caso
 *
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \return 0 si pudo cargar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

int pant_alta(sPantalla* listaPantallas, int lenLista)
{
    int retorno = -1;
    int indexVacio;
    int idNuevo;

    if(listaPantallas != NULL && lenLista > 0)
    {
        indexVacio = pant_buscarPosicionLibre (listaPantallas,lenLista);
        if (indexVacio >= 0)
        {
            char bufferAuxNombre[50];
            char bufferAuxDireccion[50];
            char bufferAuxPrecio[50];
            char bufferAuxTipo[50];

            if (val_getNombre(bufferAuxNombre,"Ingrese nombre de la pantalla:\n","Ingrese un nombre valido:\n",2,50)!= -1)
            {
                if (val_getFloat(bufferAuxPrecio,"Ingrese precio de la pantalla:\n","Ingrese un numero valido:\n",2,50) != -1 )
                {
                    if (val_getDireccion(bufferAuxDireccion,"Ingrese la direccion:\n","Ingrese una direccion valida:\n",2,50) != -1 )
                    {
                        if (val_getTipoPantalla(bufferAuxTipo,"Ingrese el tipo de pantalla 0 - Pantalla LCD // 1 - Pantalla LED:\n","\nIngrese una opcion valida (0 - 1)\n",2,50) != -1 )
                        {
                            idNuevo = pant_generarProximoId();
                            listaPantallas[indexVacio].id = idNuevo;
                            listaPantallas[indexVacio].flagOcupado = PANTALLA_OCUPADO;

                            strncpy(listaPantallas[indexVacio].nombrePantalla,bufferAuxNombre,50);
                            strncpy(listaPantallas[indexVacio].direccion,bufferAuxDireccion,50);
                            listaPantallas[indexVacio].precio = atof(bufferAuxPrecio);
                            listaPantallas[indexVacio].tipoPantalla = atoi(bufferAuxTipo);
                            printf("Se han cargado los datos exitosamente.");

                            retorno = 0;
                        }
                    }
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

/** \brief busca el index de id pasado como parametro
 *
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \param int id para buscar su index
 * \return int index de la entidad donde se encuentra ese id // -1 Error de parametros pasados o no se encontro el index
 *
 */

int pant_buscarIndicePorId(sPantalla* listaPantallas, int lenLista, int id)
{
    int i;
    int retorno = -1;
    if(listaPantallas != NULL && lenLista > 0 && id >= 0)
    {
        for(i=0; i<lenLista ; i++)
        {
            if(listaPantallas[i].flagOcupado == PANTALLA_OCUPADO)
            {
                if(id == listaPantallas[i].id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

/** \brief busca el index del id pasado como parametro y modifica los campos en ese index
 *
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \param int id para buscar su index
 * \return 0 si pudo modificar los datos correctanmente, -1 error de carga o de parametros pasados
 *
 */

int pant_modificarPantalla (sPantalla* listaPantallas, int lenLista)
{
    int retorno = -1;
    char bufferIdModificar[50];

    if(listaPantallas != NULL && lenLista > 0)
    {
        if (val_getUnsignedInt(bufferIdModificar,"\nIngrese ID de la pantalla a modificar:\n","\nIngese un ID valido\n",2,50) != -1)
        {

        int index = pant_buscarIndicePorId(listaPantallas,lenLista,atoi(bufferIdModificar));
        if(index >= 0)
        {

            char bufferAuxNombre[50];
            char bufferAuxDireccion[50];
            char bufferAuxPrecio[50];
            char bufferAuxTipo[50];

            if (val_getNombre(bufferAuxNombre,"\nIngrese nuevo nombre de la pantalla:\n","\nIngrese un nombre valido:\n",2,50)!= -1)
            {
                if (val_getFloat(bufferAuxPrecio,"Ingrese nuevo precio de la pantalla:\n","\nIngrese un numero valido\n",2,50) != -1 )
                {
                    if (val_getDireccion(bufferAuxDireccion,"Ingrese la nueva direccion:\n","\nIngrese una direccion valida\n",2,50) != -1 )
                    {
                        if (val_getTipoPantalla(bufferAuxTipo,"Ingrese el nuevo tipo de pantalla 0 - Pantalla LCD // 1 - Pantalla LED:\n","\nIngrese una opcion valida (0 - 1)\n",2,50) != -1 )
                        {
                        strncpy(listaPantallas[index].nombrePantalla,bufferAuxNombre,50);
                        strncpy(listaPantallas[index].direccion,bufferAuxDireccion,50);
                        listaPantallas[index].precio = atof(bufferAuxPrecio);
                        printf("Se han modificado los datos exitosamente.");

                        retorno = 0;
                        }
                    }
                }
            }
        }
        else
        {
            printf("\nEl ID ingresado no pertenece a ninguna pantalla.\n");
        }
    }
    }
    return retorno;
}

/** \brief realiza baja de una entidad colocando el flag estado en libre (0)
 *
 * \param puntero listaPantallas de entidad
 * \param lenLista int Longitud del listaPantallas
 * \param int id para buscar su index
 * \return 0 si dio de baja correctamente -1 error parametros o index no encontrado
 *
 */

int pant_bajaPantalla(sPantalla* listaPantallas, int lenListaPantalla, int *idBaja)
{
    int retorno = -1;
    char bufferIdBaja[50];

    if(listaPantallas != NULL && lenListaPantalla > 0)
    {
        val_getUnsignedInt(bufferIdBaja,"\nIngrese ID de la pantalla a dar de baja:\n","\nIngese un ID valido:\n",2,50);
        int index = pant_buscarIndicePorId(listaPantallas,lenListaPantalla,atoi(bufferIdBaja));

        if(index >= 0)
        {
            listaPantallas[index].flagOcupado = PANTALLA_LIBRE;
            printf("\nSe ha dado de baja la pantalla seleccionada.\n");
            *idBaja = atoi (bufferIdBaja);
            retorno = 0;
        }
        else
        {
            printf("\nNo se ha encontrado el ID ingresado.\n");
        }
    }
    return retorno;
}





