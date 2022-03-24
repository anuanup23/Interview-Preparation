// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Node of a Binary Tree
struct Node {
	struct Node* left;
	struct Node* right;
	int data;
};

// Function to create
// a new tree Node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to find the depth
// of the Binary Tree
int finddepth(Node* root)
{
	// If root is not null
	if (!root)
		return 0;

	// Left recursive subtree
	int left = finddepth(root->left);

	// Right recursive subtree
	int right = finddepth(root->right);

	// Returns the maximum depth
	return 1 + max(left, right);
}

// Function to perform the depth
// first search on the binary tree
Node* dfs(Node* root, int curr,
		int depth)
{
	// If root is null
	if (!root)
		return NULL;

	// If curr is equal to depth
	if (curr == depth)
		return root;

	// Left recursive subtree
	Node* left = dfs(root->left,
					curr + 1, depth);

	// Right recursive subtree
	Node* right = dfs(root->right,
					curr + 1, depth);

	// If left and right are not null
	if (left != NULL && right != NULL)
		return root;

	// Return left, if left is not null
	// Otherwise return right
	return left ? left : right;
}

// Function to find the LCA of the
// deepest nodes of the binary tree
Node* lcaOfDeepestLeaves(Node* root)
{
	// If root is null
	if (!root)
		return NULL;

	// Stores the deepest depth
	// of the binary tree
	int depth = finddepth(root) - 1;

	// Return the LCA of the
	// nodes at level depth
	return dfs(root, 0, depth);
}

// Driver Code
int main()
{
	// Given Binary Tree
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->left = newNode(8);
	root->right->left->right = newNode(9);
    root->left->left->left = newNode(10);

	cout << lcaOfDeepestLeaves(root)->data << endl;

	return 0;
}
