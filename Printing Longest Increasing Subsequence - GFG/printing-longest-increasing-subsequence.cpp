//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        // Code here
        //  int n=nums.size();

        vector<int> dp(n,1);
        vector<int> hash(n,0);
        iota(hash.begin(),hash.end(),0); //Set hash[i]=i;
        int lst=0;
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] && 1+dp[j]>dp[i])
                    {
                        dp[i]=1+dp[j];
                        hash[i]=j;
                    }
                if(dp[i]>mx)
                {
                    mx=dp[i];
                    lst=i;
                }
            }
        }
        
        vector<int> res;
        
        while(1)
        {
            res.push_back(nums[lst]);
               if(hash[lst]==lst)
                break;
            lst=hash[lst];
            
         
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends