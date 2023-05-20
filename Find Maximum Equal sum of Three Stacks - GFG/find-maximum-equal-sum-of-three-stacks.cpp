//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        int p1=0;
        int p2=0;
        int p3=0;
        int i=0 ,j=0,k=0;
        reverse(S1.begin(),S1.end());
           reverse(S2.begin(),S2.end());
              reverse(S3.begin(),S3.end());
        
        p1+=S1[i++];
        p2+=S2[j++];
        p3+=S3[k++];
        int ans=0;
        
        while(i<N1 || j<N2 || k<N3)
        {   
            int fg=0;  
            
            if(p1==p2 && p2==p3){
                ans=max(ans,p1);
                
                if(i<N1)
                    p1+=S1[i++];
                else
                break;
            }
             //  cout<<p1<<" "<<p2<<" "<<p3<<endl;
             int mx=max({p1,p2,p3});
            while(i<N1 &&  p1<mx)
                {   fg=1;
                    p1+=S1[i];
                    i++;
                    mx=max({p1,p2,p3});
                }
            while(j<N2 && p2<mx)
            {
                fg=1;
                p2+=S2[j];
                j++;
                mx=max({p1,p2,p3});
            }
            while(k<N3 && p3<mx)
            {
                fg=1;
                p3+=S3[k];
                k++;
                mx=max({p1,p2,p3});
            }
            
            if(p1==p2 && p2==p3)
                ans=max(ans,p1);
                
           // cout<<p1<<" "<<p2<<" "<<p3<<endl;
            if(fg==0)
                break;
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends