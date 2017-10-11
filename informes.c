#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pantalla.h"
#include "Contrataciones.h"
#include "informes.h"
#include "validar.h"

/** \brief Imprime una lista de pantallas cargadas
 *
 * \param array de estructura pantalla
 * \param  longitud del array
 * \return -1 error en parametros | 0 OK
 *
 */


int inf_listarPantallas (sPantalla* listaPantallas,int lenListaPantallas)
{
    int retorno = -1;
    int index;
    int contadorPantallas = 0;
    printf("*************************************************************\n");
    printf("************************* PANTALLAS *************************\n");
    printf("*************************************************************\n");
    if(listaPantallas != NULL && lenListaPantallas > 0 )
    {
        for (index=0; index<lenListaPantallas; index++)
        {
            if(listaPantallas[index].flagOcupado == PANTALLA_OCUPADO)
            {
                contadorPantallas++;
                printf("\nID Pantalla: %d\nNombre: %s\nPrecio: %.2f\nDireccion: %s\nTipo (0-LCD // 1-LED): %d\n",listaPantallas[index].id,
                       listaPantallas[index].nombrePantalla,
                       listaPantallas[index].precio,
                       listaPantallas[index].direccion,
                       listaPantallas[index].tipoPantalla);
                       retorno = 0;
            }
        }
        printf("\n*************************************************************\n");
        printf("*************************************************************\n");
        if(contadorPantallas == 0)
        {
            printf("\nNo hay ninguna pantalla cargada en el sistema.\n");
        }

    }
return retorno;
}

/** \brief Imprime una lista de pantallas cargadas que tienen contrataciones a partir de un CUIT
 *
 * \param array de estructura pantalla
 * \param array de estructura contrataciones
 * \param  longitud del array de estructura pantalla
 * \param  longitud del array de estructura contrataciones
 * \param array de char CUIT del usuario
 * \return -1 error en parametros | 0 OK
 *
 */
int inf_listarPantallasContratadas (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones,char* cuit)
{
    int retorno = -1;
    int indexContrataciones;
    int indexPantalla;
    int contadorContrataciones;
    printf("*************************************************************\n");
    printf("****************** PANTALLAS CONTRATADAS ********************\n");
    printf("*************************************************************\n");
    if(listaPantallas != NULL && lenListaPantallas > 0 && listaContrataciones != NULL && lenListaContrataciones > 0 )
    {
        for (indexContrataciones=0; indexContrataciones<lenListaContrataciones; indexContrataciones++)
        {
            if ( strcmp(cuit, listaContrataciones[indexContrataciones].cuitCliente) == 0)
            {
                contadorContrataciones++;
                int idPantalla = listaContrataciones[indexContrataciones].idPantalla;

                for (indexPantalla=0; indexPantalla<lenListaPantallas; indexPantalla++)
                {
                    if(listaPantallas[indexPantalla].flagOcupado == PANTALLA_OCUPADO)
                    {
                        if (idPantalla == listaPantallas[indexPantalla].id)
                        {

                            printf("\nID Pantalla: %d\nNombre: %s\nPrecio: %.2f\nDireccion: %s\nTipo (0-LCD // 1-LED): %d\nDias contratados: %d\n",listaPantallas[indexPantalla].id,
                                   listaPantallas[indexPantalla].nombrePantalla,
                                   listaPantallas[indexPantalla].precio,
                                   listaPantallas[indexPantalla].direccion,
                                   listaPantallas[indexPantalla].tipoPantalla,
                                   listaContrataciones[indexContrataciones].dias);
                            retorno = 0;
                        }
                    }
                }
            }
        }
        printf("\n*************************************************************\n");
        printf("*************************************************************\n");
        if(contadorContrataciones == 0)
        {
            printf("\nEste cliente no tiene contrataciones.\n");
            retorno = -1;
        }
    }
    return retorno;
}


int inf_listarContrataciones (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones)
{
    int retorno = -1;
    int indexContrataciones;
    int indexPantalla;
    int contadorContrataciones;
    printf("*************************************************************\n");
    printf("****************** PANTALLAS CONTRATADAS ********************\n");
    printf("*************************************************************\n");
    if(listaPantallas != NULL && lenListaPantallas > 0 && listaContrataciones != NULL && lenListaContrataciones > 0 )
    {
        for (indexContrataciones=0; indexContrataciones<lenListaContrataciones; indexContrataciones++)
        {
            if (listaContrataciones[indexContrataciones].flagOcupado == CONTRATACIONES_OCUPADO)
            {
                contadorContrataciones++;
                int idPantalla = listaContrataciones[indexContrataciones].idPantalla;
                for (indexPantalla=0; indexPantalla<lenListaPantallas; indexPantalla++)
                {
                    if(listaPantallas[indexPantalla].flagOcupado == PANTALLA_OCUPADO)
                    {
                        if (idPantalla == listaPantallas[indexPantalla].id)
                        {
                            printf("\nNombre: %s\nNombre video: %s\nDias: %d\nCUIT: %s\n",listaPantallas[indexPantalla].nombrePantalla,
                                   listaContrataciones[indexContrataciones].nombreVideo,
                                   listaContrataciones[indexContrataciones].dias,
                                   listaContrataciones[indexContrataciones].cuitCliente);

                            retorno = 0;
                        }
                    }
                }
            }
        }
        printf("\n*************************************************************\n");
        printf("*************************************************************\n");
        if(contadorContrataciones == 0)
        {
            printf("\nEste cliente no tiene contrataciones.\n");
            retorno = -1;
        }
    }
    return retorno;
}

int inf_listarImportePantallasContratadasPorCuit (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones)
{
    int retorno = -1;
    int indexContrataciones;
    int indexPantalla;
    int contadorContrataciones = 0;
    float precioFinal;
    char bufferCuit[50];

    if(listaPantallas != NULL && lenListaPantallas > 0 && listaContrataciones != NULL && lenListaContrataciones > 0 )
    {
        if(val_getCuit(bufferCuit,"\nIngrese su CUIT (formato xx-documento-x): \n","\nIngrese un numero valido\n",2,50)==0)
        {
            printf("*************************************************************\n");
            printf("****** Su CUIT registra las siguientes contrataciones *******\n");
            printf("*************************************************************\n");
            for (indexContrataciones=0; indexContrataciones<lenListaContrataciones; indexContrataciones++)
            {
                if ( strcmp(bufferCuit, listaContrataciones[indexContrataciones].cuitCliente) == 0)
                {
                    contadorContrataciones++;
                    int idPantalla = listaContrataciones[indexContrataciones].idPantalla;

                    for (indexPantalla=0; indexPantalla<lenListaPantallas; indexPantalla++)
                    {
                        if(listaPantallas[indexPantalla].flagOcupado == PANTALLA_OCUPADO)
                        {
                            if (idPantalla == listaPantallas[indexPantalla].id)
                            {
                                precioFinal = listaPantallas[indexPantalla].precio * listaContrataciones[indexContrataciones].dias;
                                printf("\nID Contratacion: %d\nPrecio de la pantalla por dia: %.2f\nDias contratados: %d\nTOTAL: $%.2f\n",listaContrataciones[indexContrataciones].idContrataciones,
                                       listaPantallas[indexPantalla].precio,
                                       listaContrataciones[indexContrataciones].dias,
                                       precioFinal);
                                retorno = 0;
                            }
                        }
                    }
                }
            }
            printf("\n*************************************************************\n");
            printf("*************************************************************\n");
            if(contadorContrataciones == 0)
            {
                printf("\nEste cliente no tiene contrataciones.\n");
                retorno = -1;
            }
        }
    }
    return retorno;
}


int inf_listarClientesConImportes (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones)
{
    int retorno = -1;
    int indexContrataciones;
    int indexPantalla;
    int i;
    float precioFinal;
    char bufferCuit[50];

    if(listaPantallas != NULL && lenListaPantallas > 0 && listaContrataciones != NULL && lenListaContrataciones > 0 )
    {
        printf("*************************************************************\n");
        printf("**************** Clientes con contrataciones ****************\n");
        printf("*************************************************************\n");
        for (indexContrataciones=0; indexContrataciones<lenListaContrataciones; indexContrataciones++)
        {
            int contadorContrataciones = 0;
            int contadorCuit = 0;
            if (listaContrataciones[indexContrataciones].flagOcupado == CONTRATACIONES_OCUPADO)
            {
                strncpy(bufferCuit,listaContrataciones[indexContrataciones].cuitCliente,50);
                int j;
                for(j=indexContrataciones; j<lenListaContrataciones; j++)
                {
                    if ( strcmp(bufferCuit, listaContrataciones[j].cuitCliente) == 0)
                    {
                        contadorCuit++;
                    }
                }
                for(i=0; i<lenListaContrataciones; i++)
                {
                    if ( strcmp(bufferCuit, listaContrataciones[i].cuitCliente) == 0)
                    {
                        contadorContrataciones++;
                    }
                }
                if(contadorCuit == 1)
                {
                    printf("\nCUIT Cliente: %s\nNombre: %s\nCantidad contrataciones: %d", bufferCuit, listaContrataciones[indexContrataciones].nombre, contadorContrataciones);
                    for (i=0; i<lenListaContrataciones; i++)
                    {
                        if ( strcmp(bufferCuit, listaContrataciones[indexContrataciones].cuitCliente) == 0)
                        {
                            int idPantalla = listaContrataciones[i].idPantalla;

                            for (indexPantalla=0; indexPantalla<lenListaPantallas; indexPantalla++)
                            {
                                if(listaPantallas[indexPantalla].flagOcupado == PANTALLA_OCUPADO)
                                {
                                    if (idPantalla == listaPantallas[indexPantalla].id)
                                    {
                                        if(listaContrataciones[i].flagOcupado == CONTRATACIONES_OCUPADO && strcmp(bufferCuit, listaContrataciones[i].cuitCliente) == 0)
                                        {
                                            precioFinal = listaPantallas[indexPantalla].precio * listaContrataciones[i].dias;
                                            printf("\nTOTAL: $%.2f",precioFinal);
                                            retorno = 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    printf("\n\n*************************************************************\n");
                    printf("*************************************************************\n");
                }

            }
        }
    }
    return retorno;
}

int inf_listarClientesConMayorImporte (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones)
{
    int retorno = -1;
    int i;
    int contadorClientes = 1;
    if(listaPantallas != NULL && lenListaPantallas > 0 && listaContrataciones != NULL && lenListaContrataciones > 0 )
    {
        printf("*************************************************************\n");
        printf("************* Cliente con el importe mas alto ***************\n");
        printf("*************************************************************\n");

        //cantidad de clientes
        for (i=0; i<lenListaContrataciones; i++)
        {
            if (listaContrataciones[i].flagOcupado==CONTRATACIONES_OCUPADO)
            {
                if (strcmp(listaContrataciones[0].cuitCliente, listaContrataciones[i].cuitCliente)!= 0)
                {
                    contadorClientes++;
                }
            }
        }

        char arrayCuitClientes[contadorClientes][50];
        float arrayAcumuladorImporte[contadorClientes];
        char bufferCuit[50];

        //inicializo arrays
        for (i=0; i<contadorClientes; i++)
        {
            strncpy(arrayCuitClientes[i],"0",50);
        }

        for (i=0; i<contadorClientes; i++)
        {
            arrayAcumuladorImporte[i] = 0;
        }
        int i,k;
        int j=0;

        //copio cuits al array
        for (i=0; i<lenListaContrataciones; i++)
        {
            if (listaContrataciones[i].flagOcupado==CONTRATACIONES_OCUPADO)
            {
                int contadorRepetido = 0;
                strncpy(bufferCuit,listaContrataciones[i].cuitCliente,50);
                for (k=0; k<contadorClientes; k++)
                {
                    if(strcmp(bufferCuit, arrayCuitClientes[k]) == 0)
                    {
                        contadorRepetido++;
                    }
                }

                if(contadorRepetido != 0)
                {
                    j--;
                }
                else
                {
                    strncpy(arrayCuitClientes[j],bufferCuit,50);
                }
                j++;
            }
        }

        //copio importes a arrayImportes
        for (i=0; i<contadorClientes; i++)
        {
            if (listaContrataciones[i].flagOcupado==CONTRATACIONES_OCUPADO)
            {
                strncpy(bufferCuit,arrayCuitClientes[i],50);
                for (k=0; k<lenListaContrataciones; k++)
                {
                    if (strcmp(bufferCuit, listaContrataciones[k].cuitCliente) == 0)
                    {
                        int idPantalla = listaContrataciones[k].idPantalla;
                        float total = listaContrataciones[k].dias * listaPantallas[idPantalla].precio;
                        arrayAcumuladorImporte[i] = arrayAcumuladorImporte[i] + total;
                    }

                }
            }
        }
        float bufferMayor = 0;
        int indexMayor;
        for (i=0; i<contadorClientes; i++)
        {
            if (arrayAcumuladorImporte[i] > bufferMayor)
            {
                bufferMayor = arrayAcumuladorImporte[i];
                indexMayor = i;
            }
        }

        printf("\nCUIT Cliente: %s\nTotal: %.2f\n",arrayCuitClientes[indexMayor],bufferMayor);
        printf("\n*************************************************************\n");
        printf("*************************************************************\n");
        retorno=0;

    }
    return retorno;
}
