#include <iostream>
#include <fstream>
#include <string>
#define N 5
#define MAX 10000

using namespace std;

///////////////////////////////////////////////////////
void transfer_to_file_matrix(int a[N][N], ofstream& out)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			out << a[i][j] << " ";
		out << endl;
	}
}
///////////////////////////////////////////////////////
void Dijkstra(int a[N][N], ofstream & out, int start, int end)
{
	int i;
	int min, minindex, temp;
	int d[N];
	bool v[N];

	for (i = 0; i < N; i++)
	{
		d[i] = MAX;
		v[i] = false;
	}

	d[start] = 0;

	do
	{
		min = MAX;
		minindex = MAX;

		for (i = 0; i < N; i++)
		{
			if ((!v[i]) && (d[i] < min))		//in the last step all vertices are visited. so min and minindex are not changed and stay MAX
			{
				min = d[i];
				minindex = i;
			}
		}
		if (minindex != MAX)
		{
			for (i = 0; i < N; i++)
			{
				if (a[minindex][i] > 0)
				{
					temp =d[minindex] + a[minindex][i];
					if (temp < d[i])
					{
						d[i] = temp;
					}
				}
			}
			v[minindex] = true;
		}
	} while (minindex < MAX);
	
	out << "The shortest route from the start node to each of the others:" << endl;
	for (i = 0; i < N; i++)
		out << start+1 << " - " << i+1 << " : " << d[i] << endl;

	int route[N];
	route[0] = end;
	int ex_end = end;
	int weight = d[end];
	int k = 1;
	while ((end != start) && (d[end]!=MAX))
	{
		for (i = 0; i < N; i++)
		{
			if (a[i][end] != 0)						//if this condition is not set, the route massive will be corrupted
			{
				temp = d[end] - a[i][end];
				if (temp == d[i])
				{
					end = i;
					weight = temp;
					route[k] = i;
					k++;
				}
			}
		}
	}

	out << "The shortest route from " << start + 1 << " to " << ex_end + 1 << ":" << endl;
	for (i = k; i > 0; i--)
		out << " -> " <<  route[i-1] + 1 ;
}
///////////////////////////////////////////////////////
void show_matrix(int a[N][N])
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << a[i][j];
		cout << endl;
	}
}
///////////////////////////////////////////////////////
int main()
{
	int a[N][N];
	int i,j,x;
	int start, end;
	ofstream out("result.txt");

	for (i = 0; i < N; i++)
	{
		a[i][i] = 0;
		for (j = i+1; j < N; j++)
		{
			cout << "Enter the distanse between " << i + 1 << " and " << j + 1 << ": ";
			cin>>x;
			a[i][j] = x;
			a[j][i] = x;
		}
	}
	transfer_to_file_matrix(a, out);

	/*bool f = true;
	while (f)
	{
		cout << "What node do we start from: "; cin >> start;
		if (start > N)
		{
			cout << "You entered too big number. Try again?(1-Yes, 0-No)"; cin >> x;
			if (x) continue;
			else f = false;
		}
		else f = false;
	}*/
	cout << "What node do we start from: "; cin >> start;
		out << "Start node: " << start << endl;

	cout << "What node are you looking for a route to: "; cin >> end;
		out << "End node: " << end << endl;
	//show_matrix(a);
		Dijkstra(a, out, start - 1, end - 1); 
	
	cout << endl;
	cout  << string(10, '>')<< " Please, check file 'result.txt' " << string(10, '<');
	cout << endl<<endl;
}
