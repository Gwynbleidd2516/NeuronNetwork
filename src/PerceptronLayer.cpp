#include"PerceptronLayer.h"

PerceptronLayer::PerceptronLayer(int inputCpasity, int layerCapasity, double studySpeed):
layers(inputCpasity, Perceptron(layerCapasity))
{
    this->studySpeed=studySpeed;
}

double PerceptronLayer::construct(const vector<double>& parametrs)
{
    double result=0;
    layers[0].construct(parametrs);
    // for (int i = 1; i < layers.size(); i++)
    // {
    //     layers[i].
    // }
    return 0;
}