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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr)return {};
        vector<vector<int>>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            pair<TreeNode*,int>p=q.front();
            q.pop();
            if(ans.size()==p.second)
            {
                ans.push_back({p.first->val});
            }
            else
            {
                ans[p.second].push_back(p.first->val);
            }
            if(p.first->left!=nullptr)q.push({p.first->left,p.second+1});
            if(p.first->right!=nullptr)q.push({p.first->right,p.second+1});
        }
        return ans;
    }
};
