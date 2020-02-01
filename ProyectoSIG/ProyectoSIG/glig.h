#ifndef GLIG_H
#define GLIG_H

/* Devuelve la coordenada x de un punto en R3 a partir de un punto (u,v) */
float xSuperQuadric(float u, float v, float R, float s1, float s2);
/* Devuelve la coordenada y de un punto en R3 a partir de un punto (u,v) */
float ySuperQuadric(float u, float v, float R, float s1, float s2);
/* Devuelve la coordenada z de un punto en R3 a partir de un punto (u,v) */
float zSuperQuadric(float u, float v, float R, float s1, float s2);
/* Calcula la variacion en x para un incremento de u, derivada de x con respecto de u */
float dxuSuperQuadric(float u, float v, float R, float s1, float s2);
/* Calcula la variacion en y para un incremento de u, derivada de y con respecto de u */
float dyuSuperQuadric(float u, float v, float R, float s1, float s2);
/* Calcula la variacion en z para un incremento de u, derivada de z con respecto de u */
float dzuSuperQuadric(float u, float v, float R, float s1, float s2);
/* Calcula la variacion en x para un incremento de v, derivada de x con respecto de v */
float dxvSuperQuadric(float u, float v, float R, float s1, float s2);
/* Calcula la variacion en y para un incremento de u, derivada de y con respecto de v */
float dyvSuperQuadric(float u, float v, float R, float s1, float s2);
/* Calcula la variacion en z para un incremento de u, derivada de z con respecto de v */
float dzvSuperQuadric(float u, float v, float R, float s1, float s2);
/* Calcula la componente x del vector normal a la supercuadrica en (u,v) */
float nxSuperQuadric(float u, float v, float R, float s1, float s2);
/* Calcula la componente y del vector normal a la supercuadrica en (u,v) */
float nySuperQuadric(float u, float v, float R, float s1, float s2);
/* Calcula la componente z del vector normal a la supercuadrica en (u,v) */
float nzSuperQuadric(float u, float v, float R, float s1, float s2);
/* Crea una cuadrica segun los parametros que se le pasan */
void igCreateSolidQuadricObject(int pu, int pv, float uMax, float vMax, float R, float s1, float s2);
/* Crea un rulo a partir de las ecuaciones de la supercuadrica */
void igSolidRulo(int pu, int pv);
/* Crea una semiesfera a partir de las ecuaciones de la supercuadrica */
void igSolidSemiSphere(int pu, int pv);
/* Crea un cono a partir de las ecuaciones de la supercuadrica */
void igSolidCone(int pu, int pv);
/* Dibuja un cubo de arista unidad y centrado en el origen */
void igSolidCube(void);
/* Crea un cilindro a partir de las ecuaciones de la supercuadrica */
void igSolidCilindro(int pu, int pv);
/* Dibuja un cubo con las coordenadas de textura indicadas  de arista unidad y centrado en el origen */
void igSolidCubeTexture(void);
/* Dibuja una piramide cuadrada con las coordenadas de textura indicadas */
void igSolidPiramideCuadrada(void);

#endif