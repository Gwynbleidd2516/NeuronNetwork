#include"MNIST.h"

uint32_t MNIST::reverseInt(uint32_t arg)
{
    int result = 0;
	for (uint8_t i = 0; i < 4; ++i)
	{
		result <<= 8;
		result += arg & 255;
		arg >>= 8;
	}
	return result;
}

MNIST::MNIST(string testFileName, string labelFileName)
{
    testsFile.open(testFileName, ios::binary);
    labelsFile.open(labelFileName, ios::binary);

    if (!testsFile.is_open())
	{
		cout << "ERROR #F1: tests file doesn't open!\n";
		cout << "Path: " << testFileName << "\n";
	}
	if (!labelsFile.is_open())
	{
		cout << "ERROR #F2: label file doesn't open!\n";
		cout << "Path: " << labelFileName << "\n";
	}

    uint32_t* testVariables[] = { &testMagicNumber,  &testNumberOfImages,
		&testRows, &testColumns };
	for (uint8_t i = 0; i < 4; ++i)
	{
		testsFile.read((char*)testVariables[i], sizeof(*(testVariables[i])));
		*(testVariables[i]) = reverseInt(*(testVariables[i]));
	}

	if (testMagicNumber != 2051)
	{
		cout << "ERROR #C1: wrong test magic number!\n";
		cout << "Magic number: " << testMagicNumber << " (correct: 2051)\n";
	}

	uint32_t* labelVariables[] = { &labelMagicNumber,  &labelNumberOfImages };
	for (uint8_t i = 0; i < 2; ++i)
	{
		labelsFile.read((char*)labelVariables[i], sizeof(*(labelVariables[i])));
		*(labelVariables[i]) = reverseInt(*(labelVariables[i]));
	}

	if (labelMagicNumber != 2049)
	{
		cout << "ERROR #C2: wrong label magic number!\n";
		cout << "Magic number: " << labelMagicNumber << " (correct: 2049)\n";
	}
}

void MNIST::read(uint32_t count)
{
    for (uint32_t i = 0; i < count; ++i)
	{
		testValues.emplace_back(std::vector<uint8_t >(0));
		readCount++;
		unsigned char temp;

		for (uint32_t i = 0; i < testRows; ++i)
		{
			for (uint32_t j = 0; j < testColumns; ++j)
			{
				testsFile.read((char*)&temp, sizeof(temp));
				testValues.back().emplace_back(temp);
			}
		}

		labelsFile.read((char*)&temp, sizeof(temp));
		labelValues.emplace_back(temp);
		cout<<(double)i/(double)count*100<<" %" << " of scannning!"<<endl;
	}
}

vector<uint8_t> MNIST::getTest(int num) const
{
	return testValues[num];
}

vector<std::vector<uint8_t>> MNIST::getMatrix(uint8_t aN, uint8_t aM) const
{
	std::vector<std::vector<uint8_t>> result;

	const std::vector<uint8_t>& val = testValues.front();
	for (uint8_t i = 0; i < aM; ++i)
	{
		result.emplace_back(val.begin() + aN * i, val.begin() + aN * (i + 1));
	}

	return result;
}

uint8_t MNIST::getLabel(int num) const
{
	return labelValues[num];
}