#ifndef MATERIAL_H
#define MATERIAL_H

#define anchoTextura 256
#define altoTextura  256
#define numTextura 14

GLubyte textura[numTextura][anchoTextura][altoTextura][3];

/* Inicia OpenGL para poder definir las propiedades de los materiales */
void IniciaMaterial(void);

/* Define las propiedades del material cobre */
void Cobre(void);

/* Lee una imagen de textura en formato tga */
void leerTextura(char *fichero, int num);
void initTextura0(char *fichero);
void textura0(void);
void initTextura1(char *fichero);
void textura1(void);
void initTextura2(char *fichero);
void textura2(void);
void initTextura3(char *fichero);
void textura3(void);
void initTextura4(char *fichero);
void textura4(void);
void initTextura5(char *fichero);
void textura5(void);
void initTextura6(char *fichero);
void textura6(void);
void initTextura7(char *fichero);
void textura7(void);
void initTextura8(char *fichero);
void textura8(void);
void initTextura9(char *fichero);
void textura9(void);
void initTextura10(char *fichero);
void textura10(void);
void initTextura11(char *fichero);
void textura11(void);
void initTextura12(char *fichero);
void textura12(void);
void initTextura13(char *fichero);
void textura13(void);

#endif