#pragma once
class Tir
{
public:
	float avancee = 1;
	int hauteur=5;
	int rayon=1;
public:
	Tir();
	Tir(float av, double h, double r);
	~Tir();
	void dessineTir();
};

