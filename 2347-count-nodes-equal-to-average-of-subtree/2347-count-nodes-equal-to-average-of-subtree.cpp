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

    pair<int,int> solve(TreeNode* root,int& ct,int sm,int n)
    {   
       
        if(root==NULL)  {
         
            return {0,0};
            }
      
        pair<int,int> l=solve(root->left,ct,sm,n);
        pair<int,int>  r=solve(root->right,ct,sm,n);

         int node=l.second+r.second+1;
      
        int avg=(l.first+r.first+root->val)/node;
     
     
        if(root->val==avg)
            ct++;

        return {l.first+r.first+root->val,node};
            
    }

    int averageOfSubtree(TreeNode* root) {
        
    int ct=0;
    int sum=0;
    int n=0;
    pair<int,int> z1=solve(root,ct,sum,n);
    return ct;
    }
};