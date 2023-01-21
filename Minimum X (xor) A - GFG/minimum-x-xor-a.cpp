//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   int get_set_bits(int num)
   {
       int count = 0;
       while(num)
       {
           if(num & 1)
                count++;
           num = num >> 1;
       }
       return count;
   }
  
    int minVal(int a, int b) {
        // code here
        int setbits = get_set_bits(b);
        int zerobit = 32 - setbits;
        vector<int> bits;
        for(int i = 31 ; i >= 0 ; i--)
        {
            int curbit = (a >> i) & 1;
            if(curbit == 0)
            {
                zerobit--;
                bits.push_back(0);
            }
            else
            {
                setbits--;
                bits.push_back(1);
            }
            if(setbits == 0 || zerobit == 0)
                break;
        }
        while(setbits--)
            bits.push_back(1);
        while(zerobit--)
            bits.push_back(0);
        int res = 0;
        for(int i = 0 ; i < bits.size() ; i++)
            res = (res*2)+bits[i];
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends