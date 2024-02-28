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

    void solve(TreeNode* root,int& h,int ht,int& ans)
    {
        if(root==NULL)
            return ;
        
        if(h==ht){
            ans=root->val;
            h++;
        }
        // cout<<h<
        solve(root->left,h,ht+1,ans);
        solve(root->right,h,ht+1,ans);
    }

    int findBottomLeftValue(TreeNode* root) {
        int ans=0;
        int H=0;
        solve(root,H,0,ans);   
        return ans;
    }
};