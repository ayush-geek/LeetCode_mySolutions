class Solution {
public:
    bool canJump(vector<int>& nums) {
        
    // M1 Greedy
        // int mxjmp=0;

        // for(int i=0;i<nums.size();i++)
        // {
        //     if(mxjmp<i)
        //         return false;

        //     mxjmp=max(mxjmp,i+nums[i]);
        // }

        // return true;



    // M2 Dp
    int n=nums.size();
    vector<int> dp(n,0);

    dp[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {

        for(int j=i;j<=i+nums[i];j++)
        {
                if(j<n && dp[j]==1)
                {
                    dp[i]=1;
                    break;
                }
        }

       
    }

        return dp[0];
    }
};