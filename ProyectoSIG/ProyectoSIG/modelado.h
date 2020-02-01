#ifndef MODELADO_H
#define MODELADO_H

/* Identificadores de las display list */

/* Define los arcos de la escena */
GLuint arco;
/* Define los arboles de la escena */
GLuint arbol;
/* Define los arboles con base de la escena */
GLuint arbolConBase;
/* Define las vallas de la escena */
GLuint valla;
/* Define los huertos de la escena */
GLuint huerto;
/* Define los suelos de la parte de arriba del castillo de la escena */
GLuint sueloMuro;
/* Define las almenas de la escena */
GLuint almena;
/* Define una secuencia de almenas de la escena */
GLuint almenas;
/* Define las paredes del castillo de la escena */
GLuint paredMuro;
/* Define las torres de la escena */
GLuint torre;
/* Define los estandartes de la escena */
GLuint estandarte;
/* Define los puestos de la escena */
GLuint puesto;
/* Identificador para la display list de la escena */
GLuint escena;

/* Inicializa las display de la escena */
void IniciaDisplayLists (void);
/* Crea la display list para el arco */
void CreaArco(void);
/* Crea la display list para el arbol */
void Arbol(void);
/* Crea la display list para el arbol con base */
void ArbolConBase(void);
/* Crea la display list para la valla */
void Valla(void);
/* Crea la display list para el huerto */
void Huerto(void);
/* Crea la display list para el suelo del muro */
void SueloMuro(void);
/* Crea la display list para la almena */
void Almena(void);
/* Crea la display list para las almenas */
void Almenas(void);
/* Crea la display list para la pared del muro */
void ParedMuro(void);
/* Crea la display list para la torre */
void Torre(void);
/* Crea la display list para el estandarte */
void Estandarte(void);
/* Crea la display list para el puesto */
void Puesto(void);

/* Define el cielo de la escena */
void CrearCielo(void);
/* Define el terreno de la escena */
void CrearTerreno(void);
/* Define el foso de la escena */
void CrearFoso(void);
/* Define el lado de entrada del castillo de la escena */
void CrearLadoEntrada(void);
/* Define el puente levadizo de la escena */
void CrearPuenteLevadizo(void);
/* Define la plaza de la escena */
void CrearPlaza(void);
/* Define los muros del castillo de la escena */
void CrearParedesMuros(void);
/* Define los bosques de la escena */
void CrearBosque(void);
/* Define el camino de la escena */
void CrearCamino(void);
/* Define los huertos de la escena */
void CrearHuertos(void);
/* Define el muro exterior del castillo de la escena */
void CrearMuroExterior(void);
/* Define la parte de la arriba del castillo de la escena */
void CrearArribaMuros(void);
/* Define las torres de la escena */
void CrearTorres(void);
/* Define los estandartes de la escena */
void CrearEstandartes(void);
/* Crea la display list para la escena */
void CrearEscena(void);
#endif
