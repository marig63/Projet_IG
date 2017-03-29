#include "Projet/Tourelle.h"
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
	size = taille;
	rot = rotTete;
	dessineTourelle();
}


Tourelle::~Tourelle()
{
}

void Tourelle::dessineTourelle() {

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
	glPopMatrix();

	glPushMatrix();
	glRotatef(80.0, 0.0f, 0.0f, 1.0f);
	glTranslatef(0.0f, 0.8f*size, -0.3f*size);
	FormeGeometrique::mySolidCylindre(1.5*size, size / 5, 16);
	glTranslatef(0.0f, 0.4f*size, 0.0f);
	FormeGeometrique::mySolidCylindre(size, size / 8, 10);
	glPopMatrix();

	glScalef(size,size, size);
	glScalef(1.3, 0.8, 1.3);
	FormeGeometrique::mySolidCube();
	//glutSolidCube(1.0*size);
	glPopMatrix();
	


	glPopMatrix();
}