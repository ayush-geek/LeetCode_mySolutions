class Solution {
public:

    int countVowelPermutation(int n) {
        int mod=1e9+7;

        vector<long long> prev(5,1);
        
        for(int i=1;i<n;i++)
        {
            vector<long long> cur(5,0);

            cur[0]=((prev[1]+prev[4])%mod+prev[2])%mod;
            cur[1]=(prev[0]+prev[2])%mod;
            cur[2]=(prev[1]+prev[3])%mod;
            cur[3]=(prev[2])%mod;
            cur[4]=(prev[3]+prev[2])%mod;

            prev=cur;
        }

        // cout<<prev[0]<<" "<<prev[1]<<endl;
        // cout<<prev[2]<<" "<<prev[3]<<endl;
        // cout<<prev[4]<<endl;

        return (((prev[0]+prev[1])%mod+(prev[2]+prev[3])%mod)%mod+prev[4])%mod;
        
    }
};