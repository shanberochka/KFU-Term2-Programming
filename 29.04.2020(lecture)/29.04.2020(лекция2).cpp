#include <iostream>
using namespace std;
struct node
{
	int koef;
	int power;
	node* next;
};
//////////////////////////////////
bool empty_polinom(node* top)
{
	return top == NULL;
}
//////////////////////////////////////////////	
void create_polinom(node*& top, node*& end, int n)
{
	int i;
	node* p;
	top = NULL;
	end = NULL;
	for (i = 0; i < n; i++)
	{
		p = new node;
		cout << " enter koef=";
		cin >> p->koef;
		cout << " enter power=";
		cin >> p->power;
		if (i == 0)
		{
			p->next = top;
			top = p;
			end = p;
		}
		else
		{
			end->next = p;
			p->next = NULL;
			end = p;
		}
	}
}
//////////////////////////////////////////////////
void pop_polinom(node*& top, int& koef, int& power)
{
	node* p;
	if (!empty_polinom(top))
	{
		koef = top->koef;
		power = top->power;
		p = top->next;
		delete top;
		top = p;
	}
}
//////////////////////////////////////////
void push_polinom(node*& top, node*& end, int koef, int power)
{
	node* p;
	p = new node;
	p->koef = koef;
	p->power = power;
	p->next = NULL;
	if (empty_polinom(top))
	{
		top = p;
		end = p;
	}
	else
	{
		end->next = p;
		end = p;
	}
}


//////////////////////////////////////////
void create_polinom_push(node*& top, node*& end, int n)
{
	int i;
	int koef, power;
	top = NULL;
	end = NULL;
	for (i = 0; i < n; i++)
	{
		cout << " enter koef=";
		cin >> koef;
		cout << " enter power=";
		cin >> power;
		push_polinom(top, end, koef, power);
	}
}
/////////////////////////////////////////
void show_polinom(node* top)
{
	node* p;
	p = top;
	while (p)
	{
		cout << p->koef << "*x^" << p->power << " + ";
		p = p->next;
	}
	cout << endl;
}
/////////////////////////////////////////////	
void order_polinom(node* top, node* end)
{
	int koef, power;
	node* p, * q;
	p = top;
	while (p != end)
	{
		q = p->next;
		while (q)
		{
			if (p->power < q->power)
			{
				power = p->power;
				p->power = q->power;
				q->power = power;
				koef = p->koef;
				p->koef = q->koef;
				q->koef = koef;
			}
			q = q->next;
		}
		p = p->next;
	}
}
///////////////////////////////////////////////////////////
node* previous(node* top, node* p)
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
///////////////////////////////////////////////////////////////
void collecting_terms_in_polinom(node*& top, node* end)
{
	int koef, power;
	order_polinom(top, end);
	node* p, * q, * pr;
	p = top;
	q = p->next;
	while (q)
	{
		if (p->power == q->power)
		{
			q->koef = q->koef + p->koef;
			if (p == top)
			{
				pop_polinom(top, koef, power);
				p = top;
			}

			else
			{
				pr = previous(top, p);
				pr->next = q;
				delete p;
				p = q;
			}
			q = q->next;
		}
		else
		{
			p = q;
			q = q->next;
		}
	}
}
/////////////////////////////////
void copy_polinom(node* top1, node* end1, node*& top2,
	node*& end2)
{
	top2 = NULL;
	end2 = NULL;

	while (top1)
	{
		push_polinom(top2, end2, top1->koef, top1->power);
		top1 = top1->next;
	}
}
///////////////////////////////////////////////////////
void addition_of_polinoms(node* top1, node* end1,
	node* top2, node* end2, node*& top3, node*& end3)
{
	node* top4, * end4;
	copy_polinom(top1, end1, top3, end3);
	copy_polinom(top2, end2, top4, end4);
	end3->next = top4;
	end3 = end4;
	collecting_terms_in_polinom(top3, end3);
}
//////////////////////////////////////////////
void mult_polinom_number(node* top, int number)
{
	node* p;
	p = top;
	while (p)
	{
		p->koef = number * p->koef;
		p = p->next;
	}
}
///////////////////////////////////////////
void subtraction_of_polinoms(node* top1, node* end1,
	node* top2, node* end2, node*& top3, node*& end3)
{
	node* top4, * end4;
	copy_polinom(top1, end1, top3, end3);
	copy_polinom(top2, end2, top4, end4);

	mult_polinom_number(top4, -1);
	end3->next = top4;
	end3 = end4;
	collecting_terms_in_polinom(top3, end3);
	

}
///////////////////////////////////////////
void mult_polinom_polinom(node* top1, node* end1,
	node* top2, node* end2, node*& top3, node*& end3)
{
	top3 = NULL;
	end3 = NULL;

	while (top1)
	{
		node* p = top2;
		while (p)
		{

			push_polinom(top3, end3, top1->koef * p->koef,
				top1->power + p->power);
			p = p->next;
		}
		top1 = top1->next;
	}
	collecting_terms_in_polinom(top3, end3);
}
////////////////////////////////////////////////
int  main()
{
	int n;

	node* top_polinom, * end_polinom;
	node* top_polinom1, * end_polinom1;
	node* top_polinom2, * end_polinom2;
	node* top_polinom3, * end_polinom3;

	cout << "enter n= ";
	cin >> n;
	create_polinom(top_polinom, end_polinom, n);

	cout << " polinom = " << endl;
	show_polinom(top_polinom);

	cout << "enter n= ";
	cin >> n;
	create_polinom_push(top_polinom1, end_polinom1, n);

	cout << " polinom1 = " << endl;
	show_polinom(top_polinom1);

	addition_of_polinoms(top_polinom, end_polinom,
		top_polinom1, end_polinom1, top_polinom2, end_polinom2);
	cout << "polinom2=polinom+polinom1 " << endl;
	show_polinom(top_polinom2);

	subtraction_of_polinoms(top_polinom2, end_polinom2, top_polinom1, end_polinom1, top_polinom3, end_polinom3);
	cout << "polinom3=polinom2- polinom1 " << endl;
	show_polinom(top_polinom3);

	mult_polinom_polinom(top_polinom, end_polinom, top_polinom1, end_polinom1, top_polinom2, end_polinom2);
	cout << "polinom2=polinom*polinom1 " << endl;
	show_polinom(top_polinom2);
	system("pause");
	return 0;

}
