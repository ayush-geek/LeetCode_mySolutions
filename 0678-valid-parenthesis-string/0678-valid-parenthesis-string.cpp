class Solution {
public:
    bool checkValidString(string s) {
        int star=0;
        int cmin=0;
        int cmax=0;
        // stack<char> st;

        int n=s.size();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
                {
                    cmax++;
                    cmin--;
                }
            else if(s[i]=='(')
                {
                    cmax++;
                    cmin++;
                }
            else
                {
                  cmax--;
                  cmin--;
                }

                if(cmax<0)
                    return false;
                cmin=max(cmin,0);
        }
        
      
            return cmin==0;
 
    }
};