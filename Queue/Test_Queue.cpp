#include <iostream>
#include "TQueue.h"
using namespace std;


void Test_Queue()
{
	const int size = 3;
	int item1 = 4, item2 = 5;
	int arr[size] = { 1,2,3 };
	TQueue<int> a(size);
	cout << "������� ������� �� " << size << " ���������" << endl;
	cout << "������� �����? �����: " << a.IsEmpty() << endl;
	cout << "������� ��������: ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
		a.Push(arr[i]);
	}
	cout << "\n������� �: " << a << endl;
	cout << "������� �����? �����: " << a.IsEmpty() << endl;
	cout << "������� ���������? �����: " << a.IsFull() << endl;
	cout << "���������� ���������: " << a.Count() << endl;
	TQueue<int> b(a);
	cout << "\n����������� ������� � � ������� �" << endl;
	cout << "�������� ������� �� �: " << b.Pop() << endl;
	cout << "������� B: " << b << endl;
	b.Push(item1);
	cout << "������� ������� " << item1 << " � ����� ������� �.";
	cout << "\n������� �: " << b << endl;
	TQueue<int> c(size);
	c.Push(arr[1]), c.Push(arr[2]), c.Push(item1);
	cout << "�������� ������� � ������� ���� ��������: " << arr[1] << ' ' << arr[2] << ' ' << item1 << endl;
	cout << "������� C: " << c << endl;
	cout << "������� C ����� ������� B? �����: " << (c == b) << endl;
	b.Clear();
	cout << "������� � �������." << endl;
	cout << "������� �: " << b << endl;
	c = a;
	cout << "������� � � �������� ������� �." << endl;
	cout << "������� C: " << c << endl;
	cout << "����� ��������� � ������� �������� �� C:" << endl << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "�������� �������: " << c.Pop() << endl;
		c.Push(i);
		cout << "�������� �������: " << i << endl;
		cout << "���������: " << c << endl;
		cout << endl;
	}
	
	

}

int main()
{
	setlocale(LC_ALL, "ru");

	Test_Queue();

	cout << endl;
	system("pause");
}