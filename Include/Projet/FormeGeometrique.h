#pragma once
class FormeGeometrique
{
public:
	FormeGeometrique();
	~FormeGeometrique();

	static void mySolidCylindre(double hauteur, double rayon, int ns);
	static void myDemiCylindre(double hauteur, double rayon, int ns);
	static void mySolidCube();
	static void mySolidSphere(float rayon, int nlat, int nlon);
	static void mySolidTorus(double r, double c, int rSeg, int cSeg);
};

