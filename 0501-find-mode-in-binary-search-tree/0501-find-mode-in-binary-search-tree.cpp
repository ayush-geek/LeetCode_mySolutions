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

    void solve(TreeNode* root,unordered_map<int,int>& mp)
    {
        if(root==NULL)
            return ;
        
        solve(root->left,mp);
        solve(root->right,mp);
  
        mp[root->val]++;
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        int ct=0;

        solve(root,mp);
        int mx=0;

        for(auto& ele: mp)
        {
            mx=max(mx,ele.second);
        }

        vector<int> res;

        for(auto& ele: mp)
        {
            if(ele.second==mx)
                res.push_back(ele.first);
        }
        return res;
    }
};