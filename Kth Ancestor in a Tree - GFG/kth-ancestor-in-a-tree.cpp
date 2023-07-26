//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
    Node* root = newNode(stoi(ip[0]));
        
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
            currNode->left = newNode(stoi(currVal));
                
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
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function

unordered_map<int,int> mp;
void dfs(Node* rt,int d,int k,int& ans,int node)
{
    if(rt==NULL)
        return ;
    
    // int z=rt->data;
    // if(rt->left!=NULL)
    // {
    //   // adj[z].push_back(rt->left->data);
    //     adj[rt->left->data].push_back(z);
    // }
    
    //  if(rt->right!=NULL)
    // {
    //     //adj[z].push_back(rt->right->data);
    //     adj[rt->right->data].push_back(z);
    // }
    if(rt->data==node)
        {   
           // cout<<d<<endl;
            if(mp.count(d+k))
                ans=mp[d+k];
        }  
    mp[d]=rt->data;
    dfs(rt->left,d-1,k,ans,node);
    dfs(rt->right,d-1,k,ans,node);
}
bool solve(int nd,int par,vector<int> adj[],int k,int& ans)
{   
    //cout<<nd<<" "<<k<<endl;
    if(k==0){
        ans=nd;
        return true;
    }
    for(auto& ele: adj[nd])
    {   
        if(ele!=par)
            if(solve(ele,nd,adj,k-1,ans))
                return true;
    }
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
        
        // vector<int> adj[100001];
          int ans=-1;
        dfs(root,0,k,ans,node);
      
        // if(adj[node].size()<k)
        //     return -1;
        // bool z=solve(node,-1,adj,k,ans);
        return ans;
        
}
