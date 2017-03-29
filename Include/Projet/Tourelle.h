#pragma once
class Tourelle
{
private:
	double size;
	double rot;

public:

	Tourelle();
	Tourelle(double taille,double rotTete);
	~Tourelle();

	void dessineTourelle();
};

