class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
       vector<int> pos,neg;
        
    
    
        
        int n=nums.size();
        
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
                pos.push_back(nums[i]);
            else
                neg.push_back(nums[i]);
        }
        
        int i=0 , j=0,k=0;
        while(i<pos.size() || j<neg.size())
        {
            
            if(i<pos.size())
                nums[k++]=pos[i++];
            if(j<neg.size())
                nums[k++]=neg[j++];
        
        }
        
        return nums;
    }
};