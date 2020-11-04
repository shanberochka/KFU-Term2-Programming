#include <iostream>
#include<fstream>
using namespace std;

struct node
{
	int data;
	node* next;
};
////////////////////////////////////////////////
bool empty_set(node* top)
{
	return top == NULL;
}
/////////////////////////////////////////////	
void push(node*& top, int data)
{
	node* p;
	p = new node;
	p->data = data;
	p->next = top;
	top = p;
}

////////////////////////////////////////
node* find_address(node* top, int x)
{
	node* p;
	p = top;
	while (p && (p->data) != x)
		p = p->next;
	return p;
}
///////////////////////////////////////////
bool is_Member(node* top, int data)
{
	if (find_address(top, data)) return true; else return false;
}
//////////////////////////////////////////
node* create_set(ifstream& f)
{
	int x;
	node* top = NULL;

	if (!f)
	{
		cout << "Can't open file!" << endl;
		system("pause");
		exit(-1);
	}

	while (f >> x)
		//if (!is_Member(top, x))
			push(top, x);
	return top;

}
//////////////////////////////////////////////////
void order_set(node* top)
{
	int data;
	node* p, * q;
	p = top;
	while (p->next)
	{
		q = p->next;
		while (q)
		{
			if (p->data > q->data)
			{
				data = p->data;
				p->data = q->data;
				q->data = data;

			}
			q = q->next;
		}
		p = p->next;
	}

}
node* big_list(node* L1, node* L2)
{
	// две упорядоченные по неубыванию последовательности объединяет в один упорядоченный по неубыванию список .. в коде элементы с двух пос-тей кладутся начиная с малого элемента в большую посл-ть, но получается как LIFO поэтому наоборот порядок
	node* L = NULL;

	while (L1 || L2)
	{
		if (L1 && L2)
		{
			if ((L1->data) < (L2->data))
			{
				push(L, L1->data);
				L1 = L1->next;
			}
			else
			{
				push(L, L2->data);
				L2 = L2->next;
			}
		}
		else
		{
			if (L2)
			{
				push(L, L2->data);
				L2 = L2->next;
			}
			if (L1)
			{
				push(L, L1->data);
				L1 = L1->next;
			}
		}
	}
	return L;
}
////////////////////////////////////////////////////
node* copy_sets(node* top)
{
	node* top1 = NULL;

	while (top)
	{
		push(top1, top->data);
		top = top->next;
	}
	return top1;
}
///////////////////////////////////////////////////
node* union_sets(node* top1, node* top2)
{
	node* top3;

	top3 = copy_sets(top1);
	while (top2)
	{
		if (!is_Member(top3, top2->data))
			push(top3, top2->data);
		top2 = top2->next;
	}
	order_set(top3);
	return top3;
}
//////////////////////////////////////////////////
node* intersection_sets(node* top1, node* top2)
{
	node* top3 = NULL;
	while (top2)
	{
		if (is_Member(top1, top2->data))
			push(top3, top2->data);
		top2 = top2->next;
	}
	order_set(top3);
	return top3;
}
////////////////////////////////////////////
node* subtruction_sets(node* top1, node* top2)

{
	node* top3 = NULL;

	while (top1)
	{
		if (!is_Member(top2, top1->data))
			push(top3, top1->data);
		top1 = top1->next;
	}
	order_set(top3);
	return top3;
}
/////////////////////////////////////////
node* symmetric_subtruction(node* top1, node* top2)

{
	node* top3, * top4, * top5;

	top4 = subtruction_sets(top1, top2);
	top5 = subtruction_sets(top2, top1);
	top3 = union_sets(top4, top5);
	order_set(top3);
	return top3;
}



/////////////////////////////////////////////
void show_set(ofstream& f, node* top)
{
	f << " { ";
	while (top)
	{
		f << top->data << " , ";
		top = top->next;
	}
	f << " }  " << endl;
}
/////////////////////////////////////////////
int main()
{
	node* top1, * top2, * top3;
	ifstream in1("data1.txt");
	ifstream in2("data2.txt");
	ofstream out("algebra_sets.txt");

	top1 = create_set(in1);

	out << "ALGEBRA OF SETS" << endl;
	out << "set1: " << endl;
	show_set(out, top1);
	in1.close();

	top2 = create_set(in2);
	out << "set2: " << endl;
	show_set(out, top2);
	in2.close();

	order_set(top1);
	out << "order set1=" << endl;
	show_set(out, top1);

	order_set(top2);
	out << "order set2=" << endl;
	show_set(out, top2);

	top3 = big_list(top1, top2);
	show_set(out, top3);

	/*top3 = union_sets(top1, top2);
	out << "set3=se1 U set2: " << endl;
	show_set(out, top3);
	top3 = intersection_sets(top1, top2);
	out << "set3=se1 ^ set2: " << endl;
	show_set(out, top3);

	top3 = subtruction_sets(top1, top2);
	out << "set3=set1 - set2: " << endl;
	show_set(out, top3);

	top3 = subtruction_sets(top2, top1);
	out << "set3=set2 - set1: " << endl;
	show_set(out, top3);

	top3 = symmetric_subtruction(top1, top2);
	out << "set3=(set1 - set2)U(set2 - set1): " << endl;
	show_set(out, top3);
	top3 = union_sets(top1, subtruction_sets(top2, top1));
	out << "set3=(set1 U (set2-set1) " << endl;
	show_set(out, top3);
	out.close();*/
	system("pause");
	return 0;
}
