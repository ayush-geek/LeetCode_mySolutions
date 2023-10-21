class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n=nums.size();
       
        vector<int> dp(n,0);
        priority_queue<pair<int,int>> pq;
        int ans=nums[0];
        pq.push({nums[0],0});
        for(int i=1;i<n;i++)
        {
                while(!pq.empty() && pq.top().second<i-k)
                    pq.pop();

                dp[i]=max(nums[i],nums[i]+pq.top().first);

                ans=max(ans,dp[i]);
                pq.push({dp[i],i});


        }
        return ans;
    }
};