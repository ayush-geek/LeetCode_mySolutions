//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int sx,int sy,vector<vector<int>> &arr){
        
        
        int n=arr.size();
        int m=arr[0].size();
        
        queue<pair<int,int>> q;
        vector<int> res;
        
         vector<vector<int>> vis(n,vector<int> (m,0));
        q.push({sx,sy});
        vis[sx][sy]=1;
        int dx[]={-2,-2,2,2,-1,1,-1,1};
        int dy[]={1,-1,1,-1,2,2,-2,-2};
        res.push_back(arr[sx][sy]);
        while(!q.empty())
        {   
            int sz=q.size();
              int ans=0;
            while(sz--)
            {
            auto nd=q.front();
            q.pop();
            int r=nd.first;
            int c=nd.second;
          
            for(int i=0;i<8;i++)
            {
                int nr=r+dx[i];
                int nc=c+dy[i];
                
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                    ans+=arr[nr][nc];
                }
              
            }
            }
              res.push_back(ans);
        }
        
        //cout<<res.size()<<endl;
        int mx=INT_MIN;
        int pos=res.size()-1;
        for(int i=res.size()-1;i>=0;i--)
        {
            if(res[i]+i<res.size())
                res[i]+=res[i+res[i]];
                
                if(res[i]>=mx)
                {
                    mx=max(mx,res[i]);
                    pos=i;
                }
              // cout<<res[i]<<endl;
        }
        
        return pos;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends