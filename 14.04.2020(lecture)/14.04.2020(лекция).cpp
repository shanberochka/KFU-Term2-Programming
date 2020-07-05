
#include <iostream>
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
//////////////////////////////////////////////	
void create_list(node*& top, int n)
{
	int i;
	node* p;
	top = new node;
	top = NULL;
	for (i = 0; i < n; i++)
	{
		p = new node;
		cout << " enter p->data=";
		cin >> p->data;
		p->next = top;
		top = p;
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
/////////////////////////////////////////
void push(node*& top, int data) // put data to list 
{
	node* p;
	p = new node;
	p->data = data;
	p->next = top;
	top = p;
}
//////////////////////////////////////////
void create_list_push(node*& top, int n)
{

	int i, data;
	top = NULL;
	for (i = 0; i < n; i++)
	{
		cout << " enter data=";
		cin >> data;
		push(top, data);
	}
}
/////////////////////////////////////////
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
	int n, data1, data2, data3, data4, data5;
	node* top_my_list;
	node* p;
	cout << "enter n= ";
	cin >> n;
	create_list(top_my_list, n);

	cout << " list = ";
	show_list(top_my_list);

	cout << "enter data1=";
	cin >> data1;
	p = find_address(top_my_list, data1);

	if (p) cout << "data1 = " << p->data << endl;
	else
	{
		cout << "sorry! data1 not exist in list " << endl;
		exit(1);
	}
	cout << "insert data2 before data1" << endl;
	cout << "enter data2= ";
	cin >> data2;
	insert_list_before(top_my_list, p, data2);

	cout << " list = ";
	show_list(top_my_list);

	cout << "insert data3 after data1" << endl;
	cout << "enter data3= ";
	cin >> data3;
	insert_list_after(top_my_list, p, data3);

	cout << " list = ";
	show_list(top_my_list);

	cout << "delete data4" << endl;
	cout << "enter data4=";
	cin >> data4;

	p = find_address(top_my_list, data4);

	if (p)
		delete_element(top_my_list, p);

	cout << " list = ";
	show_list(top_my_list);

	cout << "delete data5" << endl;
	cout << "enter data5=";
	cin >> data5;

	p = find_address(top_my_list, data5);

	if (p)
		delete_element(top_my_list, p);

	cout << " list = ";
	show_list(top_my_list);

	int data = max(top_my_list);
	while (find_address(top_my_list, data))
	{
		p = find_address(top_my_list, data);
		delete_element(top_my_list, p);
	}
	show_list(top_my_list);
	system("pause");
	return 0;

}