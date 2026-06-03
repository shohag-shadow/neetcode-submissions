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
    TreeNode *ans=nullptr;
    int lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==nullptr)return 0;
        vector<int>v;
        if(root==p)v.push_back(1);
        if(root==q)v.push_back(2);
        v.push_back(lca(root->left,p,q));
        v.push_back(lca(root->right,p,q));
        sort(v.begin(),v.end());
        int n=v.size();
        if(v[n-1]==2&&v[n-2]==1)
        {
            if(ans==nullptr)
            {
                ans=root;
                return 3;
            }
            return 3;
        }
        return v[n-1];
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca(root,p,q);
        return ans;
    }
};
