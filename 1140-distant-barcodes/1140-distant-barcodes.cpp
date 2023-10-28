class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {

        unordered_map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<barcodes.size();i++)
        {
            mp[barcodes[i]]++;

        }   

        for(auto& ele: mp)
        {
            pq.push({ele.second,ele.first});
        }

        vector<int> res;
        pair<int,int> prev={0,0};

        while(!pq.empty())
        {
            auto nd=pq.top();
            pq.pop();

            int ct=nd.first;
            int val=nd.second;

            res.push_back(val);

            ct--;
            if(prev.first!=0)
                pq.push(prev);
            prev={ct,val};

        }

        return res;
    }
};