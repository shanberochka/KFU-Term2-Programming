#include <iostream>
#include <fstream>
using namespace std;
struct Person
{
	char fio[30];
	int age;
	int edu;
	int ability[4];
	int work_exp;
	int max_work_exp;
	int num_works;
	int count_fired;
};
void Sort(Person* A, int k)
{
	int i, j;
	Person t;
	for (i = 0; i < k - 1; i++)
		for (j = i + 1; j < k; j++)
			if (A[i].work_exp < A[j].work_exp)
			{
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}

}
int main()
{

	ifstream in("input.txt");
	ofstream out("output.txt");
	Person x;
	int k = 0, n = 0;
	int i, j;
	Person mas[100];
	
	if (!in)
	{
		cout << "File 'in' not found" << endl;
		system("pause");
		exit(-1);
	}
	while (in >> x.fio >> x.age >> x.edu >> x.ability[0] >> x.ability[1] >> x.ability[2] >> x.ability[3] >> x.work_exp >> x.max_work_exp >> x.num_works >> x.count_fired)
	{
		if ((x.age <= 50) && (x.edu == 2 || x.edu == 1) && (x.ability[0]==1)|| (x.ability[1]==1) && (x.work_exp >= 5) && (x.max_work_exp >= x.work_exp/2) && (x.count_fired <=1) && (x.num_works <=5))
		{
			mas[k] = x;
			//out.write((char*)& x, sizeof(struct Person));
			k++;
		}
	}
	
	in.close();
	
	Sort(mas, k);
	cout << "Enter number of vacant seats:  "; cin >> n;
	//out << "List of the best candidates" << endl;
	for (i = 0; i < n; i++)
	{
		out << mas[i].fio << " " << mas[i].age << " " << mas[i].edu << " " << mas[i].ability[0] << " " << mas[i].ability[1] << " " << mas[i].ability[2] << " " << mas[i].ability[3] << " " << mas[i].work_exp << " " << mas[i].max_work_exp << " " << mas[i].num_works << " " << mas[i].count_fired << endl;
	}
	out.close();

	ifstream candidates("output.txt");
	ofstream chef_candidates("chef_candidates.txt");
	if (!candidates)
	{
		cout << "File 'out.txt' not found" << endl;
		system("pause");
		exit(-1);
	}
	Person cand;
	k = 0;
	while (candidates >> cand.fio >> cand.age >> cand.edu >> cand.ability[0] >> cand.ability[1] >> cand.ability[2] >> cand.ability[3] >> cand.work_exp >> cand.max_work_exp >> cand.num_works >> cand.count_fired)
	{
		
		if ((cand.age <= 45) && (cand.edu == 2) && (cand.work_exp >= 15) && (cand.count_fired == 0) && (cand.num_works <= 2))
		{
			chef_candidates << cand.fio << " " << cand.age << " " << cand.edu << " " << cand.ability[0] << " " << cand.ability[1] << " " << cand.ability[2] << " " << cand.ability[3] << " " << cand.work_exp << " " << cand.max_work_exp << " " << cand.num_works << " " << cand.count_fired << endl;
			//chef_candidates.write((char*)& cand, sizeof(struct Person));
			k++;
		}
	}
	if (k==0) { chef_candidates << "Нет таковых!"; }
	candidates.close();
	chef_candidates.close();
}
