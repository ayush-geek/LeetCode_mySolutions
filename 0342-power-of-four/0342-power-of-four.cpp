class Solution {
public:
    bool isPowerOfFour(int n) {
        
        //pos
        //1 -> 1
        //4 -> 100
        //16 -> 10000
        //64 ->1000000

        if(n<=0)
            return false;

        //power of 2  (1 bit set)
        //but not odd bit
         
        return ((n&(n-1))==0) && !(n& 0XAAAAAAAA); 
    }
};