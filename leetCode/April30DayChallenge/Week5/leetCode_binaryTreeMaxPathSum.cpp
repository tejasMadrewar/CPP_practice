#include<bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int max_path(TreeNode* root,int &res)
    {
        if(root==NULL) return 0;
        // find max left and right
        int l=max_path(root->left,res);
        int r=max_path(root->right,res);
        // max height
        int maxrl=max(r,l);

        // max height with root val
        int maxone=max(maxrl+root->val,root->val);

        // with diameter
        int maxall=max(maxone,l+r+root->val);

        // update res
        res=max(res,maxall);

        // return max height
        return maxone;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        max_path(root,res);
        return res;
    }
};


int main(){


    return 0;
}