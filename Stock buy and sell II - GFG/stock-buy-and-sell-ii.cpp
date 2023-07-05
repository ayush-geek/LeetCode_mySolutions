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
        dp.resize(n,vector<int> (2,-1));
        return solve(0,0,prices);
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