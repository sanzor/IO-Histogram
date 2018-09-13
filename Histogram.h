
#include "stdafx.h"
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
#include<string>
#include<fstream>

#define Y 'Y'
#define DOT '.'
#define SIZE 10



class Histogram
{
private:

    std::vector<int> input;
	int histo[SIZE] = { 0 };
	std::vector<std::string> payload;
	
	int Height = 0;

	void Initialize(const int  _input[],int len)
	{
		this->input.resize(len);
		this->Height = input[0];
		
		for (int i = 0; i < this->input.size(); i++)
		{
			this->input[i] = _input[i];
			this->histo[_input[i]]++;
			if (histo[i] > this->Height)
			{
				this->Height = histo[i];
			}
		}
		 
	}
	void ComputeResults()
	{
		this->payload.resize(this->Height);
		std::string inputs, breakline, footer;
		std::vector<std::string>::iterator it = payload.begin();
		std::for_each(this->input.begin(), this->input.end(), [&](int elem) {inputs += (elem + '0'); });

		for (int i = 0; i < SIZE; i++)
		{
			footer += ((i + '0'));
		}
		breakline = std::string(SIZE, DOT);

		for (int i = 0; i < this->Height; i++)
		{
			for (int j = 0; j < SIZE; ++j)
			{
				payload[i] += ((this->histo[j] < this->Height - i) ? DOT : Y);
			}
		}
		payload.insert(it, inputs);
		it = payload.begin();
		payload.insert(it + 1, breakline);
		payload.push_back(footer);
	}

public:

	Histogram( const int _input[],int len)
	{
		Initialize(_input,len);
		ComputeResults();
	}



	std::string * GetStrings()
	{
		std::string *results = new std::string[this->payload.size()];
		for (int i = 0; i < this->payload.size(); i++)
		{
			results[i] = std::string(payload[i]);
		}
		return results;
	}
	void LogToConsole()
	{
		std::cout << "Histogram-Histogram" << std::endl;
		std::for_each(this->payload.begin(), this->payload.end(), [&](std::string elem) {std::cout<< elem << '\n'; });
	}

	void WriteToFile(std::string path)
	{
		std::ofstream file;
		file.open(path);
		file.close();
	}
	
};





