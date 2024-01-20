class Solution {
public:
int mod=1e9+7;
    int sumSubarrayMins(vector<int>& nums) {
        
        stack<pair<int,int>> st;
        unordered_map<int,long long> mp;
        int n=nums.size();
      long long ans=0;
        for(int i=n-1;i>=0;i--)
        { 
          int b=1;
          long long tmp=0;
          while(!st.empty() && nums[st.top().first]>=nums[i])
          {
            b+=st.top().second;
            st.pop();
          }
          
          int z1=0,z2=0;
          if(!st.empty())
          {
         
            int z1=st.top().first;
          
            tmp =(tmp+mp[z1])%mod;
          }
         
            st.push({i,b});
           tmp+=(b)*nums[i];
          
          mp[i]=tmp%mod;
          ans=(ans+tmp)%mod;
         
        }

        return ans;
    }
};