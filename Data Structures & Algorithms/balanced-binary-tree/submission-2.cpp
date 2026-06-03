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
    pair<int,int>height(TreeNode* root)
    {
        if(root==nullptr)
        {
            return {-1,-1};
        }
        pair<int,int>l=height(root->left);
        pair<int,int>r=height(root->right);
        return {max(l.first,r.first)+1,min(l.second,r.second)+1};
    }
public:
    bool isBalanced(TreeNode* root) {
        pair<int,int>x=height(root);
        return x.first-x.second<=1;
    }
};
