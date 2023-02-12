#pragma once

#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
#include"Perceptron.h"

class PerceptronLayer
{
private:
    vector<vector<Perceptron>> layer;
    vector<int> neuronsCapasity;
    vector<double> exInput;
    double error;
    double studySpeed;
    double bias;
public:
    PerceptronLayer(int inputCpasity, int layerCapasity, double studySpeed=0.3);

    PerceptronLayer() {};

    void setPerceptronLayer(int inputCpasity, int layerCapasity, double studySpeed=0.3);

    double getError(double answear);
	
    double construct(const vector<double>& parametrs);

    void learn(double answear);
};