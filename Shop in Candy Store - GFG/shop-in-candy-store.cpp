//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        
        sort(candies,candies+n);
        
        int mnc=0;
        int ct=0;
        for(int i=0;i<n;i++)
        {
            mnc+=candies[i];
            ct+=(k+1);
            
            if(ct>=n)
                break;
            
        }
        
        int mxc=0;
        ct=0;
        for(int i=n-1;i>=0;i--)
        {
            mxc+=candies[i];
            ct+=(k+1);
            
            if(ct>=n)
                break;
            
        }
        
        return {mnc,mxc};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends