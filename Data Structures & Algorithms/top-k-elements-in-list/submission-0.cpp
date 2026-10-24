class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for(int val:nums) {
            freq[val]++;
        }

        vector<pair<int, int>> values;

        for(auto &itr:freq)
        values.push_back({itr.second, itr.first});

        sort(values.begin(), values.end(), greater<pair<int, int>>());

        vector<int> ans;

        for(int i=0 ; i<k ; i++) 
            ans.push_back(values[i].second);
        
        return ans;
    }
};
