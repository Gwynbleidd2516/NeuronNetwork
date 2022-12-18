#pragma once
#include<math.h>
using namespace std;

class Neuron
{
public:

	enum Function
	{
		SIGM,
		TAHN,
		RELU
	};

	Neuron(double value, Function function=SIGM);

	Neuron();

	void setValue(double value, Function function = SIGM);

	double getValue();

	double getActivatedValue();

	double getDerivedValue();

	void operator=(Neuron& neuron);

private:
	double value;
	double ActivatedValue;
	double DerivedValue;
	const double e = 2.718281828459045;
	Function func;
};