//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
   
    int solve(Node* root,int& mnl,int& sum,int& mns,int& mxs, bool& flag,int& target)
    {
        if(root==NULL)
            return 0 ;
            
        int lsum=0,rsum=0;
        int lmns=1e9,rmns=1e9;
        int lmxs=-1e9,rmxs=-1e9;
        bool lfg=true,rfg=true;
        
        
        int l=solve(root->left,mnl,lsum,lmns,lmxs,lfg,target);
        
        int r=solve(root->right,mnl,rsum,rmns,rmxs,rfg,target);
        
        sum=lsum+rsum+root->data;
        int len=l+r+1;
        flag=false;
        mxs=max(root->data,max(rmxs,lmxs));
          mns=min(root->data,min(rmns,lmns));
        
        if(root->data>lmxs && root->data<rmns && lfg && rfg )
        {
            flag=true;
            
            if(sum==target){
             mnl=min(mnl,len);
            
            }
        }
        
        return len;
    }

    int minSubtreeSumBST(int& target, Node *root) {
        
        // pre
        
        //smallest suaaray with sum ==target
        
        int mnl=1e9;
        bool fg=true;
        int  sum=0;
        int mn=1e9;
        int mx=-1e9;
        solve(root,mnl,sum,mn,mx,fg,target);
        
        if(mnl==1e9)
            return -1;
        return mnl;
       
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends