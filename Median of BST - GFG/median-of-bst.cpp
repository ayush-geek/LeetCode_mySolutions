//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

void dfs(struct Node* root,int& ct)
{
    if(root==NULL)
        return;
        
    dfs(root->left,ct);
    ct++;
    dfs(root->right,ct);
        
}

void solve(struct Node* root,int& k,int v1,int v2,int& ans1,int& ans2)
{
    if(root==NULL)
        return ;
    
    solve(root->left,k,v1,v2,ans1,ans2);
   
    if(v1==k)
        ans1=root->data;
    if(v2==k)
        ans2=root->data;
     k++;
        
    solve(root->right,k,v1,v2,ans1,ans2);
}

float findMedian(struct Node *root)
{
      //Code here
      //inorder sorted
      
      //ct
      //medisn
      
      int ct=0;
      dfs(root,ct);
      //cout<<ct<<endl;
      int v1=ct/2;
      int v2=(ct-1)/2;
      int ans1=0;
      int ans2=0;
      int k=0;
      solve(root,k,v1,v2,ans1,ans2);
      //cout<<ans1<<" "<<ans2<<endl;
      return (ans1+ans2)/(2.0);
      
}

