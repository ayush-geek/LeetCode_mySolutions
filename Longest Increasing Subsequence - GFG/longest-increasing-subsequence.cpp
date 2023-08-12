//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       
    //   vector<int> dp(n,1);
       
    //   int mx=1;
    //   for(int i=0;i<n;i++)
    //   {
    //       for(int j=0;j<i;j++)
    //       {
    //           if(a[i]>a[j] && dp[i]<1+dp[j])
    //           {
    //               dp[i]=1+dp[j];
    //           }
               
    //           mx=max(mx,dp[i]);
    //       }
    //   }
    //   return mx;
       
       
       vector<int> tmp;
       
       for(int i=0;i<n;i++)
       {
           if(tmp.empty() || a[i]>tmp.back())
            tmp.push_back(a[i]);
            else
            {
                int lb=lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin();
                tmp[lb]=a[i];
            }
       }
       return tmp.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends