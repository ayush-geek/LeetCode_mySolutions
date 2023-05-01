class Solution {
public:
    int minimumSemesters(int numCourses, vector<vector<int>>& relations) {
          vector<vector<int>> adj(numCourses+1);
        
        vector<int> indeg(numCourses+1,0);
     
        
        for(auto& ele: relations)
        {
            adj[ele[0]].push_back(ele[1]);
            indeg[ele[1]]++;
        }
        vector<int> res;
        int lvl=0;
        queue<int> q;
        for(int i=1;i<=numCourses;i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {   
            int sz=q.size();
            lvl++;
            while(sz--)
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
        }
        
        if(res.size()!=numCourses)
                return -1;
        return lvl;
    }
};