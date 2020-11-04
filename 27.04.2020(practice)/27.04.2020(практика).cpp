#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

struct graph
{
	int x1, y1; // координаты первой вершины
	int x2, y2; // координаты второй вершины
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
float Weight(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
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
		while (in >> g.x1 >> g.y1 >> g.x2 >> g.y2)
		{
			g.weight = Weight(g.x1, g.y1, g.x2, g.y2);
			//g.weight = sqrt((g.x1 - g.x2) * (g.x1 - g.x2) + (g.y1 - g.y2) * (g.y1 - g.y2));
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
			out << "Distance between (" << p->G.x1 << ", " << p->G.y1 << ") and (" << p->G.x2 << ", " << p->G.y2 << ") = " << p->G.weight << endl;
			p = p->next;
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

	clear_list(first);
}