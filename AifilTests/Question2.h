#include "stdafx.h"

using namespace std;

// ¬опрос 2
// Ќапишите код, который решает следующую задачу :
// »меетс€ вектор размера N.Ќеобходимо разделить его на M < N равных частей(то есть чтобы 
// количество элементов в каждой части было одинаковым).
// „асти не должны пересекатьс€ и должны покрывать весь вектор 
// (исключение - допускаютс€ промежутки от начала вектора до начала первой части
// и от конда последней части до конца вектора, но в этом случае необходимо добитьс€, 
// чтобы разница в величине этих промежутков была минимальной).
// –езультатом должны €вл€тьс€ индексы начала и конца каждой части(либо вывод на экран, 
// либо сохранение в любую структуру данных).

namespace Question2
{
	template <class T>
	vector<pair<int, int>> SplitVector(vector<T> _vector, int _parts_number)
	{
		vector<pair<int, int>> indexes_splited_vector;
		int length_part = _vector.size() / _parts_number;
		// ќбщий остаток частей после делени€ вектора на части
		// (пусть vector_.size() = 8, parts_number_ = 5, тогда
		// total_parts_remainder = 3;
		// left_parts_remainder  = 1;
		// right_parts_remainder = 2;
		int total_parts_remainder = _vector.size() - (length_part * _parts_number);
		int right_remainder       = total_parts_remainder / 2;
		int left_remainder        = total_parts_remainder - right_remainder;

		for (int i = right_remainder; i < _vector.size() - left_remainder; i += length_part)
			indexes_splited_vector.push_back(make_pair(i, i + length_part - 1));

		return indexes_splited_vector;
	}

	void PrintExample()
	{
		vector<pair<int, int>> result;
		vector<int> input_vector{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		char *n = new char[10];
		cout << "Input parts number: ";
		cin >> n;		
		result = SplitVector(input_vector, atoi(n));
		// HACK: —трашные л€мбды :(
		std::for_each(
			result.begin(),
			result.end(),
			[](pair<int, int> pairs)
			{
				cout << pairs.first << " " << pairs.second << endl;;

			});
	}
}