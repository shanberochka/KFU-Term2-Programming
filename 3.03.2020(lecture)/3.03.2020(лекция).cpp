#include <iostream>
#include <fstream>
//#include <cstring>

using namespace std;

struct person
{
	char fio[40];
	int year;
	char sex;
	int ms;
	int child;
	char edu;
	int salary;
};

int main()
{
	ifstream in("arb.txt");
	ofstream mout("outman.bin", ios::binary);
	ofstream fout("outwoman.bin", ios::binary);
	person x;
	int k1 = 0, k2 = 0;

	if (!in) 
	{
		cout << "File not found" << endl;
		system("pause");
		exit(-1);
	}
	while (in >> x.fio >> x.year >> x.sex >> x.ms >> x.child >> x.edu >> x.salary)
	{
		if ((x.sex == 'm') && ((2020 - x.year) <= 60) && ((2020 - x.year) >= 40) && (x.child >= 2) && (x.ms == 1) && (x.edu == 'v') && (x.salary >= 40000))
		{
			mout.write((char*)& x, sizeof(struct person));
			k1++;
		}
		if ((x.sex == 'w') && ((2020 - x.year) <= 40) && ((2020 - x.year) >= 20) && (x.child >= 2) && (x.ms == 1) && (x.edu == 'v'))
		{
			fout.write((char*)&x, sizeof(struct person));
			k2++;
		}
	}
	in.close();
	mout.close();
	fout.close();

	ifstream manbin("outman.bin", ios::binary);
	ifstream fembin("outwomen.bin", ios::binary);
	if (!manbin)
	{
		cout << "File (man) not found" << endl;
		//system("pause");
		//exit(-1);
	}
	if (!fembin)
	{
		cout << "File (female) not found" << endl;
		//system("pause");
		//exit(-1);
	}
	cout << " Men list" << endl;
	while (manbin.read((char*)& x, sizeof(struct person)))
	{
		cout << x.fio << ' ' << x.year << ' ' << x.child << endl;
	}
	cout << " Women list" << endl;
	while (fembin.read((char*)& x, sizeof(struct person)))
	{
		cout << x.fio << ' ' << x.year << ' ' << x.child << endl;
	}
	manbin.close();
	fembin.close();
	return 0;
}
