#include "NeuronNetwork.h"

NeuronNetwork::NeuronNetwork()
{
}

NeuronNetwork::NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity)
{
	inputData.resize(inputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.resize(layer2Capasity);

	layer3.resize(layer3Capasity);
	
	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.resize(layer1Capasity * layer2Capasity);

	sinops3.resize(layer2Capasity * layer3Capasity);

	sinopsOutput.resize(layer3Capasity);
	
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

	deltaSinops1.resize(sinops1.size());

	for(auto& x:deltaSinops1) x=0;

	deltaSinops2.resize(sinops2.size());

	for(auto& x:deltaSinops2) x=0;

	deltaSinops3.resize(sinops3.size());

	for(auto& x:deltaSinops3) x=0;

	deltaSinopsOutput.resize(sinopsOutput.size());
	
	for(auto& x:deltaSinopsOutput) x=0;

}

NeuronNetwork::NeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity)
{
	inputData.resize(inputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.resize(layer2Capasity);

	layer3.~vector();

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.resize(layer1Capasity * layer2Capasity);

	sinops3.~vector();

	sinopsOutput.resize(layer2Capasity);
	
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

	deltaSinops1.resize(sinops1.size());

	for(auto& x:deltaSinops1) x=0;

	deltaSinops2.resize(sinops2.size());

	for(auto& x:deltaSinops2) x=0;

	deltaSinops3.~vector();

	deltaSinopsOutput.resize(sinopsOutput.size());

	for(auto& x:deltaSinopsOutput) x=0;

}

NeuronNetwork::NeuronNetwork(int inputDataCapasity, int layer1Capasity)
{
	inputData.resize(inputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.~vector();

	layer3.~vector();

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.~vector();

	sinops3.~vector();

	sinopsOutput.resize(layer1Capasity);

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

	deltaSinops1.resize(sinops1.size());

	for(auto& x:deltaSinops1) x=0;

	deltaSinops2.~vector();

	deltaSinops3.~vector();

	deltaSinopsOutput.resize(sinopsOutput.size());

	for(auto& x:deltaSinopsOutput) x=0;

}

void NeuronNetwork::setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity, int layer3Capasity)
{
	inputData.resize(inputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.resize(layer2Capasity);

	layer3.resize(layer3Capasity);

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.resize(layer1Capasity * layer2Capasity);

	sinops3.resize(layer2Capasity * layer3Capasity);

	sinopsOutput.resize(layer3Capasity);

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

	deltaSinops1.resize(sinops1.size());

	for(auto& x:deltaSinops1) x=0;

	deltaSinops2.resize(sinops2.size());

	for(auto& x:deltaSinops2) x=0;

	deltaSinops3.resize(sinops3.size());

	for(auto& x:deltaSinops3) x=0;

	deltaSinopsOutput.resize(sinopsOutput.size());
	
	for(auto& x:deltaSinopsOutput) x=0;

}

void NeuronNetwork::setNeuronNetwork(int inputDataCapasity, int layer1Capasity, int layer2Capasity)
{
	inputData.resize(inputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.resize(layer2Capasity);

	layer3.~vector();

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.resize(layer1Capasity * layer2Capasity);

	sinops3.~vector();

	sinopsOutput.resize(layer2Capasity);

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

	deltaSinops1.resize(sinops1.size());

	for(auto& x:deltaSinops1) x=0;

	deltaSinops2.resize(sinops2.size());

	for(auto& x:deltaSinops2) x=0;

	deltaSinops3.~vector();

	deltaSinopsOutput.resize(sinopsOutput.size());

	for(auto& x:deltaSinopsOutput) x=0;
	
}

void NeuronNetwork::setNeuronNetwork(int inputDataCapasity, int layer1Capasity)
{
	inputData.resize(inputDataCapasity);

	layer1.resize(layer1Capasity);

	layer2.~vector();

	layer3.~vector();

	sinops1.resize(inputDataCapasity * layer1Capasity);

	sinops2.~vector();

	sinops3.~vector();

	sinopsOutput.resize(layer1Capasity);

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

	deltaSinops1.resize(sinops1.size());

	for(auto& x:deltaSinops1) x=0;

	deltaSinops2.~vector();

	deltaSinops3.~vector();

	deltaSinopsOutput.resize(sinopsOutput.size());

	for(auto& x:deltaSinopsOutput) x=0;
}

void NeuronNetwork::learn(double inputData[], bool outputData, bool bias, double studySpeed, double moment, double min_error, Neuron::Function func)
{
	for(int i=0;i<this->inputData.size();i++)
	{
		this->inputData[i]=inputData[i];
	}

	vector<double> GRAD1;
	vector<double> GRAD2;
	vector<double> GRAD3;
	vector<double> GRADOut;

	bool answer;
	
	do
	{
		error=0;
		int index=0;
		for (int i = 0; i < layer1.size(); i++) 
		{
			double sparametr = 0;
			for (int r = 0; r < this->inputData.size(); r++)
			{
				sparametr += inputData[r] * sinops1[index++]+bias;
			}
			layer1[i].setValue(sparametr, func);
		}

		index=0;
		for (int i = 0; i < layer2.size(); i++)
		{
			double sparametr = 0;
			for (int r = 0; r < layer1.size(); r++)
			{
				sparametr += layer1[r].getActivatedValue() * sinops2[index++]+bias;
			}
			layer2[i].setValue(sparametr, func);
		}
		

		index=0;
		for (int i = 0; i < layer3.size(); i++)
		{
			double sparametr = 0;
			for (int r = 0; r < layer2.size(); r++)
			{
				sparametr += layer2[r].getActivatedValue() * sinops3[index++]+bias;
			}
			layer3[i].setValue(sparametr, func);
		}
		

		index=0;
		bool write=false;
	
		double sparametr=0;
		for (int r = 0; r < layer3.size(); r++)
		{
			sparametr += layer3[r].getActivatedValue() * sinopsOutput[index++]+bias;
			write=true;
		}
		if(write) outputNeuron.setValue(sparametr,func);
		write=false;
		
		index=0;
		sparametr=0;
		for (int r = 0; r < layer2.size() && !write; r++)
		{
			sparametr += layer2[r].getActivatedValue() * sinopsOutput[index++]+bias;
			write=true;
		}
		if(write) outputNeuron.setValue(sparametr,func);
		write=false;
		
		index=0;
		sparametr=0;
		for (int r = 0; r < layer1.size() && !write; r++)
		{
			sparametr += layer1[r].getActivatedValue() * sinopsOutput[index++]+bias;
			write=true;
		}
		if(write) outputNeuron.setValue(sparametr,func);
		write=false;

		answer=outputNeuron.getActivatedValue()>=0.5;
		
		error=pow(outputData-answer,2);

		// GRADout calculation
		bool grad=false;
		grad=false;
		for(auto& l:layer3)
		{
			GRADOut.push_back(outputNeuron.getDerivedValue()*(outputData-outputNeuron.getActivatedValue()));
			grad=true;
		}
		if(!grad)
		{
			for(auto& l:layer2)
				{
					GRADOut.push_back(outputNeuron.getDerivedValue()*(outputData-outputNeuron.getActivatedValue()));
					grad=true;
				}
			}
			if(!grad)
			{
				for(auto& l:layer1)
				{
					GRADOut.push_back(outputNeuron.getDerivedValue()*(outputData-outputNeuron.getActivatedValue()));
				}
		}
		
		
		
		
		for(int i=0;i<sinops3.size();)
		{
			for(auto& l3 : layer3)
			{
				for(auto& l2 : layer2)
				{
					GRAD3.push_back(l2.getDerivedValue()*sinops3[i]*l3.getDerivedValue());
					i++;
				}
			}
		}
		
		for(int i=0;i<sinops2.size();)
		{
			for(auto& l2 : layer2)
			{
				for(auto& l1 : layer1)
				{
					GRAD2.push_back(l1.getDerivedValue()*sinops2[i]*l2.getDerivedValue());
					i++;
				}
			}
		}

		for(int i=0;i<sinops1.size();)
		{
			for(auto& l1 : layer1)
			{
				for(auto& in : this->inputData)
				{
					GRAD1.push_back(in*sinops1[i]*l1.getDerivedValue());
					i++;
				}
			}
		}

		
		int g=0;
		for(auto& sinops : sinopsOutput)
		{
			sinops+=studySpeed*GRADOut[g]+moment*deltaSinopsOutput[g];
			deltaSinopsOutput[g]=studySpeed*GRADOut[g]+moment*deltaSinopsOutput[g];
			g++;
		}

		g=0;
		for(auto& sinops : sinops3)
		{
			sinops+=studySpeed*GRAD3[g]+moment*deltaSinops3[g];
			deltaSinops3[g]=studySpeed*GRAD3[g]+moment*deltaSinops3[g];
			g++;
		}

		g=0;
		for(auto& sinops : sinops2)
		{
			sinops+=studySpeed*GRAD2[g]+moment*deltaSinops2[g];
			deltaSinops2[g]=studySpeed*GRAD2[g]+moment*deltaSinops2[g];
			g++;
		}

		g=0;
		for(auto& sinops : sinops1)
		{
			sinops+=studySpeed*GRAD1[g]+moment*deltaSinops1[g];
			deltaSinops1[g]=studySpeed*GRAD1[g]+moment*deltaSinops1[g];
			g++;
		}

		answer=outputNeuron.getActivatedValue()>=0.5;

		error=pow(outputData-answer,2);

		cout<<outputNeuron.getActivatedValue()<<endl;
		
		cout<<error<<"\n\n";
		

		GRAD1.clear();
		GRAD2.clear();
		GRAD3.clear();
		GRADOut.clear();
	} while (error>=min_error);
}


void NeuronNetwork::saveResults(string path)
{
	ofstream file;
	file.open(path);
	
	for (auto& x:sinops1)
	{
		file<<to_string(x)+"\n";
	}

	for (auto& x:sinops2)
	{
		file<<to_string(x)+"\n";
	}

	for (auto& x:sinops3)
	{
		file<<to_string(x)+"\n";
	}

	for (auto& x:sinopsOutput)
	{
		file<<to_string(x)+"\n";
	}
	file.close();
}

void NeuronNetwork::loadFromFile(string path)
{
	ifstream file;
	file.open(path);
	string buffer;
	
	for (auto& x:sinops1)
	{
		getline(file, buffer);
		x=stod(buffer);
	}

	for (auto& x:sinops2)
	{
		getline(file, buffer);
		x=stod(buffer);
	}

	for (auto& x:sinops3)
	{
		getline(file, buffer);
		x=stod(buffer);
	}

	for (auto& x:sinopsOutput)
	{
		getline(file, buffer);
		x=stod(buffer);
	}
	file.close();
	
}

double NeuronNetwork::run(double inputData[], Neuron::Function func)
{
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
	double sparametr=0;
	for (int r = 0; r < layer3.size(); r++)
	{
		sparametr += layer3[r].getActivatedValue() * sinopsOutput[index++]+bias;
		write=true;
	}
	if(write) outputNeuron.setValue(sparametr,func);
	write =false;
		
	index=0;
	sparametr=0;
	for (int r = 0; r < layer2.size() && !write; r++)
	{
		sparametr += layer2[r].getActivatedValue() * sinopsOutput[index++]+bias;
		write=true;
	}
	if(write) outputNeuron.setValue(sparametr,func);
	write =false;
	
	index=0;
	sparametr=0;
	for (int r = 0; r < layer1.size() && !write; r++)
	{
		sparametr += layer1[r].getActivatedValue() * sinopsOutput[index++]+bias;
		write=true;
	}
	if(write) outputNeuron.setValue(sparametr,func);
	write =false;

	return outputNeuron.getActivatedValue()>=0.5;
}