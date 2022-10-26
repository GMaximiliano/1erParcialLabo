/*
 * autos.c
 *
 *  Created on: 19 oct. 2022
 *      Author: Ulises
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"

int hardcodearMarcas(int* id,eMarca vec[], int tam, int cant)
{
    int todoOk = 0;

    eMarca lista[] =
    {
        {1000,"Renault"},
		{1001,"Ford"},
		{1002,"Fiat"},
		{1003,"Chevrolet"},
		{1004,"Peugeot"}
    };
    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {
        for(int i = 0 ; i < cant ; i++)
        {
            vec[i] = lista[i];
            *id = *id + 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearColor(int* id,eColor vec[], int tam, int cant)
{
    int todoOk = 0;

    eColor lista[] =
    {
        {5000,"negro"},
		{5001,"blanco"},
		{5002,"rojo"},
		{5003,"verde"},
		{5004,"azul"}
    };

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {
        for(int i = 0 ; i < cant ; i++)
        {
            vec[i] = lista[i];
            *id = *id + 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int hardcodearServicio(int* id,eServicio vec[], int tam, int cant)
{
    int todoOk = 0;

    eServicio lista[] =
    {
        {20000,"lavado",450},
		{20001,"pulido", 500},
		{20002,"encerado", 600},
		{20003,"completo", 900},
    };

    if(vec != NULL && tam > 0 && cant <= tam && cant <= 10)
    {
        for(int i = 0 ; i < cant ; i++)
        {
            vec[i] = lista[i];
            *id = *id + 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaAuto(int* id, eAuto vec[], int tam, eMarca vecM[], int tamM, eColor vecC[],int tamC)
{
    int todoOk = 0;
    int indice;
    eAuto auxAuto;

    if(id != NULL && vec != NULL && tam > 0)
    {

        system("cls");

        printf("**** Alta de Autos ****\n\n");
        buscarLibre(&indice, vec, tam);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
        	cargarAuto(&auxAuto,&vecM,&vecC,tamM,tamC);

        	auxAuto.id = *id;
            *id = *id + 1;
            vec[indice] = auxAuto;

            todoOk = 1;
        }
    }
    return todoOk;
}

int cargarAuto(eAuto* pAuto, eMarca* vecM[], eColor* vecC[], int tamM, int tamC)
{
    int todoOk = 0;
    int idMarca;
    int idColor;

    if(pAuto != NULL)
    {
        pAuto->isEmpty = 0;
        mostrarMarca(*vecM, tamM,0);

        printf("ingrese id de la Marca: ");
        scanf("%d",&idMarca);
        while(!validarIdMarca(idMarca,*vecM,tamM))
        {
        	 printf("id invalido, reingrese id: ");
        	 scanf("%d",&idMarca);
        }
        pAuto->idMarca=idMarca;

        mostrarColor(*vecC, tamC,0);
        printf("ingrese id del Color: ");
        scanf("%d",&idColor);
        while(!validarIdColor(idColor,*vecC,tamC))
        {
        	printf("id invalido, reingrese id: ");
        	scanf("%d",&idColor);
        }
        pAuto->idColor=idColor;

        printf("ingrese tipo de caja: m- manual o a- automatico");
        fflush(stdin);
        scanf("%c",&pAuto->caja);
        while(pAuto->caja!='m'&& pAuto->caja!='a')
        {
        	 printf("error, ingrese tipo de caja: m- manual o a- automatico");
        	 fflush(stdin);
        	 scanf("%c",&pAuto->caja);
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarIdMarca(int id, eMarca vec[],int tam)
{
	int todoOk=0;

	if(vec!=NULL && tam>0 && id>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(vec[i].id==id)
			{
				todoOk=1;
				break;
			}
		}
	}
	return todoOk;
}

int validarIdColor(int id, eColor vec[],int tam)
{
	int todoOk=0;

	if(vec!=NULL && tam>0 && id>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(vec[i].id==id)
			{
				todoOk=1;
				break;
			}
		}
	}
	return todoOk;
}

int buscarLibre(int* pIndice, eAuto vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( vec[i].isEmpty)
            {

                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}


int mostrarAutos(eAuto vec[], int tam, eMarca vecM[], int tamM,eColor vecC[],int tamC)
{
    int todoOk = 0;
    int flag = 1;

    if(vec != NULL && tam > 0)
    {

        printf("**** Lista de autos ****\n");
        printf("|id | marca | color | tipo de caja de cambio |  \n");
        for(int i = 0 ; i < tam ; i++)
        {
            if(!vec[i].isEmpty)
            {
            	mostrarAuto(vec[i], vecM,vecC,tam,tamM,tamC);
                flag = 0;
            }
        }
        printf("\n\n");

        if(flag)
        {
            printf("No hay autos cargados.\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int mostrarAuto(eAuto autos, eMarca vecM[],eColor vecC[],int tam,int tamM,int tamC)
{
    int todoOk = 0;
    char marca[20];
    char color[20];

    cargarDescripcionMarca(autos.idMarca, marca, vecM, tam );
    cargarDescripcionColor(autos.idColor,color,vecC,tam);
    printf("%d    %s    %s    %c    \n",
           autos.id,
           marca,
		   color,
		   autos.caja);

    return todoOk;
}

int cargarDescripcionMarca(int id, char descripcion[], eMarca vec[], int tam)
{
	int todoOk = 0;
	if(descripcion != NULL && vec != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			if(vec[i].id == id)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
 	return todoOk;
}

int cargarDescripcionColor(int id, char descripcion[], eColor vec[], int tam)
{

	int todoOk = 0;
	if(descripcion != NULL && vec != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			if(vec[i].id == id)
			{
				strcpy(descripcion, vec[i].nombre);
				break;
			}
		}
		todoOk = 1;
	}
 	return todoOk;
}


int buscarAuto(int* pIndice, int id, eAuto vec[], int tam)
{
    int todoOk = 0;
    int indice = -1;

    if(pIndice != NULL && vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            if( !vec[i].isEmpty && vec[i].id == id )
            {

                indice = i;
                break;
            }
        }
        *pIndice = indice;
        todoOk = 1;
    }
    return todoOk;
}

int bajaAuto( eAuto vec[], int tam, eMarca vecM[], int tamM,eColor vecC[],int tamC)
{
    int todoOk = 0;
    int id;
    int indice;
    char confirma;


    if(vec != NULL && tam > 0)
    {

        system("cls");
        printf("**** Baja Auto ****\n\n");

        mostrarAutos(vec, tam, vecM,tamM, vecC, tamC );

        printf("Ingrese id a dar de baja: ");
        scanf("%d", &id);

        buscarAuto(&indice, id, vec, tam);
        if(indice == -1)
        {
            printf("No existe un auto con ese id: %d\n", id);
        }
        else
        {
        	mostrarAuto(vec[indice], vecM,vecC,tam,tamM,tamC);
            printf("Confirma baja? s- para confirmar: ");
            fflush(stdin);
            confirma = getchar();

            if(confirma == 's')
            {
                vec[indice].isEmpty = 1;
                printf("Baja exitosa.\n");
            }
            else
            {
                printf("Se ha cancelado la baja.\n");
            }

        }

        todoOk = 1;
    }
    return todoOk;
}

int mostrarMarca(eMarca vec[], int tam, int cls)
{
	int todoOk = 0;

	if(vec != NULL && tam > 0 && cls>=0 && cls <=1)
	{
		if(cls)
		{
			system("cls");
		}

		printf("**** Lista de Marcas ****\n\n");
		printf("Id Descripcion\n");

		for(int i = 0 ; i < tam ; i++)
		{
			printf("%d %s\n", vec[i].id, vec[i].descripcion);
		}

	}
	printf("\n");
	system("pause");
	return todoOk;
}

int mostrarServicios(eServicio vec[], int tam, int cls)
{
	int todoOk = 0;

	if(vec != NULL && tam > 0 && cls>=0 && cls <=1)
	{
		if(cls)
		{
			system("cls");
		}

		printf("**** Lista de Servicios ****\n\n");
		printf("Id Descripcion precio\n");

		for(int i = 0 ; i < tam ; i++)
		{
			printf("%d %s %d\n", vec[i].id, vec[i].descripcion, vec[i].precio);
		}

	}
	printf("\n");
	system("pause");
	return todoOk;
}

int mostrarColor(eColor vec[], int tam, int cls)
{
	int todoOk = 0;

	if(vec != NULL && tam > 0 && cls>=0 && cls <=1)
	{
		if(cls)
		{
			system("cls");
		}

		printf("**** Lista de tipos ****\n\n");
		printf("Id Descripcion\n");

		for(int i = 0 ; i < tam ; i++)
		{
			printf("%d %s\n", vec[i].id, vec[i].nombre);
		}

	}
	printf("\n");
	system("pause");
	return todoOk;
}

char mostrarMenu()
{

	 char opcion;

	 printf("\n**ABM AUTOS**\n\n");
	 printf("a-alta auto\n");
	 printf("b-modificar auto\n");
	 printf("c-baja auto\n");
	 printf("d-listar autos\n");
	 printf("e-listar marcas\n");
	 printf("f-listar colores\n");
	 printf("g-listar servicios\n");
	 printf("h-listar trabajo\n");
	 printf("i-listar Trabajos\n");
	 printf("0- salir\n");
     fflush(stdin);
	 scanf("%c", &opcion);

    return opcion;
}

int inicializarAutos(eAuto vec[], int tam)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i = 1 ; i < tam ; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(int* idTrabajo,eTrabajo vecT[], int tamT, eAuto vec[], int tam, eMarca vecM[], int tamM, eColor vecC[],int tamC, eServicio vecS[],int tamS)
{
    int todoOk = 0;
    int indice;
    eTrabajo auxTrabajo;

    if(idTrabajo != NULL && vec != NULL && tam > 0)
    {

        system("cls");

        printf("**** Alta de Autos ****\n\n");
        buscarLibre(&indice, vec, tam);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
        	cargarTrabajo(&auxTrabajo,&vec,&vecM,&vecC,&vecS,tamM,tamC,tam,tamS);

        	auxTrabajo.id = *idTrabajo;
            *idTrabajo = *idTrabajo + 1;
            vecT[indice] = auxTrabajo;

            todoOk = 1;
        }
    }
    return todoOk;
}

int cargarTrabajo(eTrabajo* pTrabajo, eAuto* vec[], eMarca* vecM[], eColor* vecC[],eServicio* vecS[],int tamM, int tamC, int tam,int tamS)
{
    int todoOk = 0;
    int idAuto;
    int idServicio;
    int dia;
    int mes;
    int anio;

    if(pTrabajo != NULL)
    {
        pTrabajo->isEmpty = 0;
        mostrarAutos(*vec,tam,*vecM,tamM,*vecC,tamC);

        printf("ingrese id del auto a trabajar: ");
        scanf("%d",&idAuto);

        while(!validarIdAuto(idAuto,*vec,tam))
        {
        	 printf("id invalido, reingrese id: ");
        	 scanf("%d",&idAuto);
        }
        pTrabajo->idAuto=idAuto;

        mostrarServicios(*vecS,tamS,0);
        printf("ingrese id del servicio a cargar: ");
        scanf("%d",&idServicio);
        while(!validarIdServicio(idServicio,*vecS,tamS))
        {
        	printf("id invalido, reingrese id: ");
        	scanf("%d",&idServicio);
        }
        pTrabajo->idServicio=idServicio;

        printf("ingresar año cuando se realizo el trabajo: ");
        scanf("%d",&anio);

        while(anio<0)
        {
            printf("error, ingresar año cuando se realizo el trabajo: ");
            scanf("%d",&anio);
        }
        pTrabajo->fecha.anio=anio;

        printf("ingrese mes: ");
        scanf("%d",&mes);
        switch(mes)
		{
		   case  1 :
		   case  3 :
		   case  5 :
		   case  7 :
		   case  8 :
		   case 10 :
		   case 12 :

			   printf("Coloque el dia: \n");
			   scanf("%d",&dia);
			   while(dia<1 || dia>31)
			   {
				   printf("Error, Coloque el dia: \n");
				   scanf("%d",&dia);
			   }
			   pTrabajo->fecha.dia=dia;
		   break;

		   case  4 :
		   case  6 :
		   case  9 :
		   case 11 :
			   printf("Coloque el dia: \n");
			   scanf("%d",&dia);
			   while(dia<1 || dia>30)
			   {
				   printf("Error, Coloque el dia: \n");
				   scanf("%d",&dia);
			   }
			   pTrabajo->fecha.dia=dia;
		   break;

		   case 2:
			   printf("Coloque el dia: \n");
			   scanf("%d",&dia);
			   while(dia>28)
			   {
				   printf("Error, Coloque el dia: \n");
				   scanf("%d",&dia);
			   }
			   pTrabajo->fecha.dia=dia;
		   break;
		}
        pTrabajo->fecha.mes=mes;

        todoOk = 1;
    }
    return todoOk;
}

int mostrarTrabajos(eTrabajo vec[], int tam,eAuto vecA[],int tamA,eServicio vecS[],int tamS)
{
	int todoOk = 0;

	if(vec != NULL && tam > 0)
	{

		printf("**** Lista de Trabajos ****\n\n");
		printf("Id | id auto | servicio | dia | mes| año\n");

		for(int i = 0 ; i < tam ; i++)
		{
			if(!vec[i].isEmpty)
			{
				mostrarTrabajo(vec[i],vecA,vecS,tam,tamA,tamS);
			}
		}

	}
	printf("\n");
	return todoOk;
}

int validarIdServicio(int id, eServicio vec[],int tam)
{
	int todoOk=0;

	if(vec!=NULL && tam>0 && id>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(vec[i].id==id)
			{
				todoOk=1;
				break;
			}
		}
	}
	return todoOk;
}

int validarIdAuto(int id, eAuto vec[],int tam)
{
	int todoOk=0;

	if(vec!=NULL && tam>0 && id>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(vec[i].id==id)
			{
				todoOk=1;
				break;
			}
		}
	}
	return todoOk;
}

int mostrarTrabajo(eTrabajo trabajo, eAuto vecA[], eServicio vecS[],int tam,int tamA, int tamS)
{
    int todoOk = 0;
    char servicio[20];
    cargarDescripcionServicio(trabajo.idServicio,servicio,vecS,tamS);
    printf("%d\t%d\t%s\t%d\t%d\t%d\t\n",
           trabajo.id,
		   trabajo.idAuto,
		   servicio,
		   trabajo.fecha.dia,
		   trabajo.fecha.mes,
		   trabajo.fecha.anio
		   );

    return todoOk;
}

int cargarDescripcionServicio(int id, char descripcion[], eServicio vec[], int tam)
{
	int todoOk = 0;
	if(descripcion != NULL && vec != NULL && tam > 0)
	{
		for(int i = 0 ; i < tam ; i++)
		{
			if(vec[i].id == id)
			{
				strcpy(descripcion, vec[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
 	return todoOk;
}

int modificarAuto( eAuto vec[], int tam, eMarca vecM[], int tamM,eColor vecC[], int tamC)
{

	int todoOk=0;
	int indice;
	int id;
	char confirmar;
	int opcion;
	int idNuevaMarca;
	int idNuevoColor;


	if(vec!=NULL && tam>0 && vecM!=NULL && tamM>0 && vecC!=NULL && tamC>0)
	{
		printf("ingrese una opcion a modificar: ");
		printf("1- Color");
		printf("2- Marca");
		scanf("%d",&opcion);

		if(opcion==1)
		{
			mostrarAutos(vec,tam,vecM,tamM,vecC,tamC);
			printf("ingrese id del auto a modificar: ");
			scanf("%d",&id);

			buscarAuto(&indice, id, vec, tam);
			if(indice == -1)
			{
				printf("No existe un auto con ese id: %d\n", id);
			}
			else
			{
				mostrarAuto(vec[indice],vecM,vecC,tam,tamM,tamC);
				mostrarColor(vecC,tamM,0);
				printf("ingrese nuevo id para cambiar el Color: ");
				scanf("%d",&idNuevoColor);

				printf("Confirma modificacion?: ");
				fflush(stdin);
				confirmar = getchar();

				if(confirmar == 's')
				{
					vec[indice].idColor=idNuevoColor;
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Se ha cancelado la modificacion.\n");
				}
			}

		}
		else
		{
			mostrarAutos(vec,tam,vecM,tamM,vecC,tamC);
			printf("ingrese id del auto a modificar: ");
			scanf("%d",&id);

			buscarAuto(&indice, id, vec, tam);
			if(indice == -1)
			{
				printf("No existe un auto con ese id: %d\n", id);
			}
			else
			{
				mostrarAuto(vec[indice],vecM,vecC,tam,tamM,tamC);
				printf("ingrese nuevo id para cambiar la Marca: ");
				scanf("%d",&idNuevaMarca);

				printf("Confirma modificacion?: ");
				fflush(stdin);
				confirmar = getchar();

				if(confirmar == 's')
				{
					vec[indice].idMarca=idNuevaMarca;
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Se ha cancelado la modificacion.\n");
				}
			}
		}
		todoOk=1;
	}

	return todoOk;
}

int inicializarTrabajos(eTrabajo vec[], int tam)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0 ; i < tam ; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarAutosColor(eAuto vec[],int tam,eColor vecC[],int tamC, eMarca vecM[],int tamM)
{
	int todoOk=0;
	int idColor;
	if(vec!= NULL && tam > 0 && vecM!=NULL && tamM>0 && vecC!=NULL && tamC>0)
	{

		mostrarColor(vecC,tamC,0);
		printf("ingrese el id del color a filtrar por autos: ");
		scanf("%d",&idColor);

		for(int i = 0 ; i < tam ; i++)
		{
			if(vec[i].idColor==idColor)
			{
				mostrarAuto(vec[i],vecM,vecC,tam,tamM,tam);
			}
		}
		todoOk=1;
		printf("\n");
		system("pause");
	}

	return todoOk;
}

int informarAutosMarca(eAuto vec[],int tam,eColor vecC[],int tamC, eMarca vecM[],int tamM)
{
	int todoOk=0;
	int idMarca;
	if(vec!= NULL && tam > 0 && vecM!=NULL && tamM>0 && vecC!=NULL && tamC>0)
	{
		mostrarMarca(vecM,tamM,0);
		printf("ingrese el id de la marca a filtrar por autos: ");
		scanf("%d",&idMarca);

		for(int i = 0 ; i < tam ; i++)
		{
			if(vec[i].idMarca==idMarca)
			{
				mostrarAuto(vec[i],vecM,vecC,tam,tamM,tam);
			}
		}
		todoOk=1;
		printf("\n");
		system("pause");
	}

	return todoOk;
}

int informarAutosCaja(eAuto vec[],int tam, eColor vecC[],int tamC, eMarca vecM[],int tamM)
{
	int todoOk=0;
	char tipoCajaM='m';
	char tipoCajaA='a';
	if(vec!= NULL && tam > 0 && vecM!=NULL && tamM>0 && vecC!=NULL && tamC>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(vec[i].caja==tipoCajaM)
			{
				printf("lista de autos con caja Manual: \n");
				printf("id\tmarca\tcolor\t tipo de caja\n");
				mostrarAuto(vec[i],vecM,vecC,tam,tamM,tamC);
			}
		}
		printf("\n\n");

		for(int j=0;j<tam;j++)
		{
			if(vec[j].caja==tipoCajaA)
			{
				printf("lista de autos con caja Automatica: \n");
				printf("id\tmarca\tcolor\t tipo de caja\n");
				mostrarAuto(vec[j],vecM,vecC,tam,tamM,tamC);
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int informarMarcasYColor(int* contador,eAuto vec[],int tam,eColor vecC[],int tamC,eMarca vecM[],int tamM)
{
	int todoOk=0;
	int idColor;
	int idMarca;
	*contador=0;
	if(vec!= NULL && tam > 0 && vecM!=NULL && tamM>0 && vecC!=NULL && tamC>0)
	{
		mostrarColor(vecC,tamC,0);
		printf("ingrese el id del color a filtrar por autos: ");
		scanf("%d",&idColor);

		mostrarMarca(vecM,tamM,0);
		printf("ingrese el id de la marca a filtrar por autos: ");
		scanf("%d",&idMarca);

		for(int i=0;i<tam;i++)
		{
			if(vec[i].idColor==idColor && vec[i].idMarca==idMarca)
			{
				*contador=*contador+1;
			}

		}

		todoOk=1;
	}
	return todoOk;
}

int informarMarcaMasElegida(int *mayor,eAuto vec[],int tam, eColor vecC[],int tamC, eMarca vecM[],int tamM)
{
	int todoOk=0;
	int contadorRenault=0;
	int contadorFord=0;
	int contadorFiat=0;
	int contadorChevrolet=0;
	int contadorPeugeot=0;
	if(vec!= NULL && tam > 0 && vecM!=NULL && tamM>0 && vecC!=NULL && tamC>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(vec[i].idMarca==5000)
			{
				contadorRenault++;
			}

			if(vec[i].idMarca==5001)
			{
				contadorFord++;
			}
			if(vec[i].idMarca==5002)
			{
				contadorFiat++;
			}
			if(vec[i].idMarca==5003)
			{
				contadorChevrolet++;
			}
			if(vec[i].idMarca==5004)
			{
				contadorPeugeot++;
			}
		}
		if(contadorRenault>contadorFord &&contadorRenault>contadorFiat&&contadorRenault>contadorChevrolet&&contadorRenault>contadorPeugeot)
		{
			*mayor=contadorRenault;
		}
		else
		{
			if(contadorFord>contadorFiat&&contadorFord>contadorChevrolet&&contadorFord>contadorPeugeot)
			{
				*mayor=contadorFord;
			}
			else
			{
				if(contadorFiat>contadorChevrolet&&contadorFiat>contadorPeugeot)
				{
					*mayor=contadorFiat;
				}
				else
				{
					if(contadorChevrolet>contadorPeugeot)
					{
						*mayor=contadorChevrolet;
					}
					else
					{
						*mayor=contadorPeugeot;
					}
				}
			}
		}

		todoOk=1;
	}
	return todoOk;
}

int mostrarTrabajosAlAuto(eTrabajo vecT[],int tamT,eAuto vecA[],int tamA, eServicio vecS[],int tamS, eColor vecC[], int tamC, eMarca vecM[], int tamM)
{
	int todoOk=0;
	int idAuto;

	 if(vecT != NULL && vecA!= NULL && vecS!=NULL && tamT > 0 && tamA >0 && tamS>0)
	 {
	     mostrarAutos(vecA,tamA,vecM,tamM,vecC,tamC);
		 printf("ingrese el id de un autos para saber sus trabajos realizados: ");
		 scanf("%d",&idAuto);

		 for(int i=0;i<tamT;i++)
		 {
			 if(vecT[i].idAuto==idAuto)
			 {
				printf("Id | id auto | servicio |	 dia | mes| año\n");
				 mostrarTrabajo(vecT[i],vecA,vecS,tamT,tamA,tamS);
			 }
		 }
	 }

	return todoOk;
}

int hardcorearTrabajos(int* id,eTrabajo vecT[],int tamT, int cant)
{
	int todoOk=0;
	eTrabajo trabajos[]=
	{
	 {1,1,20000,1,10,2002},
	 {2,2,20001,14,5,2001},
	 {3,1,20003,5,10,2002},
	 {4,4,20001,10,10,2005}};
	 if(vecT != NULL && tamT > 0 && cant <= tamT && cant <=4)
	    {
	        for(int i = 0 ; i < cant ; i++)
	        {
	        	vecT[i] = trabajos[i];
	            *id = *id + 1;
	        }
	        todoOk = 1;
	    }
	return todoOk;
}

