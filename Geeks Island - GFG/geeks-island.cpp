//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    bool solve(int i,int j,vector<vector<int>>& ocean ,vector<vector<int>> &mat)
    {
        int N=mat.size();
        int M=mat[0].size();
        if(i<0 || j<0 ||i>=N|| j>=M || mat[i][j]==1e9)
            return 0;
        if(ocean[i][j])
            return 1;
            
             int k=mat[i][j];
        
        
        mat[i][j]=1e9;//Visited;
        int ans=0;
        
        
        
        //dfs
        
        if(i>0 && mat[i-1][j]<=k )
            ans=ans || solve(i-1,j,ocean ,mat);
        if(j>0 && mat[i][j-1]<=k)
            ans=ans || solve(i,j-1,ocean,mat);
        if(i+1<ocean.size() && mat[i+1][j]<=k )
            ans=ans || solve(i+1,j,ocean,mat);
        if(j+1<ocean[0].size() && mat[i][j+1]<=k)
            ans=ans || solve(i,j+1,ocean,mat);
        
        
        ocean[i][j]=ans;
        
        mat[i][j]=k;
        
        return ans;
    }
    
    int water_flow(vector<vector<int>> &mat,int N,int M){
    // Write your code here.
    
    
    //Just Same as Pacific and Atlantic Wtaerflow
    
    vector<vector<int>> ind(N,vector<int> (M,0));
    vector<vector<int>> arb(N,vector<int> (M,0));
    
    for(int i=0;i<N;i++)
        {   
            ind[i][0]=1;
            arb[i][M-1]=1;
            
        }
        
        for(int j=0;j<M;j++)
        {   
            ind[0][j]=1;
            arb[N-1][j]=1;
            
        }
    
    int ct=0;   
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(solve(i,j,ind,mat) && solve(i,j,arb,mat))
                    ct++;
        }
    }
    
    return ct;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends