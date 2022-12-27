class Solution {
public:


    int solve(int i,vector<int>& capacity,vector<int>& rocks,int add,vector<vector<int>>& dp)
    {
     
        if(i==capacity.size())
            return 0;
        
        
        
        if(dp[i][add]!=-1)
            return dp[i][add];
        
        //not_take
        int ans1=solve(i+1,capacity,rocks,add,dp);
        
        //take
        
        int ans2=0;
        if(add>=capacity[i]-rocks[i])
           ans2=1+ solve(i+1,capacity,rocks,add-(capacity[i]-rocks[i]),dp);
        
        return dp[i][add]=max(ans1,ans2);
        
    }

    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        

        //dp
        //01 knapsack similar

        //TLE sed 
        //addRocks Constarint
        
       
        
        
        
        int n=capacity.size();
      //   vector<vector<int>> dp(n,vector<int> (additionalRocks+1,-1));
      // return  solve(0,capacity,rocks,additionalRocks,dp);
        
        
         //Greedy will work
        //fulfill the need of the least
        //that is will be able to help 
        //more
        
        vector<int> res;
        
        
        for(int i=0;i<n;i++)
        {
            res.push_back(capacity[i]-rocks[i]);
        }
        
        sort(res.begin(),res.end());
        
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(res[i]>additionalRocks)
                break;
            
            
            additionalRocks-=res[i];
            ct++;
        }

        return ct;
    }
};