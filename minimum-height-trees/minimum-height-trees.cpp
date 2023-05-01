class Solution {
public:
    
    int solve(int i,vector<int> adj[],int n)
    {
        //only 1 node with indeg 0
        
        queue<int> q;
        q.push(i);
        int lvl=0;
        vector<int> vis(n,0);
        vis[i]=1;
        while(!q.empty())
        {
            int sz=q.size();
            lvl++;
            
            while(sz--)
            {
                auto nd=q.front();
                q.pop();
                
                for(auto & ele: adj[nd])
                {
                    if(!vis[ele]){
                        q.push(ele);
                        vis[ele]=1;
                    }

                }
            }
        }
        
        return lvl;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
                return {0};
        
        vector<int> adj[n];
        vector<int> indeg(n,0);
        
        for(auto& ele: edges)
        {
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
            
            indeg[ele[0]]++;
            indeg[ele[1]]++;
        }
        
        queue<int> q;
        vector<int> res;

        for(int i=0;i<n;i++)
        {
            if(indeg[i]==1)
                q.push(i);
        }
      
        while(!q.empty())
        {
            int sz=q.size();
            // lvl++;
         
            res.clear();
            while(sz--)
            {
                auto nd=q.front();
                 res.push_back(nd);
                q.pop();
                
                for(auto & ele: adj[nd])
                {
                    
                    indeg[ele]--;
                    
                    
                    if(indeg[ele]==1){
                       
                        q.push(ele);
                    }
                }
            }
        }
        
        return res;
        
    }
};