#include<iostream>
#include<fstream>
using namespace std;
struct node
{
	char data;
	node* next;
};
/////////////////////////////
bool empty_stack(node* top)
{
	return top == NULL;
}
/////////////////////////////
void push(node*& top, char x)
{
	node* p;
	p = new node;
	p->data = x;
	p->next = top;
	top = p;
}
//////////////////////////////
void pop(node*& top, char& x)
{
	node* p;
	if (!empty_stack(top))
	{
		x = top->data;
		p = top->next;
		delete top;
		top = p;
	}
}
/////////////////////////////////
int main()
{
	ifstream in("arb.txt");
	node* top = NULL;
	char c, op, x, y;

	if (!in)
	{
		cout << " Can’t open file!" << endl;
		system("pause");
		exit(-1);
	}

	while (in >> c)
	{
		// обработка очередного символа текста
	// символы   '(' и  ',' игнорируются
		if ((c <= '9') && (c >= '0') || (c == 'M') || (c == 'm'))
			push(top, c);
		else
			if (c == ')')
				//конец формулы  op(x,y)
			   // из стека удаляются 3 симола y, x, op
					  // выполняется операция op(x,y) и результат     //помещается в стек
			{
				pop(top, y);
				pop(top, x);
				pop(top, op);

				switch (op)
				{
				case 'M': if (x > y) c = x; else c = y; break;
				case 'm': if (x > y) c = y; else c = x; break;
				default:;
				}
				push(top, c);
			}
	}
	in.close();
	pop(top, c);
	cout << "formula=" << c << endl;
	system("pause");
	return 0;

}
