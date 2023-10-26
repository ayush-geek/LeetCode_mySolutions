class Solution {
public:
    int jump(vector<int>& nums) {

     int n=nums.size();

     int jmp=0;
     int mx_pos=0;
     int c_jmp=0;
     for(int i=0;i<n-1;i++)
     {  
         c_jmp=max(c_jmp,i+nums[i]);
         if(i==mx_pos)
         {
             jmp++;
             mx_pos=c_jmp;
         }
     }
     return jmp;

    }
};