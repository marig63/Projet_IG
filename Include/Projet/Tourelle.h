#pragma once
#include "Tir.h"

class Tourelle
{
private:
	double size;
	double rot;
	Tir t1;
	Tir t2;
	unsigned int *texId;
	

public:
	bool tir = true;

	Tourelle(unsigned int *texId);
	Tourelle(double taille,double rotTete);
	~Tourelle();

	void dessineTourelle(double taille, double rotTete, float avanceeTir);
	void tirer();
};

