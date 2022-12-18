#include "NeuronNetwork.h"

NeuronNetwork::NeuronNetwork()
{
}

NeuronNetwork::NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity, int outputDataCapasity)
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

	outputNeuron.resize(outputDataCapasity);
	
	for (int i = 0; i < sinops1.size(); i++)
	{
		sinops1[i] = DEFOULT_LEARN;
	}

	for (int i = 0; i < sinops2.size(); i++)
	{
		sinops2[i] = DEFOULT_LEARN;
	}
	

	for (int i = 0; i < sinops3.size(); i++)
	{
		sinops3[i] = DEFOULT_LEARN;
	}
	
	for (int i = 0; i < sinopsOutput.size(); i++)
	{
		sinopsOutput[i] = DEFOULT_LEARN;
	}

}

NeuronNetwork::NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int outputDataCapasity)
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

	outputNeuron.resize(outputDataCapasity);
	
	for (int i = 0; i < sinops1.size(); i++)
	{
		sinops1[i] = DEFOULT_LEARN;
	}

	for (int i = 0; i < sinops2.size(); i++)
	{
		sinops2[i] = DEFOULT_LEARN;
	}
	

	for (int i = 0; i < sinops3.size(); i++)
	{
		sinops3[i] = DEFOULT_LEARN;
	}
	
	for (int i = 0; i < sinopsOutput.size(); i++)
	{
		sinopsOutput[i] = DEFOULT_LEARN;
	}

}

NeuronNetwork::NeuronNetwork(int inputDataCapasity, int layer1Capasity, int outputDataCapasity)
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

	outputNeuron.resize(outputDataCapasity);

	for (int i = 0; i < sinops1.size(); i++)
	{
		sinops1[i] = DEFOULT_LEARN;
	}

	for (int i = 0; i < sinops2.size(); i++)
	{
		sinops2[i] = DEFOULT_LEARN;
	}
	

	for (int i = 0; i < sinops3.size(); i++)
	{
		sinops3[i] = DEFOULT_LEARN;
	}
	
	for (int i = 0; i < sinopsOutput.size(); i++)
	{
		sinopsOutput[i] = DEFOULT_LEARN;
	}

}

void NeuronNetwork::setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity, int outputDataCapasity)
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

	outputNeuron.resize(outputDataCapasity);

	for (int i = 0; i < sinops1.size(); i++)
	{
		sinops1[i] = DEFOULT_LEARN;
	}

	for (int i = 0; i < sinops2.size(); i++)
	{
		sinops2[i] = DEFOULT_LEARN;
	}
	

	for (int i = 0; i < sinops3.size(); i++)
	{
		sinops3[i] = DEFOULT_LEARN;
	}
	
	for (int i = 0; i < sinopsOutput.size(); i++)
	{
		sinopsOutput[i] = DEFOULT_LEARN;
	}

}

void NeuronNetwork::setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int outputDataCapasity)
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

	outputNeuron.resize(outputDataCapasity);

	for (int i = 0; i < sinops1.size(); i++)
	{
		sinops1[i] = DEFOULT_LEARN;
	}

	for (int i = 0; i < sinops2.size(); i++)
	{
		sinops2[i] = DEFOULT_LEARN;
	}
	

	for (int i = 0; i < sinops3.size(); i++)
	{
		sinops3[i] = DEFOULT_LEARN;
	}
	
	for (int i = 0; i < sinopsOutput.size(); i++)
	{
		sinopsOutput[i] = DEFOULT_LEARN;
	}
	
}

void NeuronNetwork::setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int outputDataCapasity)
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

	outputNeuron.resize(outputDataCapasity);

	for (int i = 0; i < sinops1.size(); i++)
	{
		sinops1[i] = DEFOULT_LEARN;
	}

	for (int i = 0; i < sinops2.size(); i++)
	{
		sinops2[i] = DEFOULT_LEARN;
	}
	

	for (int i = 0; i < sinops3.size(); i++)
	{
		sinops3[i] = DEFOULT_LEARN;
	}
	
	for (int i = 0; i < sinopsOutput.size(); i++)
	{
		sinopsOutput[i] = DEFOULT_LEARN;
	}

}

void NeuronNetwork::learn(double inputData[], double outputData[], bool bias, double studySpeed, double moment, Neuron::Function func)
{
	for(int i=0;i<this->inputData.size();i++)
	{
		this->inputData[i]=inputData[i];
	}

	for(int i=0;i<this->outputData.size();i++)
	{
		this->outputData[i]=outputData[i];
	}

	vector<double> deltaSinops1(sinops1.size());
	vector<double> deltaSinops2(sinops2.size());
	vector<double> deltaSinops3(sinops3.size());
	vector<double> deltaSinopsOutput(sinopsOutput.size());
	vector<double> GRAD1;
	vector<double> GRAD2;
	vector<double> GRAD3;
	vector<double> GRADOut;

	for (auto& x:deltaSinops1)
	{
		x=0;
	}
	for (auto& x:deltaSinops2)
	{
		x=0;
	}
	for (auto& x:deltaSinops3)
	{
		x=0;
	}
	for (auto& x:deltaSinopsOutput)
	{
		x=0;
	}

	int index=0;
	for (int i = 0; i < layer1.size(); i++) 
	{
		double sparametr = 0;
		for (int r = 0; r < this->inputData.size(); r++)
		{
			sparametr += inputData[r] * sinops1[index++]+bias;
		}
		layer1[i].setValue(sparametr);
	}

	index=0;
	for (int i = 0; i < layer2.size(); i++)
	{
		double sparametr = 0;
		for (int r = 0; r < layer1.size(); r++)
		{
			sparametr += layer1[r].getActivatedValue() * sinops2[index++]+bias;
		}
		layer2[i].setValue(sparametr);
	}
	

	index=0;
	for (int i = 0; i < layer3.size(); i++)
	{
		double sparametr = 0;
		for (int r = 0; r < layer2.size(); r++)
		{
			sparametr += layer2[r].getActivatedValue() * sinops3[index++]+bias;
		}
		layer3[i].setValue(sparametr);
	}
	

	index=0;
	bool write=false;
	for (int i=0;i<outputNeuron.size();i++)
	{
		double sparametr=0;
		for (int r = 0; r < layer1.size(); r++)
		{
			sparametr += layer1[r].getActivatedValue() * sinopsOutput[index++]+bias;
			write=true;
		}
		if(write) outputNeuron[i].setValue(sparametr,func);
		write =false;

		index=0;
		sparametr=0;
		for (int r = 0; r < layer2.size(); r++)
		{
			sparametr += layer2[r].getActivatedValue() * sinopsOutput[index++]+bias;
			write=true;
		}
		if(write) outputNeuron[i].setValue(sparametr,func);
		write =false;

		index=0;
		sparametr=0;
		for (int r = 0; r < layer3.size(); r++)
		{
			sparametr += layer3[r].getActivatedValue() * sinopsOutput[index++]+bias;
			write=true;
		}
		if(write) outputNeuron[i].setValue(sparametr,func);
		write =false;
	}

	
	
	for (int i=0;i<this->outputData.size();i++)
	{
		error+=pow(this->outputData[i]-outputNeuron[i].getActivatedValue(),2);
	}
	error/=outputNeuron.size();

	for (int i = 0; i < outputNeuron.size(); i++)
	{
		cout << outputNeuron[i].getActivatedValue() << "\t" <<error*100<<endl;
	}

	// GRADout calculation
	bool grad=false;
	for(auto& x : outputNeuron)
	{
		grad=false;
		for(auto& l:layer3)
		{
			GRADOut.push_back(x.getDerivedValue()*error*l.getActivatedValue());
			grad=true;
		}
		if(!grad)
		{
			for(auto& l:layer2)
			{
				GRADOut.push_back(x.getDerivedValue()*error*l.getActivatedValue());
				grad=true;
			}
		}
		if(!grad)
		{
			for(auto& l:layer1)
			{
				GRADOut.push_back(x.getDerivedValue()*error*l.getActivatedValue());
			}
		}
	}
	
	
	
	grad=false;
	for(auto& l3 : layer3)
	{
		for(auto& l2 : layer2)
		{
			for(auto& sinops : sinops3)
			{
				GRAD3.push_back(l2.getDerivedValue()*(sinops));
				grad=true;
			}
		}
	}
	

	for(auto& x:GRADOut)
	{
		cout<<"t"<<x<<endl;
	}
	cout<<"\n";
	int g=0;
	for(auto& sinops : sinopsOutput)
	{
		sinops+=studySpeed*GRADOut[g]+moment*deltaSinops3[g];
		g++;
	}
	for(auto& x:sinopsOutput)
	{
		cout<<x<<endl;
	}
}


void NeuronNetwork::saveResults(string path)
{
	ofstream file;
	file.open(path);
	file<<"//1\n";
	for (auto& x:sinops1)
	{
		file<<to_string(x)+"\n";
	}

	file<<"//2\n";
	for (auto& x:sinops2)
	{
		file<<to_string(x)+"\n";
	}

	file<<"//3\n";
	for (auto& x:sinops3)
	{
		file<<to_string(x)+"\n";
	}

	file<<"//out\n";
	for (auto& x:sinopsOutput)
	{
		file<<to_string(x)+"\n";
	}
	file.close();
}