#pragma once
#include "Tir.h"

class X_wing
{
public:
	float r;
	Tir t1;
	Tir t2;
	bool tir = true;

	X_wing();
	~X_wing();

	void modelise(double posX,double posY,double posZ);
	void base();
	void reacteur();
	void aile();
	void canon();
	void cockpit();
	void tirer();
};

