#include<Histogram.h>
#include<Calculator.h>

int main()
{
	int input[8]{ 2, 3, 5, 5, 5, 2, 0, 8 };
	int len = sizeof(input )/ sizeof(input[0]);
	Histogram var(input,len);
	var.WriteToFile("c:\test2.txt");
	var.LogToConsole();
	return 0;
}