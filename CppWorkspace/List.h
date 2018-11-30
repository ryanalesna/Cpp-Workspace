#ifndef LIST_H
#define LIST_H
#include <stdio.h>

//add and remove method
template <class T>
class List {
private:
	T* list;
	int numOfElements;
	int capacity;
public:
	List()
	{
		list = new T[4];
		capacity = 4;
		numOfElements = 0;
	};
	void add(int i, T x)
	{
		numOfElements++;
		if (numOfElements > capacity)
		{
			reserve(numOfElements * 2);
		}
		for (int j = numOfElements; j > i-1; j--)
		{
			list[j + 1] = list[j];
		}
		list[i] = x;
	}
	void push(T i)
	{
		numOfElements++;
		if (numOfElements > capacity)
		{
			reserve(numOfElements * 2);
		}
			list[numOfElements - 1] = i;
	}
	T remove(int i, T x)
	{
		for (int j = i; j < numOfElements; j++)
		{
			list[j] = list[j + 1];
		}
		numOfElements--;
		return x;
	}
	T get(int i)
	{
		return list[i];
	}
	int length()
	{
		return numOfElements;
	}
	void reserve(int spaces)
	{
		T* list2 = new T[spaces + numOfElements];
		for (int j = 0; j < numOfElements; j++)
		{
			list2[j] = list[j];
		}
		delete[] list;
		list = list2;
		capacity = spaces + capacity;
	}

	/* given a value, finds its index in the list, returns -1 if not in the list*/
	int indexOf(const T& value) {
		int foundIndex = -1;
		for (int i = 0; i < numOfElements && foundIndex == -1; i++)
		{
			if (list[i] == value)
			{
				foundIndex = i;
			}
		}
		return foundIndex;

	}
};
template <class T>
void printList(List <T> array, const char* code)
{
	for (int i = 0; i < array.length(); i++)
	{
		printf(code, array.get(i));
		printf(", ");
	}
}
#endif //LIST_H


