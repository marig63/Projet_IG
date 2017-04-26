#include "Projet\EtoileNoir.h"
#include "Projet\FormeGeometrique.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <time.h>


EtoileNoir::EtoileNoir(double x,double y,double z) {
	posX = x;
	posY = y;
	posZ = z;
}


void EtoileNoir::dessineEtoile() {
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
	glutSolidSphere(10.0F, 36.0F, 36.0F);
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE3);
	glPopMatrix();

	//sphere central
	glClipPlane(GL_CLIP_PLANE4, equ4);
	glEnable(GL_CLIP_PLANE4);
	glutSolidSphere(9.5F, 36.0F, 36.0F);
	glDisable(GL_CLIP_PLANE4);

	//plan pour la demi-sphere basse
	double equ1[] = { 0.0F,-1.0F,0.0F,-0.3F };
	glClipPlane(GL_CLIP_PLANE1, equ1);

	//demi sphere basse
	glPushMatrix();

	glEnable(GL_CLIP_PLANE1);
	glutSolidSphere(10.0F, 36.0F, 36.0F);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();

	glPopMatrix();


	glClipPlane(GL_CLIP_PLANE2, equ2);

	glPushMatrix();
	glEnable(GL_CLIP_PLANE2);
	glTranslatef(0.0F, 5.0F, 11.0F);
	glutSolidSphere(4.0F, 36.0F, 36.0F);
	glDisable(GL_CLIP_PLANE2);
	glPopMatrix();


}

void EtoileNoir::destructionEtoile(double diametreTorus,double depla) {
	
	glPushMatrix();

	glTranslatef(posX,posY,posZ);

	glPushMatrix();
	glRotatef(90.0F,1.0F,0.0F,0.0F);
	glScalef(diametreTorus, diametreTorus, 5.0F);
	glutSolidTorus(0.1F,1.0,36,36);
	glPopMatrix();

	
	for (int i = 0; i < nbSphereExplo;i++) {
		glPushMatrix();
		//glTranslatef(explosionX[i]+depla,explosionY[i]+depla,explosionZ[i]+depla);
		//glutSolidSphere(0.5,36,36);
		glPopMatrix();
	}
	
	glPopMatrix();
}

EtoileNoir::~EtoileNoir() {


}