class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int,vector<int>> mp;
        for(auto& ele: adjacentPairs)
        {
                mp[ele[0]].push_back(ele[1]);
                mp[ele[1]].push_back(ele[0]);
        }
        int s=-1;
        for(auto& ele: mp)
        {
            if(ele.second.size()==1)
            {
                s=ele.first;
                break;
            }
        }

        vector<int> res;

            unordered_set<int> st;

        int n=adjacentPairs.size()+1;
        st.insert(s);
        res.push_back(s);
        while(st.size()<n)
        {
            vector<int> ele=mp[res.back()];
            int a=ele[0];
            int b=-1;
            
            if(ele.size()==2)
                b=ele[1];


            if(st.count(a)==0)
            {
                 st.insert(a);
                res.push_back(a);
            }

             else if(ele.size()==2 && st.count(b)==0)
            {
                 st.insert(b);
                res.push_back(b);
            }
        }

        return res;        
        
    }
};