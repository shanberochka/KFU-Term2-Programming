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
char pop(node*& top)
{
	node* p;
	char x;
	if (!empty_stack(top))
	{
		x = top->data;
		p = top->next;
		delete top;
		top = p;
	}
	return x;
}
//////////////////////////////
bool balance(node*& top, char sym)
{
	char r = pop(top);
	switch (sym)
	{
	case ')': return r == '('; break;
	case ']': return r == '[';  break;
	case '}': return  r == '{'; break;
	default: return false;
		break;
	}
}
///////////////////////////////////
int main()
{
	bool t = true;
	char sym;
	node* top_bal = NULL;
	ifstream in("arb.txt");

	if (!in)
	{
		cout << " Can't open file!" << endl;
		exit(-1);
	}

	in >> sym;
	cout << sym;

	while ((sym != '.') && t)
	{
		if ((sym == '(') || (sym == '[') || (sym == '{')) push(top_bal, sym);
		else
			if ((sym == ')') || (sym == ']') || (sym == '}'))
			{
				if ((top_bal == NULL) || !balance(top_bal, sym)) t = false;
			}
		in >> sym;
		cout << sym;
	}
	in.close();
	cout << endl;

	if (!t || top_bal) cout << " There is no balance of brackets!" << endl;
	else cout << "There is balance of brackets!" << endl;
	system("pause");
	return 0;

}
