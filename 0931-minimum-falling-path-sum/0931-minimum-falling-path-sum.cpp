class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
          int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+2,1e9));

      
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {       
                    if(i==1 )
                        dp[i][j]=matrix[0][j-1];
                    else
                        dp[i][j]=matrix[i-1][j-1] +min({dp[i-1][j+1],dp[i-1][j],dp[i-1][j-1]});
            }
        }

        int ans=1e9;

        for(int j=1;j<=m;j++)
        {
            ans=min(ans,dp[m][j]);
        }
        return ans;
    }
};