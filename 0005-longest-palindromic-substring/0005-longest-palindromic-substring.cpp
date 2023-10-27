class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        string ans;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j])
                    {
                      if(i==j)
                        dp[i][j]=1;
                        else if(abs(i-j)==1)
                            dp[i][j]=2;
                        else if(dp[i+1][j-1]!=0)
                            dp[i][j]=2+dp[i+1][j-1];
                    }

                if(dp[i][j]>ans.size())
                    ans=s.substr(i,j-i+1);
            }
        }
        return ans;
    }
};