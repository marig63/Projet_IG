#pragma once
class Trench
{
public:
	float r;

	Trench(float position, float cam);
	~Trench();


	void Trench::addPos(float val);
	void modelise(float p);
	void Base1();
	void Ensemble1(float position);
	void tourelle(int ind);
};

