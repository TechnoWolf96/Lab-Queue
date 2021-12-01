#pragma once
#include <iostream>

template<class T>
class TQueue
{
private:
	T* arr;				// ������ ���������
	int maxSize;		// ������������ ������ �������
	int head;			// ������ ������ �������
	int tail;			// ������ ������ �������
	int count;			// ������� ���������

public:
	
	int Count() { return count; }					// �������� ���������� ��������� � �������
	TQueue(int maxSize);							// �����������
	TQueue(const TQueue& other);					// ����������� �����������
	TQueue<T>& operator=(const TQueue& other);		// �������� ������������
	~TQueue() { delete[] arr; }						// ����������

	bool IsEmpty() { return count == 0; }			// �������� �� �������
	bool IsFull() { return count == maxSize; }  	// �������� �� ������������

	void Push(T item);		// �������� ������� � ����� �������
	T Pop();				// ������� ������� �� ������ �������
	void Clear();			// ������� �������

	bool operator==(const TQueue& other);			// ��������� ������������� ��������� ���� ��������
	bool operator!=(const TQueue& other);			// ������� �����, ���� �������� ���������� ��������, ���� ���� ����. ������ �������� ������

	friend std::ostream& operator<< (std::ostream& os, const TQueue& queue)
	{
		os << '[';
		for (int i = 0; i < queue.count-1; i++)
		{
			int index = (queue.head + i) % queue.maxSize;
			os << queue.arr[index] << ", ";
		}
		if (queue.count != 0)
			os << queue.arr[(queue.head + queue.count - 1) % queue.maxSize] << ']';
		else os << ']';
		return os;
	}

};



template<class T>
inline TQueue<T>::TQueue(int maxSize)
{
	this->maxSize = maxSize;
	arr = new T[maxSize];
	head = 0;
	tail = -1;
	count = 0;
}

template<class T>
inline TQueue<T>::TQueue(const TQueue& other)
{
	maxSize = other.maxSize;
	arr = new T[maxSize];
	head = other.head;
	tail = other.tail;
	count = other.count;
	for (int i = 0; i < count; i++)
	{
		int index = (head + i) % maxSize;
		arr[index] = other.arr[index];
	}
	
}

template<class T>
inline TQueue<T>& TQueue<T>::operator=(const TQueue& other)
{
	if (maxSize != other.maxSize)
	{
		delete[] arr;
		maxSize = other.maxSize;
		arr = new T[maxSize];
	}
	head = other.head;
	tail = other.tail;
	count = other.count;
	for (int i = 0; i < count; i++)
	{
		int index = (head + i) % maxSize;
		arr[index] = other.arr[index];
	}
	return *this;
}

template<class T>
inline void TQueue<T>::Push(T item)
{
	if (IsFull()) throw "Queue is full";
	tail = (tail + 1) % maxSize;
	arr[tail] = item;
	count++;
}

template<class T>
inline T TQueue<T>::Pop()
{
	if (IsEmpty()) throw "Queue is empty";
	T temp = arr[head];
	head = (head + 1) % maxSize;
	count--;
	return temp;
}

template<class T>
inline void TQueue<T>::Clear()
{
	head = 0;
	tail = -1;
	count = 0;
}

template<class T>
inline bool TQueue<T>::operator==(const TQueue& other)
{
	if (count != other.count) return false;

	for (int i = 0; i < count; i++)
	{
		int index1 = (head + i) % maxSize;
		int index2 = (other.head + i) % other.maxSize;
		if (arr[index1] != other.arr[index2]) return false;
	}
	return true;
}

template<class T>
inline bool TQueue<T>::operator!=(const TQueue& other)
{
	return !operator==(other);
}

