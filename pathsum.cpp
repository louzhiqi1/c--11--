#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		map<TreeNode*, int> path;
		if (!root)
			return false;
		else
			path[root] = root->val;
		return search(root, path, sum);
	}
private:
	bool search(TreeNode *root, map<TreeNode*, int>& path, int sum)
	{
		if (root->left)
		{
			path[root->left] = root->left->val + path[root];
			if (search(root->left, path, sum))
				return true;
			else if (!root->right)
				return false;
		}
		if (root->right)
		{
			path[root->right] = root->right->val + path[root];
			if (search(root->right, path, sum))
				return true;
			else
				return false;
		}
		return path[root] == sum;
	}
};
void postorderTraversal(TreeNode* root, vector<int>& result)
{
	if (!root)
		return;
	if (root->left)
	{
		postorderTraversal(root->left, result);
	}
	if (root->right)
	{
		postorderTraversal(root->right, result);
	}
	result.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> result;
	postorderTraversal(root, result);
	return result;
}
