class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
            
        //Beautiful Question
            // Explaining need of pq
            
        
     
    priority_queue<int> pq;
        int n=heights.size();
        
        int i;
        for(i=0;i<n-1;i++)
        {
            int df=heights[i+1]-heights[i];
            
            
            if(df<=0)
                continue;
            pq.push(-df);
            
            if(pq.size()>ladders)
            {
                bricks+=pq.top();
                pq.pop();
            }
            
            
            if(bricks<0)
                return i;
        }
        
      return i;
        
    }
};