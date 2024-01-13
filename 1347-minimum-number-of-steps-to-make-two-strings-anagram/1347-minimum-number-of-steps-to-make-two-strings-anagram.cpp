class Solution {
public:
    int minSteps(string s, string t) {
        
        
            unordered_map<char,int> mp;
         unordered_map<char,int> mp2;
        int ans=0;
        for(auto& ele: s)
                mp[ele]++;
        
        for(auto& ele: t)
                mp2[ele]++;
        
        
        for(auto& ele: mp)
        {
            int z=mp2[ele.first];
            int z1=ele.second;
            if(z1>z)
                ans+=(z1-z);
        }
        return ans;
        
    }
};