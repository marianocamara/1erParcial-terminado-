#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


void inf_listarPantallas (sPantalla* listaPantallas,int lenListaPantallas);
int inf_listarPantallasContratadas (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones,char* cuit);
int inf_listarContrataciones (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones);
int inf_listarImportePantallasContratadas (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones);
int inf_listarClientesConImportes (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones);
int inf_listarClientesConMayorImporte (sPantalla* listaPantallas,sContrataciones* listaContrataciones, int lenListaPantallas,int lenListaContrataciones);
