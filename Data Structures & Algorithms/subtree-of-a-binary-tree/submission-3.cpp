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
    vector<TreeNode*>roots;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q!=nullptr)return false;
        if(p!=nullptr&&q==nullptr)return false;
        if(p==nullptr&&q==nullptr)return true;
        if(p->val!=q->val)return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
    void findRoot(TreeNode* root,TreeNode* subRoot)
    {
        if(root==nullptr)return;
        if(root->val==subRoot->val)
        {
            roots.push_back(root);
        }
        findRoot(root->left,subRoot);
        findRoot(root->right,subRoot);
        return;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr)return true;
        findRoot(root,subRoot);
        for(auto r:roots)
        {
            if(isSameTree(r,subRoot))return true;
        }
        return false;
    }
};
