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
    vector<Perceptron> layers;
    double error;
    double studySpeed;
    double bias;
public:
    PerceptronLayer(int inputCpasity, int layerCapasity, double studySpeed=0.3);

    double getError();
	
    double construct(const vector<double>& parametrs);

    double learn(double answear);
};