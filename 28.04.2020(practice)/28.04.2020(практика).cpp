#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int n,rows=0;

struct graph
{
	int x; // номер первой вершины 
	int y; // номер второй вершины
	int weight; // вес ребра
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
	while (p && ((p->G.x != x) || (p->G.y != y)) && ((p->G.x != y) || (p->G.y != x)))
		p = p->next;
	return p;
}
void create_list(node*& first, int ** matrix)
{
	for (int i = 0; i < (n-1); i++)
		for (int j = i+1; j < n; j++)
			if (matrix[i][j] > 0)
			{
				graph G;
				G.x = i;
				G.y = j;
				G.weight = matrix[i][j];
				addLast(first, G);
			}
}
void show_list(node* first)
{
	if (!first)
	{
		cout << "List is empty!";
		cout << endl;
	}
	else
	{
		node* p = first;
		cout << "List: " << endl;
		while (p)
		{
			cout << "(" << p->G.x << ", " << p->G.y << ") - " << p->G.weight << "; " << endl;
			p = p->next;
		}

	}
}

int ** create_adj_matrix(ifstream& in)
{
	
	if (!in)
	{
		cout << "Can't open file!";
		exit(-1);
	}
	else
	{
		
		in >> n;
		int **arr = new int* [n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[n];
		}
		int x, k=0, m=0;
		while (in >> x)
		{
			if (k == n)
			{
				k = 0;
				m++;
			}
				arr[m][k] = x;
				k++;
		}
		return arr;
	}
}
int ** create_incid_matrix(int** &matrix)
{
	int i, j;
	int m = (n - 1) * n / 2;
	int** inc_arr = new int*[m];
	for (i = 0; i < m; i++)
		inc_arr[i]= new int[n+1];
	for (i = 0; i < m; i++)
		for (j = 0; j < (n + 1); j++)
			inc_arr[i][j] = 0;

	for (i = 0; i < (n-1); i++)
		for (j = i + 1; j < n; j++)
		{
			if ((matrix[i][j] != 0))
			{
				inc_arr[rows][0] = matrix[i][j];
				inc_arr[rows][i + 1] = 1;
				inc_arr[rows][j + 1] = 1;
				rows++;
			}
		}
	return inc_arr;
}

void show_matrix(int** arr, int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
			cout << setw(5) << arr[i][j];
		cout << endl;
	}
}

void calcEdges(int**adj_matrix,int x)
{
	int j;
	if (x >= n) { cout << "There is no such node" << endl; }
	else
	{
		int edges_count = 0;
		for (j = 0; j < n; j++)
		{
			if (adj_matrix[x][j] > 0)edges_count++;
		}
		cout << "Number of edges which are conected to the node " << x << " is " << edges_count<<endl;
	}
}
int ** transpose_matrix(int** matrix, int row, int col)
{
	int i, j;
	int** new_matrix = new int* [col];
	for (i = 0; i < col; i++)
		new_matrix[i] = new int[row];
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
		{
			//new_matrix[i][j] = 0;
			new_matrix[i][j] = matrix[j][i];
		}
	return new_matrix;
}
int main()
{
	ifstream in("adjacency_matrix.txt");
	int** adj_matrix;
	int** inc_matrix;
	//int** tr_martix;
	int x;

	adj_matrix = create_adj_matrix(in);
	
	
	node* first = nullptr;

	create_list(first, adj_matrix);
	show_list(first);

	cout << endl;
	cout << "Adjacency matrix:" << endl;
	show_matrix(adj_matrix, n, n);

	inc_matrix = create_incid_matrix(adj_matrix);

	cout << "Incidence matrix:" << endl;
	show_matrix(inc_matrix, rows,n+1);

	//cout << "Transpose incidence matrix:" << endl;
	//tr_martix = transpose_matrix(inc_matrix, rows, n+1);
	//show_matrix(tr_martix, n+1 , rows);

	cout << "Enter the node: "; cin >> x;
	calcEdges(adj_matrix,x);

	in.close();
}