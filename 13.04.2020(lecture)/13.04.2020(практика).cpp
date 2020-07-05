//arb2016_basic_functions_list
// in this progam define functions
// node* previous(node* top,node* p) 
//void insert_list_before(node* &top,node* q,int x)
//void insert_list_after(node* top, node* &q, int x)
//node* find_address(node* top, int x)
//void delete_element(node* &top, node* p)

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
/////////////////////////////////////////////////
node* max(node* top)
{
	node* p, *max;
	p = top;
	max = top;
	max->data = top->data;
	while (p)
	{
		if ((p->data) > (max->data))
			max = p;
		p = p->next;
	}
	return max;
}

bool Is_prime(int n)
{
	if (n <= 1)
		return true;

	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;

	return true;
}
////////////////////////////////////////////////
int Sum_prime(node* top)
{
	node* p;
	p = top;
	int sum = 0;
	while (p)
	{
		if (Is_prime(p->data)) sum += (p->data);
		p = p->next;
	}
	return sum;
}
////////////////////////////////////////////////
bool A_pos(node* top)
{
	node* p;
	p = top;
	bool t = true;
	while (p && t)
	{
		if (p->data <= 0) t = false;
		else p = p->next;
	}
	return t;
}
////////////////////////////////////////////////
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

	///Sum of prime elements
	cout << "Sum of prime elements: " << Sum_prime(top_my_list) << endl;

	///All elements are positive?
	if (A_pos(top_my_list)) cout << "All elements are positive"<<endl;
	else cout << "Not all elements are positive"<<endl;

	///Max
	cout << "Max element: " << max(top_my_list)->data << endl;;
	///

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

	cout << "insert data3 ater data1" << endl;
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
	system("pause");
	return 0;
}