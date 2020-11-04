#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

struct node
{
	int data;
	node* next;
};

void add_First(node*& first, int g)
{
	node* tmp = new node;
	tmp->data = g;
	tmp->next = first;
	first = tmp;
}
void addLast(node*& first, int g)
{
	node* tmp = new node;
	tmp->data = g;
	tmp->next = nullptr;
	if (first == nullptr)
	{
		first = tmp;
	}
	else
	{
		node* p = first;
		while (p->next != nullptr)//(p != nullptr && p->next != nullptr)
			p = p->next;

		p->next = tmp;
	}
}
node* find_address(node* first, int x)
{
	node* p;
	p = first;
	while (p && (p->data) != x)
		p = p->next;
	return p;
}
void create_list(node*& first, ifstream& in)
{
	//first = nullptr;
	if (!in)
	{
		cout << "Can't open file!" << endl;
		system("pause");
		exit(1);
	}
	int x;
	while (in >> x)
	{
		addLast(first, x);
	}
	cout << "List created" << endl;
}
void create_set(node*& first, ifstream& in)
{
	if (!in)
	{
		cout << "Can't open file!" << endl;
		system("pause");
		exit(1);
	}
	int x;
	while (in >> x)
	{
		if (!find_address(first, x))
		{
			addLast(first, x);
		}
	}
	cout << "Set created" << endl;
}
void show_list(node* first)
{
	node* p = first;
	cout << "LIST: " << endl;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void pop_First(node*& first)
{
	if (first)
	{
		node* tmp = first;
		first = first->next;
		delete tmp;
	}
}
void clear_list(node*& first)
{
	while (first)
	{
		pop_First(first);
	}
}

node* previous(node* first, node* g)
{
	node* pr, * p;
	p = first;
	pr = nullptr;
	while (p != g && p)
	{
		pr = p;
		p = p->next;
	}

	if (p == g) return pr;
	return nullptr;
}
void insert_list_after(node* first, node*& q, int x)
// insert x after position q
{
	if (!q) { cout << "Element is not in list"; exit(-1); }
	node* p;
	p = new node;
	p->data = x;
	p->next = q->next;
	q->next = p;
}
void insert_list_before(node*& first, node* q, int x)
// insert x before position q
{
	if (!q) { cout << "Element is not in list"; exit(-1); }
	node* p, * r;
	p = new node;
	r = previous(first, q);
	if (q == first) add_First(first, x);
	else
		if (r == nullptr)
		{
			cout << " sorry, impossible insert element " << endl;
			system("pause");
			exit(-1);
		}
		else
		{
			p->data = x;
			p->next = r->next;
			r->next = p;
		}
}

void copy_set(node* top1, node*& top2)
{
	node* p = top1;
	while (p)
	{
		addLast(top2, p->data);
		p = p->next;
	}

}

void Sort(node*& first)
{
	node* p = first;
	node* q = nullptr;
	while (p)
	{
		q = p->next;
		while (q)
		{
			if (q->data < p->data)
			{
				int r = q->data;
				q->data = p->data;
				p->data = r;
			}
			q = q->next;
		}
		p = p->next;
	}
}
int main()
{
	int x = 0;
	x++;
	x += 7;
	node* first;
	//ifstream in("data.txt");
	//create_set(first, in);
	//show_list(first);
	return 0;
}