class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        
        int n=nums.size();

        vector<int> mn_l(n);
        vector<int> mn_r(n);


        for(int i=0;i<n;i++)
        {
            if(i==0)
                mn_l[i]=nums[i];
            else
                mn_l[i]=max(mn_l[i-1],nums[i]);
        }


        for(int i=n-1;i>=0;i--){

            if(i==n-1)
                mn_r[i]=nums[i];
            else
                mn_r[i]=min(mn_r[i+1],nums[i]);
        }

        for(int i=0;i<n-1;i++)
        {
            int l=mn_l[i];
            int r=mn_r[i+1];

            if(l<=r)
                return i+1;
        }

        return -n;
    }
};