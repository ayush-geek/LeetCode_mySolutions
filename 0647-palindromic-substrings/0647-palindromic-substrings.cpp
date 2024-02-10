class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.size();
        int ans=0;
        vector<vector<int>> dp(n,vector<int> (n,0));
    string res;
      for(int i=n-1;i>=0;i--)
      {
        for(int j=i;j<n;j++)
        {
          if(i==j)  
            dp[i][j]=1;
            else if(s[i]==s[j])
            {
                
              if(j-i==1)
                dp[i][j]=2;
              else if(dp[i+1][j-1])
                dp[i][j]=2+dp[i+1][j-1];

            }
            // cout<<dp[i][j]<<endl;

           if(dp[i][j])
           ans++;
        }
      }
      return ans;
    }
};