// AifilTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
char *optarg = nullptr;
int optind = 1;
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
		// HACK: �������� ������ :(
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
		// ����� ������� ������ ����� ������� ������� �� �����
		// (����� vector_.size() = 8, parts_number_ = 5, �����
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
		// HACK: �������� ������ :(
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



namespace Question4
{
	template <class T>
	struct SNodeList {
		T data;
		SNodeList *next;
	};

	template <class T>
	class CList {
	private:
		SNodeList<T> *m_head, *m_tail;
	public:
		CList() :
			m_head(nullptr),
			m_tail(nullptr){}

		void Add(T data_)
		{
			SNodeList<T> *temp_node = new SNodeList<T>();
			temp_node->data = data_;
			temp_node->next = nullptr;
			if (m_head != nullptr)
			{
				m_tail->next = temp_node;
				m_tail = temp_node;
			}
			else
			{
				m_head = m_tail = temp_node;
			}				
		}
		
		void Show()
		{
			SNodeList<T> *temp_node = m_head;
			while (temp_node != nullptr)
			{
				cout << temp_node->data << " ";
				temp_node = temp_node->next;
			}
			cout << endl;
		}

		template <class T>
		SNodeList<T> * FindTail(SNodeList<T> *list_)
		{
			while (list_->next != nullptr)
				list_ = list_->next;

			return list_;
		}

		// ���������������, ������� ������
		template <class T>
		void ReepackingChenge()
		{
			SNodeList <T> *clone_vector = m_head;
			while (clone_vector != nullptr && clone_vector->next != nullptr && clone_vector->next->next != nullptr)
			{									
				SNodeList <T> *previous = FindPenultimate(m_head);
				SNodeList <T> *next = clone_vector->next;
				Insert(clone_vector, clone_vector->next, previous, m_tail);
				m_tail = previous;
				clone_vector = next;
			}
		}
				
		void Insert(
			SNodeList<T> *previous,
			SNodeList<T> *next_, 
			SNodeList<T> *previous_added_,
			SNodeList<T> *added_)
		{			
			previous->next = added_;
			previous_added_->next = added_->next;
			added_->next = next_;
		}

		template <class T>
		SNodeList<T> * FindPenultimate(SNodeList<T> *list_)
		{
			while (list_->next->next != nullptr)
			{
				list_ = list_->next;				
			}				

			return list_;
		}

	};

}


#include <stdio.h>



int main(int argc, char * argv[]) {

	Question4::CList<int> *list = new Question4::CList<int>();
	list->Add(1);
	list->Add(2);
	list->Add(3);
	//list->Add(4);
	//list->Add(5);
	//list->Add(6);
	//list->Add(7);
	//list->Add(8);
	list->Show();

	list->ReepackingChenge<int>();
	list->Show();
	

}
