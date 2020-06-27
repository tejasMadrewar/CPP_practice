#include<bits/stdc++.h>

using namespace std;

#define PRINT cout << "PASS\n"; else cout << "FAIL\n";
//
//Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
//Note:
//You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
//
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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;

        // root is not null and stack has elemets to iterate
        while(root || !st.empty()){
            
            // go to end of tree in left side
            while(root!=NULL){
                // save current node
                st.push(root);

                // go to left node
                root = root->left;
            }

            // save top element of stack ie min
            auto top = st.top();

            // find k th min value
            // if found then return value
            if(!(--k)){return top->val;}

            // remove last element from stack
            st.pop();
            // check right part of tree
            root = top->right;
        }

        // not found
        return -1;
    }
};

    int main()
    {

        return 0;
    }