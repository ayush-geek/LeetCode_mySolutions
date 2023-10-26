class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();

        int ans=nums[0];

        int cs=0;

        for(int i=0;i<n;i++)
        {
            cs=max(cs+nums[i],nums[i]);
            ans=max(ans,cs);
        }
        return ans;
    }
};