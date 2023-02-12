#pragma once
#include"Perceptron.h"
#include<fstream>
#include<string>
#include<iostream>
#include<vector>
using namespace std;


class MNIST
{
public:
	MNIST(string testFileName, string labelFileName);

	void read(uint32_t count);

	std::vector<uint8_t> getTest(int num) const;
	std::vector<std::vector<uint8_t>> getMatrix(uint8_t aN, uint8_t aM) const;
	uint8_t getLabel(int num) const;
private:
	ifstream testsFile, labelsFile;

	uint32_t testMagicNumber;
	uint32_t testNumberOfImages;
	uint32_t testRows;
	uint32_t testColumns;

	uint32_t labelMagicNumber;
	uint32_t labelNumberOfImages;

	uint32_t readCount;

	vector<std::vector<uint8_t>> testValues;
	vector<uint8_t> labelValues;

    uint32_t reverseInt(uint32_t arg);
};