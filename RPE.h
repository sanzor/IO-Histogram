#include<iostream>

class Calculator
{
private:
	std::vector<char>Signs{ '+' ,'-','*','/' };
	std::string input;
	bool Compute(const int& a, const int &b, const  char& operation, double &result)
	{
		double rez = 0;
		if (std::find(Signs.begin(), Signs.end(), operation) == Signs.end())
		{
			return false;
		}
		if (operation == '/' && b == 0  || (a==0 && b==0))
		{
			return false;
		}
		switch (operation)
		{
		case '+': {rez = a + b; break; }
		case '-': {rez = a - b; break; }
		case '/': {rez = a / b; break; }
		case '*': {rez = a * b; break; }
		}
		return rez;
	}
public:
	
	Calculator(const std::string & _input)
	{
		this->input = _input;
	}
	bool Parse(double & result)
	{
		int count=0;
		bool implemented = true;
		int operatorIndex = 0;
		for (int i = 0; i < this->input.length(); i++) {
			if (std::find(this->Signs.begin(), this->Signs.end(), input[i])!=Signs.end())
			{
				count++;
				operatorIndex = i;
			}
			if (count > 1)
			{
				implemented = false;
				break;
			}
		}
		if (!implemented)
		{
			return false;
		}
		double operand1, operand2;
		
		operand1 = std::atoi(std::string(input.begin(), input.begin() + operatorIndex + 1).c_str());
		operand2= std::atoi(std::string(input.begin()+operatorIndex+1, input.end()).c_str());
		return Compute(operand1, operand2, input[operatorIndex], result);
	}
	
};