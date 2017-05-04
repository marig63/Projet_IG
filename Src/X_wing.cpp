#include "Projet\X_wing.h"
#include "Projet\FormeGeometrique.h"
#include <stdlib.h>

#include "PNG\ChargePngFile.h"
#include "PNG\Image.h"
#include "PNG\PngFile.h"
#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

void X_wing::modelise(double posX,double posY,double posZ){
	glPushMatrix();
	glTranslatef(posX,posY,-posZ);
	base();
	glPopMatrix();
}

X_wing::X_wing(int nbFichiers, char **images) {
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
	r = 0.0f;
	tir = false;
}

X_wing::X_wing() {
	r = 0.0f;
	tir = false;
}


X_wing::~X_wing()
{
}

void X_wing::aile() {
	glBindTexture(GL_TEXTURE_2D, texId[1]);
	glPushMatrix();

	glBegin(GL_POLYGON);
	{
		glVertex3f(-4.0F, 0.4F, -2.0F);
		glVertex3f(4.0F, 0.2F, -1.0F);
		glVertex3f(4.0F, 0.2F, 1.0F);
		glVertex3f(-4.0F, 0.4F, 2.0F);
	}
	{
		glVertex3f(-4.0F, -0.4F, -2.0F);
		glVertex3f(4.0F, -0.2F, -1.0F);
		glVertex3f(4.0F, -0.2F, 1.0F);
		glVertex3f(-4.0F, -0.4F, 2.0F);
	}
	{
		glVertex3f(-4.0F, 0.4F, 2.0F);
		glVertex3f(4.0F, 0.2F, 1.0F);
		glVertex3f(4.0F, -0.2F, 1.0F);
		glVertex3f(-4.0F, -0.4F, 2.0F);
	}
	{
		glVertex3f(-4.0F, 0.4F, -2.0F);
		glVertex3f(4.0F, 0.2F, -1.0F);
		glVertex3f(4.0F, -0.2F, -1.0F);
		glVertex3f(-4.0F, -0.4F, -2.0F);
	}
	{
		glVertex3f(4.0F,0.2F, 1.0F);
		glVertex3f(4.0F, 0.2F, -1.0F);
		glVertex3f(4.0F, -0.2F, -1.0F);
		glVertex3f(4.0F, 0.2F, 1.0F);
	}
	
	glEnd();

	glPopMatrix();
}

void X_wing::reacteur() {
	glBindTexture(GL_TEXTURE_2D, texId[1]);
	glPushMatrix();
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	//avant du réacteur
	FormeGeometrique::mySolidCylindre(2.5F, 1.0F, 36);
	glTranslatef(0.0F, -3.5F, 0.0F);
	glTranslatef(-0.3F, 0.0F, 0.0F);
	glTranslatef(0.0F, 0.0F, -0.3F);
	//arriere du réacteur
	FormeGeometrique::mySolidCylindre(5.0F, 0.6F, 36);
	glPopMatrix();
}

void X_wing::canon(){
	glBindTexture(GL_TEXTURE_2D, texId[1]);
	glPushMatrix();
	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	glTranslatef(0.0F, -0.4F, 0.0F);
	FormeGeometrique::mySolidCylindre(3.0F,0.4F,36);
	glTranslatef(0.0F,3.0F,0.0F);
	FormeGeometrique::mySolidCylindre(4.0F, 0.3F, 36);
	glTranslatef(0.0F, 4.0F, 0.0F);
	FormeGeometrique::mySolidCylindre(4.0F, 0.2F, 36);

	glBindTexture(GL_TEXTURE_2D, texId[0]);
	t1 = Tir(r, 7, 1);

	if (tir) {
		glEnable(GL_LIGHT2);
		tirer();
		glDisable(GL_LIGHT2);
	}

	glBindTexture(GL_TEXTURE_2D, texId[1]);

	glTranslatef(0.0F, 2.4F, 0.0F);

	glPushMatrix();
	glRotatef(-90.0F,1.0F,0.0F,0.0F);
	FormeGeometrique::myDemiCylindre(0.5F, 0.4F, 36);
	glPopMatrix();

	FormeGeometrique::mySolidCylindre(2.0F, 0.1F, 36);
	
	glPopMatrix();
}

void X_wing::tirer() {
	t1.dessineTir();
}

void X_wing::cockpit() {
	glBindTexture(GL_TEXTURE_2D, texId[1]);
	double hauteur = 18.0F;
	double ns = 6.0F;
	double rayon = 2.5F;
	double M_PI = 3.141592;

	glPushMatrix();

	GLboolean nm = glIsEnabled(GL_NORMALIZE);
	if (!nm)
		glEnable(GL_NORMALIZE);
	float normale[4];
	glGetFloatv(GL_CURRENT_NORMAL, normale);
	glPushMatrix();
	hauteur /= 2.0F;
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= ns; i++) {
		float a = (2 * M_PI *i) / ns;
		float cs = cos(a);
		float sn = -sin(a);
		glNormal3f(cs, 0.0F, sn);
		float x = rayon*cs;
		float z = rayon*sn;

		float z1 = rayon / 3 * sn;
		float x1 = rayon / 3 * cs;

		glVertex3f(x1, hauteur, z1);
		glVertex3f(x, -hauteur, z);
	}
	glEnd();
	glPopMatrix();
	glNormal3f(normale[0], normale[1], normale[2]);
	if (!nm)
		glDisable(GL_NORMALIZE);

	//Pointe du  vaisseau
	glTranslatef(0.0F,hauteur+1.0F,0.0F);

	hauteur = 2.0F;
	rayon = rayon/3 +0.1F;

	nm = glIsEnabled(GL_NORMALIZE);
	if (!nm)
		glEnable(GL_NORMALIZE);
	glGetFloatv(GL_CURRENT_NORMAL, normale);
	glPushMatrix();
	hauteur /= 2.0F;
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= ns; i++) {
		float a = (2 * M_PI *i) / ns;
		float cs = cos(a);
		float sn = -sin(a);
		glNormal3f(cs, 0.0F, sn);
		float x = rayon*cs;
		float z = rayon*sn;

		float x1 = 0.01F * cs;
		float z1 = 0.01F * sn;

		glVertex3f(x1, hauteur, z1);
		glVertex3f(x, -hauteur, z);
	}
	glEnd();
	glPopMatrix();
	glNormal3f(normale[0], normale[1], normale[2]);
	if (!nm)
		glDisable(GL_NORMALIZE);

	glPopMatrix();
}

void X_wing::base() {

	glBindTexture(GL_TEXTURE_2D, texId[1]);
	glPushMatrix();

	glScalef(0.8F, 0.8F, 0.8F);
	//création de la base du vaisseau
	glPushMatrix();

	glRotatef(90.0F, 1.0F, 0.0F, 0.0F);
	FormeGeometrique::mySolidCylindre(5.0F,2.5F,6);

	glPopMatrix();

	//1er réacteur
	glPushMatrix();
	glRotatef(30.0F, 0.0F, 0.0F, 1.0F);
	glTranslatef(3.2F, 0.0F, 0.0F);
	glTranslatef(0.0F,0.0F,1.2F);
	reacteur();
	glPopMatrix();

	//2eme réacteur
	glPushMatrix();
	glRotatef(-30.0F, 0.0F, 0.0F, 1.0F);
	glTranslatef(3.2F, 0.0F, 0.0F);
	glTranslatef(0.0F, 0.0F, 1.2F);
	glRotatef(120.0F, 0.0F, 0.0F, 1.0F);
	reacteur();
	glPopMatrix();

	//3eme réacteur
	glPushMatrix();
	glRotatef(150.0F, 0.0F, 0.0F, 1.0F);

	glTranslatef(3.2F, 0.0F, 0.0F);
	glTranslatef(0.0F, 0.0F, 1.2F);

	glRotatef(90.0F, 0.0F, 0.0F, 1.0F);
	reacteur();
	glPopMatrix();

	//4eme réacteur
	glPushMatrix();
	glRotatef(210.0F, 0.0F, 0.0F, 1.0F);

	glTranslatef(3.2F, 0.0F, 0.0F);
	glTranslatef(0.0F, 0.0F, 1.2F);

	glRotatef(-30.0F, 0.0F, 0.0F, 1.0F);
	reacteur();
	glPopMatrix();

	//1er aile
	glPushMatrix();
	glRotatef(30.0F, 0.0F, 0.0F, 1.0F);
	glTranslatef(6.2F,0.0F,0.0F);
	glTranslatef(0.0F, -0.9F, 0.0F);
	aile();
	glTranslatef(3.7F,0.5F,0.0F);
	glRotatef(60.0F, 0.0F, 0.0F, 1.0F);
	canon();
	glPopMatrix();

	//2eme aile
	glPushMatrix();
	glRotatef(-30.0F, 0.0F, 0.0F, 1.0F);
	glTranslatef(6.2F, 0.0F, 0.0F);
	glTranslatef(0.0F, 0.9F, 0.0F);
	aile();
	glTranslatef(3.7F, -0.5F, 0.0F);
	glRotatef(120.0F, 0.0F, 0.0F, 1.0F);
	canon();
	glPopMatrix();

	//3eme aile
	glPushMatrix();
	glRotatef(150.0F, 0.0F, 0.0F, 1.0F);
	glTranslatef(6.2F, 0.0F, 0.0F);
	glTranslatef(0.0F, 0.9F, 0.0F);
	aile();
	glTranslatef(3.7F, -0.5F, 0.0F);
	glRotatef(120.0F, 0.0F, 0.0F, 1.0F);
	canon();
	glPopMatrix();

	//4eme aile
	glPushMatrix();
	glRotatef(210.0F, 0.0F, 0.0F, 1.0F);
	glTranslatef(6.2F, 0.0F, 0.0F);
	glTranslatef(0.0F, -0.9F, 0.0F);
	aile();
	glTranslatef(3.7F, 0.5F, 0.0F);
	glRotatef(60.0F,0.0F,0.0F,1.0F);
	canon();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0F,0.0F,11.0F);
	glRotatef(90.0F,1.0F,0.0F,0.0F );
	cockpit();
	glPopMatrix();


	glPopMatrix();
}
