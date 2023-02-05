#include"PerceptronLayer.h"

PerceptronLayer::PerceptronLayer(int inputCpasity, int layerCapasity, double studySpeed)
{
    this->studySpeed=studySpeed;
    layer.resize(layerCapasity, vector<Perceptron>(inputCpasity));
    exInput.resize(inputCpasity);
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
    exInput.resize(inputCpasity);
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
    construct(exInput);
    double inError=0;
    do
    {
        // inError=0;
        // for (int i = 0; i < neuronsCapasity[0]; i++)
        // {
        //     construct(exInput);
        //     layer[0][i].learn(answear);
        // }                  
        
        // for (int layerNum = 1; layerNum < layer.size(); layerNum++)
        // { 
            
        //     for (int i = 0; i < neuronsCapasity[layerNum]; i++)
        //     {
        //         construct(exInput);
        //         layer[layerNum][i].learn(answear);
        //         inError+=answear-construct(exInput);
        //     }
        //     // cout<<(double)(layerNum)/(layer.size())*100<<" % "<<layerNum<<endl;
        //     cout<<"error "<<inError<<endl;
        
        // }

        inError=0;

        layer[layer.size()-1][0].learn(answear);

        for (int layerNum = layer.size()-2; layerNum > 0; layerNum--)
        { 
            
            for (int i = 0; i < neuronsCapasity[layerNum]; i++)
            {
                double m_error=0;
                for (int y = 0; y < neuronsCapasity[layerNum+1]; y++)
                {
                    m_error+=layer[layerNum+1][y].getError()[i];
                }
                m_error/=layer[layerNum+1].size();
                layer[layerNum][i].learnWithError(m_error);
            }
            // cout<<(double)(layerNum)/(layer.size())*100<<" % "<<layerNum<<endl;
            
        }
        inError+=answear-construct(exInput);
        cout<<endl<<"error "<<inError<<" "<<this<<endl;
        
    } while (abs(inError)>=error);
}

double PerceptronLayer::getError(double answear)
{
    return answear-layer[layer.size()-1][0].getOutPut();
}