#include <stdlib.h>
#include <stdio.h>


static const int nbSphereExplo = 100;

class EtoileNoir
{
private:
	double posX, posY, posZ;
	int nbFichiers;
	char **images;
	unsigned int *texId;

public:

	EtoileNoir(int nbFichiers, char **images,double posX, double posY, double posZ);
	EtoileNoir();
	~EtoileNoir();
	void dessineEtoile();
	void destructionEtoile(double diametreTorus,double depla);

};