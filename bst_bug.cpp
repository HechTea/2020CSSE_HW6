
//Binary Search Tree Program
//#include "stdafx.h"		// @TODO
#include <iostream>
#include <cstdlib>
using namespace std;

class BinarySearchTree
{
private:
	struct tree_node
	{
		tree_node* left;
		tree_node* right;
		int data;		// @BUG  missing semi-colon
	};
	tree_node* root;
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void print_inorder();
	void inorder(tree_node*);
	void print_preorder();
	void preorder(tree_node*);
	void print_postorder();
	void postorder(tree_node*);
	void insert(int);
	void remove(int);
};	// @BUG  missing semi-colon

// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert(int d)	// @BUG  "viod" -> "void"
{
	tree_node* t = new tree_node;
	tree_node* parent;
	t->data = d;	// @BUG  "." -> "->"
	t->left = NULL;
	t->right = NULL;
	parent = NULL;
	// is this a new tree?
	if (isEmpty()) root = t;
	else
	{
		//Note: ALL insertions are as leaf nodes
		tree_node* curr;
		curr = root;
		// Find the Node's parent
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;	// @BUG  "t->data < curr->data" -> "t->data > curr->data".  定義右邊是較大的
			else curr = curr->left;
		}

		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}

void BinarySearchTree::remove(int d)	// @BUG  ":"  ->  "::"
{
	//Locate the element
	int found = false;
	if (isEmpty())
	{
		cout << " This Tree is empty! " << endl;
		return;
	}
	tree_node* curr;
	tree_node* parent = NULL;
	curr = root;
	while (curr != NULL)
	{
		if (curr->data == d)
		{
			found = true;	//  @BUG  missing semi-colon
			break;
		}
		else
		{
			parent = curr;
			if (d > curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	if (!found)
	{
		cout << " Data NOT found! " << endl;	// @BUG `" Data found! "` -> `" Data NOT found! "`.
		return;
	}

	if (curr == root) {delete curr;  root = NULL;  return;}	// @BUG  added this line.
	// 3 cases :
	// 1. We're removing a leaf node
	// 2. We're removing a node with a single child
	// 3. we're removing a node with 2 children

	// Node with single child
	if ((curr->left == NULL && curr->right != NULL) || // @BUG  "&" -> "&&"
		(curr->left != NULL && curr->right == NULL))
	{
		if (curr->left == NULL && curr->right != NULL)	// @BUG "curr->left = NULL" -> "curr->left == NULL"
		{
			if (parent->left == curr)
			{
				parent->left = curr->right;
				delete curr;
			}
			else
			{
				parent->right = curr->right;
				delete curr;	// @BUG  "cur" -> "curr"
			}
		}
		else // left child present, no right child
		{
			if (parent->left == curr)
			{
				parent->left = curr->left;
				delete curr;
			}
			else
			{
				parent->right = curr->left;
				delete curr;	//  @BUG  missing semi-colon
			}
		}
		return;
	}

	//We're looking at a leaf node
	if (curr->left == NULL && curr->right == NULL)
	{
		if (parent->left == curr) parent->left = NULL;	// @BUG  extra "}"
		else parent->right = NULL;
		delete curr;
		return;
	}


	//Node with 2 children
	// replace node with smallest value in right subtree
	if (curr->left != NULL && curr->right != NULL)
	{
		tree_node* chkr;
		chkr = curr->right;	// @BUG  "ckhr" -> "chkr"
		if ((chkr->left == NULL) && (chkr->right == NULL))
		{
			chkr->left = curr->left; // @BUG  curr = chkr;
			curr->left = chkr->left; curr->right = chkr->right; curr->data = chkr->data; // @BUG  delete chkr;
			delete chkr; // @BUG  curr->right = NULL;
		}
		else // right child has children
		{
			//if the node's right child has a left child
			// Move all the way down left to locate smallest element

			if ((curr->right)->left != NULL)	// @BUG "curr->right)->left != NULL" -> "(curr->right)->left != NULL"
			{
				tree_node* lcurr;
				tree_node* lcurrp;
				lcurrp = curr->right;
				lcurr = (curr->right)->left;
				while (lcurr->left != NULL)
				{
					lcurrp = lcurr;	// @BUG  missing semi-colon
					lcurr = lcurr->left;
				}
				curr->data = lcurr->data;
				delete lcurr;
				lcurrp->left = NULL;
			}
			else
			{
				tree_node* tmp;
				tmp = curr->right;
				curr->data = tmp->data;	// @BUG  missing semi-colon
				curr->right = tmp->right;
				delete tmp;
			}

		}
		return;
	}

}

void BinarySearchTree::print_inorder()
{
	inorder(root);	// @BUG  ";;" -> ";"
}

void BinarySearchTree::inorder(tree_node* p)
{
	if (p != NULL)
	{
		if (p->left) inorder(p->left);
		cout << " " << p->data << " ";
		if (p->right) inorder(p->right);	// @BUG  ";;" -> ";"
	}
	else return;
}

void BinarySearchTree::print_preorder()
{
	preorder(root);	// @BUG "rooot" -> "root"
}

void BinarySearchTree::preorder(tree_node* p)
{
	if (p != NULL)
	{
		cout << " " << p->data << " ";
		if (p->left) preorder(p->left);	// @BUG  removed "{}" after 'if'
		if (p->right) preorder(p->right);
	}
	else return;
}

void BinarySearchTree::print_postorder()
{
	postorder(root);
}

void BinarySearchTree::postorder(tree_node* p)
{
	if (p != NULL)	// @BUG  "=" -> "!="
	{
		if (p->left) postorder(p->left);
		if (p->right) postorder(p->right);
		cout << " " << p->data << " ";
	}
	else return;
}

int main()
{
	cout << "AHHH" << endl;
	BinarySearchTree b;
	int ch, tmp, tmp1;
	while (1)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Operations " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insertion/Creation " << endl;
		cout << " 2. In-Order Traversal " << endl;
		cout << " 3. Pre-Order Traversal " << endl;
		cout << " 4. Post-Order Traversal " << endl;
		cout << " 5. Removal " << endl;
		cout << " 6. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1: cout << " Enter Number to be inserted : ";
			cin >> tmp;
			b.insert(tmp);	// @BUG  "b.inssert(tmp);" -> "b.insert(tmp);"
			break;
		case 2: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_inorder();
			break;
		case 3: cout << endl;
			cout << " Pre-Order Traversal " << endl;
			cout << " -------------------" << endl;
			b.print_preorder();
			break;
		case 4: cout << endl;
			cout << " Post-Order Traversal " << endl;
			cout << " --------------------" << endl;
			b.print_postorder();
			break;
		case 5: cout << " Enter data to be deleted : ";
			cin >> tmp1;
			b.remove(tmp1);	// @BUG  "ch" -> "tmp1"
			break;
		case 6: system("pause");
			return 0;
			break;
		}
	}
}

