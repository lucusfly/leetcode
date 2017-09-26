#include <iostream>
#include <vector>
#include <stack>

using namespace std;


typedef struct Tree
{
	int value;
	struct Tree * left;
	struct Tree * right;
	
	Tree(int v)
	{
		value = v;
		left = NULL;
		right = NULL;
	}
	
} TreeNode;

void travel(TreeNode * root)
{
	if (root == NULL)
	{
		return;
	}
	
	travel(root->left);
	
	travel(root->right);
	cout << root->value << ',';
	
}

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode *> stack;
    
    int dept = 0;
    while (!stack.empty() || root != NULL)
    {
    	if (root != NULL)
    	{
    		stack.push(root);
    		root = root->left;
		}
		else
		{
			root = stack.top();
			stack.pop();
			
			dept++;
			if (dept == k)
			{
				return root->value;
			}
			
			root = root->right;
		}
	}
}

int main()
{
	TreeNode * root = new TreeNode(5);
	
	root->left = new TreeNode(4);
	root->right = new TreeNode(7);
	root->left->left = new TreeNode(3);
	//root->left->right = new TreeNode(5);
	//root->left->right->left = new TreeNode(8);
	root->right->left = new TreeNode(6);
	//root->right->right = new TreeNode(7);
	
	cout << kthSmallest(root, 2);
}
