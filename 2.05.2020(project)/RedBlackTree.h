#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* parent;
	Node* left;
	Node* right;
	int color;
};

typedef Node* NodePtr;

class RedBlackTree
{
private:
	NodePtr root;
	NodePtr TNULL;//a nil leaf

	//void initializeNULLNode(NodePtr node, NodePtr parent)
	//{
	//	node->data = 0;
	//	node->parent = parent;
	//	node->left = nullptr;
	//	node->right = nullptr;
	//	node->color = 0;
	//	// all leafs contain this data
	//}

	void preOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			cout << node->data << " ";
			preOrderHelper(node->left);
			preOrderHelper(node->right);
		}
	}

	void inOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			inOrderHelper(node->left);
			cout << node->data << " ";
			inOrderHelper(node->right);
		}
	}

	void postOrderHelper(NodePtr node)
	{
		if (node != TNULL)
		{
			postOrderHelper(node->left);
			postOrderHelper(node->right);
			cout << node->data << " ";
		}
	}

	NodePtr searchTreeHelper(NodePtr node, int key)
	{
		if (node == TNULL || key == node->data)
		{
			return node;
		}

		if (key < node->data)
		{
			return searchTreeHelper(node->left, key);
		}
		return searchTreeHelper(node->right, key);
	}

	void deleteFix(NodePtr x)
	{
		NodePtr s;
		while (x != root && x->color == 0)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->color == 1)
				{
					s->color = 0;
					x->parent->color = 1;
					leftRotate(x->parent);
					s = x->parent->right;
				}
				/// unkle is black
				if (s->left->color == 0 && s->right->color == 0)
				{
					s->color = 1;
					x = x->parent;
				}
				else
				{
					if (s->right->color == 0)
					{
						s->left->color = 0;
						s->color = 1;
						rightRotate(s);
						s = x->parent->right;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->right->color = 0;
					leftRotate(x->parent);
					x = root;
				}
			}
			else
			{
				s = x->parent->left;
				if (s->color == 1)
				{
					s->color = 0;
					x->parent->color = 1;
					rightRotate(x->parent);
					s = x->parent->left;
				}

				if (s->left->color == 0 && s->right->color == 0)
				{
					s->color = 1;
					x = x->parent;
				}
				else
				{
					if (s->left->color == 0)
					{
						s->right->color = 0;
						s->color = 1;
						leftRotate(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = 0;
					s->left->color = 0;
					rightRotate(x->parent);
					x = root;
				}
			}
		}
		x->color = 0;
	}

	void rbTransplant(NodePtr u, NodePtr v)	// make v as a child of u's parent instead of u, make u's parent as a v's parent
	{
		if (u->parent == nullptr)
		{
			root = v;
		}
		else if (u == u->parent->left)
		{
			u->parent->left = v;
		}
		else
		{
			u->parent->right = v;
		}
		v->parent = u->parent;
	}

	void deleteNodeHelper(NodePtr node, int key)
	{
		NodePtr z = TNULL;
		NodePtr x, y;
		while (node != TNULL)		// looping until no nil node
		{
			if (node->data == key)
			{
				z = node;
			}

			if (node->data <= key) // even if values equal we go to the right so this provide that node in the end will be nil
			{
				node = node->right;
			}
			else
			{
				node = node->left;
			}
		}

		if (z == TNULL)
		{
			cout << "Key not found in the tree" << endl;
			return;
		}

		y = z;
		int original_color = z->color;
		if (z->left == TNULL)
		{
			x = z->right;			// guaranteed that x is leaf because tree is balansed 
			rbTransplant(z, z->right);
		}
		else if (z->right == TNULL)
		{
			x = z->left;
			rbTransplant(z, z->left);
		}
		else
		{
			y = minimum(z->right);
			original_color = y->color;
			x = y->right;
			
			rbTransplant(y, y->right);//y->right replaces y

			rbTransplant(z, y);

			y->right = z->right;
			z->right->parent = y;
			

			
			y->left = z->left;
			z->left->parent = y; 
			y->color = z->color;
		}
		delete z;
		if (original_color == 0)
		{
			deleteFix(x);
		}
	}

	void insertFix(NodePtr k)
	{
		NodePtr u;
		while (k->parent->color == 1)//if sequentially reds 
		{
			if (k->parent == k->parent->parent->right)//if k's parent is right child of k's grandparent
			{
				u = k->parent->parent->left;			//k's uncle
				if (u->color == 1) // if uncle is red we only recolor
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->left)
					{
						k = k->parent;
						rightRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					leftRotate(k->parent->parent);
				}
			}
			else								//case if k's parent is left child of k's grandparent
			{
				u = k->parent->parent->right;	//k's uncle

				if (u->color == 1)				// if uncle is red we only recolor
				{
					u->color = 0;
					k->parent->color = 0;
					k->parent->parent->color = 1;
					k = k->parent->parent;
				}
				else
				{
					if (k == k->parent->right)
					{
						k = k->parent;
						leftRotate(k);
					}
					k->parent->color = 0;
					k->parent->parent->color = 1;
					rightRotate(k->parent->parent);
				}
			}
			if (k == root)
			{
				break;
			}
		}
		root->color = 0;
	}

	void printHelper(NodePtr root, string indent, bool last)
	{
		if (root != TNULL)
		{
			cout << indent;
			if (last)
			{
				cout << "R----";
				indent += "   ";
			}
			else
			{
				cout << "L----";
				indent += "|  ";
			}

			string sColor = root->color ? "RED" : "BLACK";
			cout << root->data << "(" << sColor << ")" << endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}

public:
	RedBlackTree()
	{
		TNULL = new Node;
		TNULL->color = 0;
		TNULL->left = nullptr;
		TNULL->right = nullptr;
		root = TNULL;
	}

	/*void preorder()
	{
		preOrderHelper(this->root);
	}

	void inorder()
	{
		inOrderHelper(this->root);
	}

	void postorder()
	{
		postOrderHelper(this->root);
	}

	NodePtr searchTree(int k)
	{
		return searchTreeHelper(this->root, k);
	}*/

	NodePtr minimum(NodePtr node)
	{
		while (node->left != TNULL)
		{
			node = node->left;
		}
		return node;
	}

	NodePtr maximum(NodePtr node)
	{
		while (node->right != TNULL)
		{
			node = node->right;
		}
		return node;
	}

	/*NodePtr successor(NodePtr x)
	{
		if (x->right != TNULL)
		{
			return minimum(x->right);
		}

		NodePtr y = x->parent;
		while (y != TNULL && x == y->right)
		{
			x = y;
			y = y->parent;
		}
		return y;
	}

	NodePtr predecessor(NodePtr x)
	{
		if (x->left != TNULL)
		{
			return maximum(x->left);
		}

		NodePtr y = x->parent;
		while (y != TNULL && x == y->left)
		{
			x = y;
			y = y->parent;
		}

		return y;
	}*/

	void leftRotate(NodePtr x)
	{
		NodePtr y = x->right;
		x->right = y->left;
		if (y->left != TNULL)
		{
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr)
		{
			this->root = y;
		}
		else if (x == x->parent->left)
		{
			x->parent->left = y;
		}
		else
		{
			x->parent->right = y;
		}
		y->left = x;
		x->parent = y;
	}

	void rightRotate(NodePtr x)
	{
		NodePtr y = x->left;
		x->left = y->right;
		if (y->right != TNULL)
		{
			y->right->parent = x;
		}
		y->parent = x->parent;
		if (x->parent == nullptr)
		{
			this->root = y;
		}
		else if (x == x->parent->right)
		{
			x->parent->right = y;
		}
		else
		{
			x->parent->left = y;
		}
		y->right = x;
		x->parent = y;
	}

	void insert(int key)
	{
		NodePtr node = new Node;
		node->parent = nullptr;
		node->data = key;
		node->left = TNULL;
		node->right = TNULL;
		node->color = 1;

		NodePtr y = nullptr; // will contain the parent of the inserting node
		NodePtr x = this->root; // will contain a place to insert

		while (x != TNULL) // root is not a leaf in the second insertion
		{
			y = x;
			if (node->data < x->data)
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}

		node->parent = y;
		if (y == nullptr) // the first node(root) insertion
		{
			root = node;
		}
		else if (node->data < y->data)
		{
			y->left = node;
		}
		else
		{
			y->right = node;
		}

		if (node->parent == nullptr)// the first node(root) insertion
		{
			node->color = 0;
			return; // that means we wont run the insertFix() - it's a first node insertion
		}

		if (node->parent->parent == nullptr)
		{
			return;// that means we wont run the insertFix() - it is case if the inserting node will settle down on first level of tree///(the root is black, children are red)
		}

		insertFix(node);
	}

	/*NodePtr getRoot()
	{
		return this->root;
	}*/

	void deleteNode(int data)
	{
		deleteNodeHelper(this->root, data);
	}

	void printTree()
	{
		if (root)
		{
			printHelper(this->root, "", true);
		}
	}
};

