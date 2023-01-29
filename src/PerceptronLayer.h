#pragma once

#include<vector>
using namespace std;

class PerceptronLayer
{
private:
    double activationFunction(double value);
    double deactivationFunction(double value);

    double summ;
    vector<double> weights;
    vector<double> exInputs;
    double learningSpeed;
    double bias;

public:
    PerceptronLayer(int capasity);

    void setPerceptronLayer(int capasity);

    void setLearningSpeed(double speed);

    double construct(const vector<double>& args);

    void learn(double answer);

    double getOutPut();

    double getError(double answear);

    const vector<double> getWeights();
};