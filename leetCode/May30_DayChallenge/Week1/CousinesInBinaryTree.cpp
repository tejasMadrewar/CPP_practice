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
    
    vector<int> dfs(TreeNode* root,int target,int depth,int parent)
    {
        // end condition
        if(root==NULL){
            // return empty list
            return {};
        }
        // found target
        if(root->val==target)
            return {depth,parent};
        // target not found
        else
        {
            parent = root->val;
            vector<int> l = dfs(root->left,target,depth+1,parent);
            vector<int> r = dfs(root->right,target,depth+1,parent);
            if(l.empty())
                return r;
            else
                return l;
        }
        
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> d1 = dfs(root,x,0,-1);
        vector<int> d2 = dfs(root,y,0,-1);
        if(d1[0]==d2[0] && (d1[1]!=d2[1]))
            return true;
        else
            return false;
    }
};
int main(){



    return 0;
}