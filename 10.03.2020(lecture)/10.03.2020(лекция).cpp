#include <iostream>
#include <fstream>
using namespace std;

struct abit
{
	char fio[40];
	int mark[3];
	int sum;
};

int main()
{
	ifstream in("arb.txt");
	ofstream out_bin("out.bin", ios::binary);
	if (!in)
	{
		cout << "File not found" << endl;
			system("pause");
			exit(-1);
	}
	abit x;
	int k = 0;
	while (in>>x.fio>>x.mark[0]>>x.mark[1]>>x.mark[2])
		if ((x.mark[0] >= 40) && (x.mark[1] >= 40) && (x.mark[2] >= 40))
		{
			k++;
			x.sum = x.mark[0] + x.mark[1] + x.mark[2];
			out_bin.write((char*)& x, sizeof(struct abit));
		}
	in.close(); out_bin.close();

	abit* a = new abit[k];

	ifstream in_bin("out.bin", ios::binary);

	int i;
	for (i = 0; i < k; i++)
	{
		in_bin.read((char*)& x, sizeof(struct abit));// можно вместо x a[i]
		a[i] = x;
	}
	in_bin.close();
	
	int j;
	for (i=0;i<k-1;i++)
		for (j=i+1;j<k;j++)
			if (a[i].sum < a[j].sum) // присваем структуру структуре - не отдельно по полям
			{
				x = a[i];
				a[i] = a[j];
				a[j] = x;
			}
	int n;
	cout << "Enter n = "; cin >> n;
	ofstream out("priem.txt");
	out << "List of students" << endl;
	for (i = 0; i < n; i++)
	{
		out << a[i].fio << " " << a[i].sum << endl;
	}
	out << "minimum=" << a[n - 1].sum << endl << endl;
	i = n;
	while ((i < k) && (a[i].sum == a[n - 1].sum)) // k - число прошедших порог студентов
	{
		i++;

	}
	int dop = i - n;
	out << "Dop students" << endl;
	for (j = 0; j < dop; j++)
		out << a[j + n].fio << " " << a[j + n].sum << endl;
	out.close();
}
    
