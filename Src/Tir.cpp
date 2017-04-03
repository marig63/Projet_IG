#include "Projet\Tir.h"
#include "Projet\FormeGeometrique.h"
#include <GL/glut.h>

#include <GL/gl.h>
#include <GL/glu.h>


Tir::Tir()
{
	
}

Tir::Tir(float av, double h, double r) {
	avancee = av;
	hauteur = h;
	rayon = r;
}


Tir::~Tir()
{
}


void Tir::dessineTir() {
	

	glPushMatrix();
	//glRotatef(0.0, dir[0], dir[0], dir[1]);
	glTranslatef(0.0f, avancee, 0.0f);
	FormeGeometrique::mySolidCylindre(hauteur,rayon, 16);

	glPopMatrix();


}