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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q!=nullptr)return false;
        if(p!=nullptr&&q==nullptr)return false;
        if(p==nullptr&&q==nullptr)return true;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    TreeNode* findRoot(TreeNode* root,TreeNode* subRoot)
    {
        if(root==nullptr)return root;
        if(root->val==subRoot->val)return root;
        TreeNode* l=findRoot(root->left,subRoot);
        if(l!=nullptr)return l;
        TreeNode* r=findRoot(root->right,subRoot);
        if(r!=nullptr)return r;
        return nullptr;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr)return true;
        TreeNode* newRoot=findRoot(root,subRoot);
        if(newRoot==nullptr)return false;
        return isSameTree(newRoot,subRoot);
    }
};
