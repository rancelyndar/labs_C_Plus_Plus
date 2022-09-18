#pragma once
#include <iostream>

template<typename T>
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(T data);
	void clear();
	T& operator[](const int index);
	int getSize();
	void DeleteDub();
	T elementFromTheEnd(const int number) const;
	T element(const int index) const;

private:

	template<typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}


	};

	int Size;
	Node<T> *head;
	Node<T> *tail;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T & List<T>::operator[](const int index)
{
	int count = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		if (count == index)
		{
			return current->data;
		}
		current = current->pNext;
		count++;
	}
}

template<typename T>
int List<T>::getSize()
{
	return Size;
}

template<typename T>
void List<T>::DeleteDub()
{
	Node<T>* current = this->head;
	while (current)
	{
		Node<T>* temp = current;
		while (temp->pNext)
		{
			if (current->data == temp->pNext->data)
			{
				Size--;
				if (temp->pNext->pNext)
				{
					temp->pNext = temp->pNext->pNext;
				}
				else
				{
					temp->pNext = nullptr;
					tail = temp;
					break;
				}
			}
			else temp = temp->pNext;
		}
		current = current->pNext;
	}
}

template<typename T>
T List<T>::elementFromTheEnd(const int k) const
{
	int index = Size - k;
	return element(index);
}

template<typename T>
T List<T>::element(const int index) const
{
	Node<T> *result = this->head;
	for (int i = 0; i < index; i++)
	{
		result = result->pNext;
	}
	return result->data;
}