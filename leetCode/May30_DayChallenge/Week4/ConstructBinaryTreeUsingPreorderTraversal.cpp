#include <bits/stdc++.h>

using namespace std;

#define PRINT         \
    cout << "PASS\n"; \
    else cout << "FAIL\n";

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *helper(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            root = new TreeNode(val);
            return root;
        }

        if (root->val > val)
            root->left = helper(root->left, val);
        else
            root->right = helper(root->right, val);

        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = NULL;

        for (auto &i : preorder)
        {
            root = helper(root, i);
        }

        return root;
    }
};

int main()
{
    Solution s;
    vector<int> v = {8,5,1,7,10,12};

    TreeNode* root = s.bstFromPreorder(v);

    return 0;
}