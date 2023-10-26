class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        //2 cases 
        int n=arr.size();

        //odd
        int c1=0;
        int mx1=0;
        int mx2=0;

        for(int i=0;i<n-1;i++)
        {      
            if(i%2==1)
            {
            if(i+1<n  && arr[i]>arr[i+1])
                c1+=(c1==0)?2:1;
            else
                c1=0;
            }
            else
            {
                if(i+1<n && arr[i]<arr[i+1])
                    c1+=(c1==0)?2:1;
                else
                    c1=0;
            }
            mx1=max(c1,mx1);
        }  

            int c2=0;

           for(int i=0;i<n;i++)
        {      
            if(i%2==1)
            {
            if(i+1<n && arr[i]<arr[i+1])
                    c2+=(c2==0)?2:1;
            else
                c2=0;
            }
            else
            {
                if(i+1<n && arr[i]>arr[i+1])
                    c2+=(c2==0)?2:1;
                else
                    c2=0;
            }
            mx2=max(mx2,c2);
        }  
            cout<<mx1<<" "<<mx2<<endl;
            return max({mx1,mx2,1});


        
     }
};