#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <exception>
#include <stdexcept>

namespace algo
{
	template <typename T>
	class node
	{
	public:
		T data;
		node<T>* next = nullptr;
		node<T>* prev = nullptr;

		node(T data) :data(data) {};
		node() { this->data = NULL; }
	};

	template <typename T>
	class LL
	{
		node<T>* head = nullptr;
		node<T>* tail = nullptr;
		int size = 0;
	public:
		void AddToTail(T dane)//Dodanie na koncu
		{
			if (tail == nullptr)
			{
				head = new node<T>(dane);
				tail = head;
				head->next = nullptr;
				head->prev = nullptr;
			}
			else
			{
				node<T>* temp = new node<T>(dane);
				temp->prev = tail;
				tail->next = temp;
				tail = temp;
				tail->next = nullptr;
			}
			size++;
		}
		void AddToHead(T dane)//Dodanie na poczatku
		{
			if (head == nullptr)
			{
				head = new node<T>(dane);
				tail = head;
				head->next = nullptr;
				head->prev = nullptr;
			}
			else
			{
				node<T>* temp = new node<T>(dane);
				temp->next = head;
				head->prev = temp;
				head = temp;
				head->prev = nullptr;
			}
			size++;
		}
		T Get(int which)//Zwrocenie danych i-tego elementu
		{
			if (which < 0 || which > size - 1) { throw std::out_of_range("which is out of range"); }
			else
			{
				if (size / 2 > which)
				{
					node<T>* temp = head;
					for (int i = 0; i < which; i++)
					{
						temp = temp->next;
					}
				return temp->data;
				}
				else
				{
					node<T>* temp = tail;
					for (int i = 0; i < size - which - 1; i++)
					{
						temp = temp->prev;
					}
					return temp->data;
				}
			}
		}
		void DeleteHead()//Usuniecie pierwszego elementu
		{
			if (head != nullptr)
			{
				node<T>* temp = head;
				head = head->next;
				delete temp;
				if (head != nullptr) { head->prev = nullptr; }
				size--;
			}
		}
		void DeleteTail()//Usuniecie ostatniego elementu
		{
			if (tail != nullptr)
			{
				node<T>* temp = tail;
				tail = tail->prev;
				delete temp;
				if (tail != nullptr) { tail->next = nullptr; }
				size--;
			}
		}
		void Replace(T dane, int which)//Podmiana danych elementu
		{
			if (this->size >= which && which >= 0)
			{
				if (size / 2 > which)
				{
					node<T>* temp = head;
					for (int i = 0; i < which; i++)
					{
						temp = temp->next;
					}
					temp->data = dane;
				}
				else
				{
					node<T>* temp = tail;
					for (int i = 0; i < size - which - 1; i++)
					{
						temp = temp->prev;
					}
					temp->data = dane;
				}
			}
			else { throw out_of_range("which is out of range"); }
		}
		node<T>* Search(T dane, int (*cmpr)(T, T))//Wyszukanie elementu
		{
			node<T>* temp = head;

			for (int i = 0; i < size; i++)
			{
				if (cmpr(dane, temp->data) == 0) { return temp; }
				temp = temp->next;
			}
			return nullptr;
		}
		int SearchByIndex(T dane, int (*cmpr)(T, T))//Wyszukanie elementu po indexie
		{
			node<T>* temp = head;

			for (int i = 0; i < size; i++)
			{
				if (cmpr(dane, temp->data) == 0) { return i; }
				temp = temp->next;
			}
			return -1;
		}
		std::string ListToString(int elements = 0)//To_string
		{
			std::string str = "List size:";
			str += to_string(size);
			str += " List elements:";
			node<T>* temp = head;
			if (elements == 0)
			{
				for (int i = 0; i < size; i++)
				{
					str += to_string(temp->data) + ' ';
					if (i < size - 1)temp = temp->next;
				}
			}
			else
			{
				for (int i = 0; i < elements; i++)
				{
					str += to_string(temp->data) + ' ';
					temp = temp->next;
				}
			}
			return str;
		}
		void Clear()//Czysczenie listy
		{
			node<T>* temp = head;
			for (int i = 0; i < size - 1; i++)
			{
				temp = temp->next;
				delete temp->prev;
			}
			delete temp;
			head = nullptr;
			tail = nullptr;
			size = 0;
		}
		bool DeleteGiven(T dane, int (*cmpr)(T, T))//Wyszukanie i usuniecie
		{
			node<T>* temp = head;
			bool flag = false;

			for (int i = 0; i < size; i++)
			{
				if (cmpr(dane, temp->data) == 0)
				{
					if (temp->next != nullptr && temp->prev != nullptr)
					{
						temp->prev->next = temp->next;
						temp->next->prev = temp->prev;
					}
					else if (temp->prev != nullptr)
					{
						temp->prev->next = nullptr;
						tail = temp->prev;
					}
					else if (temp->next != nullptr)
					{
						temp->next->prev = nullptr;
						head = temp->next;
					}
					else
					{
						head = nullptr;
						tail = nullptr;
					}
					delete temp;
					size--;
					flag = 1;
					return flag;
				}
				else temp = temp->next;
			}
			return flag;
		}
		void AddInOrder(T dane, int (*cmpr)(T, T))//Dodanie z wymuszeniem porzadku
		{
			node<T>* temp = head;

			if (head == nullptr) { add_to_head(dane); return; }
			else
			{
				for (int i = 0; i < size; i++)
				{
					if (cmpr(dane, temp->data) > 0)
					{
						if (i == size - 1) { add_to_tail(dane); return; }
						else { temp = temp->next; }
					}
					else
					{
						if (i == 0) { add_to_head(dane); return; }
						else
						{
							node<T>* newnode = new node<T>(dane);
							newnode->next = temp;
							newnode->prev = temp->prev;
							newnode->prev->next = newnode;
							newnode->next->prev = newnode;
							size++;
							return;
						}
					}
				}
			}
		}
		void DeletePenultimate()
		{
			node<T>* tmp = tail;
			tmp = tmp->prev;
			if (tmp->prev == nullptr)
			{
				head = tmp->next;
			}
			else
			{
				tmp->prev->next = tmp->next;
			}
			tmp->next->prev = tmp->prev;
			delete tmp;
			size--;
		}
		int GetSize() { return size; }
		T* ListToArray()
		{
			node<T>* temp = head;
			T* resultArray = new T[size];
			if (head == nullptr) return nullptr;
			for (int i = 0; i < size; i++)
			{
				resultArray[i] = temp->data;
				temp = temp->next;
			}
			return resultArray;
		}
		node<T>* GetHead()
		{
			return head;
		}
	};
}



#endif