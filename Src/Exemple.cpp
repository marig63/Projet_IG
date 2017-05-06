/* Une animation en OpenGL                      */
/*                                              */
/* Auteur: Nicolas JANEY                        */
/* nicolas.janey@univ-fcomte.fr                 */
/* Septembre 2012                               */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "Projet\FormeGeometrique.h"
#include "Projet\X_wing.h"
#include "Projet\Tourelle.h"
#include "Projet\EtoileNoir.h"
#include "Projet\Tir.h"
#include "Projet\Trench.h"
#include "PNG\ChargePngFile.h"

/* Variables et constantes globales             */
/* pour les angles et les couleurs utilises     */

static float r0 = 0.0F;
static float r1 = 0.0F;

static float r2 = 0.0F;
static float r3 = 0.0F;
static float testplusajour;
static float r4 = 0.0F;
static float r5 = 0.0F;
static const float blanc[] = { 1.0F,1.0F,1.0F,1.0F };

static const float noir[] = { 0.0F,0.0F,0.0F,1.0F };
static const float gris[] = { 0.2F,0.2F,0.2F,1.0F };
static const float jaune[] = { 1.0F,1.0F,0.0F,1.0F };
static const float rouge[] = { 1.0F,0.0F,0.0F,1.0F };
static const float vert[] = { 0.0F,1.0F,0.0F,1.0F };
static const float bleu[] = { 0.0F,0.0F,1.0F,1.0F };

static float diametreTorus = 10.0F;
static int destructionOn = 0;
static int animOn = 0;
static float attenteExplo = 0.0f;
static float deplaSphereExplo = 0.0F;
static int changementCam = 0;
static double posXwingX = 0.0;
static double posXwingY = 0.0;
static double posYMax = 4.0;
static double posXMax = 10.0;
static double rotateEtoile = 0.0F;

static float cam = 20.0f;
Trench tr = Trench();
X_wing wing = X_wing();
EtoileNoir etoile = EtoileNoir();


int rx, ry;
GLfloat l_pos[] = { 1.0,1.0,1.0,0.0 };
/* Fonction d'initialisation des parametres     */
/* OpenGL ne changeant pas au cours de la vie   */
/* du programme                                 */



void init(void) {/*
  const GLfloat shininess[] = { 50.0 };
  glMaterialfv(GL_FRONT,GL_SPECULAR,blanc);
  glMaterialfv(GL_FRONT,GL_SHININESS,shininess);
  GLfloat no_mat[] = { 0.0F,0.0F,0.0F,1.0F };
  GLfloat mat_diffuse[] = { 0.1F,0.5F,0.8F,1.0F };
  GLfloat no_shininess[] = { 0.0F };
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, no_mat);
  //glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blanc);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, no_mat);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, no_shininess);
  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_mat);
  glLightfv(GL_LIGHT0,GL_DIFFUSE,blanc);
  glLightfv(GL_LIGHT1,GL_DIFFUSE,bleu);
  glLightfv(GL_LIGHT2, GL_DIFFUSE,rouge);
  //glLightfv(GL_LIGHT2,GL_DIFFUSE,bleu);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  //glEnable(GL_LIGHT1);
  //glEnable(GL_LIGHT2);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  glEnable(GL_AUTO_NORMAL);*/

	GLfloat l_pos[] = { 1.0,1.0,1.0,0.0 };
	const GLfloat shininess[] = { 50.0 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, blanc);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, l_pos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, blanc);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, blanc);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, bleu);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHT2);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_AUTO_NORMAL);

  /*
  GLfloat pos[] = { 0.0F,0.0F,-1.0F,0.0F };
  GLfloat shininess[] = { 50.0F };
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glLightfv(GL_LIGHT0, GL_AMBIENT, gris);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, blanc);
  glMaterialfv(GL_FRONT, GL_SPECULAR, blanc);
  glMaterialfv(GL_FRONT, GL_SHININESS, shininess);*/


  char* fichiers[6] = { "M1.png","M2.png","M3.png","M4.png","M5.png","M6.png" };
  


  tr = Trench(6,fichiers,cam + 10, cam);
  wing = X_wing(6, fichiers);
  etoile = EtoileNoir(6, fichiers,0.0, 0.0, 0.0);

}

/* Scene dessinee                               */
void scene(void) {
  glPushMatrix();


  if (animOn == 0) {
	  //glRotatef(90.0F,0.0F,1.0F,0.0F);
	  glRotatef(r0, 0.0F, 1.0F, 0.0F);
	  glRotatef(r1, 1.0F, 0.0F, 0.0F);

	  //Positionnement du x-wing
	  glPushMatrix();

	  glEnable(GL_LIGHT1);
	  glLightfv(GL_LIGHT0, GL_POSITION, l_pos);
	  glRotatef(180.0F, 0.0F, 1.0F, 0.0F);
	  glTranslatef(0.0F, 10.0F, 0.0F);
	  wing.modelise(posXwingX, posXwingY, cam);
	  glDisable(GL_LIGHT1);
	  
	  glPopMatrix();

	  tr.modelise(20);

  }

  

  if (destructionOn == 0 && animOn == 1) {
	  glPushMatrix();
	  glLightfv(GL_LIGHT0, GL_POSITION, l_pos);
	  glScalef(1.6F,1.6F,1.6F);
	  glRotatef(rotateEtoile,0.0F,1.0F,0.0F);
	  etoile.dessineEtoile();
	  glPopMatrix();
  }
  else {
	  //  etoile.dessineEtoile();
	  etoile.destructionEtoile(diametreTorus, deplaSphereExplo);
  }


  glPopMatrix();

}

/* Fonction executee lors d'un rafraichissement */
/* de la fenetre de dessin                      */

void display(void) {
  //printf("D\n");
  glClearColor(0.5F,0.5F,0.5F,0.5F);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  const GLfloat light0_position[] = { 100.0,100.0,100.0,1.0 };
  const GLfloat light1_position[] = { -1.0,1.0,1.0,0.0 };
  const GLfloat light2_position[] = { 1.0,-1.0,1.0,0.0 };
  glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
  glLightfv(GL_LIGHT1,GL_POSITION,light1_position);
  glLightfv(GL_LIGHT2,GL_POSITION,light2_position);
  glPushMatrix();

  if (changementCam == 0) {
	  //camera troisieme personne 
	  gluLookAt(0.0, 20.0, cam + 20, 0.0, 0.0, cam - 20, 0.0, 1.0, 0.0);
  } else {
	  //camera 1er personne
	  gluLookAt(-posXwingX, posXwingY+13.0 , cam - 2, -posXwingX, posXwingY + 13.0, cam - 30, 0.0, 1.0, 0.0);
  }
  //camera vu etoile noir pour destruction
  //gluLookAt(0.0, 20.0, -80.0, 0.0, 0.0, 20.0, 0.0, 1.0, 0.0);
  scene();
  glPopMatrix();
  glFlush();
  glutSwapBuffers();
  int error = glGetError();
  if ( error != GL_NO_ERROR )
    printf("Attention erreur %d\n",error);
}

/* Fonction executee lorsqu'aucun evenement     */
/* n'est en file d'attente                      */

void idle(void) {
  //printf("I\n");
  //r0 += 0.3355F;
  //r1 += 0.6117F;
  r2 += 0.4174F;
  r3 += 0.5715F;
  r4 += 0.3333f;
  //r5 += 1.5f;
  if (tr.r > 300) { tr.r = 0.0f; }
  else { tr.r += 8.0f; }

  if (r5 > 300) { r5 = 0.0f; wing.r = r5; }
  else { r5 += 8.0f; wing.r = r5; }

  if (cam <= -2000) {
	  animOn = 1;
	  cam = 20.0f;
	  changementCam = 0;
  }

  if (cam < -1800) {
	  wing.tir = true;
  }

  if (animOn == 1) {
	  rotateEtoile += 0.1F;
	  attenteExplo += 1.0f;
  }

  if (attenteExplo >= 500.0f) {
	  destructionOn = 1;
  }

  if (destructionOn == 1) {
	  diametreTorus += 0.1;
	  deplaSphereExplo += 0.01;
  }

  if (animOn == 0) {
	  cam = cam - 2;
  }
  tr.addPos(2);
  glutPostRedisplay();

}

/* Fonction executee lors d'un changement       */
/* de la taille de la fenetre OpenGL            */

void reshape(int x,int y) {
  //printf("R\n");
  glViewport(0,0,x,y); 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(80.0F,(float) x/y,1.0,400.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //gluLookAt(0.0,0.0,20.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

/* Fonction executee lors de l'appui            */
/* d'une touche alphanumerique du clavier       */

void keyboard(unsigned char key,int x,int y) {
  switch (key) {
  case 0x0D:
  { static int anim = 1;
  anim = !anim;
  glutIdleFunc((anim) ? idle : NULL); }
  break;
  case 0x1B:
	  exit(0);

  case 'd':
	  if (-posXMax < posXwingX) {
		  posXwingX--;
	  }
	  break;

  case 'q':
	  if (posXMax > posXwingX) {
		  posXwingX++;
	  }
	  break;

  case 's':
	  if (-posYMax < posXwingY) {
		  posXwingY--;
	  }
	  break;

  case 'z':
	  if (posYMax > posXwingY) {
		  posXwingY++;
	  }
	  break;
  case 't':
	  r5 = 0.0f;
	  break;
  case 'k':
	  destructionOn = 1;
	  cam = 0.0;
	  break;
  case 'l':
	  //destructionOn = 0;
	  //diametreTorus = 10.0;
	  break;

  case 'c':
	  if (changementCam == 0) {
		  changementCam = 1;
	  } else {
		  changementCam = 0;
	  }
	  break;
  }
}

/* Fonction principale                          */

int main(int argc,char **argv) {
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
  glutInitWindowSize(800,800);
  glutInitWindowPosition(50,50);
  glutCreateWindow("X-wing");

  //img = chargeImagePng("testure.png", &rx, &ry);

  init();
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutIdleFunc(idle);
  glutDisplayFunc(display);
  glutMainLoop();

  //free(img);
  return(0);
}
