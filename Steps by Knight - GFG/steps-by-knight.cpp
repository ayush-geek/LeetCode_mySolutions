//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&s,vector<int>&t,int N)
	{   
	    s[0]-=1;
	    s[1]-=1;
	    t[0]-=1;
	    t[1]-=1;
	    vector<vector<int>> vis(N,vector<int> (N,0));
	    
	    queue<pair<int,int>> q;
	    q.push({s[0],s[1]});
	    int steps=0;
	    vis[s[0]][s[1]]=1;
	    int dr[]={-2,-2,2,2,-1,-1,1,1};
	    int dc[]={-1,1,-1,1,2,-2,2,-2};
	    
	    if(s==t)
	        return 0;
	    while(!q.empty())
	    {   
	        steps++;
	        int sz=q.size();
	        
	        while(sz--)
	        {
	        int r=q.front().first;
	        int c=q.front().second;
	        q.pop();
	        
	        
	        for(int  i=0;i<8;i++)
	        {
	            int nr=r+dr[i];
	            int nc=c+dc[i];
	            
	            if(nr>=0 && nr<N && nc>=0 && nc<N && !vis[nr][nc])
	            {
	                vis[nr][nc]=1;
	                q.push({nr,nc});
	            }
	            if(nr==t[0] && nc==t[1])
	                return steps;
	        }
	        }
	        
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends