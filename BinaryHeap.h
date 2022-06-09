#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <string>

namespace algo
{
	template <typename T>
	class BinaryHeap
	{
		T* array = nullptr;
		int size = 0;
		int capacity = 1;
		bool state = 0;//0=top-down, 1=bottom-up

		void HeapUp(int index, int(*cmpr)(T, T))
		{
			int parentIndex = (index - 1) / 2;
			if (parentIndex >= 0 && cmpr(array[index], array[parentIndex]) > 0)
			{
				std::swap(array[index], array[parentIndex]);
				HeapUp(parentIndex, cmpr);
			}
			else return;
		}
		void HeapDown(int index, int(*cmpr)(T, T))
		{
			int childIndex1 = index * 2 + 1;
			int childIndex2 = index * 2 + 2;
			//brak dzieci lub mniejsze dzieci
			if (childIndex1 > size - 1 || (cmpr(array[index], array[childIndex1]) > 0 && cmpr(array[index], array[childIndex2]) > 0)) return;
			//dwójka dzieci
			else if (childIndex2 < size)
			{
				//porownanie ktore wieksze, zamiana
				if (cmpr(array[childIndex1], array[childIndex2]) <= 0 && cmpr(array[index], array[childIndex2]) <= 0)
				{
					std::swap(array[index], array[childIndex2]);
					HeapDown(childIndex2, cmpr);
				}
				else if (cmpr(array[childIndex1], array[childIndex2]) > 0 && cmpr(array[index], array[childIndex1]) <= 0)
				{
					std::swap(array[index], array[childIndex1]);
					HeapDown(childIndex1, cmpr);
				}
			}
			//jedno dziecko
			else if (childIndex2 == size && cmpr(array[index], array[childIndex1]) <= 0)
			{
				std::swap(array[index], array[childIndex1]);
				HeapDown(childIndex1, cmpr);
			}
			return;
		}
		void FixHeap(int(*cmpr)(T, T))
		{
			if (state)
			{
				for (int i = 0; i < size; i++)HeapUp(i, cmpr);
			}
			else
			{
				for (int i = size - 1; i >= 0; i--)HeapDown(i, cmpr);
			}
		}
	public:
		BinaryHeap() {}
		BinaryHeap(T* array, int size) { this->array = array; this->size = size; }

		void Put(T data, int(*cmpr)(T, T))//Dodanie nowego elementu
		{
			if (size == capacity)//koniecznosc zwiekszenia pojemnosci
			{
				T* temparr = new T[capacity * 2];
				for (int i = 0; i < size; i++)
				{
					temparr[i] = array[i];
				}
				size++;
				capacity *= 2;
				temparr[size - 1] = data;
				delete[] array;
				array = temparr;
			}
			else//brak koniecznosci
			{
				if (array == nullptr) { array = new T[1]; }
				array[size] = data;
				size++;
			}
			HeapUp(size - 1, cmpr);
		}
		T Poll(int(*cmpr)(T, T))
		{
			if (size == 0) { throw out_of_range("elements is out of range"); }
			T result = array[0];
			swap(array[0], array[size - 1]);
			size--;
			HeapDown(0, cmpr);
			return result;
		}
		void Clear()//C) Czyszczenie kopca
		{
			delete[] array;
			size = 0;
			capacity = 1;
			array = nullptr;
		}
		std::string Heap_to_string(int elements = 0, std::string(*tostr)(T) = to_string)//to_string
		{
			if (elements < 0 || elements > size&& size != 0) { throw out_of_range("elements is out of range"); }
			else
			{
				string str = "Size:";
				str += to_string(size);
				str += " Capacity:";
				str += to_string(capacity);
				str += " List of elements:";
				if (size == 0) str += " Kopiec pusty";
				else
				{
					if (elements == 0) { for (int i = 0; i < size; i++) { str += tostr(array[i]) + " "; } }
					else { for (int i = 0; i < elements; i++) { str += tostr(array[i]) + " "; } }
				}
				return str;
			}
		}
		void Sort(int(*cmpr)(T, T))
		{
			int startSize = size;
			FixHeap(cmpr);

			for (int i = 0; i < startSize; i++)
			{
				std::swap(array[0], array[size - 1]);
				size--;
				HeapDown(0, cmpr);
			}

		}
		void ChangeState()
		{
			if (state)state = 0;
			else state = 1;
		}
	};
}

#endif

