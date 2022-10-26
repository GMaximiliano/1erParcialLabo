/*
 ============================================================================
 Name        : 1erParcialLaboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autos.h"


#define TAM 10
#define TAM_M 5
#define TAM_C 5
#define TAM_S 4
#define TAM_T 4

int main(void) {
	setbuf(stdout,NULL);
	int nextId=1;
	int nextIdTrabajo=1;
	int idMarca=1000;
	int idColor=5000;
	int idServicio=20000;
	int contadorMarcaYColor;
	int masElegido=0;
	char salir ='n';
	eAuto autos[TAM];
	eMarca marcas[TAM_M];
	eColor colores[TAM_C];
	eServicio servicios[TAM_S];
	eTrabajo trabajos[TAM_S];

	inicializarAutos(autos,TAM);
	hardcodearMarcas(&idMarca,marcas,TAM_M,5);
	hardcodearColor(&idColor,colores,TAM_C,5);
	hardcodearServicio(&idServicio,servicios,TAM_S,4);
	inicializarTrabajos(trabajos,TAM_T);
	hardcorearTrabajos(&nextIdTrabajo,trabajos,TAM_T,4);

	do
	{
		switch(mostrarMenu())
		{
		case 'a':
			if(!altaAuto(&nextId,autos,TAM,marcas,TAM_M,colores,TAM_C))
			{
				printf("no se pudo realizar el alta...\n");
			}
			else
			{
				printf("alta exitosa\n");
			}
			break;

		case 'b':
			if(!modificarAuto(autos,TAM,marcas,TAM_M,colores,TAM_C))
			{
				printf("no se pudo realizar el alta...\n");
			}
			else
			{
				printf("alta exitosa\n");
			}
			break;

		case 'c':
			if(!bajaAuto(autos,TAM,marcas,TAM_M,colores,TAM_C))
			{
				printf("no se pudo realizar el alta\n");
			}
			else
			{
				printf("baja exitosa");
			}
			break;
		case 'd':
			mostrarAutos(autos,TAM,marcas,TAM_M,colores,TAM_C);
			break;
		case 'e':
			mostrarMarca(marcas,TAM_M,0);
			break;
		case 'f':
			mostrarColor(colores,TAM_C,0);
			break;
		case 'g':
			mostrarServicios(servicios,TAM_S,0);
			break;
		case 'h':
			if(!altaTrabajo(&nextIdTrabajo,trabajos,TAM_T,autos,TAM,marcas,TAM_M,colores,TAM_C,servicios,TAM_S))
			{
				printf("no se pudo realizar el alta...\n");
			}
			else
			{
				printf("alta exitosa\n");
			}
			break;

		case 'i':
			mostrarTrabajos(trabajos,TAM_T,autos,TAM,servicios,TAM_S);
			break;
		case 'j':
			informarMarcasYColor(&contadorMarcaYColor,autos,TAM,colores,TAM_C,marcas,TAM_M);
			if(contadorMarcaYColor==0)
			{
				printf("no hay marca y color coincidentes entre los autos cargados");
			}
			else
			{
				printf("la cantidad de autos con la misma marca y color son:%d ",contadorMarcaYColor);
			}
			break;

		case 'k':
			informarMarcaMasElegida(&masElegido,autos,TAM,colores,TAM_C,marcas,TAM_M);
			if(masElegido==0)
			{
				printf("no hay marcas ");
			}
			else
			{
				printf("la cantidad de autos con la misma marca y color son:%d ",contadorMarcaYColor);
			}
			break;
		case 'l':
			mostrarTrabajosAlAuto(trabajos,TAM_S,autos,TAM,servicios,TAM_S,colores,TAM_C, marcas,TAM_M);

		}

	}
	while(salir=='n');
	return EXIT_SUCCESS;
}


