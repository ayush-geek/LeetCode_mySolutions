class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        
        vector<vector<int>> adj(numCourses);
        
        vector<int> indeg(numCourses,0);
     
        
        for(auto& ele: pre)
        {
            adj[ele[1]].push_back(ele[0]);
            indeg[ele[0]]++;
        }
        vector<int> res;
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            auto nd=q.front();
            q.pop();
            
            res.push_back(nd);
            
            for(auto& ele: adj[nd])
            {
                indeg[ele]--;
                
                if(indeg[ele]==0)
                        q.push(ele);
            }
        }
        
        if(res.size()!=numCourses)
                return {};
        return res;
    }
};