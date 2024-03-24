class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // for(int i=0;i<nums.size();i++)
        // {
        //     int z=abs(nums[i]);
            

        //     if(nums[z-1]<0)
        //         return z;
        //     nums[z-1]=-1*nums[z-1];
        // }
        // return -1;

        int slow=nums[0];
        int fast=nums[nums[0]];

        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];

        }

       fast = 0;
  while (slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
		return slow;

    }
};