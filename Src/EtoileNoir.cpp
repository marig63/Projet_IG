#include "Projet\EtoileNoir.h"
#include "Projet\FormeGeometrique.h"
#include "PNG\ChargePngFile.h"
#include "PNG\Image.h"
#include "PNG\PngFile.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <time.h>

EtoileNoir::EtoileNoir() {
	posX = 0;
	posY = 0;
	posZ = 0;
}

EtoileNoir::EtoileNoir(int nbFichiers, char **images, double x,double y,double z) {

	/* Configuration des textures utilisees */
	glEnable(GL_TEXTURE_2D);
	texId = (unsigned int *)calloc(5, sizeof(unsigned int));
	glGenTextures(5, texId);
	for (int i = 0; i < 5; i++) {
		glBindTexture(GL_TEXTURE_2D, texId[i]);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		int rx;
		int ry;
		unsigned char *img = chargeImagePng(images[i], &rx, &ry);
		if (img) {
			glTexImage2D(GL_TEXTURE_2D, 0, 3, rx, ry, 0, GL_RGB, GL_UNSIGNED_BYTE, img);
			free(img);
		}
	}
	/* Fin configuration des textures       */
	//glDisable(GL_TEXTURE_2D);

	this->images = images;
	this->nbFichiers = nbFichiers;


	posX = x;
	posY = y;
	posZ = z;
}


void EtoileNoir::dessineEtoile() {
	glBindTexture(GL_TEXTURE_2D, texId[2]);
	double equ3[] = { 0.0F,-4.0F,-8.0F,87.5F };
	double equ2[] = { 0.0F,-4.0F,-8.0F,84.0F };
	//plan pour la demi sphere haute 
	double equ[] = { 0.0F,1.0F,0.0F,-0.3F };
	double equ4[] = { 0.0F,-4.0F,-8.0F,81.0F };
	glPushMatrix();

	glTranslatef(posX,posY,posZ);

	glClipPlane(GL_CLIP_PLANE0, equ);
	glClipPlane(GL_CLIP_PLANE3, equ3);
	//demi sphere haute
	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE3);
	FormeGeometrique::mySolidSphere(10.0F, 36.0F, 36.0F);
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE3);
	glPopMatrix();

	//sphere central
	glClipPlane(GL_CLIP_PLANE4, equ4);
	glEnable(GL_CLIP_PLANE4);
	FormeGeometrique::mySolidSphere(9.5F, 36.0F, 36.0F);
	glDisable(GL_CLIP_PLANE4);

	//plan pour la demi-sphere basse
	double equ1[] = { 0.0F,-1.0F,0.0F,-0.3F };
	glClipPlane(GL_CLIP_PLANE1, equ1);

	//demi sphere basse
	glPushMatrix();

	glEnable(GL_CLIP_PLANE1);
	FormeGeometrique::mySolidSphere(10.0F, 36.0F, 36.0F);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();

	glPopMatrix();


	glClipPlane(GL_CLIP_PLANE2, equ2);

	glPushMatrix();
	glEnable(GL_CLIP_PLANE2);
	glTranslatef(0.0F, 5.0F, 11.0F);
	FormeGeometrique::mySolidSphere(4.0F, 36.0F, 36.0F);
	glDisable(GL_CLIP_PLANE2);
	glPopMatrix();


}

void EtoileNoir::destructionEtoile(double diametreTorus,double depla) {
	
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texId[1]);
	glColor3f(1.0f, 1.0f, 0.0f);
	glTranslatef(posX,posY,posZ);

	glPushMatrix();
	glRotatef(90.0F,1.0F,0.0F,0.0F);
	glScalef(diametreTorus, diametreTorus, 5.0F);
	FormeGeometrique::mySolidTorus(0.1F,1.0,36,36);
	glPopMatrix();

	
	for (int i = 0; i < nbSphereExplo;i++) {
		glPushMatrix();
		//glTranslatef(explosionX[i]+depla,explosionY[i]+depla,explosionZ[i]+depla);
		//FormeGeometrique::mySolidSphere(0.5,36,36);
		glPopMatrix();
	}
	glPopMatrix();
}

EtoileNoir::~EtoileNoir() {


}