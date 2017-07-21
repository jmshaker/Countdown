// Countdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


bool solve(int input[], char operatorsarray[])
{
	bool solved = false;
	int total = input[0];

	/*for (int i = 0; i < 7; i++)
	{
		cout << input[i] << "\n\n";
	}
	*/
	

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
		solutions = solutions + 1;
		solved = true;
	}

	if (solutions != 0)
	{
		cout << "\n\nNumber of solutions found:" << solutions;
	}

	return solved;
}

void operatorsarraygenerator(int input[])
{
	char operators[4] = { '+', '-', 'x', '/' };
	char operatorsarray[5];

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
						operatorsarray[0] = operators[x];
						solve(input, operatorsarray);
					}
					operatorsarray[1] = operators[y];
					solve(input, operatorsarray);
				}
				operatorsarray[2] = operators[z];
				solve(input, operatorsarray);
			}
			operatorsarray[3] = operators[a];
			solve(input, operatorsarray);
		}
		operatorsarray[4] = operators[b];
		solve(input, operatorsarray);
	}

}

void swap(int temparray[], int i, int j)
{
	int temp = temparray[i];
	temparray[i] = temparray[j];
	temparray[j] = temp;
}

void print_array(const int temparray[], int size)
{
	static int count = 0;
	std::cout << std::setw(3) << ++count << ". ";
	for (int i = 0; i < size; ++i) std::cout << temparray[i] << ' ';
	std::cout << '\n';
}

void permute(int temparray[], int size, int from = 0)
{
	if (from == size) 
	{

		operatorsarraygenerator(temparray);

		//return print_array(temparray, size);
	}
	for (int i = from; i < size; ++i)
	{
		swap(temparray, from, i);
		permute(temparray, size, from+1);
		swap(temparray, from, i);
	}
}

int main(int argc, int argv[6])
{
	int input[7];
	std::cout << "Please enter 6 numbers and a target number.\n\n";
	std::cin >> argv[0] >> argv[1] >> argv[2] >> argv[3] >> argv[4] >> argv[5] >> argv[6];
	for (int i = 0; i < 7; i++)
	{
		input[i] = argv[i];
	}

	bool solved = false;
	std::cout << "\n\nAttempting to solve...\n\n";

	int temparray[6] = { input[0], input[1], input[2], input[3], input[4], input[5]};

	permute(temparray, sizeof(temparray) / sizeof(temparray[0]));

	if (solved == true) {
		cout << "\n\nI win!";
	}
	else
	{
		cout << "\n\nI cannot find a solution! You win...";
	}

	return 0;
}