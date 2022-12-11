#include "Matrix.h"

Matrix::Matrix(Neuron::Function Type)
{
	type = Type;
}

void Matrix::learn()
{
	for (int i = 0; i < 16; i++)
	{
		if (i % 4 == 0) cout << endl;
		cin >> matrix[i];
	}

	cin >> vertical >> gorizontal;

	Neuron cell1[16];
	Neuron cell2[2];


	for (int i = 0; i < 16; i++)
	{
		cell1[i].setValue(matrix[i], type);
	}

	cell2[0].setValue(vertical, type);
	cell2[1].setValue(gorizontal, type);


	ofstream file;
	file.open("Brain.txt"/*, ios::app*/);
	file << "//\n";
	for (int i = 0; i < 16; i++)
	{
		file << to_string(matrix[i] / cell1[i].getActivatedValue()) << "\n";
		file << to_string(matrix[i] / cell1[i].getActivatedValue()) << "\n";
	}
	file.close();
}

void Matrix::play()
{
	for (int i = 0; i < 16; i++)
	{
		if (i % 4 == 0) cout << endl;
		cin >> matrix[i];
	}

	string buffer;

	Neuron cell1[16];
	Neuron cell2[2];

	for (int i = 0; i < 16; i++)
	{
		cell1[i].setValue(matrix[i]);
	}

	double sp[32];
	sp[0] = 0.0f;
	ifstream OpenFile;
	OpenFile.open("Brain.txt");
	int i = 0;
	while (i<33)
	{
		getline(OpenFile, buffer);
		if (i > 0)
		{
			sp[i - 1] = stod(buffer);
		}
		i++;
	}
	OpenFile.close();

	double branch1 = 0, branch2 = 0;
	for (int i = 0; i < 33; i += 2)
	{
		branch1 += matrix[i] * sp[i];
		branch2 += matrix[i] * sp[i + 1];
	}
	cell2[0].setValue(branch1, type);
	cell2[1].setValue(branch2, type);
	vertical = cell2[0].getActivatedValue();
	gorizontal = cell2[1].getActivatedValue();

	cout << cell2[0].getActivatedValue() << "\t" << cell2[1].getActivatedValue();
}
