#include<stdint.h>
#include<vector>
#include"Neuron.h"
#include"NeuronNetwork.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define PATH "bird.jpg"
#define E 2.718281828459045

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
    /*double input, output;
    cin >> input >> output;
    Neuron a(input,Neuron::SIGM);
    Neuron b(output,Neuron::SIGM);
    cout << a.getActivatedValue() << endl << b.getDerivedValue() << endl;
    cout << b.getDerivedValue() / a.getActivatedValue();*/

    /*Matrix mat;
    mat.learn();
    mat.play();*/


    // double error, output, ideal = 1.0;
    // double sinops[6] = { 0.45,0.78,-0.12,0.13,1.5,-2.3 };

    // Neuron a(1 * sinops[0] + 0 * sinops[2]);
    // Neuron b(1 * sinops[1] + 0 * sinops[3]);
    // Neuron c(a.getActivatedValue() * sinops[4] + b.getActivatedValue() * sinops[5]);
    // output = c.getActivatedValue();
    // cout << output << endl;
    // double cd, ad, bd;
    // error = pow(ideal - output, 2);
    // cd = (ideal - output) * c.getDerivedValue();
    // cout << cd << endl;
    // c.setValue(cd);
    // ad = c.getDerivedValue() * (cd * sinops[4]);
    // cout << ad << endl;
    // double GRADw5 = c.getActivatedValue() * cd;
    // cout << GRADw5 << endl;
    // sinops[4] += 0.7 * GRADw5 + 0 * 0.3;
    // cout << sinops[4]<<endl;

    // int* a = new int[2] {1, 3};
    // int* b = new int[4] {1, 2, 3, 4};
    // Neuron* c = new Neuron[2];
    // c = NULL;
    // while (&c[0])
    // {
    //     cout << 1;
    // }
    // if (&c[0])
    // {
    //     cout << 1;
    // }
    // else {
    //     cout << 0;
    // }


    // NeuronNetwork gorisontal(9,5,2,1);
    // NeuronNetwork vertical(9,5,2,1);
    // gorisontal.loadFromFile("brain1.txt");
    // vertical.loadFromFile("brain2.txt");

    // while (true)
    // {   
    
    //     double field[9];
    //     for(int x=0;x<9;x++)
    //     {
    //         cin>>field[x];
    //     }
        

    //     double gor,ver;
    //     cin>>gor>>ver;

    //     if(gor==-1 || ver==-1) break;
    //     gorisontal.learn(field,gor,true,0.7,0.3,0.0001);
    //     gorisontal.saveResults("brain1.txt");
    //     gorisontal.learn(field,gor,true,0.7,0.3,0.0001);
    //     gorisontal.saveResults("brain1.txt");
    //     vertical.learn(field,ver,true,0.7,0.3,0.0001);
    //     vertical.saveResults("brain2.txt");
    //     vertical.learn(field,ver,true,0.7,0.3,0.0001);
    //     vertical.saveResults("brain2.txt");
    // }

    // double field[9];
    // for(int x=0;x<9;x++)
    // {
    //     cin>>field[x];
    // }

    // gorisontal.loadFromFile("brain1.txt");
    // vertical.loadFromFile("brain2.txt");
    // cout<<gorisontal.run(field)<<"\t"<<vertical.run(field);

    // NeuronNetwork a(2,2);
    // double b[2];
    // b[0]=1;
    // b[1]=0;
    // a.learn(b,false,true,0.7,0.3,0.01);
    // cout<<a.run(b);

    // Neuron a(1),b;
    // double sinops=0.1;
    // b.setValue(a.getActivatedValue()*sinops);
    // cout<<b.getActivatedValue()<<endl<<pow(0-b.getActivatedValue(),2)<<endl;
    // double grad=(0-0.33)*b.getDerivedValue();
    // cout<<0.7*grad<<endl;
    // cout<<sinops+0.7*grad;

    // NeuronNetwork ab(1,1);
    // double x[]={1};
    // ab.learn(x,0,false,0.3,0.7,0.01);
    // double l[]={45};
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

    NeuronNetwork setosa(4,10);
    NeuronNetwork virginica(4,10);
    NeuronNetwork versicolor(4,10);
    bool bias=true;
    Neuron::Function func=Neuron::SIGM;

    for (auto& iris:priznak)
    {
        double pri[]={iris.dlinaChashelistnika,iris.shirinaChashelistnika,iris.dlinaLepestka,iris.shirinaLepestka};
        if(iris.type=="setosa")
        {
            setosa.learn(pri,true,bias,0.3,0.7,0.001, func);
            virginica.learn(pri,false,bias,0.3,0.7,0.001, func);
            versicolor.learn(pri,false,bias,0.3,0.7,0.001, func);
        }
        if(iris.type=="virginica")
        {
            setosa.learn(pri,false,bias,0.3,0.7,0.001, func);
            virginica.learn(pri,true,bias,0.3,0.7,0.001, func);
            versicolor.learn(pri,false,bias,0.3,0.7,0.001, func);
        }
        if(iris.type=="versicolor")
        {
            setosa.learn(pri,false,bias,0.3,0.7,0.001, func);
            virginica.learn(pri,false,bias,0.3,0.7,0.001, func);
            versicolor.learn(pri,true,bias,0.3,0.7,0.001, func);
        }
    }


    double pri[4];
    cout<<L"Ввидите признаки:\n1. Длинна чашелистника\n2. Ширина Чашелистника\n1. Длинна лепестка\n2. Ширина лепестка\n";

    for(auto& x:pri)
    {
        cin>>x;
    }

    cout<<setosa.run(pri, func)<<endl<<virginica.run(pri, func)<<endl<<versicolor.run(pri, func);
}
