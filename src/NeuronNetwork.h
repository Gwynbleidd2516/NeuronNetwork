#pragma once

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<fstream>
#include"Neuron.h"
using namespace std;

#define DEFOULT_LEARN 0

class NeuronNetwork
{
private:
	vector<double> inputData;
	vector<Neuron> layer1;
	vector<Neuron> layer2;
	vector<Neuron> layer3;
	Neuron outputNeuron;
	double outputData;
	bool bias=true;
	double studySpeed;
	double moment;
	Neuron::Function type;
	vector<double> sinops1;
	vector<double> sinops2;
	vector<double> sinops3;
	vector<double> sinopsOutput;
	double error=0;
	vector<double> deltaSinops1;
	vector<double> deltaSinops2;
	vector<double> deltaSinops3;
	vector<double> deltaSinopsOutput;

public:
	NeuronNetwork();

	NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity);

	NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity);

	NeuronNetwork(int inputDataCapasity, int layer1Capasity);

	void setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity);

	void setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity);

	void setNeuronNetwork(int inputDataCapasity, int layer1Capasity);

	void learn(double inputData[], bool outputData, bool Bias, double studySpeed, double moment, double min_error, Neuron::Function func = Neuron::SIGM);

	void saveResults(string path);

	double getError();

	void loadFromFile(string path);

	double run(double inputData[], Neuron::Function func = Neuron::SIGM);
};