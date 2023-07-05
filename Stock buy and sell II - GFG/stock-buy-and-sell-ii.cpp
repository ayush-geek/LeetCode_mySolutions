//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> dp;
    int solve(int i,int b,vector<int>& prices)
    {
        if(i==prices.size())
            return 0;
            
        if(dp[i][b]!=-1)
            return dp[i][b];
        
        if(b==0)
        {
            return dp[i][b]=max(solve(i+1,b,prices),-prices[i]+solve(i+1,1,prices));
        }
        else
        {
            return dp[i][b]= max(solve(i+1,b,prices),prices[i]+solve(i+1,0,prices));
        }
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        dp.resize(n+1,vector<int> (2,0));
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i][0]=max(dp[i+1][0],-prices[i]+dp[i+1][1]);
            dp[i][1]=max(dp[i+1][1],prices[i]+dp[i+1][0]);
        }
        
        return dp[0][0];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends