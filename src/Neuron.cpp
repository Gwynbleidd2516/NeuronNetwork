#include "Neuron.h"

Neuron::Neuron(double value, Function function)
{
    func = function;
	this->value = value;
	switch (func)
	{
	case Neuron::SIGM:
		ActivatedValue = 1 / (1 + pow(e, -value));
		break;
	case Neuron::TAHN:
		ActivatedValue = (pow(e,value)-pow(e,-value))/(pow(e,value)+pow(e,-value));
		break;
	case Neuron::RELU:
		ActivatedValue = fmax(0, value);
		break;
	}
}

Neuron::Neuron()
{
}

void Neuron::setValue(double value, Function function)
{
	func = function;
	this->value = value;
	switch (func)
	{
	case Neuron::SIGM:
		ActivatedValue = 1 / (1 + pow(e, -value));
		break;
	case Neuron::TAHN:
		ActivatedValue = (pow(e,value)-pow(e,-value))/(pow(e,value)+pow(e,-value));
		break;
	case Neuron::RELU:
		ActivatedValue = fmax(0, value);
		break;
	}
}

double Neuron::getValue()
{
	return value;
}

double Neuron::getActivatedValue()
{
	return ActivatedValue;
}

double Neuron::getDerivedValue()
{
	switch (func)
	{
	case Neuron::SIGM:
		return ActivatedValue * (1 - ActivatedValue);
		break;
	case Neuron::TAHN:
		return 1/pow(((pow(e,value)+pow(e,-value)))/2,2);
		break;
	case Neuron::RELU:
		if (value > 0)
			return 1;
		else
			return 0;
		break;
	}
}

void Neuron::operator=(Neuron& neuron)
{
	this->value=neuron.value;
	this->func=neuron.func;
}