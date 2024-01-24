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
    
    unordered_map<int,int> mp;
    void solve(TreeNode* root,int& ans)
    {
        if(root==NULL)
            return ;
        
        if(root->left ==NULL && root->right==NULL)
        {
            mp[root->val]++;
            
            {
                int c=0;
                for(auto itr=mp.begin();itr!=mp.end();++itr)
                {//cout<<itr->first<<" "<<itr->second<<endl;
                    if(itr->second%2!=0 && itr->second>0)
                        c++;
                }
                
                if(c<=1)
                    ans++;
            }
            

            mp[root->val]--;
            return;
        }
        mp[root->val]++;
        
        
        
        solve(root->left,ans);
        
        solve(root->right,ans);
        
        mp[root->val]--;

    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int ans=0;
        if(root)
        {
            solve(root,ans);
            
        }
        
        return ans;
    }
};