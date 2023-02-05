#include"PerceptronLayer.h"

PerceptronLayer::PerceptronLayer(int inputCpasity, int layerCapasity, double studySpeed)
{
    this->studySpeed=studySpeed;
    layer.resize(layerCapasity, vector<Perceptron>(inputCpasity));
    neuronsCapasity.resize(layerCapasity);
    neuronsCapasity[0]=inputCpasity;
    neuronsCapasity[neuronsCapasity.size()-1]=1;
    for (int i = 1; i < neuronsCapasity.size()-1; i++)
    {
        if(neuronsCapasity[i-1]%2==0)
        {
            neuronsCapasity[i]=neuronsCapasity[i-1]/2;
        }
        else if(neuronsCapasity[i-1]%3==0)
        {
            neuronsCapasity[i]=neuronsCapasity[i-1]/3;
        }
        else
        {
            neuronsCapasity[i]=(neuronsCapasity[i-1]+1)/2;
        }
    }
    
    for(auto& x:layer[0])
    {
        x.setPerceptron(1);
        x.setLearningSpeed(studySpeed);
    }

    for (int layerNum = 1; layerNum < layerCapasity; layerNum++)
    {
        for (int neur = 0; neur < neuronsCapasity[layerNum]; neur++)
        {
            layer[layerNum][neur].setPerceptron(neuronsCapasity[layerNum-1]);
            layer[layerNum][neur].setLearningSpeed(studySpeed);
        }       
    }    
}

void PerceptronLayer::setPerceptronLayer(int inputCpasity, int layerCapasity, double studySpeed)
{
    this->studySpeed=studySpeed;
    layer.resize(layerCapasity, vector<Perceptron>(inputCpasity));
    neuronsCapasity.resize(layerCapasity);
    neuronsCapasity[0]=inputCpasity;
    neuronsCapasity[neuronsCapasity.size()-1]=1;
    for (int i = 1; i < neuronsCapasity.size()-1; i++)
    {
        if(neuronsCapasity[i-1]%2==0)
        {
            neuronsCapasity[i]=neuronsCapasity[i-1]/2;
        }
        else if(neuronsCapasity[i-1]%3==0)
        {
            neuronsCapasity[i]=neuronsCapasity[i-1]/3;
        }
        else
        {
            neuronsCapasity[i]=(neuronsCapasity[i-1]+1)/2;
        }
    }
    
    for(auto& x:layer[0])
    {
        x.setPerceptron(1);
        x.setLearningSpeed(studySpeed);
    }

    for (int layerNum = 1; layerNum < layerCapasity; layerNum++)
    {
        for (int neur = 0; neur < neuronsCapasity[layerNum]; neur++)
        {
            layer[layerNum][neur].setPerceptron(neuronsCapasity[layerNum-1]);
            layer[layerNum][neur].setLearningSpeed(studySpeed);
        }       
    }    
}

double PerceptronLayer::construct(const vector<double>& parametrs)
{    
    exInput=parametrs;
    double summ=0;
    for (int i = 0; i < layer[0].size(); i++)
    {
        summ+=layer[0][i].construct({parametrs[i]});
    }
    
    for (int layerNum = 1; layerNum < layer.size(); layerNum++)
    {
        vector<double> ans(neuronsCapasity[layerNum-1]);
        for(auto& x:ans) x=summ;
        summ=0;
        for (int i = 0; i < neuronsCapasity[layerNum]; i++)
        {
            summ+=layer[layerNum][i].construct(ans);
        }
        
    }
    
    return summ;
}

void PerceptronLayer::learn(double answear, double error)
{
    double inError=0;
    do
    {
        inError=0;           
        
        for (int layerNum = 1; layerNum < layer.size(); layerNum++)
        { 
            
            for (int i = 0; i < neuronsCapasity[layerNum]; i++)
            {
                construct(exInput);
                layer[layerNum][i].learn(answear);
                inError+=answear-construct(exInput);
            }
            // cout<<(double)(layerNum)/(layer.size())*100<<" % "<<layerNum<<endl;
            cout<<inError*100<<endl;
        
        }
    } while (inError>=error);
}

double PerceptronLayer::getError(double answear)
{
    return answear-layer[layer.size()-1][0].getOutPut();
}