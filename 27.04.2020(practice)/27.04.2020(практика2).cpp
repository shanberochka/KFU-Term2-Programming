#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

struct graph
{
	int x; // номер первой вершины 
	int y; // номер второй вершины
	float weight; // вес ребра
};
struct node
{
	graph G;
	node* next;
};

void add_First(node*& first, graph g)
{
	node* tmp = new node;
	tmp->G = g;
	tmp->next = first;
	first = tmp;
}
void addLast(node*& first, graph g)
{
	node* tmp = new node;
	tmp->G = g;
	tmp->next = nullptr;
	if (first == nullptr)
	{
		first = tmp;
	}
	else
	{
		node* p = first;
		while (p != nullptr && p->next != nullptr)
			p = p->next;

		p->next = tmp;
	}
}

node* find_address(node* first, int x, int y)
{
	node* p;
	p = first;
	while (p && ((p->G.x != x) || (p->G.y != y)) && ( (p->G.x != y) || (p->G.y != x)))
		p = p->next;
	return p;
}
void create_list(node*& first, ifstream& in)
{
	if (!in)
	{
		cout << "Can't open file!";
		exit(-1);
	}
	else 
	{
		graph g;
		first = nullptr;
		while (in >> g.x >> g.y >> g.weight)
		{
			addLast(first, g);
		}
	}
}
void show_list(node*& first, ofstream& out)
{
	if (!first)
	{
		out << "There is no nodes";
	}
	else
	{
		node* p = first;
		while (p)
		{
			out << "Distance between (" << p->G.x << " and " << p->G.y << ") = " << p->G.weight << endl;
			p = p->next;
		}
	}
}

void IsEdge(node *&first, ifstream& in, ofstream& out)
{
	if (!first || !in)
	{
		out << "Sorry, no data";
	}
	else
	{
		int x, y;
		while (in >> x >> y)
		{
			node* p = find_address(first, x, y);
			if (!p)
			{
				out << "Distance between (" << x << " and " << y << ") = " << " is indefinite" << endl;
			}
			else
			{
				out << "Distance between (" << x << " and " << y << ") = " << p->G.weight << endl;
			}
		}
	}
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

int main()
{
	node* first = nullptr;
	ifstream in("data.txt");
	ofstream out("result.txt");

	create_list(first, in);
	show_list(first, out);

	in.close();
	out.close();

	ifstream check("check.txt");
	ofstream check_res("checkResult.txt");

	IsEdge(first, check, check_res);

	check.close();
	check_res.close();

	clear_list(first);
}
