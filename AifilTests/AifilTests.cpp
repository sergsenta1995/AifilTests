// AifilTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

namespace Question2
{	
	template <class T>
	vector<pair<int, int>> SplitVector(vector<T> vector_, int parts_number_)
	{
		vector<pair<int, int>> indexes_splited_vector;
		int length_part = vector_.size() / parts_number_;
		// Общий остаток частей после деления вектора на части
		// (пусть vector_.size() = 8, parts_number_ = 5, тогда
		// total_parts_remainder = 3;
		// left_parts_remainder = 1;
		// right_parts_remainder = 2;
		int total_parts_remainder = vector_.size() - (length_part * parts_number_);		
		int right_remainder = total_parts_remainder / 2;
		int left_remainder = total_parts_remainder - right_remainder;
		
		for (int i = right_remainder; i < vector_.size() - left_remainder; i += length_part)
			indexes_splited_vector.push_back(make_pair(i,i+length_part-1));

		return indexes_splited_vector;
	}

	void OutputToConsole()
	{		
		vector<pair<int, int>> result;
		vector<int> input_vector{1, 2, 3, 4, 5, 6, 7, 8, 9};
		char *n = new char[10];
		cin >> n;
		result = SplitVector(input_vector, atoi(n));
		// HACK: Страшные лямбды :(
		std::for_each(
			result.begin(),
			result.end(),
			[](pair<int, int> pairs)
			{
				cout << pairs.first << " " << pairs.second << endl;;
			
			}
		);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Question2::OutputToConsole();
		

	return 0;
}

