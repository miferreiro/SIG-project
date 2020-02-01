/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/
#include "glut.h"
#include <stdio.h>
#include <math.h>
#include "main.h"
#include "glig.h"
#include "luces.h"
#include "material.h"
#include "modelado.h"

/******************************************************************************************/
/* Realiza el recorrido del modo panoramico                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void iniciarRecorridoPanoramico(void)
{
	
	if (puntoActual < 360/anguloPan) {

		gluLookAt(oxActualP, oyActualP, ozActualP, ixActualP, iyActualP, izActualP, 0, 1, 0);

		if (puntoActual <= ((360 * 1) / (anguloPan * 4))) {
			oxActualP = 50.0 + sin(grad2rad(anguloPan * puntoActual)) * radius;
			ozActualP = (radius - 50.0) - sin(grad2rad(anguloPan * puntoActual)) * radius;
		} else {
			if (puntoActual > ((360 * 1) / (anguloPan * 4 )) && puntoActual <= ((360 * 2) / (anguloPan * 4))) {
				oxActualP = (radius + 50.0) + cos(grad2rad(anguloPan * puntoActual)) * radius;
				ozActualP = -50.0 + cos(grad2rad(anguloPan * puntoActual)) * radius;
			} else {
				if (puntoActual > ((360 * 2) / (anguloPan * 4)) && puntoActual <= ((360 * 3) / (anguloPan * 4))) {
					oxActualP = 50.0 + sin(grad2rad(anguloPan * puntoActual)) * radius;
					ozActualP = (-radius - 50.0) - sin(grad2rad(anguloPan * puntoActual)) * radius;
				} else {
					oxActualP = (-radius + 50.0) + cos(grad2rad(anguloPan * puntoActual)) * radius;
					ozActualP = -50.0 + cos(grad2rad(anguloPan * puntoActual)) * radius;
				}
			}
		}
		puntoActual++;
		
	} else {
		puntoActual = 0.0;
		oxActualP = ixActualP; oyActualP = iyActualP + 40; ozActualP = radius + izActualP;
		gluLookAt(oxActualP, oyActualP, ozActualP, ixActualP, iyActualP, izActualP, 0, 1, 0);
	}
	glutPostRedisplay();
	
}

/******************************************************************************************/
/* Establece el area visible y el tipo de proyeccion                                      */
/* Parametros: int ancho --> Ancho del area visible                                       */
/*             int alto --> Alto del area visible                                         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void TamanyoVentana (GLsizei ancho, GLsizei alto)
{
    /* Definicion del viewport */
	glViewport(0, 0, ancho, alto);  
    /* Definicion de la vista */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(60.0, (GLdouble)alto / (GLdouble)ancho, 1.0, 400.0);
}

/******************************************************************************************/
/* Abre una ventana OpenGL                                                                */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void AbreVentana (int numeroArgumentos, char ** listaArgumentos)
{
	glutInit(&numeroArgumentos, listaArgumentos);
	/* Cambia los parametros para utilizar doble buffer */
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize (VentanaAncho, VentanaAlto);
	glutInitWindowPosition (VentanaX, VentanaY);
	glutCreateWindow (listaArgumentos[0]);
	glutDisplayFunc (Dibuja);
	glutReshapeFunc (TamanyoVentana);
}

/******************************************************************************************/
/* Define las acciones tras una pulsacion del teclado                                     */
/* Parametros: unsigned char key --> Codigo de la tecla pulsada                           */
/*             int x --> Coordenada x del cursor en el momento de pulsar la tecla         */
/*             int y --> Coordenada y del cursor en el momento de pulsar la tecla         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Teclado (unsigned char tecla, int x, int y)
{
	switch (tecla)
	{
		case 27 : /* Codigo de la tecla de Escape */
			exit (0);
			break;
		case 'w':
			modo = WALK;			
			printf("Modo = WALK      \r");
			break;
		case 'e':
			modo = EXAMINAR;
			printf("Modo = EXAMINAR    \r");
			break;
		case 'f':
			modo = FLY;
			printf("Modo = FLY      \r");
			break;
		case 'p':
			modo = PAN;
			printf("Modo = PANORAMICO      \r");
			glRotated(-18.0, 1.0, 0.0, 0.0);			
			oxActualP = ixActualP; oyActualP = iyActualP + 40; ozActualP = radius + izActualP;
			puntoActual = 0;
			glutPostRedisplay();
			break;
	}
}

/******************************************************************************************/
/* Define las acciones tras una pulsacion del teclado ampliado                            */
/* Parametros: unsigned char tecla --> Codigo de la tecla pulsada                         */
/*             int x --> Coordenada x del cursor en el momento de pulsar la tecla         */
/*             int y --> Coordenada y del cursor en el momento de pulsar la tecla         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void TecladoAmpliado (int tecla, int x, int y)
{
	if (modo != PAN) {
		switch (tecla)
		{
			case GLUT_KEY_UP: /* Pulsacion cursor arriba del teclado ampliado */
				if (modo == WALK) {
					ox = ix;
					oz = iz;
					ix = ox + PASO * sin(grad2rad(alfa));
					iz = oz - PASO * cos(grad2rad(alfa));
					break;
				}
				if (modo == EXAMINAR) {
					beta = beta + 10.0;
					if (beta > 360.0) beta = beta - 360.0;
					iy = oy + PASO * sin(grad2rad(beta));
					break;
				}
				if (modo == FLY) {
					ox = ix;
					oy = iy;
					oz = iz;

					ix = ox + PASO * sin(grad2rad(alfa));
					iy = iy + PASO * sin(grad2rad(beta));
					iz = oz - PASO * cos(grad2rad(alfa));
					break;
				}
				break;

			case GLUT_KEY_DOWN: /* Pulsacion cursor abajo del teclado ampliado */
				if (modo == WALK) {
					ox = ox - (ix - ox);
					oz = oz - (iz - oz);
					ix = ox + PASO * sin(grad2rad(alfa));
					iz = oz - PASO * cos(grad2rad(alfa));
					break;
				}
				if (modo == EXAMINAR) {
					beta = beta - 10.0;
					if (beta < 0.0) beta = beta + 360.0;
					iy = oy + PASO * sin(grad2rad(beta));
					break;
				}
				if (modo == FLY) {
					ox = ox - (ix - ox);
					oz = oz - (iz - oz);
					iy = oy;

					oy = oy - PASO * sin(grad2rad(beta));
					ix = ox + PASO * sin(grad2rad(alfa));
					iz = oz - PASO * cos(grad2rad(alfa));
					break;
				}
				break;

			case GLUT_KEY_RIGHT: // Pulsacion cursor derecha del teclado ampliado
				alfa = alfa + 10.0;
				if (alfa > 360.0) alfa = alfa - 360.0;
				ix = ox + PASO * sin(grad2rad(alfa));
				iz = oz - PASO * cos(grad2rad(alfa));
				break;

			case GLUT_KEY_LEFT: // Pulsacion cursor izquierda del teclado ampliado
				alfa = alfa - 10.0;
				if (alfa < 0.0) alfa = alfa + 360.0;
				ix = ox + PASO * sin(grad2rad(alfa));
				iz = oz - PASO * cos(grad2rad(alfa));
				break;

			case GLUT_KEY_PAGE_DOWN:
				if (modo == FLY)
				{
					beta = beta - 10.0;
					if (beta > 360.0) beta = beta - 360.0;
					iy = oy + PASO * sin(grad2rad(beta));
				}
				break;

			case GLUT_KEY_PAGE_UP:
				if (modo == FLY)
				{
					beta = beta + 10.0;
					if (beta > 360.0) beta = beta - 360.0;
					iy = oy + PASO * sin(grad2rad(beta));
				}
				break;
		}

	} else {
		printf("Modo PANORAMICO activado, las acciones de movimiento están inhabilitadas\n");
	}
	
	glutPostRedisplay();
}

/******************************************************************************************/
/* Rutina de definición de eventos														  */
/* Inicia las funciones de callback                                                       */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaFuncionesCallback (void)
{
	glutKeyboardFunc (Teclado);
	glutSpecialFunc (TecladoAmpliado);
}

/******************************************************************************************/
/* Funcion de dibujado                                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Dibuja (void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 
    /* Transformacion de la camara */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if (modo == PAN) { 
		iniciarRecorridoPanoramico();
	} else {
		gluLookAt(ox, oy, oz, ix, iy, iz, 0, 1, 0);
	}
	
	glCallList(escena);
	
	/* Utiliza la funcion de la glut que intercambia los buffers */
	glutSwapBuffers();
}

/******************************************************************************************/
/* Inicia caracteristicas de la visualizacion OpenGL                                      */
/* Parametros: Ninguno.                                                                   */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaOpenGL(void)
{
	/* Establece el color de borrado */
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 

	/* Especifica el tipo de la comparación en el Z-buffer. GL_LESS por defecto */
	glDepthFunc(GL_LESS);

	/* Activa el Z-buffer */
	glEnable(GL_DEPTH_TEST);

	/* Activa la niebla */
	Niebla();
	
	/* Inicia los materiales */
	IniciaMaterial();

	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/* Funcion principal                                                                      */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Un entero que se devuelve al sistema al acabar la ejecucion del programa       */
/******************************************************************************************/
int main(int numArgumentos, char ** listaArgumentos)
{	
	/* Creación de la ventana de la aplicación */
	AbreVentana(numArgumentos, listaArgumentos);

	/* Llamada a las funciones de inicializacion */
	IniciaOpenGL();

	/* Rutinas para el control de eventos */
    IniciaFuncionesCallback();
	
	initTextura0("texturas/brick5b3a.tga");
	initTextura1("texturas/brick3.tga");
	initTextura2("texturas/cielo256.tga");
	initTextura3("texturas/brick2e2.tga");
	initTextura4("texturas/wood.tga");
	initTextura5("texturas/kt_rock_1f_rot_shiny.tga");
	initTextura6("texturas/kt_rock_2.tga");
	initTextura7("texturas/alriver.tga");
	initTextura8("texturas/kt_rot_2.tga");
	initTextura9("texturas/kattex-3-stone.tga");
	initTextura10("texturas/kt_rock_1d.tga");
	initTextura11("texturas/kattex-3-stone3.tga");
	initTextura12("texturas/brick2-2.tga");
	initTextura13("texturas/marble.tga");
	/* Crea las display list de cada cuadrica */
	IniciaDisplayLists();
	
	printf("Modo = FLY\r");

	/* A la espera de eventos.... */
	glutMainLoop();

	return(0);
}
