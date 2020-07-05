#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	int data;
	node* next;
};
////////////////////////////////////////////////
bool empty_list(node* top)
{
	return top == NULL;
}
/////////////////////////////////////////
void push(node*& top, int data) // put data to list 
{
	node* p;
	p = new node;
	p->data = data;
	p->next = top;
	top = p;
}
//////////////////////////////////////////////	
void create_list(ifstream& f,node*& top)
{
	int x;
	top = nullptr;
	if (!f)
	{
		cout << "Can't open file!" << endl;
		system("pause");
		exit(-1);
	}
	else 
	{
		while (f >> x)
			push(top, x);
		f.close();
	}
}
/////////////////////////////////////////
void show_list(ofstream&f,node* top)
{
	node* p;
	p = top;
	while (p)
	{
		f << p->data << " ";
		p = p->next;
	}
	f << endl;
	//f.close();
}
//////////////////////////////////////////////////
void list_two_lists(node* top, node*& top1, node*& top2)
{
	int x;
	top1 = nullptr;
	top2 = nullptr;

	node* p = top;

	while (p)
	{
		if ((p->data) % 2 == 1) push(top1, p->data);
		else push(top2, p->data);

		p = p->next;
	}
}
//////////////////////////////////////////////////
void pop(node*& top, int& data) // get data from list
{
	node* p;
	if (!empty_list(top))
	{
		data = top->data;
		p = top->next;
		delete top;
		top = p;
	}
}
//////////////////////////////////////////
int pop1(node*& top) // get data from list
{
	int data;
	node* p;
	if (top)
	{
		data = top->data;
		p = top->next;
		delete top;
		top = p;
	}
	return data;
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
// insert x before position q
{
	node* p, * r;
	p = new node;
	r = previous(top, q);
	if (q == top) push(top, x);
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
void delete_element(node*& top, node* p)
{
	node* r; int x;
	if (p == top)
		pop(top, x);

	else
	{
		r = previous(top, p);
		r->next = p->next;
		delete p;
	}
}
////////////////////////////////////////////////

int sum(node* top)
{
	int s = 0;
	node* p = top;
	while (p)
	{
		s = s + p->data;
		p = p->next;
	}
	return s;
}

////////////////////////////////////////////////

int max(node* top)
{
	if (!top)
	{
		cout << "Lisr is empty";
		exit(-1);
	}
	else {
		int m = top->data;
		node* p = top->next;
		while (p)
		{
			if (m < p->data)
			{
				m = p->data;
			}
			p = p->next;
		}
		return m;
	}
}
int  main()
{
	node* top = nullptr;
	node* top1 = nullptr;
	node* top2 = nullptr;

	ifstream in("data.txt");
	ofstream out("out.txt");
		ofstream out1("out1.txt");
			ofstream out2("out2.txt");
	create_list(in, top);
		out << "list: " << endl;
		show_list(out, top);
	
		list_two_lists(top, top1, top2);
		out << "list of even numbers: " << endl;
			show_list(out, top1);
		out << "list of odd numbers: " << endl;
			show_list(out, top2);
	out.close();

	out1 << "list of odd numbers: " << endl;
	show_list(out1, top1);
	out1.close();

	out1 << "list of even numbers: " << endl;
	show_list(out2, top2);
	out2.close();

	system("pause");
	return 0;

}


