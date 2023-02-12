#include"MultiPerceptron.h"

MultiPerceptron::MultiPerceptron(uint16_t inputCapasity, uint16_t layersCapasity, uint16_t outputCapasity, double studySpeed)
{
    layers.resize(layersCapasity,vector<Perceptron>(0));
    layers[0]=vector<Perceptron>(inputCapasity);
    layers[layersCapasity-1]=vector<Perceptron>(outputCapasity);
    int param=1;
    if(outputCapasity-inputCapasity<0) param*=-1;
    
    for (int i = 1; i < layers.size()-1; i++)
    {
        if(layers[i-1].size()%2==0)
        {
            if (param>0)
            {
                if(layers[i-1].size()*pow(2,param)<outputCapasity && layers[i-1].size()*pow(2,param)>inputCapasity)
                    layers[i]=vector<Perceptron>(layers[i-1].size()*pow(2,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }
            else
            {
                if(layers[i-1].size()*pow(2,param)>outputCapasity && layers[i-1].size()*pow(2,param)<inputCapasity)
                    layers[i]=vector<Perceptron>(layers[i-1].size()*pow(2,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }  
        }
        else if(layers[i-1].size()%3==0)
        {
            if (param>0)
            {
                if(layers[i-1].size()*pow(3,param)<outputCapasity && layers[i-1].size()*pow(3,param)>inputCapasity)
                    layers[i]=vector<Perceptron>(layers[i-1].size()*pow(3,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }
            else
            {
                if(layers[i-1].size()*pow(3,param)>outputCapasity && layers[i-1].size()*pow(3,param)<inputCapasity)
                    layers[i]=vector<Perceptron>(layers[i-1].size()*pow(3,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }  
        }
        else
        {
            if (param>0)
            {
                if((layers[i-1].size()+1)*pow(2,param)<outputCapasity && (layers[i-1].size()+1)*pow(2,param)>inputCapasity)
                    layers[i]=vector<Perceptron>((layers[i-1].size()+1)*pow(2,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }
            else
            {
                if((layers[i-1].size()+1)*pow(2,param)>outputCapasity && (layers[i-1].size()+1)*pow(2,param)<inputCapasity)
                    layers[i]=vector<Perceptron>((layers[i-1].size()+1)*pow(2,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }
        }
    }
    this->studySpeed=studySpeed;
    for(auto& x:layers[0])
    {
        x.setPerceptron(1);
        x.setLearningSpeed(studySpeed);
    }
    for (int i = 1; i < layers.size(); i++)
    {
        for(auto& layer:layers[i])
        {
            layer.setPerceptron(layers[i-1].size());
            layer.setLearningSpeed(studySpeed);
        }
    }
    
}

void MultiPerceptron::setMultiPerceptron(uint16_t inputCapasity, uint16_t layersCapasity, uint16_t outputCapasity, double studySpeed)
{
    layers.resize(layersCapasity,vector<Perceptron>(0));
    layers[0]=vector<Perceptron>(inputCapasity);
    layers[layersCapasity-1]=vector<Perceptron>(outputCapasity);
    int param=1;
    if(outputCapasity-inputCapasity<0) param*=-1;
    
    for (int i = 1; i < layers.size()-1; i++)
    {
        if(layers[i-1].size()%2==0)
        {
            if (param>0)
            {
                if(layers[i-1].size()*pow(2,param)<outputCapasity && layers[i-1].size()*pow(2,param)>inputCapasity)
                    layers[i]=vector<Perceptron>(layers[i-1].size()*pow(2,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }
            else
            {
                if(layers[i-1].size()*pow(2,param)>outputCapasity && layers[i-1].size()*pow(2,param)<inputCapasity)
                    layers[i]=vector<Perceptron>(layers[i-1].size()*pow(2,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }  
        }
        else if(layers[i-1].size()%3==0)
        {
            if (param>0)
            {
                if(layers[i-1].size()*pow(3,param)<outputCapasity && layers[i-1].size()*pow(3,param)>inputCapasity)
                    layers[i]=vector<Perceptron>(layers[i-1].size()*pow(3,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }
            else
            {
                if(layers[i-1].size()*pow(3,param)>outputCapasity && layers[i-1].size()*pow(3,param)<inputCapasity)
                    layers[i]=vector<Perceptron>(layers[i-1].size()*pow(3,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }  
        }
        else
        {
            if (param>0)
            {
                if((layers[i-1].size()+1)*pow(2,param)<outputCapasity && (layers[i-1].size()+1)*pow(2,param)>inputCapasity)
                    layers[i]=vector<Perceptron>((layers[i-1].size()+1)*pow(2,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }
            else
            {
                if((layers[i-1].size()+1)*pow(2,param)>outputCapasity && (layers[i-1].size()+1)*pow(2,param)<inputCapasity)
                    layers[i]=vector<Perceptron>((layers[i-1].size()+1)*pow(2,param));
                else
                    layers[i]=vector<Perceptron>(layers[i-1].size());
            }
        }
    }
    this->studySpeed=studySpeed;
    for(auto& x:layers[0])
    {
        x.setPerceptron(1);
        x.setLearningSpeed(studySpeed);
    }
    for (int i = 1; i < layers.size(); i++)
    {
        for(auto& layer:layers[i])
        {
            layer.setPerceptron(layers[i-1].size());
            layer.setLearningSpeed(studySpeed);
        }
    }
}

vector<double> MultiPerceptron::construct(const vector<double>& parametrs)
{    
    exInput=parametrs;
    for (int i = 0; i < layers[0].size(); i++)
    {
        layers[0][i].construct({parametrs[i]});
    }
    for (int i = 1; i < layers.size(); i++)
    {
        vector<double> summ;
        for(auto& layer:layers[i-1])
        {
            summ.push_back(layer.getOutPut());
        }
        for(auto& layer:layers[i])
        {
            layer.construct(summ);
        }
    }
    vector<double> summ;
    for(auto& x : layers[layers.size()-1])
    {
        summ.push_back(x.getOutPut());
    }
    return summ;
}

void MultiPerceptron::learn(vector<double>& answear)
{
    for (int i = 0; i < layers[layers.size()-1].size(); i++)
    {
        layers[layers.size()-1][i].learn(answear[i]);
    }
    for (int i = layers.size()-2; i >= 0; i--)
    {
        for (int j = 0; j < layers[i].size(); j++)
        {
            double err=0;
            for (int k = 0; k < layers[i+1].size(); k++)
            {
                err+=layers[i+1][k].getError()[j];
            }
            
            layers[i][j].learnWithError(err);
        }
        
    }
       
}

double MultiPerceptron::getError(vector<double>& answear)
{
    vector<double> ans=construct(exInput);
    double error=0;
    for (int i = 0; i < ans.size(); i++)
    {
        error+=abs(answear[i]-ans[i]);
    }
    return error;
}