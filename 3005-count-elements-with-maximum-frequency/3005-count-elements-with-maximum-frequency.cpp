class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mx=0;
        for(auto& ele: nums)
        {
            mp[ele]++;
            if(mp[ele]>mx)
                mx=mp[ele];
        }
        int ans=0;
        for(auto& ele: mp)
        {
            if(ele.second==mx)
                ans+=ele.second;
        }
        return ans;
    }
};