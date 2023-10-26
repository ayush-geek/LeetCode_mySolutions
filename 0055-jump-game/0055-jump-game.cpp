class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        int mxJ=0;


        for(int i=0;i<n-1;i++)
        {
            if(i>mxJ)
                return false;
            mxJ=max(mxJ,i+nums[i]);
        }

        return mxJ>=n-1;
    }
};