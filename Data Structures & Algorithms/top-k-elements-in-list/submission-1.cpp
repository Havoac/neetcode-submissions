class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int val:nums) {
            freq[val]++;
        }

        priority_queue<pair<int, int>> pq;

        for(auto &itr:freq)
        pq.push({itr.second, itr.first});

        vector<int> ans;

        for(int i=0 ; i<k ; i++) 
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
