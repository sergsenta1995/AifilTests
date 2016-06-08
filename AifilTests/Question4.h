#include "stdafx.h"

using namespace std;

// Имеется простой односвязный список размера N. Необходимо реализовать алгоритм, 
//который перепаковывает список так, чтобы за первым элеметом следовал последний, 
// затем второй, затем предпоследний и т. д. 
// Пример работы алгоритма:
// исходный список : 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8
// перепакованный список : 1 - 8 - 2 - 7 - 3 - 6 - 4 - 5.
// Оценить сложность предложенного алгоритма.

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
		
		void Add(T _data)
		{
			SNodeList<T> *temp_node = new SNodeList<T>();
			temp_node->data = _data;
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

		// Переупаковывает, изменяя вектор		
		void RepackingChange()
		{
			SNodeList <T> *clone_vector = m_head;
			while (clone_vector != nullptr && clone_vector->next != nullptr && clone_vector->next->next != nullptr)
			{				
				SNodeList <T> *previous = FindPrevious(m_head);
				SNodeList <T> *next = clone_vector->next;
				Insert(clone_vector, clone_vector->next, previous, m_tail);
				m_tail = previous;
				clone_vector = next;
			}
		}

		// Вставляет _insertable между _previous и _next
		void Insert(
			SNodeList<T> *_previous,
			SNodeList<T> *_next,
			SNodeList<T> *_previous_insertable_,
			SNodeList<T> *_insertable)
		{
			_previous->next = _insertable;
			_previous_insertable_->next = _insertable->next;
			_insertable->next = _next;
		}
		
		
		SNodeList<T> * FindPrevious(SNodeList<T> *list_)
		{
			while (list_->next->next != nullptr)
			{
				list_ = list_->next;
			}

			return list_;
		}

	};

	void PrintExample()
	{
		CList<int> *list = new CList<int>();
		list->Add(1);
		list->Add(2);
		list->Add(3);
		//list->Add(4);
		//list->Add(5);
		//list->Add(6);
		//list->Add(7);
		//list->Add(8);
		cout << "Before:" << endl;
		list->Show();
		cout << "After: " << endl;
		list->RepackingChange();
		list->Show();
	}
}
