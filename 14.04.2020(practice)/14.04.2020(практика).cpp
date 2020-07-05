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
	tmp->next = NULL;
	if (first == NULL)
	{
		first = tmp;
	}
	else
	{
		node* p = first;
		while (p != NULL && p->next != NULL)
			p = p->next;

		p->next = tmp;
	}
}
void create_list(node*& first, int n)
{
	int g;
	first = NULL;
	for (int i = 0; i < n; i++)
	{
		cout << " enter data = ";
		cin >> g;
		addLast(first, g);
	}

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
node* find_address(node* first, int x)
{
	node* p;
	p = first;
	while (p && (p->data) != x)
		p = p->next;
	return p;
}
node* previous(node* first, node* g)
{
	node* pr, * p;
	p = first;
	pr = NULL;
	while (p != g && p)
	{
		pr = p;
		p = p->next;
	}

	if (p == g) return pr;
	return NULL;
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
		if (r == NULL)
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

int main()
{

	node* first = NULL;
	int n,qnum;
	node *p,*q;
	cout << "enter n= ";
	cin >> n;
	create_list(first, n);
	show_list(first);
	cout << endl;
	Sort(first);
	cout << "sorted\n";
	show_list(first);
	//node* last = first;
	//while (last->next != NULL)
		//last = last->next;
	//cout << "check" << endl;
	//cout << previous(first, last)->data;
	
	cout << "Enter q to find in list: "; cin >> qnum;
	q = find_address(first, qnum);
	p = previous(first, q);
	insert_list_after(first, q, 99);
	cout << "Insert 99 after element q" << endl;
	show_list(first);
	cout << endl;
	insert_list_before(first, q, 0);
	cout << "Insert 0 before element q" << endl;
	show_list(first);
	clear_list(first);
	return 0;
}
