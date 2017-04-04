#include "Projet\Trench.h"
#include "Projet\FormeGeometrique.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>

float pos;
float posCam;

Trench::Trench(float position, float cam)
{
	pos = position;
	posCam = cam;
}


Trench::~Trench()
{
}

void Trench::addPos(float val)
{
	pos += val;
	posCam -= val;
}

void Trench::modelise(float p)
{
	printf("pos: %f  pasCam: %f\n", pos, posCam);
	if (pos - posCam <= 170) {
		for (int i = 0; i < 8; i++) {

			Ensemble1(pos - i * 20);
		}
		//on construit le prochain morceau
		if (pos - posCam >= 20) {
			for (int i = 0; i < 8; i++) {

				Ensemble1((pos - 160) - i * 20);
			}
		}
	}
	else {
		pos = posCam + 10;
	}
	
}

void Trench::Ensemble1(float position)
{
	glPushMatrix();
	//glScalef(2.0f, 2.0f, 1.0f);

	glTranslatef(-10.0f, 0.0f,  position);
	Base1();

	glPushMatrix();
	glTranslatef(-19.0f, 20.0f, 0.0f);
	Base1();
	glPopMatrix();

	glTranslatef(20.0f, 0.0f, 0.0f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	Base1();

	glPushMatrix();
	glTranslatef(0.0f, 20.0f, 19.0f);
	Base1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 10.0f, 10.0f);
	glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
	Base1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 10.0f, -30.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	Base1();
	glPopMatrix();



	glPopMatrix();
}

void Trench::Base1()
{

	glPushMatrix();


	glPushMatrix();
	glScalef(20.0f, 2.0f, 20.0f);
	glutSolidCube(1);
	glPopMatrix();
	glTranslatef(0.0f, 1.0f, 0.0f);

	glPushMatrix();
	glTranslatef(-8.0f, 0.0f, -8.0f);
	glutSolidSphere(1, 36, 36);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5f, 0.0f, -8.5f);
	glScalef(3.0f, 1.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5f, 0.0f, -7.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	FormeGeometrique::mySolidCylindre(2.0F, 0.6F, 36);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5f, 0.0f, -5.5f);
	glScalef(3.0f, 1.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-6.5f, 0.0f, -2.0f);
	FormeGeometrique::mySolidCylindre(1.0F, 2.5F, 36);

	glScalef(4.0f, 1.5f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -2.0f);
	glScalef(2.0f, 1.0f, 1.0f);
	glutSolidCube(1);
	glTranslatef(0.0f, 0.0f, -1.5f);
	glutSolidCube(1);
	glTranslatef(0.0f, 0.0f, -1.5f);
	glutSolidCube(1);
	glTranslatef(0.0f, 0.0f, -1.5f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5f, 0.0f, -5.5f);
	glScalef(3.0f, 1.0f, 3.0f);
	glutSolidCube(1);

	glTranslatef(0.2f, 0.1f, -0.2f);
	FormeGeometrique::mySolidCylindre(1.0F, 0.2F, 36);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0f, 0.0f, -9.0f);
	glScalef(3.0f, 2.0f, 2.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5f, 0.0f, -9.0f);
	glScalef(1.0f, 2.0f, 2.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.5f, 0.0f, -7.5f);
	glScalef(3.0f, 3.0f, 3.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(9.0f, 0.0f, -8.5f);
	glScalef(2.0f, 4.0f, 1.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.5f, 0.0f, -2.5f);
	glScalef(3.0f, 1.0f, 5.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.5f, 0.0f, -3.0f);
	glScalef(1.0f, 2.0f, 2.0f);
	glutSolidCube(1);
	glTranslatef(2.0f, 0.0f, 0.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5f, 0.0f, 5.0f);
	glScalef(7.0f, 1.0f, 8.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5f, 0.0f, 5.0f);
	glScalef(3.0f, 2.5f, 6.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5.5f, 0.0f, 4.0f);
	FormeGeometrique::mySolidCylindre(3.0F, 1.5F, 36);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8.0f, 0.0f, 3.5f);
	glScalef(2.0f, 2.5f, 1.0f);
	glutSolidCube(1);
	glTranslatef(0.0f, 0.0f, 2.0f);
	glutSolidCube(1);
	glTranslatef(0.0f, 0.0f, 2.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8.0f, 0.0f, 8.0f);
	glScalef(2.0f, 1.5f, 4.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5f, 0.0f, 9.0f);
	glScalef(3.0f, 1.0f, 2.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-8.0f, 0.0f, 4.0f);
	glScalef(2.0f, 1.0f, 2.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.5f, 0.0f, 4.5f);
	glScalef(3.0f, 1.0f, 3.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5.5f, 0.0f, 4.5f);
	glScalef(1.0f, 1.5f, 2.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5f, 0.0f, 4.5f);
	glScalef(1.0f, 1.5f, 3.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5f, 0.0f, 5.5f);
	glScalef(1.0f, 1.5f, 5.0f);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5f, 0.0f, 3.5f);
	FormeGeometrique::mySolidCylindre(3.0F, 0.5F, 36);
	glTranslatef(0.0f, 0.0f, 4.0f);
	FormeGeometrique::mySolidCylindre(3.0F, 0.5F, 36);
	glPopMatrix();

	glPopMatrix();
}
