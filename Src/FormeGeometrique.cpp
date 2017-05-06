#include "Projet\FormeGeometrique.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <math.h>

static float M_PI = 3.141592;
FormeGeometrique::FormeGeometrique()
{
}


FormeGeometrique::~FormeGeometrique()
{
}

void FormeGeometrique::mySolidCylindre(double hauteur, double rayon, int ns) {
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
		glTexCoord2f(0.0f, 1.0f);
		glNormal3f(cs, 0.0F, sn);
		float x = rayon*cs;
		float z = rayon*sn;
		glTexCoord2f(1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x, hauteur, z);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x, -hauteur, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= ns; i++) {
		float a = (2 * M_PI *i) / ns;
		float cs = cos(a);
		float sn = -sin(a);


		glTexCoord2f(cs, sn);

		glNormal3f(cs, 0.0F, sn);
		float x = rayon*cs;
		float z = rayon*sn;

		float tcs = cs * 0.5 + 0.5;
		float tsn = sn * 0.5 + 0.5;

		glTexCoord2f(tcs, tsn);

		glVertex3f(x, hauteur, z);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i <= ns; i++) {
		float a = (2 * M_PI *i) / ns;
		float cs = cos(a);
		float sn = -sin(a);

		glTexCoord2f(cs, sn);
		glNormal3f(cs, 0.0F, sn);
		float x = rayon*cs;
		float z = rayon*sn;


		float tcs = cs * 0.5 + 0.5;
		float tsn = sn * 0.5 + 0.5;
		glTexCoord2f(tcs, tsn);
		glVertex3f(x, -hauteur, z);
	}
	glEnd();
	glPopMatrix();
	glNormal3f(normale[0], normale[1], normale[2]);
	if (!nm)
		glDisable(GL_NORMALIZE);
}

void FormeGeometrique::myDemiCylindre(double hauteur, double rayon, int ns) {
	GLboolean nm = glIsEnabled(GL_NORMALIZE);
	if (!nm)
		glEnable(GL_NORMALIZE);
	float normale[4];
	glGetFloatv(GL_CURRENT_NORMAL, normale);
	glPushMatrix();
	hauteur /= 2.0F;
	glBegin(GL_QUAD_STRIP);
	for (int i = 0; i <= ns/2; i++) {
		float a = (2 * M_PI *i) / ns;
		float cs = cos(a);
		float sn = -sin(a);
		glTexCoord2f(0.0f, 1.0f);
		glNormal3f(cs, 0.0F, sn);
		float x = rayon*cs;
		float z = rayon*sn;
		glTexCoord2f(1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(x, hauteur, z);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x, -hauteur, z);
	}
	glEnd();
	glPopMatrix();
	glNormal3f(normale[0], normale[1], normale[2]);
	if (!nm)
		glDisable(GL_NORMALIZE);
}

void FormeGeometrique::mySolidCube() {

	glBegin(GL_QUADS);
	// top
	glNormal3f(0.0f, 1.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// front
	glNormal3f(0.0f, 0.0f, 1.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// right
	glNormal3f(1.0f, 0.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, 0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// left
	glNormal3f(-1.0f, 0.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.5f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// bottom
	glNormal3f(0.0f, -1.0f, 0.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5f, -0.5f, 0.5f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.5f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glEnd();

	glBegin(GL_QUADS);
	// back
	glNormal3f(0.0f, 0.0f, -1.0f);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5f, 0.5f, -0.5f);

	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5f, -0.5f, -0.5f);

	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5f, -0.5f, -0.5f);

	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5f, 0.5f, -0.5f);

	glEnd();
}


void FormeGeometrique::mySolidSphere(float rayon, int nlat, int nlon) {
	// http://raphaello.univ-fcomte.fr/ig/Td-Tp/2007-2008-Executables/SphereTexturee.htm
	// cette fonction permet de dessiner une sphere et de prendre en compte les textures

	for (int i = 0; i < nlat; i++) {
		float a1 = -M_PI / 2.0F + i*M_PI / nlat;
		float a2 = a1 + M_PI / nlat;
		float cs1 = cos(a1);
		float cs2 = cos(a2);
		float sn1 = sin(a1);
		float sn2 = sin(a2);
		float t1 = 1.0F - (float)i / nlat;
		float t2 = 1.0F - (float)(i + 1) / nlat;
		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= nlon; j++) {
			float a = j * 2 * M_PI / nlon;
			float x1 = cs1*cos(a);
			float z1 = cs1*sin(a);
			float x2 = cs2*cos(a);
			float z2 = cs2*sin(a);
			float s = 1.0F - (float)j / nlon;
			glTexCoord2f(s, t1);
			glNormal3f(x1, sn1, z1);
			glVertex3f(rayon*x1, rayon*sn1, rayon*z1);
			glTexCoord2f(s, t2);
			glNormal3f(x2, sn2, z2);
			glVertex3f(rayon*x2, rayon*sn2, rayon*z2);
		}
		glEnd();
	}
}

void FormeGeometrique::mySolidTorus(double r , double c ,
	int rSeg, int cSeg)
{
	// https://gist.github.com/gyng/8939105
	// Cette fonction permet de prendre en compte les textures avec un Tore
	glFrontFace(GL_CW);

	//glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	const double PI = 3.1415926535897932384626433832795;
	const double TAU = 2 * PI;

	for (int i = 0; i < rSeg; i++) {
		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= cSeg; j++) {
			for (int k = 0; k <= 1; k++) {
				double s = (i + k) % rSeg + 0.5;
				double t = j % (cSeg + 1);

				double x = (c + r * cos(s * TAU / rSeg)) * cos(t * TAU / cSeg);
				double y = (c + r * cos(s * TAU / rSeg)) * sin(t * TAU / cSeg);
				double z = r * sin(s * TAU / rSeg);

				double u = (i + k) / (float)rSeg;
				double v = t / (float)cSeg;

				glTexCoord2d(u, v);
				glNormal3f(2 * x, 2 * y, 2 * z);
				glVertex3d(2 * x, 2 * y, 2 * z);
			}
		}
		glEnd();
	}

	glFrontFace(GL_CCW);
}
