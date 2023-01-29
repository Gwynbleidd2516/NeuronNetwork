#include<stdint.h>
#include<vector>
#include<algorithm>
#include"Neuron.h"
#include"NeuronNetwork.h"
#include"Perceptron.h"
#include<iostream>
#include<string>
#include<fstream>
#include"MNIST.h"
using namespace std;

#define PATH "bird.jpg"
#define E 2.718281828459045

#define TEST_IMAGE_FILE "t10k-images.idx3-ubyte"
#define TEST_LABELS_FILE "t10k-labels.idx1-ubyte"

#define TRAIN_IMAGE_FILE "train-images.idx3-ubyte"
#define TRAIN_LABELS_FILE "train-labels.idx1-ubyte"

struct Iris
{
	double dlinaChashelistnika;
	double shirinaChashelistnika;
	double dlinaLepestka;
	double shirinaLepestka;
	string type;
	Iris(double dlinaChashelistnika,
	double shirinaChashelistnika,
	double dlinaLepestka,
	double shirinaLepestka,
	string type)
	{
		this->dlinaChashelistnika=dlinaChashelistnika;
		this->shirinaChashelistnika=shirinaChashelistnika;
		this->dlinaLepestka=dlinaLepestka;
		this->shirinaLepestka=shirinaLepestka;
		this->type=type;
	}

	Iris(){}
};


double f(double x)
{
	return 1 / (1 + pow(E, -x));
}

int main()
{
	
	// NeuronNetwork a(2,2);
	// double b[2];
	// b[0]=1;
	// b[1]=0;
	// a.learn(b,false,true,0.7,0.3,0.01,10);
	// cout<<a.run(b);

	// Neuron a(1),b;
	// double sinops=0.1;
	// b.setValue(a.getActivatedValue()*sinops);
	// cout<<b.getActivatedValue()<<endl<<pow(0-b.getActivatedValue(),2)<<endl;
	// double grad=(0-0.33)*b.getDerivedValue();
	// cout<<0.7*grad<<endl;
	// cout<<sinops+0.7*grad;

	// NeuronNetwork ab(1,1,1);
	// double x[]={1};
	// ab.learn(x,1,true,0.1,0.7,0.001,10000,Neuron::SIGM);
	// double l[]={0};
	// cout<<ab.run(l);

	vector<Iris> priznak;
	ifstream file;
	file.open("iris.txt");
	while (!file.eof())
	{
		string buffer="";
		Iris iris;
		getline(file,buffer);
		iris.dlinaChashelistnika=stod(buffer);
		getline(file,buffer);
		iris.shirinaChashelistnika=stod(buffer);
		getline(file,buffer);
		iris.dlinaLepestka=stod(buffer);
		getline(file,buffer);
		iris.shirinaLepestka=stod(buffer);
		getline(file,buffer);
		iris.type=buffer;
		priznak.push_back(iris);
		getline(file,buffer);
		getline(file,buffer);
	}
	file.close();

	// NeuronNetwork setosa(4,10);
	// NeuronNetwork virginica(4,10);
	// NeuronNetwork versicolor(4,10);
	// bool bias=true;
	// Neuron::Function func=Neuron::SIGM;
	// double studySpeed=0.1,moment=0.9,error=0.01;

	// // double pi = 3.1415926535;
	// // cout<<atan(tan(45*pi/60000))*60000/pi<<endl;
	// // cout<<atan2(2,2)*60000/pi<<endl;

	// for (auto& iris:priznak)
	// {
	//     double pri[]={iris.dlinaChashelistnika,iris.shirinaChashelistnika,iris.dlinaLepestka,iris.shirinaLepestka};
	//     if(iris.type=="setosa")
	//     {
	//         setosa.learn(pri,true,bias,studySpeed,moment,error, func);
	//         virginica.learn(pri,false,bias,studySpeed,moment,error, func);
	//         versicolor.learn(pri,false,bias,studySpeed,moment,error, func);
	//     }
	//     if(iris.type=="virginica")
	//     {
	//         setosa.learn(pri,false,bias,studySpeed,moment,error, func);
	//         virginica.learn(pri,true,bias,studySpeed,moment,error, func);
	//         versicolor.learn(pri,false,bias,studySpeed,moment,error, func);
	//     }
	//     if(iris.type=="versicolor")
	//     {
	//         setosa.learn(pri,false,bias,studySpeed,moment,error, func);
	//         virginica.learn(pri,false,bias,studySpeed,moment,error, func);
	//         versicolor.learn(pri,true,bias,studySpeed,moment,error, func);
	//     }
	// }


	// double pri[4];
	// cout<<"Ввидите признаки:\n1. Длинна чашелистника\n2. Ширина Чашелистника\n1. Длинна лепестка\n2. Ширина лепестка\n";

	// for(auto& x:pri)
	// {
	//     cin>>x;
	// }

	// cout<<setosa.run(pri, func)<<endl<<virginica.run(pri, func)<<endl<<versicolor.run(pri, func);

	// Perceptron a(1);
	// vector<double> vec(1);
	// for(auto& x:vec)
	// {
	//     x=0;
	// }
	// vec[0]=1;
	// a.setLearningSpeed(0.3);
	// while (a.getError(1)>=0.01)
	// {
	//     a.construct(vec);
	//     a.learn(1);
	// }
	// vec[0]=0;
	// a.construct(vec);
	// cout<<a.getOutPut()<<endl<<a.getError(1)<<endl;
	// for(auto& x:a.getWeights())
	// {
	//     cout<<x<<endl;
	// }

	// Perceptron setosa(4);
	// Perceptron virginica(4);
	// Perceptron versicolor(4);
	// double studySpeed=0.3;
	// double error=0.001;
	// setosa.setLearningSpeed(studySpeed);
	// virginica.setLearningSpeed(studySpeed);
	// versicolor.setLearningSpeed(studySpeed);

	// for(auto& iris:priznak)
	// {
	//     vector<double> pri={iris.dlinaChashelistnika,iris.shirinaChashelistnika,iris.dlinaLepestka,iris.shirinaLepestka};
	//     if(iris.type=="setosa")
	//     {
	//         while (setosa.getError(1)>=error)
	//         {
	//             setosa.construct(pri);
	//             setosa.learn(1);
	//         }
	//         while (virginica.getError(0)>=error)
	//         {
	//             virginica.construct(pri);
	//             virginica.learn(0);
	//         }
	//         while (versicolor.getError(0)>=error)
	//         {
	//             versicolor.construct(pri);
	//             versicolor.learn(0);
	//         }
	//     }

	//     if(iris.type=="virginica")
	//     {
	//         while (setosa.getError(0)>=error)
	//         {
	//             setosa.construct(pri);
	//             setosa.learn(0);
	//         }
	//         while (virginica.getError(1)>=error)
	//         {
	//             virginica.construct(pri);
	//             virginica.learn(1);
	//         }
	//         while (versicolor.getError(0)>=error)
	//         {
	//             versicolor.construct(pri);
	//             versicolor.learn(0);
	//         }
	//     }

	//     if(iris.type=="versicolor")
	//     {
	//         while (setosa.getError(0)>=error)
	//         {
	//             setosa.construct(pri);
	//             setosa.learn(0);
	//         }
	//         while (virginica.getError(0)>=error)
	//         {
	//             virginica.construct(pri);
	//             virginica.learn(0);
	//         }
	//         while (versicolor.getError(1)>=error)
	//         {
	//             versicolor.construct(pri);
	//             versicolor.learn(1);
	//         }
	//     }
	// }
	
	// vector<vector<double>> vec(4);
	// for(auto& x:vec)
	// {
	//     cin>>x;
	// }
	// setosa.construct(vec);
	// virginica.construct(vec);
	// versicolor.construct(vec);
	// cout<<setosa.getOutPut()<<endl<<virginica.getOutPut()<<endl<<versicolor.getOutPut();
	MNIST test(TRAIN_IMAGE_FILE, TRAIN_LABELS_FILE);
	test.read(60000);
	
	vector<Perceptron> nums(10);
	for (auto& x:nums)
	{
		x.setPerceptron(784);
		x.setLearningSpeed(0.3);
	}
	vector<vector<double>> teach(60000, vector<double>(0));


	vector<double> ans;
	for (int i = 0; i < 60000; i++)
	{
		ans.push_back(test.getLabel(i));
	}
	

	vector<vector<double>> answears;
	answears.resize(60000, vector<double>(10));
	for (int i = 0; i < ans.size(); i++)
	{
		for(auto& x:answears[i])
		{
			x=0;
		}
		answears[i][ans[i]]=1;
	}
	
	for (int i = 0; i < 60000; i++)
	{
		for (auto& x:test.getTest(i))
		{
			teach[i].push_back((double)x/255);
		}
	}

	int error = 0;
	do
	{
		error = 0;  
		for (int j = 0; j < 60000; j++)
		{
			for (int i = 0; i < nums.size(); i++)
			{
				nums[i].construct(teach[j]);
				nums[i].learn(answears[j][i]);

				cout<<nums[i].getError(answears[j][i])<< "  "<<j<<endl;
				error += nums[i].getError(answears[j][i]);
			}
			std::cout << endl;
		}
	}
	while (std::abs(error)>=0.001);

	MNIST train(TEST_IMAGE_FILE, TEST_LABELS_FILE);
	train.read(10000);
	
	vector<vector<double>> teach1(10000, vector<double>(0));


	vector<double> ans1;
	for (int i = 0; i < 10000; i++)
	{
		ans1.push_back(train.getLabel(i));
	}
	

	vector<vector<double>> answears1;
	answears1.resize(10000, vector<double>(10));
	for (int i = 0; i < ans1.size(); i++)
	{
		for(auto& x:answears1[i])
		{
			x=0;
		}
		answears1[i][ans1[i]]=1;
	}
	
	for (int i = 0; i < 10000; i++)
	{
		for (auto& x:train.getTest(i))
		{
			teach1[i].push_back((double)x/255);
		}
	}

	int result=0;
	
    for (int j = 0; j < 10000; j++)
    {
		vector<double> anse;
		for(auto& x:nums)
		{
			x.construct(teach1[j]);
			anse.push_back(x.getOutPut());
		}
		
		// for(auto& x:answears1[j])
		// {
		// 	cout<<x<<" ";
		// }
		// cout<<endl;
		// for(auto& x:nums)
		// {
		// 	cout<<x.getOutPut()<<" ";
		// }
		// cout<<endl;

		auto num=max_element(anse.begin(), anse.end())-anse.begin();
		auto br=max_element(answears1[j].begin(), answears1[j].end())-answears1[j].begin();
		cout<<num<<" "<<br<<endl;
		if (num==br) result++;
	}
	cout<<result;
}