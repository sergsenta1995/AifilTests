#include "stdafx.h"

using namespace std;

// ������ 2
// �������� ���, ������� ������ ��������� ������ :
// ������� ������ ������� N.���������� ��������� ��� �� M < N ������ ������(�� ���� ����� 
// ���������� ��������� � ������ ����� ���� ����������).
// ����� �� ������ ������������ � ������ ��������� ���� ������ 
// (���������� - ����������� ���������� �� ������ ������� �� ������ ������ �����
// � �� ����� ��������� ����� �� ����� �������, �� � ���� ������ ���������� ��������, 
// ����� ������� � �������� ���� ����������� ���� �����������).
// ����������� ������ �������� ������� ������ � ����� ������ �����(���� ����� �� �����, 
// ���� ���������� � ����� ��������� ������).

namespace Question2
{
	template <class T>
	vector<pair<int, int>> SplitVector(vector<T> _vector, int _parts_number)
	{
		vector<pair<int, int>> indexes_splited_vector;
		int length_part = _vector.size() / _parts_number;
		// ����� ������� ������ ����� ������� ������� �� �����
		// (����� vector_.size() = 8, parts_number_ = 5, �����
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
		// HACK: �������� ������ :(
		std::for_each(
			result.begin(),
			result.end(),
			[](pair<int, int> pairs)
			{
				cout << pairs.first << " " << pairs.second << endl;;

			});
	}
}