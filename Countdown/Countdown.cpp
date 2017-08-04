// Countdown.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


void solve(int input[], char operatorsarray[])
{
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
		solutions = solutions + 1;
	}
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

void permute(int temparray[], int size, int from = 0)
{
	if (from == size)
	{
		operatorsarraygenerator(temparray);
	}
	for (int i = from; i < size; ++i)
	{
		swap(temparray, from, i);
		permute(temparray, size, from + 1);
		swap(temparray, from, i);
	}
}

int main(int argc, int argv[6])
{
	std::cout << "Please enter 6 numbers and a target number.\n\n";
	std::cin >> argv[0] >> argv[1] >> argv[2] >> argv[3] >> argv[4] >> argv[5] >> argv[6];

	int temparray[7] = { argv[0], argv[1], argv[2], argv[3], argv[4], argv[5], argv[6] };
	std::cout << "\n\nAttempting to solve...\n\n";
	permute(temparray, (sizeof(temparray) / sizeof(temparray[0])) - 1);

	return 0;
}
