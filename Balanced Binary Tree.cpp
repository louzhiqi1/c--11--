#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//bool isBalanced(TreeNode* LeftNode, TreeNode* RightNode)
//{
//	if (LeftNode && RightNode)
//	{
//		return isBalanced(LeftNode->left, LeftNode->right) && isBalanced(RightNode->left, RightNode->right);
//	}
//	else if (LeftNode)
//	{
//		if (LeftNode->left || LeftNode->right)
//			return false;
//		else
//			return true;
//	}
//	else if (RightNode)
//	{
//		if (RightNode->left || RightNode->right)
//			return false;
//		else
//			return true;
//	}
//	else{
//		return true;
//	}
//}
//
//
//bool isBalanced(TreeNode* root) {
//	if (!root)
//		return true;
//	return isBalanced(root->left, root->right);
//}

int getDepth(TreeNode* tree, int currentDepth){
	if (!tree){
		return currentDepth;
	}
	return max(getDepth(tree->left, currentDepth + 1),
		getDepth(tree->right, currentDepth + 1));
}
	bool isBalanced(TreeNode* root) {
		if (!root){
			return true;
		}

		int depthOfLeft = getDepth(root->left, 1);
		int depthOfRight = getDepth(root->right, 1);

		if (abs(depthOfRight - depthOfLeft) > 1){
			return false;
		}
		else{
			return isBalanced(root->left) && isBalanced(root->right);
		}
	}



int ma4in()
{
	TreeNode n1(1), n2(2);
	n1.left = &n2;
	cout << isBalanced(&n1) << endl;
	getchar();
	return 0;
}


