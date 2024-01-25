class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                
                dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
            }
        }
         int ans=dp[n][m];

        int i=n,j=m;
        string res;
        while(i>0 && j>0)
        {
            if(text1[i-1]==text2[j-1])
            {
                res.push_back(text1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i=i-1;
            }
            else
            {
                j=j-1;
            }
        }

        reverse(res.begin(),res.end());
        cout<<res<<endl;
        return ans;
    }
};