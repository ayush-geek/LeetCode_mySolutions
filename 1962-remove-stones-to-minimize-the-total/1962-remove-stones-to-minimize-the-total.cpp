class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

     //max heap

     priority_queue<int> pq;

    int n=piles.size();
    for(int i=0;i<n;i++ )
        pq.push(piles[i]);


    while(k--)
    {
        int zz=pq.top();
        pq.pop();


        pq.push(zz-zz/2);
    }

    int sm=0;
    while(!pq.empty())
    {
        sm+=pq.top();

        pq.pop();
    }


    return sm;

    }
};