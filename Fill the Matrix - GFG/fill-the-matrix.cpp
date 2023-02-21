//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
      int n=N;
      int m=M;
      vector<vector<int>> vis(n+1,vector<int> (m+1,0));
      
        queue<pair<pair<int,int>,int>> q;
        
        q.push({{x,y},0});
        vis[x][y]=1;
        
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        
        
        int ans=0;
        while(!q.empty())
        {
            auto it=q.front();
            int r=it.first.first;
            int c=it.first.second;
            int d=it.second;
            q.pop();
            ans=max(ans,d);
          
            for(int i=0;i<4;i++)
            {
                int nr=r+dr[i];
                int nc=c+dc[i];
                
                if(nr>0 && nr<=n && nc>0 && nc<=m && !vis[nr][nc])
                {
                  
                    q.push({{nr,nc},d+1});
                    vis[nr][nc]=1;
                }
            }
            
           
            
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends