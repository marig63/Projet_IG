#include <stdlib.h>
#include <stdio.h>


static const int nbSphereExplo = 100;

class EtoileNoir
{
private:
	double posX, posY, posZ;

public:

	EtoileNoir(double posX, double posY, double posZ);
	~EtoileNoir();
	void dessineEtoile();
	void destructionEtoile(double diametreTorus,double depla);

};