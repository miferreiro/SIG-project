#include "glut.h"

/******************************************************************************************/
/* Define y activa la niebla                                                              */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Niebla(void)
{
	GLfloat color_de_niebla[4] = { 1.0f, 1.0f, 1.0f, 0.7f };
	glFogfv(GL_FOG_COLOR, color_de_niebla);

	glFogi(GL_FOG_MODE, GL_EXP);

	glFogf(GL_FOG_DENSITY, 0.002f); 
	glFogf(GL_FOG_START, 20.0f);
	glFogf(GL_FOG_END, 70.0f);
	glHint(GL_FOG_HINT, GL_NICEST);

	glEnable(GL_FOG);

}