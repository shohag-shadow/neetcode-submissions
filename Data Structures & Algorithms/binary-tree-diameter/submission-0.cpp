/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    pair<int,int>func(TreeNode *root)
    {
        if(root==nullptr)return {-1,0};
        pair<int,int>l=func(root->left);
        pair<int,int>r=func(root->right);
        return {max(l.first+1,r.first+1),max({l.second,r.second,l.first+r.first+2})};
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return func(root).second;
    }
};
