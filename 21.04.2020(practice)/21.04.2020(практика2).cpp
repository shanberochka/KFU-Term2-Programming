#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int data;
	node* next;
};
void push(node*& first, int n)
{
	node* tmp = new node;
	tmp->data = n;
	tmp->next = first;
	first = tmp;
}
void show_list(node* first)
{
	node* p = first;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
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
int back(node*& first)
{
	if (first) return first->data;
	else return '000';
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
int createlist(node*& first, ifstream& in)
{
	char ch; int x, y;
	while (in>>ch)
	{
		if ((ch != '+') && (ch != '-') && (ch != '*') && (ch != ' '))
		{
			push(first, int(ch) - '0');
		}
		if (ch == '+')
		{
			x = back(first);
			pop(first);
			y = back(first);
			pop(first);
			push(first, x + y);
		}
		if (ch == '-')
		{
			x = back(first);
			pop(first);
			y = back(first);
			pop(first);
			push(first, y - x);
		}
		if (ch == '*')
		{
			x = back(first);
			pop(first);
			y = back(first);
			pop(first);
			push(first, x * y);
		}
	}
	return first->data;
}
int main()
{

	// Exercise 4
	node* first = NULL;
	ifstream in("RPN.txt");
	ofstream out("result.txt");
	out << "Result: " << createlist(first, in);
	in.close();
	out.close();
}
