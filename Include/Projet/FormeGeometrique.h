#pragma once
class FormeGeometrique
{
public:
	FormeGeometrique();
	~FormeGeometrique();

	static void mySolidCylindre(double hauteur, double rayon, int ns);
	static void myDemiCylindre(double hauteur, double rayon, int ns);
};

