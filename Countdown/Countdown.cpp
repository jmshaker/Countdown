// Countdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


void solve(int input[], char operatorsarray[])
{
	//std::cout << input[4];
	//std::cout << operatorsarray[0] << " " << operatorsarray[1] << operatorsarray[2] << operatorsarray[3] << operatorsarray[4];
	int total = input[0];
	for (int i = 0; i < 5; i++)
	{
		switch (operatorsarray[i])
		{
		case '+':
			total = total + input[i + 1];
			break;
		case '-':
			total = total - input[i + 1];
			break;
		case 'x':
			total = total * input[i + 1];
			break;
		case '/':
			if ((input[i + 1]) == 0) 
			{
			}
			else 
			{
				total = total / input[i + 1];
			}
			break;
		default:
			break;
		} 
	}
	
	int solutions = 0;

	if (total == input[6])
	{
		cout << "\n\nFound a correct combination! " << std::to_string(input[0]) << " " << operatorsarray[0] << " " << std::to_string(input[1]) << " " << operatorsarray[1] << " " << std::to_string(input[2]) << " " << operatorsarray[2] << " " << std::to_string(input[3]) << " " << operatorsarray[3] << " " << std::to_string(input[4]) << " " << operatorsarray[4] << " " << std::to_string(input[5]) << /* " " << operatorsarray[5] */ " = " << std::to_string(input[6]);
		//cout << "test";
		solutions = 1;
	}

	if (solutions != 0) 
	{
		cout << "\n\nNumber of solutions found:" << solutions;
	}
}

int main(int argc, int argv[6])
{
	int input[7];
	std::cout << "Please enter 6 numbers and a target number.\n\n";
	std::cin >> argv[0] >> argv[1] >> argv[2] >> argv[3] >> argv[4] >> argv[5] >> argv[6];
	for (int i=0;i<7;i++)
	{
		input[i] = argv[i];
	}
	char operators[4] = { '+', '-', 'x', '/' };
	char operatorsarray[5];
	std::cout << "\n\nAttempting to solve...\n\n";
	for (int b = 0; b < 4; b++)
	{
		for (int a = 0; a < 4; a++)
		{
			for (int z = 0; z < 4; z++)
			{
				for (int y = 0; y < 4; y++)
				{
					for (int x = 0; x < 4; x++)
					{
						operatorsarray[1] = operators[x];
						solve(input, operatorsarray);
					}
					operatorsarray[2] = operators[y];
					solve(input, operatorsarray);
				}
				operatorsarray[3] = operators[z];
				solve(input, operatorsarray);
			}
			operatorsarray[4] = operators[a];
			solve(input, operatorsarray);
		}
		operatorsarray[5] = operators[b];
		solve(input, operatorsarray);
	}
	
    
	return 0;
}