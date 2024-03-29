//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int t=0,b=n-1,l=0,r=m-1;
 		
 		while(t<=b && l<=r)
 		{
 		    for(int j=l;j<=r;j++)
 		    {
 		        k--;
 		        if(k==0)
 		            return a[t][j];
 		    }
 		    t++;
 		    
 		    for(int i=t;i<=b;i++)
 		    {
 		        k--;
 		        if(k==0)
 		            return a[i][r];
 		    }
 		    
 		    r--;
 		    
 		    
 		    for(int j=r;j>=l;j--)
 		    {
 		         k--;
 		        if(k==0)
 		            return a[b][j];
 		    }
 		    b--;
 		    
 		    for(int i=b;i>=t;i--)
 		    {
 		         k--;
 		        if(k==0)
 		            return a[i][l];
 		    }
 		    l++;
 		}
    
        return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends