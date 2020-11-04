#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int  main()
{
	const int n = 20, kol_sost = 4; //s1=0;s2=1;s3=2;s4=3
	const int number_comand = 8;
	char a[n], b[n];
	struct zap
	{
		char sym;
		int sost;
	};
	zap tabl[kol_sost][100];
	int i, p;
	char y1, y2;
	int sost_avt = 0;

	for (i = 0; i < n; i++)
	{
		a[i] = ' ';
		b[i] = ' ';
	};
	ifstream in("avtomat.txt");
	char sym_in, sym_out;
	int sost_in, sost_out;
	if (!in)
	{
		cout << "Can't open file " << endl;
		system("pause");
		exit(1);
	}
	for (i = 0; i < number_comand; i++)
	{
		in >> sym_in >> sym_out >> sost_in >> sost_out;
		tabl[sost_in][sym_in].sost = sost_out;
		tabl[sost_in][sym_in].sym = sym_out;
	}

	in.close();
	cout << "TABLE OF AVTOMAT" << endl;

	cout << setw(5) << 'a' << setw(5) << 'b' << endl;
	for (sost_in = 0; sost_in < kol_sost; sost_in++)
	{
		cout << sost_in;
		for (char sym_in = 'a'; sym_in <= 'b'; sym_in++)
			cout << setw(4) << tabl[sost_in][sym_in].sost << tabl[sost_in][sym_in].sym;
		cout << endl;
	}

	cout << endl << "enter input word number symbols <=20; symbol 'n' is end of  word  " << endl;
	cout << "alfabet input ['a','b'] " << endl;
	cout << "alfabet output['c','d','e','f','g'] " << endl;
	cout << endl << "input word " << endl;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 'n') break;
	}
	cout << "enter y1= ";
	cin >> y1;
	cout << "enter y2= ";
	cin >> y2;
	i = 0;

	while ((a[i] != 'n') && (i < n))
	{
		b[i] = tabl[sost_avt][a[i]].sym;
		sost_avt = tabl[sost_avt][a[i]].sost;
		i++;
	};

	p = 0;// p -  number of subwords y1y2 in word b
	for (i = 0; i < n - 1; i++)
		if ((b[i] == y1) && (b[i + 1] == y2)) p++;

	cout << endl;

	cout << "input word" << endl;
	for (i = 0; i < n && a[i] != 'n'; i++) cout << a[i];
	cout << endl;

	cout << endl << "output word" << endl;
	for (i = 0; i < n - 1; i++)
		cout << b[i];
	cout << endl;
	cout << endl << "number of words   " << y1 << y2 << "   p=   " << p << endl;
	system("pause");
	return 0;
}