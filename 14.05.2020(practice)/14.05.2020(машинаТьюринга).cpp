
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>

using namespace std;

int  main()
{
	const int n = 100, kol_sost = 22;
	const int number_comand = 44;
	char a[n];
	struct zap
	{
		char sym;
		int sost;
		char move;// R-right L-left H-halt
	};

	zap tabl[kol_sost][100];
	int i, p;

	int sost = 1;

	for (i = 0; i < n; i++)
		a[i] = '_';

	ifstream in("turing.txt");
	ofstream out("out.txt");
	char sym_in, sym_out;
	int sost_in, sost_out;
	char mv;
	if (!in)
	{
		cout << "Can't open file " << endl;
		system("pause");
		exit(-1);
	}
	for (i = 0; i < number_comand; i++)
	{
		in >> sym_in >> sym_out >> mv >> sost_in >> sost_out;
		tabl[sost_in][sym_in].sost = sost_out;
		tabl[sost_in][sym_in].sym = sym_out;
		tabl[sost_in][sym_in].move = mv;
	}

	in.close();
	out << "   TURING MACHINES  (ALAN TURING 1937) " << endl;

	out << setw(10) << 1 << setw(9) << 2 << setw(9) << 3 << setw(9) << 4 << setw(9) << 5 << setw(9) << 6 << setw(9) << 7 << setw(9) << 8 << setw(9) << 9 << setw(9) << 10 << setw(9) << 11 << setw(9) << 12 << setw(9) << 13 << setw(9) << 14 << setw(9) << 15 << setw(9) << 16 << setw(9) << 17 << setw(9) << 18 << setw(9) << 19 << setw(9) << 20 << setw(9) << 21 << setw(9) << 22 << endl;
	out << '_';
	for (sost_in = 1; sost_in <= kol_sost; sost_in++)
	{
		if (tabl[sost_in]['_'].sost == (-858993460)) { out << setw(7) << 'O' << 'O' << 'O'; }
		else 
		{
			if (tabl[sost_in]['_'].sost>9) out << setw(6) << tabl[sost_in]['_'].sym << tabl[sost_in]['_'].sost
				<< tabl[sost_in]['_'].move;
			else out << setw(7) << tabl[sost_in]['_'].sym << tabl[sost_in]['_'].sost
				<< tabl[sost_in]['_'].move;
		}
	}
	out << endl;


	out << '1';
	for (sost_in = 1; sost_in <= kol_sost; sost_in++)
	{
		if (tabl[sost_in]['1'].sost == (-858993460)) { out << setw(7) << 'O' << 'O' << 'O'; }
		else
		{
			if (tabl[sost_in]['1'].sost>9) out << setw(6) << tabl[sost_in]['1'].sym << tabl[sost_in]['1'].sost
				<< tabl[sost_in]['1'].move;
			else out << setw(7) << tabl[sost_in]['1'].sym << tabl[sost_in]['1'].sost
				<< tabl[sost_in]['1'].move;
		}
	}
	out << endl;
	in.close();

	cout << endl << "enter input word; number of symbols <=20;  symbol '_' is a last symbol  " << endl;
	cout << "alfabet  ['_','1'] " << endl;

	cout << endl << "input word " << endl;

	for (i = 50; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == '_') break;
	}

	out << "input word" << endl;
	for (i = 0; i < n; i++) out << a[i];
	out << endl;


	i = 50; int t = 0;
	while (sost && (t < 10000))
	{
		char r = tabl[sost][a[i]].sym;
		int s = tabl[sost][a[i]].sost;
		mv = tabl[sost][a[i]].move;
		sost = s;
		a[i] = r;
		if (mv == 'R') i++; else
			if (mv == 'L') i--;
		t++;
	};


	out << endl << "output word" << endl;
	for (i = 0; i < n; i++) out << a[i];
	out << endl;
	out.close();
	system("pause");
	return 0;
}
