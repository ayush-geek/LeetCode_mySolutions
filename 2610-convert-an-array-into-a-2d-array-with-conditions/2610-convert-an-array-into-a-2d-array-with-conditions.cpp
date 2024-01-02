class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        
        vector<vector<int>> res;
        
        unordered_map<int,int> mp;
        
        for(int  i=0;i<nums.size();i++)
            mp[nums[i]]++;
        
        int ct=0;
        while(ct<nums.size())
        {
            vector<int> tmp;
            for(auto& ele: mp)
            {  
             
                if(mp[ele.first]>0){
                    ct++;
                tmp.push_back(ele.first);
                mp[ele.first]-=1;
                }
                
                
            }
            //cout<<ct<<endl;
           // break;
         res.push_back(tmp);
        }
        
        return res;
    }
};