#pragma once
class Trench
{
public:
	float r;
	int nbFichiers;
	char **images;
	unsigned int *texId;

	Trench(int nbFichiers, char **images,float position, float cam);
	Trench();
	~Trench();


	void Trench::addPos(float val);
	void modelise(float p);
	void Base1();
	void Ensemble1(float position);
	void tourelle(int ind);
};

