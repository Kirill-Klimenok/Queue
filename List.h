#pragma once
#include<iostream>
#include <fstream>
using namespace std;


template<typename T>
class List {
public:
	List<T>();
	~List<T>();

	void PushBack(T data);
	int GetSize() { return this->Size; }
	/*оператор квадратные скобки*/
	T& operator[](const int index);// пртотип метода ... возвращаем ссылку на тип “
	void PopFront();
	void PushFront(T data);
	int View(List lst);
	void Clear(List lst);
	void AddID(T value, int index);
	void ClearForID(int index);
	List ReadFile(const char* filename, List lst2)
	{
		List Q123;
			int a;
		ifstream file(filename);
		do {
			file >> a;
			Q123.PushFront(a);
		}
		while (!file.eof());
		return Q123;
		
	}
	List QList(List lst1, List lst2)
	{
		List Q;
		int k = lst1.GetSize() + lst2.GetSize() - 1;
		int* mass=new int[k];

		for (int i = 0; i <lst1.Size - 1; i++) mass[i] = lst1[i];

		for (int i = 0; i < lst2.Size - 1; i++) mass[i + lst1.Size] = lst2[i];

		for (int i = 0; i <k; i++) {
			for (int j = 1; j <k; j++) {
				if (mass[j - 1] < mass[j]) {
					int x = mass[j - 1];
						mass[j - 1] = mass[j];
					mass[j] = x;
				}
			}
		}
		for (int i = 0; i < k; i++) {
			Q.PushFront(mass[i]);
		}
		return Q;

	}

private:


	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<int>* head;
};
