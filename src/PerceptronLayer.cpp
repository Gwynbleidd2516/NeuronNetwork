#include"PerceptronLayer.h"

PerceptronLayer::PerceptronLayer(int capasity)
{
    weights.resize(capasity);
    for(auto& x : weights)
    {
        x=(rand()%1000-500)/1000.0;
    }
    bias=(rand()%1000-500)/1000.0;
}

void PerceptronLayer::setPerceptronLayer(int capasity)
{
    weights.resize(capasity);
    for(auto& x : weights)
    {
        x=(rand()%1000-500)/1000.0;
    }
    bias=(rand()%1000-500)/1000.0;
}

double PerceptronLayer::construct(const vector<double>& args)
{
    exInputs=args;
    summ=0;

    for (int i = 0; i < weights.size(); i++)
    {
        summ+=args[i]*weights[i];
    }
    summ+=bias;
    return activationFunction(summ);
}

void PerceptronLayer::learn(double answear)
{
    double error=answear-activationFunction(summ);
    double teta=error*deactivationFunction(summ);

    for (int i = 0; i < weights.size(); i++)
    {
        weights[i]+=learningSpeed*teta*exInputs[i];
    }
    bias+=learningSpeed*teta;
}

double PerceptronLayer::activationFunction(double value)
{
    return 1.0 / (1.0 + exp(-value));
}

double PerceptronLayer::deactivationFunction(double value)
{
    return activationFunction(value) * (1. - activationFunction(value));
}

double PerceptronLayer::getOutPut()
{
    return activationFunction(summ);;
}

void PerceptronLayer::setLearningSpeed(double speed)
{
    this->learningSpeed=speed;
}

double PerceptronLayer::getError(double answear)
{
    return answear-activationFunction(summ);
}

const vector<double> PerceptronLayer::getWeights() 
{
    return weights;
}