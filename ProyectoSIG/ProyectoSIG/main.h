#ifndef MAIN_H
#define MAIN_H

/* Funcion de conversion de grados a radianes */
#define  grad2rad(x)  ((float) (3.14159 * x) / 180.0)
#define PASO 4 /* Definicion del paso para el movimiento del observador */

#define WALK 1
#define EXAMINAR 2
#define FLY 3
#define PAN 4

/* Variables Globales del modulo */
int VentanaAncho = 500, VentanaAlto = 500; /* Tamanyo de la ventana */
int VentanaX = 100, VentanaY = 100; /* Posicion de la ventana */
GLdouble  alfa = 0.0, beta = 0.0, gamma = 0.0, z = 0.0;
GLuint cuadrica;

double ox = 50.0, oy = 44.0, oz = 130.0; /* Posicion del observador */
double ix = 50.0, iy = 44.0, iz = 130.0 - PASO; /* Posicion del punto de interes */

int modo = FLY;

double puntoActual = 0.0;
double anguloPan = 1.0;
double radius = 170.0;
double oxActualP, oyActualP, ozActualP;
double ixActualP = 50.0, iyActualP = 50.0, izActualP = -50.0;

/* Realiza el recorrido del modo panoramico */
void iniciarRecorridoPanoramico(void);

/* Abre una ventana OpenGL */
void AbreVentana (int numeroArgumentos, char ** listaArgumentos);

/* Inicia parametros de la OpenGL */
void IniciaOpenGL(void);

/* Funcion de dibujado */
void Dibuja(void);

/* Establece el area visible */
void TamanyoVentana (GLsizei ancho, GLsizei alto);

/* Inicia las funciones de Callback */
void IniciaFuncionesCallback (void);

/* Define las acciones tras una pulsacion del teclado */
void Teclado (unsigned char tecla, int x, int y);

#endif