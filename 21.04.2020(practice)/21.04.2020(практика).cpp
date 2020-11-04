#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	char data;
	node* next;
};
void push(node*& first, char n)
{
	node* tmp = new node;
	tmp->data = n;
	tmp->next = first;
	first = tmp;
}
void pop(node*& first)
{
	int data;
	if (first)
	{
		node* tmp = first;
		data = first->data;
		first = first->next;
		delete tmp;
	}
	else cout << "error";
}
char back(node*& first)
{
	if (first) return first->data;
	else return 'e';
}
int size(node*& first)
{
	node* p;
	p = first;
	int count = 0;
	while (p)
	{
		p = p->next;
		count++;
	}
	return count;
}
void clear(node*& first)
{
	while (first)
	{
		pop(first);
	}
}
int createstack(node*& first, ifstream& in)
{
	char ch;
	while (in>>ch)
	{
		if (ch == '(') push(first, ch);
		if (ch == ')')
		{
			if (back(first) == '(') pop(first);
			else push(first, ch);
		}
	}
	return size(first);
}

int main()
{
	// Exercise 3
	node* first = nullptr;
	ifstream in("brackets.txt");
	ofstream out("result.txt");
	out << "Need to delete: " << createstack(first, in) << " brackets";
	in.close();
	out.close();
}
