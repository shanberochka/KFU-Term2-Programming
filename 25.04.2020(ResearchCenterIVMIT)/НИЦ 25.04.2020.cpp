#include <iostream>
using namespace std;


class LinkedList
{
public:
	LinkedList()
	{
		size = 0;
		head = nullptr;
	}
	~LinkedList(){}
	int& operator[](const int& data);
	void push_back(int data);
	void push_front(int new_data);
	void pop_front();
	void pop_back(); // HW
	void removeAt(int index);

	int getSize(){ return size; }
private:
	class Node
	{
	public:
		int data;
		Node* pNext;
		Node(int data = 0, Node * next = nullptr)
		{
			this->data = data;
			this->pNext = next;
		}
	};
	Node* head;
	int size;
	
};


void LinkedList::push_back(int new_data)
{
	if (head == nullptr)
	{
		head = new Node(new_data); // создаем экземпляр класса Node, вызыватеся полный конструктор 
	}
	else
	{
		Node* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(new_data);
	}
	size++;
}

void LinkedList::push_front(int new_data)
{
	head = new Node(new_data, head);
	size++;
}
void LinkedList::pop_front()
{
	Node* temp = head;
	head = head->pNext;
	delete temp;
	size--;
}
void LinkedList::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node* prev = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			prev = prev->pNext;
		}
		Node* toDelete = prev->pNext;
		prev->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}
int& LinkedList::operator[](const int& index)
{
	int counter = 0;
	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	LinkedList list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);

	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << list[i] << " " ;
	}
	std::cout << std::endl;
	for (int i = 0; i < list.getSize(); i++)
	{
		 list[i]+10 ;
	}
	for (int i = 0; i < list.getSize(); i++)
	{
		std::cout << list[i] << " " ;
	}
}