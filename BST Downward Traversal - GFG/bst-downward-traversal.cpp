//{ Driver Code Starts
//Initial Template for C++
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




// } Driver Code Ends
//User function Template for C++
/*
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


//User function Template for C++
/*
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

class Solution{
public:
    
    void dfs(Node* rt,int ac,long long& sum,unordered_map<Node*,pair<int,int>>& mp)
    {
        if(rt==NULL)
            return ;
            
            int c=mp[rt].second;
        if(c==ac)
            sum+=rt->data;
        dfs(rt->left,ac,sum,mp);
         dfs(rt->right,ac,sum,mp);
    }

    long long int verticallyDownBST(Node *root,int target){
        // Code here
        
        //bfs
        if(root==NULL)
            return 0;
        
        unordered_map<Node*,pair<int,int>> mp;
        
        int fg=0;
        int ac=-1;
        long long ans=0;
        queue<Node*> q;
        
        q.push(root);
        mp[root]={0,0};
        Node* as=NULL;
        while(!q.empty())
        {
            int sz=q.size();
            
            for(int i=0;i<sz;i++)
            {
                Node* tmp=q.front();
                q.pop();
                int r=mp[tmp].first;
                int c=mp[tmp].second;
                
               
                
                if(tmp->data==target)
                {
                    fg=1;
                    ac=c;
                    as=tmp;
                }
                
                else  if(fg==1 && c==ac)
                {
                    ans+=1ll*tmp->data;
                }
                
                if(tmp->left!=NULL)
                    {
                        q.push(tmp->left);
                        mp[tmp->left]={r+1,c-1};
                    }
                 if(tmp->right!=NULL)
                    {
                        q.push(tmp->right);
                        mp[tmp->right]={r+1,c+1};
                    }
            }
        }
        
        long long sm=0;
        if(as!=NULL)
            dfs(as,ac,sm,mp);
        else
            return -1;
        return sm-target;
    }
};

//{ Driver Code Starts.

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

void inorder(Node *root, vector<int> &v)
{
    if(root==NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

int main() {
 
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        int target;
        cin>>target;
        string newline;
        getline(cin,newline);
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.verticallyDownBST(root, target)<<endl;
   }
   return 0;
}
// } Driver Code Ends