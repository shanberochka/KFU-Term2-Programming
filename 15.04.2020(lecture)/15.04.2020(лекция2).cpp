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
void create_list(ifstream& f, node*& top)
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
void create_order_list(ifstream& f, node*& top)
{
	int data;
	top = nullptr;
	node* p;
	node* pr;
	if (!f)
	{
		cout << "Can't open file!" << endl;
		system("pause");
		exit(-1);
	}
	else
	{	
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
			if (!p)
				insert_list_after(top, pr, data);
			else
				insert_list_before(top, p, data);
		}

		f.close();
	}
}
/////////////////////////////////////////
void show_list(ofstream& f, node* top)
{
	node* p;
	p = top;
	while (p)
	{
		f << p->data << " ";
		p = p->next;
	}
	f << endl;
}
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
////////////////////////////////////////////////
int min(node* top)
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
			if (m > p->data)
			{
				m = p->data;
			}
			p = p->next;
		}
		return m;
	}
}
void change_max_min(node* top)
{
	int min1 = min(top);
	int max1 = max(top);

	node* pmin = find_address(top, min1);
	node* pmax = find_address(top, max1);
	int r = pmin->data;
	pmin->data = pmax->data;
	pmax->data = r;
}

int main()
{
	node* top = nullptr;
	ifstream in("data.txt");
	ofstream out("out.txt");


	create_list(in,top);

	out << "list:" << endl;

	show_list(out, top);
	change_max_min(top);

	out << "new list change max min: " << endl;
	show_list(out, top);

	change_max_min(top);

	out << "new2 list change max min: " << endl;
	show_list(out, top);

	// создание упорядоченного списка
	node* top2 = nullptr;
	ifstream in2("data2.txt");
	create_order_list(in2, top2);
	

	in.close();
	in2.close();
	out.close();

}