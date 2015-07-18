#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//	vector<vector<int>> result;
//	bool seq = false;
//	if (root)
//	{
//		vector<int> layer;
//		layer.push_back(root->val);
//		result.push_back(layer);
//		zigzagLevelOrder(root->left);
//	}
//	return result;
//}
//void zigzagLevelOrder(TreeNode* root, vector<vector<int>> &result, bool seq)
//{
//	while (root->left || root->right)
//	{
//		vector<int> layer;
//		if (root->left)
//			layer.push_back(root->left->val);
//		if (root->right)
//			layer.push_back(root->right->val);
//		if (seq)
//			::reverse(layer.begin(), layer.end());
//		result.push_back(layer);
//		seq = seq ? false : true;
//		zigzagLevelOrder(root->left, result, seq);
//		zigzagLevelOrder(root->right, result, seq);
//	}
//}

void zigzagLevelOrder(TreeNode *root, vector<vector<int>> &result, int depth)
{
	if (!root)
		return;
	if (depth == result.size())
	{
		result.push_back(vector<int>());
	}
	if (depth % 2 == 0)
	{
		result[depth].push_back(root->val);
	}
	else
	{
		result[depth].insert(result[depth].begin(), root->val);
	}
	if (root->left) zigzagLevelOrder(root->left, result, depth + 1);
	if (root->right) zigzagLevelOrder(root->right, result, depth + 1);
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> result;
	zigzagLevelOrder(root, result, 0);
	return result;
}

