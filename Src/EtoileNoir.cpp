#include "Projet\EtoileNoir.h"
#include "Projet\FormeGeometrique.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>


EtoileNoir::EtoileNoir() {
	double equ3[] = { 0.0F,-4.0F,-8.0F,87.5F };
	double equ2[] = { 0.0F,-4.0F,-8.0F,84.0F };
	//plan pour la demi sphere haute 
	double equ[] = {0.0F,1.0F,0.0F,-0.3F};
	double equ4[] = { 0.0F,-4.0F,-8.0F,81.0F };
	glPushMatrix();

	glClipPlane(GL_CLIP_PLANE0,equ);
	glClipPlane(GL_CLIP_PLANE3, equ3);
	//demi sphere haute
	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE3);
	glutSolidSphere(10.0F,36.0F,36.0F);
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
	glTranslatef(0.0F,5.0F,11.0F);
	glutSolidSphere(4.0F,36.0F,36.0F);
	glDisable(GL_CLIP_PLANE2);
	glPopMatrix();

}

EtoileNoir::~EtoileNoir() {


}