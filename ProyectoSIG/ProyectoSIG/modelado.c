/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "glut.h"
#include "glig.h"
#include "modelado.h"
#include "material.h"

/********************** RUTINA DE INICIO **************************************************/
/******************************************************************************************/
/* Inicia OpenGL para poder inicializar las display lists                                 */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaDisplayLists (void)
{
	CreaArco();
	Arbol();
	ArbolConBase();
	Valla();
	Huerto();
	SueloMuro();
	Almena();
	Almenas();
	ParedMuro();
	Torre();
	Estandarte();
	Puesto();
	CrearEscena();
}

/******************************************************************************************/
/* Crea la display list para el arco                                                      */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CreaArco(void)
{
	arco = glGenLists(1);

	if (arco != 0)
	{
		glNewList(arco, GL_COMPILE);
		glPushMatrix();
		glTranslatef(0.75f, 0.0f, 0.0f);
		glScalef(0.5f, 2.0f, 0.5f);
		igSolidCubeTexture();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.75f, 0.0f, 0.0f);
		glScalef(0.5f, 2.0f, 0.5f);
		igSolidCubeTexture();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.0f, 0.75f, 0.0f);
		glScalef(2.0f, 0.5f, 0.5f);
		igSolidCubeTexture();
		glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para un arco.");
}

/******************************************************************************************/
/* Crea la display list para el arbol                                                     */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Arbol(void)
{
	arbol = glGenLists(1);
	if (arbol != 0)
	{
		glNewList(arbol, GL_COMPILE);
		glPushMatrix();
			textura5();
			glTranslatef(0.0f, 8.0f, 0.0f);
			glScalef(6.0f, 8.0f, 6.0f);
			glScalef(0.75f, 1.0f, 0.75f);
			igSolidRulo(10, 10);
			glTranslatef(0.0f, 0.25f, 0.0f);
			glScalef(0.75f, 1.0f, 0.75f);
			igSolidRulo(10, 10);
			glTranslatef(0.0f, 0.25f, 0.0f);
			glScalef(0.75f, 1.0f, 0.75);
			igSolidRulo(10, 10);
			glTranslatef(0.0f, -0.5f, 0.0f);
			glScalef(0.1f, 1.0f, 0.1f);
		glPopMatrix();

		glPushMatrix();
			textura4();
			glTranslatef(0.0f, 0.0f, 0.0f);
			glScalef(10.0f, 4.0f, 10.0f);
			glScalef(0.1f, 1.0f, 0.1f);
			igSolidCubeTexture();
		glPopMatrix();

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos del arbol.");
}

/******************************************************************************************/
/* Crea la display list para el arbol con base                                            */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void ArbolConBase(void)
{
	arbolConBase = glGenLists(1);
	if (arbolConBase != 0)
	{
		glNewList(arbolConBase, GL_COMPILE);
		glPushMatrix();
		textura3();
		glTranslatef(0.0f, 0.25f, 0.0f);
		glScalef(6.0f, 0.5f, 1.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura3();
		glTranslatef(0.0f, 0.25f, -5.0f);
		glScalef(6.0f, 0.5f, 1.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura3();
		glTranslatef(-3.0f, 0.25f, -2.5f);
		glScalef(1.0f, 0.5f, 6.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura3();
		glTranslatef(3.0f, 0.25f, -2.5f);
		glScalef(1.0f, 0.5f, 6.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura9();
		glTranslatef(0.0f, 0.005f, -2.5f);
		glScalef(4.0f, 0.2f, 4.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.0f, 0.0f, -2.5f);
		glCallList(arbol);
		glPopMatrix();

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos del arbol con base.");
}


/******************************************************************************************/
/* Crea la display list para la valla                                                     */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Valla(void)
{
	valla = glGenLists(1);
	if (valla != 0)
	{
		glNewList(valla, GL_COMPILE);

		glPushMatrix();
			glPushMatrix();
				glColor3f(0.651, 0.369, 0.18);
				glTranslatef(0.0f, 0.0f, 0.0f);
				glScalef(0.5f, 3.0f, 0.5f);
				igSolidCube();
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.651, 0.369, 0.18);
				glTranslatef(0.0f, 1.5f, 3.0f);
				glScalef(0.5f, 0.5f, 7.0f);
				igSolidCube();
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.651, 0.369, 0.18);
				glTranslatef(0.0f, 0.0f, 5.5f);
				glScalef(0.5f, 3.0f, 0.5f);
				igSolidCube();
			glPopMatrix();
			glColor3f(1.0f, 1.0f, 1.0f);
		glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos de una valla.");
}

/******************************************************************************************/
/* Crea la display list para el huerto                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Huerto(void)
{
	huerto = glGenLists(1);
	if (huerto != 0)
	{
		glNewList(huerto, GL_COMPILE);
		int i;
		int j;
		int p;
		int x;

		for (j = 0; j < 2; j++) {
			for (i = 0; i < 3; i++) {
				glPushMatrix();
				textura10();
				glTranslatef(i * 28, -1.99f, j * 28);
				glScalef(22.0f, 0.005f, 22.0f);
				igSolidCubeTexture();
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
			}
		}


		float posXvalla[2] = { -13.0f, 70.0f };
		for (i = 0;i < 4;i++) {
			for (j = 0;j < 8;j++) {
				glPushMatrix();
				glTranslatef(posXvalla[i], 1.0f, -12.5 + j * 7);
				glCallList(valla);
				glPopMatrix();
			}
		}


		float posZvalla[2] = { 0.0f, 54.5f };
		for (i = 0;i < 2;i++) {
			for (j = 0;j < 12;j++) {
				glPushMatrix();
				glTranslatef(-13.0f + j * 7, 1.0f, -12.5 + posZvalla[i]);
				glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
				glCallList(valla);
				glPopMatrix();
			}
		}

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos del huerto.");
}

/******************************************************************************************/
/* Crea la display list para el suelo del muro                                            */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void SueloMuro(void)
{
	sueloMuro = glGenLists(1);
	if (sueloMuro != 0)
	{
		glNewList(sueloMuro, GL_COMPILE);
		glPushMatrix();
			textura0();
			glScalef(20.0f, 5.0f, 80.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos del suelo del muro.");
}

/******************************************************************************************/
/* Crea la display list para la almena                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Almena(void)
{
	almena = glGenLists(1);
	if (almena != 0)
	{
		glNewList(almena, GL_COMPILE);

		glPushMatrix();
			glPushMatrix();
				glScalef(3.0f, 3.0f, 5.0f);
				igSolidCubeTexture();
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0f, 1.5f, 0.0f);
				glScalef(1.5f, 2.0f, 2.5f);
				igSolidPiramideCuadrada();
			glPopMatrix();
		glPopMatrix();

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos de una almena.");
}

/******************************************************************************************/
/* Crea la display list para las almenas                                                  */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Almenas(void)
{
	almenas = glGenLists(1);
	if (almenas != 0)
	{
		glNewList(almenas, GL_COMPILE);
		//Almenas
		int i;
		glPushMatrix();

		for (i = 0; i < 16; i++) {
			glPushMatrix();
			if (i % 2)
				textura1();
			else
				textura3();
			glTranslatef(i * 5.0f, 0.0f, 0.0f);
			glCallList(almena);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();

			glPushMatrix();
			if (i % 2)
				textura1();
			else
				textura3();
			glTranslatef(i * 5.0f, 1.5f, 0.0f);
			glCallList(almena);
			glDisable(GL_TEXTURE_2D);
			glPopMatrix();
		}

		glPopMatrix();

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos de una serie de almenas.");
}

/******************************************************************************************/
/* Crea la display list para la pared del muro                                            */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void ParedMuro(void)
{
	paredMuro = glGenLists(1);
	if (paredMuro != 0)
	{
		glNewList(paredMuro, GL_COMPILE);

		glPushMatrix();
		textura1();
		glScalef(5.0f, 30.0f, 80.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos de la pared del muro");

}

/******************************************************************************************/
/* Crea la display list para la torre                                                     */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Torre(void)
{
	torre = glGenLists(1);
	if (torre != 0)
	{
		glNewList(torre, GL_COMPILE);
		//base
		glPushMatrix();
		textura1();
		glScalef(25.0f, 25.0f, 25.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);		
		glPopMatrix();

		//parte de arriba
		glPushMatrix();
			textura1();
			glTranslatef(-11.5f, 22.5f, -9.0f);
			glScalef(2.0f, 20.0f, 7.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura3();
			glTranslatef(-11.5f, 22.5f, -4.0f);
			glScalef(2.0f, 20.0f, 3.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		
		glPushMatrix();
			textura3();
			glTranslatef(-11.5f, 22.5f, 4.0f);
			glScalef(2.0f, 20.0f, 3.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura1();
			glTranslatef(-11.5f, 22.5f, 9.0f);
			glScalef(2.0f, 20.0f, 7.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura3();
			glTranslatef(-4.0f, 22.5f, 11.5f);
			glScalef(3.0f, 20.0f, 2.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura1();
			glTranslatef(-9.0f, 22.5f, 11.5f);
			glScalef(7.0f, 20.0f, 2.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura3();
			glTranslatef(4.0f, 22.5f, 11.5f);
			glScalef(3.0f, 20.0f, 2.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura1();
			glTranslatef(9.0f, 22.5f, 11.5f);
			glScalef(7.0f, 20.0f, 2.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura3();
			glTranslatef(11.5f, 22.5f, 5.0f);
			glScalef(2.0f, 20.0f, 5.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();


		glPushMatrix();
			textura1();
			glTranslatef(11.5f, 22.5f, 10.0f);
			glScalef(2.0f, 20.0f, 5.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura3();
			glTranslatef(-4.0f, 22.5f, -11.5f);
			glScalef(3.0f, 20.0f, 2.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura1();
			glTranslatef(-9.0f, 22.5f, -11.5f);
			glScalef(7.0f, 20.0f, 2.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura3();
		glTranslatef(11.5f, 22.5f, -6.5f);
		glScalef(2.0f, 20.0f, 5.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura1();
			glTranslatef(11.5f, 22.5f, -9.5f);
			glScalef(2.0f, 20.0f, 3.0f);
			igSolidCubeTexture();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura1();
		glTranslatef(11.0f, 22.5f, -11.5f);
		glScalef(3.0f, 20.0f, 2.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura3();
		glTranslatef(8.0f, 22.5f, -11.5f);
		glScalef(3.0f, 20.0f, 2.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		//Ventanas
		glPushMatrix();
		textura3();
		glTranslatef(0.0f, 15.5f, 11.5f);
		glScalef(5.0f, 6.0f, 2.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura3();
		glTranslatef(0.0f, 30.0f, 11.5f);
		glScalef(5.0f, 4.0f, 2.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura3();
		glTranslatef(-11.5f, 15.5f, 0.0f);
		glScalef(2.0f, 6.0f, 5.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura3();
		glTranslatef(-11.5f, 30.0f, 0.0f);
		glScalef(2.0f, 4.0f, 5.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		//puertas
		glPushMatrix();
		textura3();
		glTranslatef(2.0f, 30.0f, -11.5f);
		glScalef(9.0f, 6.0f, 2.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura3();
		glTranslatef(11.5f, 30.0f, -2.0f);
		glScalef(2.0f, 6.0f, 9.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		//Tejado
		glPushMatrix();
		textura12();
		glTranslatef(0.0f, 32.0f, 0.0f);
		glScalef(20.0f, 20.0f, 20.0f);
		igSolidPiramideCuadrada();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos de una torre.");

}

/******************************************************************************************/
/* Crea la display list para el estandarte                                                */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Estandarte(void)
{
	estandarte = glGenLists(1);
	if (estandarte != 0)
	{
		glNewList(estandarte, GL_COMPILE);
		
		glPushMatrix();
			glColor3f(0.357f, 0.227f, 0.161f);
			glBegin(GL_POLYGON);
			glVertex3f(-1.20f, 1.0f, 0.005f);
			glVertex3f(-1.20f, -1.0f, 0.005f);
			glVertex3f(0.0f, -2.0f, 0.005f);
			glVertex3f(1.20f, -1.0f, 0.005f);
			glVertex3f(1.20f, 1.0f, 0.005f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f, 0.502f, 0.0f);
			glBegin(GL_POLYGON);
			glVertex3f(-1.5f, 1.7f, 0.0025f);
			glVertex3f(-1.5f, -4.5f, 0.0025f);
			glVertex3f(0.0f, -3.0f, 0.0025f);
			glVertex3f(1.5f, -4.5f, 0.0025f);
			glVertex3f(1.5f, 1.7f, 0.0025f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f, 0.502f, 0.0f);
			glBegin(GL_POLYGON);
			glVertex3f(1.5f, 1.7f, 0.0025f);
			glVertex3f(1.5f, 2.3f, 0.0025f);
			glVertex3f(0.9f, 2.3f, 0.0025f);
			glVertex3f(0.9f, 1.7f, 0.0025f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f, 0.502f, 0.0f);
			glBegin(GL_POLYGON);
			glVertex3f(0.3f, 1.7f, 0.0025f);
			glVertex3f(0.3f, 2.3f, 0.0025f);
			glVertex3f(-0.3f, 2.3f, 0.0025f);
			glVertex3f(-0.3f, 1.7f, 0.0025f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			glColor3f(1.0f, 0.502f, 0.0f);
			glBegin(GL_POLYGON);
			glVertex3f(-0.9f, 2.3f, 0.0025f);
			glVertex3f(-1.5f, 2.3f, 0.0025f);
			glVertex3f(-1.5f, 1.7f, 0.0025f);
			glVertex3f(-0.9f, 1.7f, 0.0025f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			Cobre();
			glBegin(GL_POLYGON);
			glVertex3f(-1.7f, 1.9f, 0.0f);
			glVertex3f(-1.7f, -4.8f, 0.0f);
			glVertex3f(0.0f, -3.3f, 0.0f);
			glVertex3f(1.7f, -4.8f, 0.0f);
			glVertex3f(1.7f, 1.9f, 0.0f);
			glEnd();
		glPopMatrix();

		glPushMatrix();
			Cobre();
			glBegin(GL_POLYGON);
			glVertex3f(1.7f, 1.7f, 0.0f);
			glVertex3f(1.7f, 2.5f, 0.0f);
			glVertex3f(0.7f, 2.5f, 0.0f);
			glVertex3f(0.7f, 1.7f, 0.0f);
			glEnd();
		glPopMatrix();
		
		glPushMatrix();
			Cobre();
			glBegin(GL_POLYGON);
			glVertex3f(0.5f, 1.7f, 0.0f);
			glVertex3f(0.5f, 2.5f, 0.0f);
			glVertex3f(-0.5f, 2.5f, 0.0f);
			glVertex3f(-0.5f, 1.7f, 0.0f);
			glEnd();
		glPopMatrix();
		
		glPushMatrix();
			Cobre();
			glBegin(GL_POLYGON);
			glVertex3f(-0.7f, 1.7f, 0.0f);
			glVertex3f(-0.7f, 2.5f, 0.0f);
			glVertex3f(-1.7f, 2.5f, 0.0f);
			glVertex3f(-1.7f, 1.7f, 0.0f);
			glEnd();
		glPopMatrix();

		glColor3f(1.0f, 1.0f, 1.0f);

		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos de un estandarte.");
}

/******************************************************************************************/
/* Crea la display list para el puesto                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Puesto(void)
{
	puesto = glGenLists(1);
	if (puesto != 0)
	{
		glNewList(puesto, GL_COMPILE);
		glPushMatrix();
		glPushMatrix();
		textura4();
		glTranslatef(0.0f, 1.5f, 0.0f);
		glScalef(10.0f, 3.0f, 1.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura4();
		glTranslatef(-4.5f, 1.5f, -1.5f);
		glScalef(1.0f, 3.0f, 3.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura4();
		glTranslatef(4.5f, 1.5f, -1.5f);
		glScalef(1.0f, 3.0f, 3.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura4();
		glTranslatef(-4.75f, 5.5f, -0.25f);
		glScalef(0.5f, 5.0f, 0.5f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura4();
		glTranslatef(4.25f, 5.5f, -0.25f);
		glScalef(0.5f, 5.0f, 0.5f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura4();
		glTranslatef(-4.75f, 5.5f, -2.75f);
		glScalef(0.5f, 5.0f, 0.5f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura4();
		glTranslatef(4.25f, 5.5f, -2.75f);
		glScalef(0.5f, 5.0f, 0.5f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura4();
		glTranslatef(0.0f, 8.0f, -1.5f);
		glScalef(12.0f, 1.0f, 5.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
		textura13();
		glTranslatef(3.0f, 3.5f, 0.0f);
		glutSolidTeapot(0.5);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPushMatrix();
			textura13();
			glTranslatef(-2.0f, 3.5f, 0.0f);
			glRotatef(135.0f, 0.0f, 1.0f, 0.0f);
			glutSolidTeapot(0.5);
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();


		glPushMatrix();
			textura13();
			glTranslatef(1.0f, 3.5f, 0.0f);
			glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);
			glutSolidTeapot(0.5);
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();

		glPopMatrix();
		glEndList();
	}
	else puts("Se ha producido un error creando la display list para los elementos de un arbol con base.");
}

/******************************************************************************************/
/* Define el cielo de la escena                                                           */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearCielo(void)
{
	textura2();
	glDepthMask(GL_FALSE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glFrontFace(GL_CCW);
	glTranslatef(50.0, -1.0, -50.0);
	glScalef(200.0, 220.0, 200.0);
	igSolidSemiSphere(40, 40);
	glFrontFace(GL_CW);
	glPopMatrix();
	glDisable(GL_BLEND);
	glDepthMask(GL_TRUE);
}

/******************************************************************************************/
/* Define el terreno de la escena                                                         */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearTerreno(void)
{
	//Terreno debajo del castillo
	glPushMatrix();
	textura6();
	glTranslatef(50.0f, -9.55f, -50.0f);
	glScalef(140.0f, 19.10f, 135.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Terreno Parte delantera
	glPushMatrix();
	textura6();
	glTranslatef(50.0f, -9.55f, 102.0f);
	glScalef(400.0f, 15.0f, 134.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Terreno Parte de atras
	glPushMatrix();
	textura6();
	glTranslatef(50.0f, -9.55f, -198.0f);
	glScalef(400.0f, 15.0f, 120.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Terreno Parte izquieda
	glPushMatrix();
	textura6();
	glTranslatef(-95.0f, -9.55f, -51.5f);//-123
	glScalef(110.0f, 15.0f, 172.999f);//167
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Terreno Parte derecha
	glPushMatrix();
	textura6();
	glTranslatef(195.0f, -9.55f, -51.5f);
	glScalef(110.0f, 15.0f, 173.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Cesped Parte delantera
	glPushMatrix();
	textura8();
	glTranslatef(50.0f, -2.0f, 102.0f);
	glScalef(397.0f, 0.008f, 130.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Cesped Parte trasera
	glPushMatrix();
	textura8();
	glTranslatef(50.0f, -2.0f, -196.0f);
	glScalef(398.0f, 0.008f, 115.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Cesped Parte izquierda
	glPushMatrix();
	textura8();
	glTranslatef(-95.25f, -2.0f, -53.0f);
	glScalef(106.5f, 0.008f, 182.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Cesped Parte derecha
	glPushMatrix();
	textura8();
	glTranslatef(195.25f, -2.0f, -54.0f);
	glScalef(106.5f, 0.008f, 182.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

/******************************************************************************************/
/* Define el foso de la escena                                                            */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearFoso(void)
{
	//agua delante
	glPushMatrix();
	textura7();
	glTranslatef(50.0f, -15.75f, 26.25f);
	glScalef(140.0f, 6.0f, 17.45f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//agua detras
	glPushMatrix();
	textura7();
	glTranslatef(50.0f, -15.75f, -127.5f);
	glScalef(140.0f, 6.0f, 20.9f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//agua izquierda
	glPushMatrix();
	textura7();
	glTranslatef(-30.0f, -15.75f, -51.5f);
	glScalef(19.9f, 6.0f, 172.9f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//agua derecha
	glPushMatrix();
	textura7();
	glTranslatef(130.0f, -15.75, -51.5f);
	glScalef(19.9f, 6.0f, 172.9f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//palos delante y detras
	int i, j, p;
	float x, z, zActual;
	float aux, aux2;
	float initialz[2] = { 27.55f, -125.0f };
	for (p = 0;p < 2;p++) {
		for (j = 0;j < 2;j++) {
			zActual = initialz[p] - (j * 8);

			//srand();
			for (i = 0; i < 43; i++) {
				aux = (float)(rand() % 5);
				aux2 = (float)rand() / (float)RAND_MAX;
				x = 134.0f - (4.0f * i) + (aux2);
				z = zActual + aux;

				//Puerta hierros vertical
				glPushMatrix();
				textura4();
				glTranslatef(x, -13.75f, z);
				glScalef(1.0f, 5.0f, 1.0f);
				igSolidCilindro(30, 30);
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				//picos
				glPushMatrix();
				textura4();
				glTranslatef(x, -8.75f, z);
				glScalef(1.0f, 2.0f, 1.0f);
				igSolidCone(30, 30);
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				aux = -aux;
				aux2 = -aux2;
			}
		}
	}
	//palos derecha y izquierda
	float xActual;
	float initialx[2] = { -27.0f, 133.0f };
	for (p = 0;p < 2;p++) {
		for (j = 0;j < 2;j++) {
			xActual = initialx[p] - (j * 8);

			//srand();
			for (i = 0; i < 35; i++) {
				aux = (float)(rand() % 5);
				aux2 = (float)rand() / (float)RAND_MAX;
				z = 17.0f - (4 * i) + (aux2);
				x = xActual + aux;

				//Puerta hierros vertical
				glPushMatrix();
				textura4();
				glTranslatef(x, -13.75f, z);
				glScalef(1.0f, 5.0f, 1.0f);
				igSolidCilindro(30, 30);
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				//picos
				glPushMatrix();
				textura4();
				glTranslatef(x, -8.75f, z);
				glScalef(1.0f, 2.0f, 1.0f);
				igSolidCone(30, 30);
				glDisable(GL_TEXTURE_2D);
				glPopMatrix();
				aux = -aux;
				aux2 = -aux2;
			}
		}
	}
}

/******************************************************************************************/
/* Define el lado de entrada del castillo de la escena                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearLadoEntrada(void)
{

	//Muro izquierdo exterior
	glPushMatrix();
	textura1();
	glTranslatef(25.0f, 15.0f, 10.0f);
	glRotatef(90.0f, 0.0f, 0.1f, 0.0f);
	glScalef(5.0f, 30.0f, 30.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Muro derecho exterior
	glPushMatrix();
	textura1();
	glTranslatef(75.0f, 15.0f, 10.0);
	glScalef(30.0f, 30.0f, 5.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Muro izquierdo interior
	glPushMatrix();
	textura1();
	glTranslatef(25.0f, 15.0, -10.0f);
	glScalef(30.0f, 30.0f, 5.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Muro derecho interior
	glPushMatrix();
	textura1();
	glTranslatef(75.0f, 15.0f, -10.0f);
	glScalef(30.0f, 30.0f, 5.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Muro encima de la puerta interior
	glPushMatrix();
	textura1();
	glTranslatef(50.0f, 25.0f, 10.0f);
	glScalef(20.0f, 10.0f, 5.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Muro encima de la puerta interior
	glPushMatrix();
	textura1();
	glTranslatef(50.0f, 25.0f, -10.0f);
	glScalef(20.0f, 10.0f, 5.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Arco puerta
	glPushMatrix();
	textura3();
	glTranslatef(50.0f, 10.0f, 2.5f);
	glScalef(10.0f, 10.0f, 60.0f);
	glCallList(arco);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Suelo puerta
	glPushMatrix();
	textura0();
	glTranslatef(50.0f, 0.0f, 2.5f);
	glScalef(10.0f, 0.005f, 30.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	int i;

	for (i = 0; i < 10; i = i + 2) {
		//Puerta hierros vertical
		glPushMatrix();
		textura4();
		glTranslatef(46.0f + i, 11.4f, 0.0f);
		glScalef(1.0f, 7.0f, 1.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		//picos
		glPushMatrix();
		textura4();
		glTranslatef(46.0f + i, 8.05f, 0.0f);
		glScalef(0.7f, 1.0f, 0.7f);
		glRotatef(45.0f, 0.0f, 1.0f, 0.0f);
		igCreateSolidQuadricObject(20, 20, 1.0f, 1.0f, 1.0f, 2.0f, 2.0f);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();

	}
	//Puerta hierros horizontal
	for (i = 0; i < 5; i = i + 2) {
		glPushMatrix();
		textura4();
		glTranslatef(50.0f, 13.0f - i, 0.0f);
		glScalef(10.0f, 0.9f, 0.9f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
}

/******************************************************************************************/
/* Define el puente levadizo de la escena                                                 */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearPuenteLevadizo(void)
{
	//puerta de madera
	glPushMatrix();
	textura4();
	glTranslatef(50.0f, -1.0f, 27.5f);
	glScalef(10.0f, 2.0f, 20.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//suelo cadena izquierda
	glPushMatrix();
	glColor3d(56, 56, 56);
	glTranslatef(46.0f, 0.0f, 30.0f);
	glScalef(1.0f, 0.05f, 1.0f);
	igSolidCube();
	glPopMatrix();
	//pared cadena izquierda
	glPushMatrix();
	glColor3d(56, 56, 56);
	glTranslatef(46.0f, 16.0f, 17.5f);
	glScalef(1.0f, 1.0f, 0.05f);
	igSolidCube();
	glPopMatrix();

	//suelo cadena derecha
	glPushMatrix();
	glColor3d(56, 56, 56);
	glTranslatef(54.0f, 0.0f, 30.0f);
	glScalef(1.0f, 0.05f, 1.0f);
	igSolidCube();
	glPopMatrix();

	//pared cadena izquierda
	glPushMatrix();
	glColor3d(56, 56, 56);
	glTranslatef(54.0f, 16.0f, 17.5f);
	glScalef(1.0f, 1.0f, 0.05f);
	igSolidCube();
	glPopMatrix();
	int i;
	for (i = 0; i < 18; i++) {

		glPushMatrix();
		glColor3d(136, 136, 136);
		glTranslatef(46.0f, 0.0f + (i * 0.9f), 30.0f + (i * -0.7f));
		glRotatef(135.0f, 1.0f, 0.0f, 0.0f);
		glScalef(0.25f, 0.5f, 0.25f);
		glutSolidTorus(0.2f, 0.9f, 30, 30);
		glPopMatrix();

		glPushMatrix();
		glColor3d(136, 136, 136);
		glTranslatef(54.0f, 0.0f + (i * 0.9f), 30.0f + (i * -0.7f));
		glRotatef(135.0f, 1.0f, 0.0f, 0.0f);
		glScalef(0.25f, 0.5f, 0.25f);
		glutSolidTorus(0.2f, 0.9f, 30, 30);
		glPopMatrix();
	}

	int j;
	for (j = 0; j < 18; j++) {
		glPushMatrix();
		glColor3d(136, 136, 136);
		glTranslatef(46.0f, 0.45f + (j * 0.9f), 29.65f + (j * -0.7f));
		glRotatef(135.0f, 1.0f, 0.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(0.25f, 0.5f, 0.25f);
		glutSolidTorus(0.2f, 0.9f, 30, 30);
		glPopMatrix();
		glPushMatrix();
		glColor3d(136, 136, 136);
		glTranslatef(54.0f, 0.45f + (j * 0.9f), 29.65f + (j * -0.7f));
		glRotatef(135.0f, 1.0f, 0.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(0.25f, 0.5f, 0.25f);
		glutSolidTorus(0.2f, 0.9f, 30, 30);
		glPopMatrix();
	}
}

/******************************************************************************************/
/* Define la plaza de la escena                                                           */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearPlaza(void)
{
	//Suelo
	glPushMatrix();
		textura0();
		glTranslatef(50.0f, 0.0f, -50.0f);
		glScalef(75.0f, 0.005f, 75.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	//Puestos
	glPushMatrix();
		glTranslatef(35.0f, 0.0f, -80.0f);
		glCallList(puesto);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(65.0f, 0.0f, -80.0f);
		glCallList(puesto);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(80.0f, 0.0f, -62.0f);
		glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
		glCallList(puesto);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(80.0f, 0.0f, -33.0f);
		glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
		glCallList(puesto);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25.0f, 0.0f, -62.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glCallList(puesto);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(25.0f, 0.0f, -33.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glCallList(puesto);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	//Arboles
	glPushMatrix();
		glTranslatef(17.5f, 0.0f, -17.5f);
		glCallList(arbolConBase);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(17.5f, 0.0f, -45.0f);
		glCallList(arbolConBase);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(17.5f, 0.0f, -73.5f);
		glCallList(arbolConBase);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(83.5f, 0.0f, -17.5f);
		glCallList(arbolConBase);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(83.5f, 0.0f, -45.0f);
		glCallList(arbolConBase);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(83.5f, 0.0f, -73.5f);
		glCallList(arbolConBase);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(50.0f, 0.0f, -80.0f);
		glCallList(arbolConBase);
	glPopMatrix();


	//pozo
	glPushMatrix();
		textura3();
		glTranslatef(50.0f, 0.25f, -50.0f);
		glScalef(10.0f, 0.5f, 10.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura1();
		glTranslatef(50.0f, 1.5f, -48.0f);
		glScalef(5.0f, 3.0f, 1.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura1();
		glTranslatef(50.0f, 1.5f, -52.0f);
		glScalef(5.0f, 3.0f, 1.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura1();
		glTranslatef(52.0f, 1.5f, -50.0f);
		glScalef(1.0f, 3.0f, 5.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura1();
		glTranslatef(48.0f, 1.5f, -50.0f);
		glScalef(1.0f, 3.0f, 5.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura7();
		glTranslatef(50.0f, 1.0f, -50.0f);
		glScalef(3.5f, 2.0f, 3.5f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();



	glPushMatrix();
		textura4();
		glTranslatef(52.0f, 4.0f, -50.0f);
		glScalef(0.5f, 4.0f, 0.5f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura4();
		glTranslatef(48.0f, 4.0f, -50.0f);
		glScalef(0.5f, 4.0f, 0.5f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura4();
		glTranslatef(50.0f, 6.1f, -50.0f);
		glScalef(8.0f, 0.4f, 2.4f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura4();
		glTranslatef(50.0f, 6.8f, -49.2f);
		glRotatef(55.0, 1.0f, 0.0f, 0.0f);
		glScalef(8.2f, 0.1f, 3.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura4();
		glTranslatef(50.0f, 6.8f, -50.8f);
		glRotatef(55.0, -1.0f, 0.0f, 0.0f);
		glScalef(8.2f, 0.1f, 3.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glPushMatrix();
		textura4();
		glTranslatef(54.0f, 6.0f, -50.0f);
		glScalef(0.005f, 2.0f, 1.4f);
		igSolidPiramideCuadrada();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura4();
		glTranslatef(46.0f, 6.0f, -50.0f);
		glScalef(0.005f, 2.0f, 1.4f);
		igSolidPiramideCuadrada();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();



	glPushMatrix();
		textura4();
		glTranslatef(50.0f, 4.0f, -50.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		glScalef(0.25f, 1.6f, 0.25f);
		igSolidCilindro(20,20);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura4();
		glTranslatef(50.5f, 4.0f, -50.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		glScalef(0.15f, 2.6f, 0.15f);
		igSolidCilindro(20, 20);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glPushMatrix();
		textura4();
		glTranslatef(53.0f, 3.5f, -50.0f);
		glScalef(0.1f, 0.8f, 0.1f);
		igSolidCilindro(20, 20);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	glPushMatrix();
		textura4();
		glTranslatef(53.5f, 3.0f, -50.0f);
		glRotatef(90.0f, 0.0f, 0.0f, 1.0f);
		glScalef(0.15f, 0.8f, 0.15f);
		igSolidCilindro(20, 20);
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	int i;
	for (i = 0; i < 10; i++) {
		glPushMatrix();
			glColor3f(0.6, 0.6, 0.6);
			glTranslatef(49.0f + (0.2 * i), 4.0f, -50.0f);
			glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
			glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
			glutSolidTorus(0.1f, 0.25f, 30, 30);
		glPopMatrix();
	}
	glPushMatrix();
		glColor3f(0.6, 0.6, 0.6);
		glTranslatef(50.0f, 2.0f, -50.1f);
		glScalef(0.1f, 2.0f, 0.1f);
		igSolidCilindro(20, 20);
	glPopMatrix();

	glColor3f(1.0f, 1.0f, 1.0f);

}

/******************************************************************************************/
/* Define los bosques de la escena                                                        .*/
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearParedesMuros(void)
{
	//Muro0010I
	glPushMatrix();
		glTranslatef(10.0f, 15.0f, -50.0f);
		glCallList(paredMuro);
	glPopMatrix();

	//Muro0010E
	glPushMatrix();
		glTranslatef(-10.0f, 15.0f, -50.0f);
		glCallList(paredMuro);
	glPopMatrix();
	
	//Muro1011I
	glPushMatrix();
		glTranslatef(50.0f, 15.0f, -90.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glCallList(paredMuro);
	glPopMatrix();

	//Muro1011E
	glPushMatrix();
		glTranslatef(50.0f, 15.0f, -110.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glCallList(paredMuro);
	glPopMatrix();

	//Muro1011I
	glPushMatrix();
		glTranslatef(90.0f, 15.0f, -50.0f);
		glCallList(paredMuro);
	glPopMatrix();

	//Muro1101E
	glPushMatrix();
		glTranslatef(110.0f, 15.0f, -50.0f);
		glCallList(paredMuro);
	glPopMatrix();
}

/******************************************************************************************/
/* Define el cielo de la escena                                                           */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearBosque(void)
{
	int i, j;
	for (j = 0; j < 12;j++) {
		for (i = 0; i < 6;i++) {
			glPushMatrix();
				glTranslatef(-50.0f - (i * 15.0f), 0.0f, 30.0f - (j * 15.0f));
				glCallList(arbol);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(225.0f - (i * 15.0f), 0.0f, 30.0f - (j * 15.0f));
				glCallList(arbol);
			glPopMatrix();
		}
	}
}

/******************************************************************************************/
/* Define el camino de la escena                                                          */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearCamino(void)
{
	glPushMatrix();
	textura9();
	glTranslatef(50.0f, -1.99f, 92.5f);
	glScalef(20.0f, 0.005f, 115.0f);
	igSolidCubeTexture();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	int i, j;
	int x = 37.5;
	for (j = 0; j < 2; j++) {
		for (i = 0; i < 7; i++) {
			glPushMatrix();
			glTranslatef(x, 0.0f, 15.0f * i + 50.0f);
			glCallList(arbol);
			glPopMatrix();
		}
		x = x + 26;
	}
		
	glPushMatrix();
		textura9();
		glTranslatef(50.0f, -1.99f, -200.0f);
		glScalef(20.0f, 0.005f, 100.0f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

/******************************************************************************************/
/* Define los huertos de la escena                                                        */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearHuertos(void)
{
	glPushMatrix();
		glTranslatef(-45.0f, 0.0f, 69.0f);
		glCallList(huerto);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(88.0f, 0.0f, 69.0f);
		glCallList(huerto);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(75.0f, 0.0f, -165.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glCallList(huerto);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-40.0f, 0.0f, -195.0f);
		glCallList(huerto);
	glPopMatrix();

}

/******************************************************************************************/
/* Define el muro exterior del castillo de la escena                                      */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearMuroExterior(void)
{

	glPushMatrix();
		textura11();
		glTranslatef(-1.0f, -2.0f, 36.0f);
		glScalef(82.2f, 24.0f, 2.1f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura11();
		glTranslatef(101.0f, -2.0f, 36.0f);
		glScalef(82.2f, 24.0f, 2.1f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura11();
		glTranslatef(50.0f, -2.0f, -139.0f);
		glScalef(184.1f, 24.0f, 2.1f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura11();
		glTranslatef(-41.0f, -2.0f, -51.5f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(177.2f, 24.0f, 2.1f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();
		textura11();
		glTranslatef(141.0f, -2.0f, -51.5f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glScalef(177.2f, 24.0f, 2.1f);
		igSolidCubeTexture();
		glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	
}

/******************************************************************************************/
/* Define la parte de la arriba del castillo de la escena                                 */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearArribaMuros(void)
{
	//SueloMuro0010
	glPushMatrix();
		glTranslatef(0.0f, 20.0f, -50.0f);
		glCallList(sueloMuro);
	glPopMatrix();

	//SueloMuro1011
	glPushMatrix();
		glTranslatef(50.0f, 20.0f, -100.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glCallList(sueloMuro);
	glPopMatrix();

	//SueloMuro1101
	glPushMatrix();
		glTranslatef(100.0f, 20.0f, -50.0f);
		glCallList(sueloMuro);
	glPopMatrix();

	//SueloMuro0100
	glPushMatrix();
		glTranslatef(50.0f, 21.0f, 0.0f);
		glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
		glCallList(sueloMuro);
	glPopMatrix();

	//Almenas
	glPushMatrix();
		glTranslatef(12.5, 31.5, 10.0);
		glCallList(almenas);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(12.5, 31.5, -10.0);
		glCallList(almenas);
	glPopMatrix();

	glPushMatrix();
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(12.5, 31.5, 10.0);
		glCallList(almenas);
	glPopMatrix();

	glPushMatrix();
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(12.5, 31.5, -10.0);
		glCallList(almenas);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(12.5, 31.5, -90.0);
		glCallList(almenas);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(12.5, 31.5, -110.0);
		glCallList(almenas);
	glPopMatrix();

	glPushMatrix();
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(12.5, 31.5, 90.0);
		glCallList(almenas);
	glPopMatrix();

	glPushMatrix();
		glRotatef(90.0, 0.0, 1.0, 0.0);
		glTranslatef(12.5, 31.5, 110.0);
		glCallList(almenas);
	glPopMatrix();
}

/******************************************************************************************/
/* Define las torres de la escena                                                         */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearTorres(void)
{
	//Torre00
	glPushMatrix();
	glTranslatef(-2.5f, 12.5f, 2.5f);
	glCallList(torre);
	glPopMatrix();

	//Torre10
	glPushMatrix();
	glTranslatef(-2.5f, 12.5f, -102.5f);
	glRotatef(90.0f, 0.0f, -1.0f, 0.0f);
	glCallList(torre);
	glPopMatrix();

	//Torre11
	glPushMatrix();

	glTranslatef(102.5f, 12.5f, -102.5f);
	glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
	glCallList(torre);
	glPopMatrix();

	//Torre01
	glPushMatrix();

	glTranslatef(102.5f, 12.5f, 2.5f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glCallList(torre);
	glPopMatrix();

}

/******************************************************************************************/
/* Define los estandartes de la escena                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearEstandartes(void)
{
	glPushMatrix();
		glTranslatef(45.0, 25.0, 12.6);
		glCallList(estandarte);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(55.0, 25.0, 12.6);
		glCallList(estandarte);
	glPopMatrix();
}

/******************************************************************************************/
/* Crea la display list para la escena                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CrearEscena(void) {

	escena = glGenLists(1);
		
	if (escena != 0)
	{
		glNewList(escena, GL_COMPILE);
		glPushMatrix();

			CrearCielo();
			CrearTerreno();
			CrearFoso();
			CrearPuenteLevadizo();
			CrearLadoEntrada();
			CrearCamino();
			CrearBosque();
			CrearArribaMuros();
			CrearParedesMuros();
			CrearTorres();
			CrearMuroExterior();
			CrearHuertos();
			CrearEstandartes();
			CrearPlaza();
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
		glEndList();
	}
}