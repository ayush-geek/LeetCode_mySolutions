class Graph {
public:
    vector<vector<long long>> mat;
    int N;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        mat.resize(n,vector<long long> (n,LLONG_MAX));
        
        for(auto& ele: edges)
        {
            mat[ele[0]][ele[1]]=(long long)ele[2];
        }
        
        
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {   if(i==j)
                        mat[i][j]=0;
                    else if(mat[i][via]!=LLONG_MAX && mat[via][j]!=LLONG_MAX)
                    mat[i][j]=min(mat[i][j],mat[i][via]+mat[via][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        int a=edge[0];
        int b=edge[1];
        int w=edge[2];
        
      //  mat[a][b]=(long long)w;
        int n=N;
        
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {   
                    if(mat[i][a]!=LLONG_MAX && mat[b][j]!=LLONG_MAX)
                    mat[i][j]=min(mat[i][j],mat[i][a]+w+mat[b][j]);
                }
            }
        
        
         
    
    }
    
    int shortestPath(int node1, int node2) {
       
        
        return mat[node1][node2]==LLONG_MAX?-1:mat[node1][node2];
    }
};

