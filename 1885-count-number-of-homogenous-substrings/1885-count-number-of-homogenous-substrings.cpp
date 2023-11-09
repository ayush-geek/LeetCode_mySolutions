class Solution {
public:
    int countHomogenous(string s) {
        int mod=1e9+7;

        int ans=0;
        int ct=0;
    
        for(int i=0;i<s.size();i++)
        {
            if(i==0)
                {
                    ct++;
                }
            else 
            {
                if(s[i]!=s[i-1])
                    {
                        ct=1;
                    }
                else
                    ct++;
            }

            ans=(ans+ct)%mod;
        }
        return ans;
    }
};