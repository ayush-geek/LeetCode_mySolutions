class Solution {
public:
    int numSquares(int n) {
        

        //Return Least NuMBER oF pERFECT Squares
        vector<long long> dp(n+1,INT_MAX);
      
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            
            int j=1;
            
               
            
        
           while(j*j<=i)
            {
                dp[i]=min(dp[i],dp[i-j*j]+1);
                
                if(j*j==i){
                    dp[i]=1;
                    }
                 j++;
            }
               
           
            // cout<<i<<" "<<dp[i]<<" "<<j<<"\n";
        }
        return dp[n];


    }
};