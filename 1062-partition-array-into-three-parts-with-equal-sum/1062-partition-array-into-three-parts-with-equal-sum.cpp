class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n=arr.size();

        long long sm=accumulate(arr.begin(),arr.end(),0ll);

        if(sm%3!=0)
            return false;
        long long cs=0;
    
        int f1=0;
        int f2=0;
        for(int i=0;i<arr.size()-1;i++)
        {       
            cs+=arr[i];
            if(f1==1 && cs==2*sm/3)
                f2=1;

            if(cs==sm/3)
                f1=1;
            


        } 

        if(f2)
            return true;
        return false;       
    }
};