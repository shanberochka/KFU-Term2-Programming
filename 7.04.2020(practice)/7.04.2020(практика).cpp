#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

//////////////////////////////

void main()
{
	ifstream in("sint.txt");
	ofstream out("result.txt");
	char x;
	int q = 0;
	if (!in)

	{
		cout << "Can't open file" << endl;
		exit(-1);
	}

	while (in >> x && q != 6)
	{
		out << x;
		switch (q)
		{
		case 0: if (x == 'A' || x == 'B' || x == 'C')q = 1; else q = 6; break;
		case 1: if (x == 'A') q = 2; else q = 6; break;
		case 2: if (x == 'A' || x == 'C') q = 3; else q = 6; break;
		case 3: if (x == 'A') q = 4; else q = 6; break;
		case 4: if ( x == 'B') q = 5;
				else if (x == 'A' || x == 'C') q = 3;
					else q = 6; break;

		default: q = 6; break;

		}
				out << setw(2) << q << endl;

	}
	out << endl;
	if (q == 5) out << " sequense is element of L" << endl;
	else out << "sequense is not element of L" << endl;
	in.close();
	out.close();

}