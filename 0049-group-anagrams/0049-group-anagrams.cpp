class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;


        for(auto& ele: strs)
        {
            string tmp=ele;

            sort(tmp.begin(),tmp.end());
            mp[tmp].push_back(ele);
        }

        vector<vector<string>> res;

        for(auto& ele: mp)
        {
            res.push_back(ele.second);
        }
        return res;
    }
};