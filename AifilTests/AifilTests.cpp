// AifilTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Вопрос 1
namespace Question1
{
	vector<int> Factorization(int number)
	{
		vector<int> factorization_number;
		for (int multiplier = 2; multiplier <= sqrt(number); multiplier++)
		{
			while (number % multiplier == 0)
			{
				factorization_number.push_back(multiplier);
				number /= multiplier;
			}
		}

		if (number != 1)
			factorization_number.push_back(number);

		return factorization_number;
	}

	vector<vector<int>> FactorizationForNNumber(int n)
	{
		vector<vector<int>> factorization_for_n_number;
		for (int number = 1; number < n+1; number++)
		{
			vector<int> factorization_number = Factorization(number);
			factorization_for_n_number.push_back(factorization_number);
		}

		return factorization_for_n_number;
	}

	void OutputToConsole()
	{
		vector<vector<int>> result;
		char *n = new char[10];
		cin >> n;
		result = FactorizationForNNumber(atoi(n));
		// HACK: Страшные лямбды :(
		std::for_each(
			result.begin(),
			result.end(),
			[](vector<int> multiplieres)
		{
			static int number = 1;
			cout << "For " << number << ": ";
			std::for_each(
				multiplieres.begin(),
				multiplieres.end(),
				[](int multiplier)
				{
					cout << multiplier << " ";
				}
			);
			cout << endl;
			number++;
		}
		);
	}
}



int _tmain(int argc, _TCHAR* argv[])
{
	Question1::OutputToConsole();
		

	return 0;
}

