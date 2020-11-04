#include<iostream>
using namespace std;
struct node
{
	int info1;// числитель
	int info2;// знаменатель
	node* next;
};
/////////////////
void createListFarray(node*& top, int n)
{
	node* p, * r, * c;
	int a, b, k;
	p = new node;
	top = p;
	p->info1 = 1;
	p->info2 = 0;
	p->next = new node;
	p = p->next;
	p->info1 = 1;
	p->info2 = 1;
	p->next = NULL;
	for (k = 2; k <= n; k++)
	{
		p = top;
		while (p->next)
		{
			c = p;
			a = p->info1;
			b = p->info2;
			p = p->next;
			if (p->info1 + a == k)
			{
				r = new node;
				r->info1 = k;
				r->info2 = p->info2 + b;
				r->next = p;
				c->next = r;
			}
		}
	}
}
///////////////////
void showFarray(node* top)
{
	node* p;
	p = top;
	while (p)
	{
		cout << p->info2 << "/" << p->
			info1 << ',';
		p = p->next;
	}
	cout << endl;
}
/////////////////////
int main()
{
	node* list_Farray;
	int n;
	cout << "enter order of row Farray"<<endl<<"n = ";
		cin >> n;

	createListFarray(list_Farray, n);
	cout << "Row of  Farray" << endl;
	showFarray(list_Farray);
	system("pause");
	return 0;
}
