// #include<opencv2/opencv.hpp>
#include<stdint.h>
#include<vector>
#include"Neuron.h"
#include"NeuronNetwork.h"
#include<iostream>
using namespace std;
// using namespace cv;

#define PATH "bird.jpg"
#define E 2.718281828459045

double f(double x)
{
    return 1 / (1 + pow(E, -x));
}

int main()
{
    /*Mat original = imread(PATH, cv::ImreadModes::IMREAD_COLOR);
    Mat modified = imread(PATH, cv::ImreadModes::IMREAD_COLOR);

    Mat splitChannels[3];

    split(original, splitChannels);

    imshow("B", splitChannels[0]);
    imshow("G", splitChannels[1]);
    imshow("R", splitChannels[2]);


    splitChannels[2] = Mat::zeros(splitChannels[2].size(), CV_8UC1);

    Mat outPut;

    merge(splitChannels, 3, outPut);


    namedWindow("Mereged", cv::WindowFlags::WINDOW_FREERATIO);

    imshow("Mereged", outPut);
    waitKey();*/

    
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


    NeuronNetwork gorisontal(9,5,2,1);
    NeuronNetwork vertical(9,5,2,1);
    // gorisontal.loadFromFile("brain1.txt");
    // vertical.loadFromFile("brain2.txt");

    while (true)
    {   
    
        double field[9];
        for(int x=0;x<9;x++)
        {
            cin>>field[x];
        }
        

        double gor,ver;
        cin>>gor>>ver;

        if(gor==-1 || ver==-1) break;
        gorisontal.learn(field,gor,true,0.7,0.3,0.0001);
        gorisontal.saveResults("brain1.txt");
        gorisontal.learn(field,gor,true,0.7,0.3,0.0001);
        gorisontal.saveResults("brain1.txt");
        vertical.learn(field,ver,true,0.7,0.3,0.0001);
        vertical.saveResults("brain2.txt");
        vertical.learn(field,ver,true,0.7,0.3,0.0001);
        vertical.saveResults("brain2.txt");
    }

    double field[9];
    for(int x=0;x<9;x++)
    {
        cin>>field[x];
    }

    gorisontal.loadFromFile("brain1.txt");
    vertical.loadFromFile("brain2.txt");
    cout<<gorisontal.run(field)<<"\t"<<vertical.run(field);

    // NeuronNetwork a(2,2);
    // double b[2];
    // b[0]=1;
    // b[1]=0;
    // a.learn(b,false,true,0.7,0.3,0.01);
    // cout<<a.run(b);
}
