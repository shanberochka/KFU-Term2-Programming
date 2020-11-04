// Implementing Red-Black Tree in C++

#include <iostream>
#include "RedBlackTree.h"

using namespace std;

int main()
{
	RedBlackTree bst;
	bst.insert(21);
	bst.insert(41);
	bst.insert(61);
	bst.insert(31);
	bst.insert(36);
	bst.insert(63);
	bst.insert(9);
	bst.insert(60);
	bst.insert(20); 


	bst.printTree();
	cout << endl
		<< "After deleting 36" << endl;
	bst.deleteNode(36);
	bst.printTree();
	cout << endl
		<< "After deleting 61" << endl;
	bst.deleteNode(61);
	
	bst.printTree();
}