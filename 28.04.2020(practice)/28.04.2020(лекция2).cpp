#include <iostream>
using namespace std;
struct node
{
	int data;
	node* next;
	node* prev;
};
////////////////////////////////////////////////
bool empty_list(node* top)
{
	return top == NULL;
}
//////////////////////////////////////////////	
int length_list(node* top)
{
	node* p;
	int len;
	if (empty_list(top))  len = 0;
	else
	{
		len = 0;
		p = top;
		while (p)
		{
			p = p->next;
			len++;
		}
	}
	return len;
}
//////////////////////////////////////////////////
void create_list(node*& top, node*& end, int n)
{
	int i;
	node* p;
	top = NULL;
	end = NULL;
	for (i = 0; i < n; i++)
	{
		p = new node;
		cout << " enter p->data=";
		cin >> p->data;
		if (top == NULL)
		{
			top = p;
			p->next = NULL;
			p->prev = NULL;
			end = p;
		}
		else
		{
			end->next = p;
			p->prev = end;
			p->next = NULL;
			end = p;
		}
	}
}
//////////////////////////////////////////////////
void pop(node*& top, node*& end, int& data)
{
	node* p;
	if (length_list(top) > 1)
	{
		data = top->data;
		p = top->next;
		p->prev = NULL;
		delete top;
		top = p;
	}
	else
		if (length_list(top) == 1)
		{
			data = top->data;
			delete top;
			top = NULL;
			end = NULL;
		}
}
//////////////////////////////////////////
int pop(node*& top, node*& end) // get data from list
{
	node* p;
	int data;
	if (length_list(top) > 1)
	{
		data = top->data;
		p = top->next;
		p->prev = NULL;
		delete top;
		top = p;
	}
	else
		if (length_list(top) == 1)
		{

			data = top->data;
			delete top;
			top = NULL;
			end = NULL;
		}
	return data;
}
/////////////////////////////////////////
void push(node*& top, node*& end, int data)
{
	node* p;
	if (length_list(top) == 0)
	{
		top = new node;
		end = top;
		top->data = data;
		top->next = NULL;
		top->prev = NULL;
	}
	else
	{
		p = new node;
		p->data = data;
		p->next = NULL;
		p->prev = end;
		end->next = p;
		end = p;
	}
}
//////////////////////////////////////////
void create_list_push(node*& top, node*& end, int n)
{
	int i, data;
	top = NULL;
	end = top;
	for (i = 0; i < n; i++)
	{
		cout << " enter data=";
		cin >> data;
		push(top, end, data);
	}
}
//////////////////////////////////////////
void show_list(node* top)
{
	node* p;
	p = top;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}
///////////////////////////////////////////
node* find_address(node* top, int x)
{
	node* p = top;
	while (p && p->data != x)
		p = p->next;
	return p;
}
/////////////////////
void insert_before(node*& top, node* q, int x)
{
	node* p = new node;
	p->data = x;
	if (q == top)
	{
		p->next = top;
		p->prev = NULL;
		top->prev = p;
		top = p;

	}
	else
	{
		p->prev = q->prev;
		q->prev = p;
		p->prev->next = p;
		p->next = q;
	}
}
//////////////////////////////
void insert_after(node*& top, node*& end, node* q, int x)
{

	if (q == end) push(top, end, x);
	else
		insert_before(top, q->next, x);
}
//////////////////////////////////////////////
void delete_element(node*& top, node*& end, node* q)
{
	if (q == top) pop(top, end);
	else
		if (q == end)
		{
			q->prev->next = NULL;
			end = q->prev;
			delete q;
		}
		else
		{
			q->prev->next = q->next;
			q->next->prev = q->prev;
			delete q;
		}
}
///////////////////////////////
void delete_all_x(node*& top, node*& end, int x)
{
	while (find_address(top, x))
		delete_element(top, end, find_address(top, x));
}
//////////////////////////////
int max(node* top)
{
	int  maxx;
	node* p = top;
	maxx = top->data;
	while (p)
	{
		if (maxx < p->data)
			maxx = p->data;
		p = p->next;
	}
	return maxx;
}
//////////////////////////////////////////////////////////////////
void show_from_right_to_left(node* end)
{
	node* p;
	p = end;
	while (p)
	{
		cout << p->data << " ";
		p = p->prev;
	}
}
//////////////////////////////////////////////////////
void order_list(node* top)
{
	node* p, * q;
	int r;
	p = top;
	while (p->next)
	{
		q = p->next;
		while (q)
		{
			if (p->data > q->data)
			{
				r = p->data;
				p->data = q->data;
				q->data = r;
			}
			q = q->next;
		}
		p = p->next;
	}
}
/////////////////////////////////////////////////////
int main()
{
	int n, data, data1, data2;
	node* top_my_list, * end_my_list;
	top_my_list = NULL;
	end_my_list = NULL;
	cout << "enter n= ";
	cin >> n;
	create_list(top_my_list, end_my_list, n);

	cout << " list = ";
	show_list(top_my_list);

	cout << "lenght list= " << length_list(top_my_list) << endl;

	if (!empty_list(top_my_list))
	{
		pop(top_my_list, end_my_list, data);
		cout << endl << " pop data=  " << data << endl;
	}
	cout << " list = ";
	show_list(top_my_list);

	cout << " insert data1 before data2 " << endl;
	cout << "enter data2 = ";
	cin >> data2;
	//node* p=find_address(top_my_list,data2);

	cout << "enter data1 = ";
	cin >> data1;

	//insert_before(top_my_list,p,data1);
	insert_before(top_my_list, find_address(top_my_list, data2), data1);

	cout << " list = ";
	show_list(top_my_list);

	cout << " insert data1 after  data2 " << endl;
	cout << "enter data2 = ";
	cin >> data2;
	// node* p=find_address(top_my_list,data2);

	cout << "enter data1 = ";
	cin >> data1;
	// insert_after(top_my_list,end_my_list,p,data1);
	insert_after(top_my_list, end_my_list,
		find_address(top_my_list, data2), data1);
	cout << " list = ";
	show_list(top_my_list);

	int m = max(top_my_list);
	delete_all_x(top_my_list, end_my_list, m);

	cout << " after delete all max  list=" << endl;
	show_list(top_my_list);

	order_list(top_my_list);
	cout << "order list " << endl;
	show_list(top_my_list);
	cout << endl;

	cout << " order list from right to left " << endl;
	show_from_right_to_left(end_my_list);
	cout << endl;
	system("pause");
	return 0;
}
