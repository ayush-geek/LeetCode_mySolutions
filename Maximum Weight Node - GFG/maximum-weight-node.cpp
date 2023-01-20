//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
        
        vector<int> indeg(N,0);
        
        
        vector<int> adj[N];
        int mx=0;
        
        for(int i=0;i<Edge.size();i++)
        {
            
            
            if(Edge[i]!=-1)
            {
             indeg[Edge[i]]+=i;
            
          
            }
            
        }
        
        for(int i=0;i<N;i++)
        {
            
           
            
            if(indeg[i]>=indeg[mx])
            {
              mx=i; 
            }
            
        }
        
        return mx;
        
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends