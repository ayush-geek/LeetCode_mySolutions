class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int mx=*max_element(arr.begin(),arr.end());
        
        if(k>=n-1)
        {
            return mx;
        }
        
        int mxe=max(arr[0],arr[1]);
        int ct=1;
        if(ct==k)
            return mxe;
        for(int i=2;i<n;i++)
        {
            int cmx=max(arr[i],mxe);
            if(cmx==mxe)
            {
                ct++;
                if(ct==k)
                        return mxe;
            }
            else
            {
                mxe=cmx;
                ct=1;
            }
        }
        return mx;
    }
};