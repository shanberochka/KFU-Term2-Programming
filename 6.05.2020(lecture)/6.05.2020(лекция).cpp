#include<iostream>
#include<fstream>
using namespace std;

//////////////////
const int N = 80;
struct node
{
	char data;
	node* next;
};

////////////////////////////
void Fill_In(ifstream& f, char z[N])
{
	f >> z;
}
/////////////////////////////
void Check(ofstream& f, char z[N])
{
	f << z << endl;
}
/////////////////////////////
void Push(node*& top, char x)
{
	node* p;
	p = new node;
	p->next = top;
	p->data = x;
	top = p;
}

//////////////////////////////////
void Error(ofstream& f, bool& output)
{
	output = true;
	f << " error= output=" << output << endl;
}
//////////////////////////
void Print_Error(ofstream& f, bool output)
{
	if (output)
		f << "sentence error" << endl;
}
////////////////////////////
void Show_stack(ofstream& f, node* top)
{
	node* p;
	p = top;

	f << endl << "stack=" << endl;;

	while (p)
	{
		f << p->data;
		p = p->next;
	}
	f << endl;
}
////////////////////////////
int Length_stack(node* top)
{
	int l;
	node* p;
	l = 0;
	p = top;
	while (p)
	{
		p = p->next;
		l++;
	}
	return l;
}
////////////////////////////////
void Action1(ofstream& f, node*& top, bool& output)
{
	node* p;
	if ((top->data != '+') ||
		(top->next->data != 'E'))
		Error(f, output);

	else

	{
		p = top->next;
		delete top;
		top = p;
	}
}



/////////////////////////////////
void Action2(ofstream& f, node*& top, bool& output)
{

	node* p2, * p3, * p4, * p5, * p6, * p7;

	if ((top->data != 'E') ||
		(top->next->data != '('))
		Error(f, output);
	else

	{
		Push(top, ')');
		Show_stack(f, top);

		if (Length_stack(top) > 7)
		{
			p2 = top->next;
			p3 = p2->next;
			p4 = p3->next;
			p5 = p4->next;
			p6 = p5->next;
			p7 = p6->next;

			if ((top->data == ')') &&
				(p2->data == 'E') &&
				(p3->data == '(') &&
				(p4->data == '*') &&
				(p5->data == ')') &&
				(p6->data == 'E') &&
				(p7->data == '('))
			{
				delete top;
				delete p2;
				delete p3;
				delete p4;
				delete p5;
				delete p6;
				top = p7;
				top->data = 'E';

				if (Length_stack(top) > 3)
				{
					p2 = top->next;
					p3 = p2->next;
					if ((top->data == 'E') &&
						(p2->data == '+') && (p3->data == 'E'))
					{
						delete top;
						delete p2;
						top = p3;
					}
				}
			}
		}

	}
}



///////////////////////////////////////////  
void Action3(ofstream& f, node*& top, bool
	& output)
{
	if ((top->data == 'E') &&
		(top->next->data == 'm'))
		f << "correct sentence" << endl;
	else Error(f, output);
}
///////////////////////////////////////////

int main()
{
	node* p, * top;
	bool output;
	char str[N];
	char x;
	int i;
	ifstream in("test.txt");
	ofstream out("result.txt");

	if (!in)
	{
		cout << " Can’t open file!" << endl;
		system("pause");
		exit(-1);
	}
	Fill_In(in, str);
	in.close();

	out << endl << "arithmetic sentence " << endl;
	Check(out, str);

	p = new node;
	top = p;
	p->data = 'm';
	p->next = NULL;
	i = -1;
	output = false;
	do
	{
		x = top->data;
		i++;
		switch (str[i])
		{
		case '(': switch (x)
		{
		case '+':
			Push(top, str[i]);
			break;
		case '*': Push(top, str[i]);
			break;
		case '(': Push(top, str[i]);
			break;
		case 'm':Push(top, str[i]);
			break;
		default: Error(out, output);
			break;
		}
				  break;

		case 'A': switch (x)
		{
		case '+':
			Action1(out, top, output);
			break;
		case '(': Push(top, 'E');
			break;
		case 'm':Push(top, 'E');
			break;

		default: Error(out, output);
			break;
		}
				  break;

		case '+': switch (x)
		{
		case 'E':
			Push(top, str[i]);
			break;
		default: Error(out, output);
			break;
		}
				  break;

		case '*': switch (x)
		{
		case ')': Push(top, str[i]);
			break;
		default: Error(out, output);
			break;
		}
				  break;

		case ')': switch (x)
		{
		case 'E':
			Action2(out, top, output);
			break;
		default: Error(out, output);
			break;
		}
				  break;


		case '$': switch (x)
		{
		case 'E':
			Action3(out, top, output);
			break;
		default: Error(out, output);
			break;
		}
				  break;

		default: Error(out, output);
			break;
		}

		Show_stack(out, top);

	} while ((str[i] != '$') && (!output));
	Print_Error(out, output);
	out.close();
	system("pause");
	return 0;
}
