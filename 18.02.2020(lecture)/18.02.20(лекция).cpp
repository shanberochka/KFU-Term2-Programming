#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	char fname[20];
	int x;
	cout << "Enter name of file:";
	cin >> fname;
	// Открытие двоичного файла для вывода
	ofstream out(fname, ios::binary);
	if (!out)
	{
		cout << "Not open file" << endl;
		system("pause");
		exit(1);
	}
	cout << "Enter integer numbers. Number 9999 - end of input" << endl;
	// Ввод целых чисел с экрана терминала и запись в двоичный файл.
	// Функция sizeof(int) возвращает количество байт,
	// выделяемых для размещения числа типа int

	while (cin >> x && x != 9999)
		out.write((char*)& x, sizeof(int));
	out.close();
	// Открытие созданного двоичного файла для ввода.
	ifstream in(fname, ios::binary);
	if (!in)
	{
		cout << "Not open file" << endl;
		system("pause");
		exit(1);
	}
	cout << "Output file: " << endl;
	// Чтение двоичного файла и вывод его на экран терминала.
	while (in.read((char*)& x, sizeof(int)));
	cout << x << ' ';
	cout << endl;
	in.close();
	in.open(fname);
	int y = 0;
	while (in.read((char*)& x, sizeof(int)))
		y += x;
	in.close();
	cout << "y=" << endl;
	ofstream out1("arb1.bin", ios::binary);
	ofstream out2("arb2.bin", ios::binary);
	in.open(fname);
	while (in.read((char*)& x, sizeof(int)))
		if (x % 2 == 1) out1.write((char*)& x, sizeof(int));
		else out2.write((char*)& x, sizeof(int));
	in.close();
	out1.close();
	out2.close();
	ifstream in1("arb1.bin", ios::binary);
	ifstream in2("arb2.bin", ios::binary);
	y = 0;
	while (in1.read((char*)& x, sizeof(int)))
		y += x;
	in1.close();
	cout << "y1=" << y << endl;
	y = 0;
	while (in2.read((char*)& x, sizeof(int)))
		y += x;
	in2.close();
	cout << "y2=" << y << endl;
	system("pause");
	return 0;
}

