#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Book
{
	char book_name[50];
	int format;//0-paper, 1-e-book, 2-audiobook
	int cost;
	int genre[13];//GROUP!!!0-children's,1-poetry,2-novel,3-drama,4-biography,5-detective,6-mystety,7-fantasy,8-science fiction,9-horror,10-romance,11-historical,12-spec/prof literature
	char author[30];
	int length;
	char publisher[30];
	int pub_year;
	char language[30];
	int age_restr;
	int rating;
};
void Sort_rating(Book* A, int k)//сорт по убыванию
{
	int i, j;
	Book t;
	for (i = 0; i < k - 1; i++)
		for (j = i + 1; j < k; j++)
			if (A[i].rating < A[j].rating)
			{
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}

}
void Sort_cost(Book* A, int k)//сорт по возрастанию
{
	int i, j;
	Book t;
	for (i = 0; i < k - 1; i++)
		for (j = i + 1; j < k; j++)
			if (A[i].cost > A[j].cost)
			{
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}

}
int main()
{

	ifstream in("books.txt");
	ofstream out_bin("appropriate_books.bin", ios::binary);
	Book x;
	int k = 0, n = 0;
	int i;
	Book mas[100];
	if (!in)
	{
		cout << "File 'books.txt' not found" << endl;
		system("pause");
		exit(-1);
	}


	while (in >> x.book_name >> x.format >> x.cost >> x.genre[0] >> x.genre[1] >> x.genre[2] >> x.genre[3] >> x.genre[4] >> x.genre[5] >> x.genre[6] >> x.genre[7] >> x.genre[8] >> x.genre[9] >> x.genre[10] >> x.genre[11] >> x.genre[12] >> x.author >> x.length >> x.publisher >> x.pub_year >> x.language >> x.age_restr >> x.rating)
	{
		// выбираем бумажную книгу жанра (научная фантастика или поэзия или роман) не (исторический) от авторов (Бродский или Набоков или Шопенгауэр или Киз) годов 1880-1980 язык русский 
		if ((x.format == 0) && ((x.genre[1] == 1) || (x.genre[2] == 1) || (x.genre[7] == 1)) && (x.genre[11] == 0) &&
			((!strcmp(x.author, "Brodsky")) || (!strcmp(x.author, "Nabokov")) || (!strcmp(x.author, "Keyes"))) &&
			((x.pub_year >= 1880) && (x.pub_year <= 1990)) && (!strcmp(x.language, "rus")))
		{
			mas[k] = x;
			k++;
		}
	}

	in.close();

	Sort_rating(mas, k); // сортируем по убыванию рейтинга
	cout << "Enter number of books on one page:  "; cin >> n;
	//out << "List of the n bestsellers" << endl;
	for (i = 0; i < n; i++)
	{
		out_bin.write((char*)& mas[i], sizeof(struct Book));
	}
	out_bin.close();

	ifstream good_rating("appropriate_books.bin", ios::binary);
	ofstream good_rating_cost("best_app_books.txt");
	if (!good_rating)
	{
		cout << "File 'appropriate_books.bin' not found" << endl;
		system("pause");
		exit(-1);
	}
	Book* book = new Book[n];
	k = 0;
	for (i = 0; i < n; i++)
	{
		good_rating.read((char*)& x, sizeof(struct Book));
		if ((x.length < 500) && (x.age_restr >= 12))// отбираем не слишком длинные и не слишком детские книги
		{
			book[k] = x; k++;
		}
	}
	if (k == 0) { good_rating_cost << "There is no appropriate book!"; }
	else
	{
		Sort_cost(book, k);// отсортировали книги с хорошим рейтингом по возрастанию(от дешёвого к дорогому)
		for (i = 0; i < k; i++)
		{
			good_rating_cost << book[i].book_name << " "  << book[i].cost << " " <<  book[i].author << " " << book[i].length << " " << book[i].pub_year << " " << book[i].language << " " << book[i].age_restr << " " << book[i].rating << endl;
		}
	}
	good_rating.close();
	good_rating_cost.close();
	delete[] book;
}
