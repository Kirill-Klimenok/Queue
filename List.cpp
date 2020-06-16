#include"List.h"

template<typename T>
List<T>::List()
{
	this->Size = Size;
	this->head = head;
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List()
{
	Clear();
	return GetSize();
}

template<typename T>
void List<T>::PushBack(T data)
{
	this->head = head;
	this->Size = Size;
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;

		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)//пока current HE 0
	{
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}



}
template<typename T>
void List<T>::PushFront(T data)
{
	this->head = head;
	this->Size = Size;

	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::PopFront()
{
	this->head = head;
	this->Size = Size;

	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;

}

template<typename T>
int List<T>::View(List lst)
{
	for (int i = 0; i < lst.GetSize; i++) {
		cout << lst[i] << endl;
	}
	return 0;
}

template<typename T>
void List<T>::Clear(List lst)
{
	
	this->Size = Size;
	while (Size)
	{
		lst.PopFront();
	}
}

template<typename T>
void List<T>::AddID(T value, int index)
{
	this->head = head;
	this->Size = Size;
	if (index == 0) {
		PushFront(value);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node<T>(value, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}
}

template<typename T>
void List<T>::ClearForID(int index)
{
	
	this->Size = Size;
	if (index == 0) {
		PopFront();
	}
	else {
		Node<T>* previous = this->pNext;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;

	}
}



