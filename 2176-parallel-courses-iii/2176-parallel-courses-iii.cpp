class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {

        vector<int> adj[n+1];
        vector<int> indeg(n+1,0);
        for(auto& ele: relations)
        {
            adj[ele[0]].push_back(ele[1]);
            indeg[ele[1]]++;
        }   

        int  ans=0;
      queue<pair<int,int>> q;
        
        vector<int> dis(n+1,0);
        // unordered_set<int> st;
        for(int i=1;i<=n;i++)
        {   
            if(indeg[i]==0){
                 q.push({0,i});
                dis[i]=0; 
                }
        }


        while(!q.empty())
        {
            
             
                int t=q.front().first;
                int nd=q.front().second;
                q.pop();


                // if(st.count(nd))
                //     continue;
                // st.insert(nd);
                int cur=t+time[nd-1];
                ans=max(ans,cur);
                for(auto& ele: adj[nd])
                {
                    indeg[ele]--;
                    dis[ele]=max(dis[ele],cur);
                    if(indeg[ele]==0)
                        q.push({dis[ele],ele});
                }


            
            
             
        }

        return ans;

    }
};