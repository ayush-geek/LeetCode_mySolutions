class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        unordered_map<char,int> mp;
        
          for(int j=0;j<chars.size();j++)
            {
                mp[chars[j]]++;
            }
        
        int res=0;
        for(int i=0;i<words.size();i++)
        {  unordered_map<char,int> mp2;
                int fg=0;
            for(int j=0;j<words[i].size();j++)
            {
             
                
                mp2[words[i][j]]++;
            
            }
            
            for(int j=0;j<words[i].size();j++)
            {
                if(mp.find(words[i][j])==mp.end() || mp2[words[i][j]]>mp[words[i][j]] )
                {
                    fg=1;
                    break;
                }
            }
            
            if(fg==0)
                res+=words[i].size();
        }
    
      
        return res;
    
    }
};