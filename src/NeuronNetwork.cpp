#include "NeuronNetwork.h"

NeuronNetwork::NeuronNetwork()
{
}

NeuronNetwork::NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func)
{
	inputData.resize(inputDataCapasity);

	outputData.resize(outputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.resize(layer2Capasity);

	layer3.resize(layer3Capasity);
	
	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.resize(layer1Capasity * layer2Capasity);

	sinops3.resize(layer2Capasity * layer3Capasity);

	sinopsOutput.resize(layer3Capasity * outputDataCapasity);

	bias = Bias;
	this->studySpeed = studySpeed;
	this->moment = moment;
	type = func;
}

NeuronNetwork::NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func)
{
	inputData.resize(inputDataCapasity);

	outputData.resize(outputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.resize(layer2Capasity);

	layer3.~vector();

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.resize(layer1Capasity * layer2Capasity);

	sinops3.~vector();

	sinopsOutput.resize(layer2Capasity * outputDataCapasity);

	bias = Bias;
	this->studySpeed = studySpeed;
	this->moment = moment;
	type = func;
}

NeuronNetwork::NeuronNetwork(int inputDataCapasity, int layer1Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func)
{
	inputData.resize(inputDataCapasity);

	outputData.resize(outputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.~vector();

	layer3.~vector();

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.~vector();

	sinops3.~vector();

	sinopsOutput.resize(layer1Capasity * outputDataCapasity);

	bias = Bias;
	this->studySpeed = studySpeed;
	this->moment = moment;
	type = func;
}

void NeuronNetwork::setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func)
{
	inputData.resize(inputDataCapasity);

	outputData.resize(outputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.resize(layer2Capasity);

	layer3.resize(layer3Capasity);

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.resize(layer1Capasity * layer2Capasity);

	sinops3.resize(layer2Capasity * layer3Capasity);

	sinopsOutput.resize(layer3Capasity * outputDataCapasity);

	bias = Bias;
	this->studySpeed = studySpeed;
	this->moment = moment;
	type = func;
}

void NeuronNetwork::setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func)
{
	inputData.resize(inputDataCapasity);

	outputData.resize(outputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.resize(layer2Capasity);

	layer3.~vector();

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.resize(layer1Capasity * layer2Capasity);

	sinops3.~vector();

	sinopsOutput.resize(layer2Capasity * outputDataCapasity);

	bias = Bias;
	this->studySpeed = studySpeed;
	this->moment = moment;
	type = func;
}

void NeuronNetwork::setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int outputDataCapasity, bool Bias, double studySpeed, double moment, Neuron::Function func)
{
	inputData.resize(inputDataCapasity);

	outputData.resize(outputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.~vector();

	layer3.~vector();

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.~vector();

	sinops3.~vector();

	sinopsOutput.resize(layer1Capasity * outputDataCapasity);

	bias = Bias;
	this->studySpeed = studySpeed;
	this->moment = moment;
	type = func;
}

double NeuronNetwork::learn(double inputData[], double outputData[])
{
	for (int i = 0; i < sinops1.size(); i++)
	{
		sinops1[i] = DEFOULT_LEARN;
	}

	if (&sinops2) {
		for (int i = 0; i < sinops2.size(); i++)
		{
			sinops2[i] = DEFOULT_LEARN;
		}
	}

	if (&sinops3) {
		for (int i = 0; i < sinops3.size(); i++)
		{
			sinops3[i] = DEFOULT_LEARN;
		}
	}

	if (&sinopsOutput) {
		for (int i = 0; i < sinopsOutput.size(); i++)
		{
			sinopsOutput[i] = DEFOULT_LEARN;
		}
	}

	for (int i = 0; i > layer1.size(); i++) 
	{
		double sparametr = 0;
		for (int r = 0; r > layer1.size(); r++)
		{
			sparametr += inputData[r] * sinops1[r];
		}
		layer1[i].setValue(sparametr);
	}

	if (&layer2)
	{
		for (int i = 0; i > layer2.size(); i++)
		{
			double sparametr = 0;
			for (int r = 0; r > layer2.size(); r++)
			{
				sparametr += layer1[r].getActivatedValue() * sinops2[r];
			}
			layer2[i].setValue(sparametr);
		}
	}

	if (&layer3)
	{
		for (int i = 0; i > layer3.size(); i++)
		{
			double sparametr = 0;
			for (int r = 0; r > layer3.size(); r++)
			{
				sparametr += layer2[r].getActivatedValue() * sinops3[r];
			}
			layer3[i].setValue(sparametr);
		}
	}

	if (&layer3)
	{
		for (int i = 0; i > outputNeuron.size(); i++)
		{
			double sparametr = 0;
			for (int r = 0; r > outputNeuron.size(); r++)
			{
				sparametr += layer3[r].getActivatedValue() * sinopsOutput[r];
			}
			outputNeuron[i].setValue(sparametr);
		}
	}
	else if (&layer2)
	{
		for (int i = 0; i > outputNeuron.size(); i++)
		{
			double sparametr = 0;
			for (int r = 0; r > outputNeuron.size(); r++)
			{
				sparametr += layer2[r].getActivatedValue() * sinopsOutput[r];
			}
			outputNeuron[i].setValue(sparametr);
		}
	}
	else if (&layer1)
	{
		for (int i = 0; i > outputNeuron.size(); i++)
		{
			double sparametr = 0;
			for (int r = 0; r > outputNeuron.size(); r++)
			{
				sparametr += layer1[r].getActivatedValue() * sinopsOutput[r];
			}
			outputNeuron[i].setValue(sparametr);
		}
	}


	for (int i = 0; i < outputNeuron.size(); i++)
	{
		cout << outputNeuron[i].getActivatedValue() << endl;
	}

	double answer = 0;
	return answer;
}
