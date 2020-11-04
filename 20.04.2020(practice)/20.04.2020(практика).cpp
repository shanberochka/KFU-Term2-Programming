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
bool createstack(node*& first, ifstream& in)
{
	char ch;
	while (((ch = in.get()) != '\n') )
	{
		if ((ch == '(') || (ch == '[') || (ch == '{')) push(first, ch);
		if ((ch == ')') || (ch == ']') || (ch == '}'))
			if (size(first) == 0) { return false; }
			else
			{
				if (((back(first) == '(') || (back(first) == '{')) && (ch == ']'))
				{
					return false;
				}
				if (((back(first) == '(') || (back(first) == '[')) && (ch == '}'))
				{
					return false;
				}
				if (((back(first) == '[') || (back(first) == '{')) && (ch == ')'))
				{
					return false;
				}
				if ((ch == ')') && back(first) == '(') pop(first);
				if ((ch == ']') && back(first) == '[') pop(first);
				if ((ch == '}') && back(first) == '{') pop(first);
			}
	}
	if (size(first) == 0) { return true; }
	else { return false; }
	
}
int main()
{
	node* first = NULL;
	ifstream in("stack.txt");
	if (createstack(first, in))
		cout << "Yes";
	else cout << "No";
}
