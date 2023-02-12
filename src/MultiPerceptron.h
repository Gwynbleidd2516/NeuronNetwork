#pragma once

#include"Perceptron.h"
#include<iostream>
#include<math.h>

class MultiPerceptron
{
private:
    vector<vector<Perceptron>> layers;
    vector<double> exInput;
    double error;
    double studySpeed;
public:
    MultiPerceptron(){};

    MultiPerceptron(uint16_t inputCapasity, uint16_t layersCapasity, uint16_t outputCapasity, double studySpeed=0.3);

    void setMultiPerceptron(uint16_t inputCapasity, uint16_t layersCapasity, uint16_t outputCapasity, double studySpeed=0.3);

    double getError(vector<double>& answear);

    vector<double> construct(const vector<double>& parametrs);

    void learn(vector<double>& answear);
};