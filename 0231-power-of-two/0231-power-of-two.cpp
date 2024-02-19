class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        
        //if only 1 set Bit
        if(n== -2147483648)
            return false;
        
        int ct=0;
        for(int i=0;i<32;i++)
        {
            int z=1<<i;
           // cout<<z<<endl;
       // int b=n& z;
          //  cout<<b<<endl;
            if((n & z))
                ct++;
        
            
        }
        
        cout<<ct<<endl;
        return ct==1;
    }
};