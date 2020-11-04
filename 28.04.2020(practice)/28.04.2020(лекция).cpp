#include<iostream>
#include<fstream>
using namespace std;
struct node
{
	int data;
	node* next;
};
////////////////////////////////////////////////
void push(node*& top, int data) // put data to stack 
{
	node* p;
	p = new node;
	p->data = data;
	p->next = top;
	top = p;
}
//////////////////////////////////////////
void show_list(node* top)
{
	node* p;
	p = top;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
/////////////////////////////////////////////	
node* previous(node* top, node* p) // pointer p define 
// task: find previous pointer
{
	node* pr, * q;
	q = top;
	pr = NULL;
	while (q != p && q)
	{
		pr = q;
		q = q->next;
	}
	if (q == p) return pr;
	return NULL;
}
//////////////////////////////////////////
void insert_list_before(node*& top, node* q, int x)
// insert x pred position q
{
	node* p, * g;
	p = new node;
	g = previous(top, q);
	if (q == top) push(top, x);
	else
	{
		p->data = x;
		p->next = g->next;
		g->next = p;
	}
}
///////////////////////////////////////////
void insert_list_after(node* top, node*& q, int x)
// insert x after position q
{
	node* p;
	p = new node;
	p->data = x;
	p->next = q->next;
	q->next = p;
}
///////////////////////////////////////////////////
node* find_address(node* top, int x)
{
	node* p;
	p = top;
	while (p && (p->data) != x)
		p = p->next;

	return p;
}
/////////////////////////////////////////////////
void create_order_list(ifstream& f, node*& top)
{
	int	data;
	node* p;
	node* pr;
	top = NULL;
	if (!f)
	{
		cout << "Can't open file" << endl;
		system("pause");
		exit(-1);
	}
	f >> data;
	push(top, data);
	while (f >> data)
	{
		p = top;
		pr = p;
		while (p && p->data < data)
		{
			pr = p;
			p = p->next;
		}
		if (p == NULL)
			insert_list_after(top, pr, data);
		else
			insert_list_before(top, p, data);
	}
}
//////////////////////////////////////////////////
int  main()
{
	node* top_my_list;
	ifstream my("data.txt");
	create_order_list(my, top_my_list);
	my.close();
	cout << "  order list  = ";
	show_list(top_my_list);
	system("pause");
	return 0;
}

