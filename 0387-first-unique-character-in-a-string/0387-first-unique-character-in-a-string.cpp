class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<int,int> st;
        
        for(int i=0;i<s.size();i++)
        {
            st[s[i]]++;
        }
        
         for(int i=0;i<s.size();i++)
        {
           if(st[s[i]]==1)
                return i;
        }
        
        return -1;
    }
};