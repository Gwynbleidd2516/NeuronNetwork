#pragma once

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include"Neuron.h"
using namespace std;

#define DEFOULT_LEARN 0.1

class NeuronNetwork
{
private:
	vector<double> inputData;
	vector<Neuron> layer1;
	vector<Neuron> layer2;
	vector<Neuron> layer3;
	vector<Neuron> outputNeuron;
	vector<double> outputData;
	bool bias;
	double studySpeed;
	double moment;
	Neuron::Function type;
	vector<double> sinops1;
	vector<double> sinops2;
	vector<double> sinops3;
	vector<double> sinopsOutput;

public:
	NeuronNetwork();

	NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func = Neuron::SIGM);

	NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func = Neuron::SIGM);

	NeuronNetwork(int inputDataCapasity, int layer1Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func = Neuron::SIGM);

	void setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func = Neuron::SIGM);

	void setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func = Neuron::SIGM);

	void setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func = Neuron::SIGM);

	double learn(double inputData[], double outputData[]);
};