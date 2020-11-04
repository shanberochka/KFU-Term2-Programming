#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sstream>

using namespace std;
void exe1();
void exe2();
void exe3();
void exe4();
void exe5();
void exe6();
int main()
{
	setlocale(LC_ALL, "RUS");
	int num_exe;
	bool finish = false;

	do {
		cout << "\n Выберете номер задачи(0-Завершить): ";
		cin >> num_exe;

		switch (num_exe)
		{
		case 0: finish = true; break;
		case 1: exe1(); break;
		case 2: exe2(); break;
		case 3: exe3(); break;
		case 4: exe4(); break;
		case 5: exe5(); break;
		case 6: exe6(); break;

		default:
			cout << "Такой задачи нет";
			break;
		}

	} while (!finish);
	
	
}
void exe1()
{
	cout << "\t =========== Задание 1 ===========" << endl;
	cout << "\t Фаимиля Имя Отчество" << endl;
	char fio[80], fam[80], im[80], otch [80];
	cout << "Введите ФИО: ";
	cin.get();
	cin.getline(fio, 50);

	int i, j;

	for (i = 0; fio[i] != ' '; i++)
		fam[i] = fio[i];
	fam[i] = '\0';
	i++; j = 0;
	while (fio[i] != ' ')
	{
		im[j] = fio[i];
		i++;
		j++;
	}
	im[j] = '\0';
	i++;
	j = 0;
	while (fio[i] != '\0')
	{
		otch[j] = fio[i];
		i++; j++;
	}
	otch[j] = '\0';
	cout << "Фамилия: \t" << fam << endl;
	cout << "Имя: \t\t" << im << endl;
	cout << "Отчество: \t" << otch << endl;
}
void exe2()
{
	cout << "\t =========== Задание 2 ===========" << endl;
	cout << "\t Вывод строки в обратном порядке" << endl;
	char str[50];
	cout << "Введите строку: ";
	cin.get();
	cin.getline(str, 50);
	for (int i = strlen(str); i >= 0; i--)
		cout << str[i]; 
	cout << endl;
}
void exe3()
{
	cout << "\t =========== Задание 3 ===========" << endl;
	cout << "\t Вывод текста, печатая каждое слово в обратном порядке" << endl;
	char line[50]; int n,i; bool t = true;

	cout << "Введите строку: " ;
	cin.get();
	cin.getline(line, 50);
	char word[50] = {};

	stringstream x;
	x << line;

	while (x >> word)
	{
		n = strlen(word);
		for (i = n-1; i >= 0; i--)
		{
			cout << word[i];
		}
		cout << ' ';
	}
	cout << endl;

}
void exe4()
{
	cout << "\t =========== Задание 4 ===========" << endl;
	cout << "\t Сколько слов содержит ровно две буквы Х (Х вводится с клавиатуры)" << endl;
	char line[50], letter[2]; int n,i,let_count, word_count=0;
	cout << "Введите строку: " << endl;
	cin.sync();
	cin.get();
	cin.getline(line, 50);

	cout << "Введите букву: " << endl;
	cin.getline(letter, 2);
	char word[50] = {};
	
	stringstream x;        
	x << line;       

	while (x >> word)
	{
		bool t = true;
		n = strlen(word);
		let_count = 0;
		for (i = 0; i < n && t; i++) // проверка Слово?
		{
			if (word[i] < 'A' || word[i] > 'z') t = false;
		}
		if (t)
			for (i = 0; i < n; i++)
		{
			if (word[i] == letter[0]) let_count++;
		}
		if (let_count == 2) word_count++;
	}
	cout << "Количество слов с двумя " << letter[0] << ": " << word_count << endl;
}
void exe5()
{
	cout << "\t =========== Задание 5 ===========" << endl;
	cout << "\t Если последний символ цифра X (Х вводится с клавиатуры)\n \t заменить первые Х символов символом &" << endl;
	char line[50];
	char what[2];
	int r;
	cout << "Введите строку: " << endl;
	cin.sync();
	cin.get();
	cin.getline(line, 50);
	cout << "Введите число: " << endl;
	cin.getline(what, 2);
	int len = strlen(line);
	if (line[len - 1] == what[0]) { r = atoi(what); }
	else r = 0;
	for (int i = 0; i < r && i < len; i++)
		line[i] = '&';
	cout << "Результат:  " << line << endl;
}
void exe6()
{
	cout << "\t =========== Задание 6 ===========" << endl;
	cout << "\t Сортировка каждого слова строки в лексикографическом порядке" << endl;
	char line[50];
	char k;
	int i, j, n;
	bool fl;
	cout << "Введите строку: " << endl;
	cin.sync();
	cin.get();
	cin.getline(line, 50);
	char word[50] = {};


	stringstream x;        //Создание потоковой переменной
	x << line;                //Перенос строки в поток

	while (x >> word) 
	{
		fl = true;
		n = strlen(word);
		for (i = 0; i < n && fl; i++)
		{
			fl = false;
			for (j = 0; j < n - i - 1; j++)
				if (word[j] > word[j + 1])
				{
					k = word[j];
					word[j] = word[j + 1];
					word[j + 1] = k;
					fl = true;
				}
		}
		cout << word << ' ';
	}
	
	cin.get();
}


