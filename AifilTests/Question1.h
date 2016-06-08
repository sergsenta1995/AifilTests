#ifndef QUESTION_1
#define QUESTION_1

#include "stdafx.h"
using namespace std;

// Вопрос 1
// Напишите функцию, которая перебирает натуральные числа от 1 до N включительно
// и раскладывает каждое число на простые множители.
// Результат можно выводить на экран либо копить в любой структуре данных.
namespace Question1
{
	vector<int> Factorization(int _number)
	{
		vector<int> factorization_number;
		for (int multiplier = 2; multiplier <= sqrt(_number); multiplier++)
		{
			while (_number % multiplier == 0)
			{
				factorization_number.push_back(multiplier);
				_number /= multiplier;
			}
		}

		// Остался последний множитель.
		if (_number != 1)
			factorization_number.push_back(_number);

		return factorization_number;
	}

	vector<vector<int>> FactorizationForNNumber(int _n)
	{
		vector<vector<int>> factorization_for_n_number;
		for (int number = 1; number < _n + 1; number++)
		{
			vector<int> factorization_number = Factorization(number);
			factorization_for_n_number.push_back(factorization_number);
		}

		return factorization_for_n_number;
	}

	void PrintExample()
	{
		vector<vector<int>> result;
		char *n = new char[10];
		cout << "Input N: ";
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
		});
	}
}


#endif
