#include <stdio.h>
#include "glut.h"
#include "material.h"


/********************** RUTINA DE INICIO **************************************************/
/******************************************************************************************/
/* Inicia OpenGL para poder definir las propiedades de los materiales                     */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaMaterial(void)
{
	glColorMaterial(GL_FRONT, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

/*********************** DEFINICION DE MATERIALES *****************************************/
/******************************************************************************************/
/* Define las propiedades del material cobre                                              */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Cobre(void) {

	GLfloat material_Ka[] = { 0.33,0.26,0.23,1.0 };
	GLfloat material_Kd[] = { 0.5,0.11,0.0,1.0 };
	GLfloat material_Ks[] = { 0.95,0.73,0.0,1.0 };
	GLfloat material_Se[] = { 93.0 };

	glMaterialfv(GL_FRONT, GL_AMBIENT, material_Ka);
	glColor3fv(material_Kd);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_Ks);
	glMaterialfv(GL_FRONT, GL_SHININESS, material_Se);
}

/*********************** ESPECIFICACIÓN DE TEXTURAS****************************************/
/******************************************************************************************/
/* Lee una imagen de textura en formato tga                                               */
/* Parametros --> char *fichero : Cadena de caracteres con el nombre del fichero          */
/*				  int num: Numero que identifica la textura                               */
/* Salido --> Ninguna                                                                     */
/******************************************************************************************/
void leerTextura(char *fichero, int num)
{
	int   i, j;
	char  r, g, b, c;
	FILE  *tga;

	/* Apertura del fichero TGA */
	if ((tga = fopen(fichero, "rb")) == NULL)
		printf("Error abriendo el fichero: %s\n", fichero);
	else
	{
		/* Lee los 18 primeros caracteres de la cabecera */
		for (j = 1; j <= 18; j++)
			fscanf(tga, "%c", &c);

		/* Lee la imagen */
		for (j = altoTextura - 1; j >= 0; j--)
		{
			for (i = anchoTextura - 1; i >= 0; i--)
			{
				fscanf(tga, "%c%c%c", &b, &g, &r);
				textura[num][j][i][0] = (GLubyte)r;
				textura[num][j][i][1] = (GLubyte)g;
				textura[num][j][i][2] = (GLubyte)b;
			}
		}
		fclose(tga);   /* Cierre del fichero TGA */
	}
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura0(char *fichero)
{
	leerTextura(fichero, 0);
}

/******************************************************************************************/
/******************************************************************************************/
void textura0(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);

}

/******************************************************************************************/
/******************************************************************************************/
void initTextura1(char *fichero)
{
	leerTextura(fichero, 1);
}

/******************************************************************************************/
/******************************************************************************************/
void textura1(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[1]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);

}

/******************************************************************************************/
/******************************************************************************************/
void initTextura2(char *fichero)
{
	leerTextura(fichero, 2);
}

/******************************************************************************************/
/******************************************************************************************/
void textura2(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[2]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura3(char *fichero)
{
	leerTextura(fichero, 3);
}

/******************************************************************************************/
/******************************************************************************************/
void textura3(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[3]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura4(char *fichero)
{
	leerTextura(fichero, 4);
}

/******************************************************************************************/
/******************************************************************************************/
void textura4(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[4]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura5(char *fichero)
{
	leerTextura(fichero, 5);
}

/******************************************************************************************/
/******************************************************************************************/
void textura5(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[5]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura6(char *fichero)
{
	leerTextura(fichero, 6);
}

/******************************************************************************************/
/******************************************************************************************/
void textura6(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[6]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura7(char *fichero)
{
	leerTextura(fichero, 7);
}

/******************************************************************************************/
/******************************************************************************************/
void textura7(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[7]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura8(char *fichero)
{
	leerTextura(fichero, 8);
}

/******************************************************************************************/
/******************************************************************************************/
void textura8(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[8]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura9(char *fichero)
{
	leerTextura(fichero, 9);
}

/******************************************************************************************/
/******************************************************************************************/
void textura9(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[9]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura10(char *fichero)
{
	leerTextura(fichero, 10);
}

/******************************************************************************************/
/******************************************************************************************/
void textura10(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[10]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura11(char *fichero)
{
	leerTextura(fichero, 11);
}

/******************************************************************************************/
/******************************************************************************************/
void textura11(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[11]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura12(char *fichero)
{
	leerTextura(fichero, 12);
}

/******************************************************************************************/
/******************************************************************************************/
void textura12(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[12]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}

/******************************************************************************************/
/******************************************************************************************/
void initTextura13(char *fichero)
{
	leerTextura(fichero, 13);
}

/******************************************************************************************/
/******************************************************************************************/
void textura13(void)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, anchoTextura, altoTextura, 0, GL_RGB, GL_UNSIGNED_BYTE, textura[13]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
}