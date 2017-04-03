#include "Projet/Tourelle.h"
#include "Projet\Tir.h"
#include "Projet\FormeGeometrique.h"
#include <GL/glut.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

Tourelle::Tourelle()
{
	size = 4.0;
	rot = 0.0f;
}

Tourelle::Tourelle(double taille,double rotTete)
{
	//dessineTourelle();
}


Tourelle::~Tourelle()
{
}

void Tourelle::dessineTourelle(double taille, double rotTete,float avanceeTir) {
	size = taille;
	rot = rotTete;

	glPushMatrix();

	
	glPushMatrix();
	glScalef(1.3, 2.0, 1.3);

	glScalef(size, size, size);
	FormeGeometrique::mySolidCube();
	//glutSolidCube(1.0*size);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, (1.5*size)-(0.1*size), 0.0f);
	glRotatef(rot, 0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glRotatef(80.0, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.8f*size, 0.4f*size);
	FormeGeometrique::mySolidCylindre(1.5*size, size / 5, 16);
	glTranslatef(0.0f, 0.4f*size, 0.0f);
	FormeGeometrique::mySolidCylindre(size, size / 8, 10);
	//glRotatef(40.0, 0.0f, 0.0f, 1.0f);
	t1 = Tir(avanceeTir, 7,1);

	if (tir) {
		tirer();
	}

	glPopMatrix();

	glPushMatrix();
	glRotatef(80.0, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.8f*size, -0.3f*size);
	FormeGeometrique::mySolidCylindre(1.5*size, size / 5, 16);
	glTranslatef(0.0f, 0.4f*size, 0.0f);
	FormeGeometrique::mySolidCylindre(size, size / 8, 10);
	//glRotatef(40.0, 0.0f, 0.0f, 1.0f);
	t2 = Tir(avanceeTir,7,1);
	if (tir) {
		tirer();
	}

	glPopMatrix();

	glScalef(size,size, size);
	glScalef(1.3, 0.8, 1.3);
	FormeGeometrique::mySolidCube();
	//glutSolidCube(1.0*size);
	glPopMatrix();
	


	glPopMatrix();

	
}

void Tourelle::tirer() {
	t1.dessineTir();
	t2.dessineTir();

}