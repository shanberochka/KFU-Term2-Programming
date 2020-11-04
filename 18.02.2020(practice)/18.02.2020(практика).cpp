#include <iostream>
#include <cstring>
using namespace std;
int main()
{

	//strlen(str
   // for (int i = 0; str[i] = '\0'; i++)
   // strcpy(s1, s2);//копирование из одной в дургую
//strcat(s1, s2);// объединение 
   // isalpha(c); 
	char st[80];
	cout << "\t =====\tExercise number two\t===== \n";
	cout << "Enter the line:" << endl;
	cin.getline(st, 80);
	int cap_num = 0, low_num = 0;
	for (int i = 0; i < strlen(st); i++)
	{
		if ((int(st[i]) >= 65) && (int(st[i]) <= 90)) cap_num++;
		if ((int(st[i]) >= 97) && (int(st[i]) <= 122)) low_num++;
	}
	
	cout << "The number of capital letter is " << cap_num << endl;
	cout << "The number of lowercase letter is " << low_num << endl;

	cout << "\t =====\tExercise number three\t===== \n";
	int num;
	cout << "Enter the number to determine the appropriate symbol in ASCII: " << endl; cin >> num;
	cout << "It is a " << char(num) << endl;

	cout << "\t =====\tExercise number one\t===== \n";
	char str[80];
	int i = 0, j, k, word_count=0;
	bool t ;
	cout << "Enter the line:" << endl;
	cin.getline(str, 80);
	
	while (str[i] != '\0')
	{
		j = 0;
		t = true;
		while ((str[i] != ' '))
		{
			j++; 
			i++;
		}
		for (k = i - j; k < i && t; k++)
		{
			if (!isalpha(str[k])) t = false;
		}
		if (t) word_count++;
		i++;
	}
	cout << "Words count is " << word_count << endl;
}