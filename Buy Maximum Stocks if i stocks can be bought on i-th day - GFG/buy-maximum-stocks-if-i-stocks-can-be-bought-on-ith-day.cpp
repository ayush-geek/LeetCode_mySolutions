//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        
        //cost per stock
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            
            vp.push_back({price[i],i+1});
        }
        
        sort(vp.begin(),vp.end());
            
        int ct=0;
        for(int i=0;i<vp.size();i++)
        {
            int cantake=min(vp[i].second,k/vp[i].first);
            
            k-=vp[i].first*cantake;
            ct+=cantake;
        }
        return ct;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends