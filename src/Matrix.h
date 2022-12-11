#pragma once

#include"Neuron.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class Matrix
{
private:
	int cols = 2;
	int rows = 2;
	bool matrix[16];
	Neuron::Function type;
	bool vertical;
	bool gorizontal;

public:
	Matrix(Neuron::Function Type = Neuron::SIGM);

	void learn();

	void play();

	bool getVertical() { return vertical; };

	bool getGorizontal() { return gorizontal; };
};