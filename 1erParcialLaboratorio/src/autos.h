/*
 * autos.h
 *
 *  Created on: 19 oct. 2022
 *      Author: Ulises
 */

#ifndef AUTOS_H_
#define AUTOS_H_


typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	char descripcion[20];
}eMarca;

typedef struct
{
	int id;
	char nombre[20];
}eColor;
typedef struct
{
	int id;
	int idMarca;
	int idColor;
	char caja;
	int isEmpty;
}eAuto;

typedef struct
{
	int id;
	char descripcion[25];
	int precio;
}eServicio;

typedef struct
{
	int id;
	int idAuto;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

/**
 *
 * @param id variable indentificadora segun la marca
 * @param vec[] array que contiene la informacion de marcas
 * @param tam tamaño del array de marcas
 * @param cant cantidad marcas
 * @return retorna si funciona bien
 */
int hardcodearMarcas(int* id,eMarca vec[], int tam, int cant);

/**
 *
 * @param id variable indentificadora segun el color
 * @param vec[] array que contiene la informacion de los colores
 * @param tam tamaño del array de colores
 * @param cant cantidad colores
 * @return retorna si funciona bien
 */
int hardcodearColor(int* id,eColor vec[], int tam, int cant);

/**
 *
 * @param id variable indentificadora segun el Servicio
 * @param vec[] array que contiene la informacion de los servicios
 * @param tam tamaño del array de servicios
 * @param cant cantidad servicios
 * @return retorna si funciona bien
 */
int hardcodearServicio(int* id,eServicio vec[], int tam, int cant);

/**
 *
 * @param id contiene el el id del auto y se va incrementando segun se haga un alta
 * @param vec array de autos
 * @param tam tamaño del aray de autos
 * @param vecM array de marcas
 * @param tamM tamaño de la cantidad de marcas
 * @param vecC array de Colores
 * @param tamC tamaño de la cantidad de colores
 * @return retorna 1 si el alta funcion y 0 en caso contrario
 */
int altaAuto(int* id, eAuto vec[], int tam, eMarca vecM[], int tamM, eColor vecC[],int tamC);

int cargarAuto(eAuto* pAuto, eMarca* vecM[], eColor* vecC[], int tamM, int tamC);
int validarIdMarca(int id, eMarca vec[],int tam);
int validarIdColor(int id, eColor vec[],int tam);
int validarIdServicio(int id, eServicio vec[],int tam);
int validarIdAuto(int id, eAuto vec[],int tam);
int buscarLibre(int* pIndice, eAuto vec[], int tam);
int mostrarAutos(eAuto vec[], int tam, eMarca vecM[], int tamM,eColor vecC[],int tamC);
int mostrarAuto(eAuto autos, eMarca vecM[],eColor vecC[],int tam,int tamM,int tamC);
int cargarDescripcionMarca(int id, char descripcion[], eMarca vec[], int tam);
int cargarDescripcionColor(int id, char descripcion[], eColor vec[], int tam);
int cargarDescripcionServicio(int id, char descripcion[], eServicio vec[], int tam);
int bajaAuto( eAuto vec[], int tam, eMarca vecM[], int tamM,eColor vecC[],int tamC);
int modificarAuto( eAuto vec[], int tam, eMarca vecM[], int tamM,eColor vecC[], int tamC);
int mostrarMarca(eMarca vec[], int tam, int cls);
int buscarAuto(int* pIndice, int id, eAuto vec[], int tam);
int mostrarColor(eColor vec[], int tam, int cls);
int mostrarServicios(eServicio vec[], int tam, int cls);
char mostrarMenu();
int inicializarAutos(eAuto vec[], int tam);
int listarAutos(eAuto vec[], int tam,eMarca vecM[], int tamM,eColor vecC[],int tamC);
int mostrarTrabajos(eTrabajo vec[], int tam,eAuto vecA[],int tamA,eServicio vecS[],int tamS);
int altaTrabajo(int* idTrabajo,eTrabajo vecT[], int tamT, eAuto vec[], int tam, eMarca vecM[], int tamM, eColor vecC[],int tamC, eServicio vecS[],int tamS);
int cargarTrabajo(eTrabajo* pTrabajo, eAuto* vec[], eMarca* vecM[], eColor* vecC[],eServicio* vecS[],int tamM, int tamC, int tam, int tamS);
int mostrarTrabajo(eTrabajo trabajo, eAuto vecA[], eServicio vecS[],int tam,int tamA, int tamS);
int inicializarTrabajos(eTrabajo vec[], int tam);
int informarAutosColor(eAuto vec[],int tam,eColor vecC[],int tamC, eMarca vecM[],int tamM);
int informarAutosMarca(eAuto vec[],int tam,eColor vecC[],int tamC, eMarca vecM[],int tamM);
int informarAutosCaja(eAuto vec[],int tam, eColor vecC[],int tamC, eMarca vecM[],int tamM);
int informarMarcasYColor(int* contador,eAuto vec[],int tam,eColor vecC[],int tamC,eMarca vecM[],int tamM);
int informarMarcaMasElegida(int *mayor,eAuto vec[],int tam, eColor vecC[],int tamC, eMarca vecM[],int tamM);
int mostrarTrabajosAlAuto(eTrabajo vecT[],int tamT,eAuto vecA[],int tamA, eServicio vecS[],int tamS, eColor vecC[], int tamC, eMarca vecM[], int tamM);
int hardcorearTrabajos(int* id,eTrabajo vecT[],int tamT, int cant);
#endif /* AUTOS_H_ */
