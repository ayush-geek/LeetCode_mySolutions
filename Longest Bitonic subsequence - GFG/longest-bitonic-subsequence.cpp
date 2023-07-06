//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
vector<int> findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        // vector<int> ct(n,1);
        vector<int> dp(n,1);
        // int mx=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && 1+dp[j]>dp[i])
                {
                    // ct[i]=ct[j];
                    dp[i]=1+dp[j];
                }
                // else if(nums[j]<nums[i] && 1+dp[j]==dp[i])
                // {
                //     ct[i]+=ct[j];
                // }
                // mx=max(dp[i],mx);
            }
        }
    
    return dp;
    
}
	
	int LongestBitonicSequence(vector<int>nums)
	{
	    int ans=0;
	    vector<int> a=findNumberOfLIS(nums);
	    reverse(nums.begin(),nums.end());
	    vector<int> b=findNumberOfLIS(nums);
	    reverse(b.begin(),b.end());
	    
	    for(int i=0;i<a.size();i++)
	    {
	        ans=max(ans,a[i]+b[i]-1);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends