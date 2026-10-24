class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i=0 ; i<n ; i++)
            mp[nums[i]].push_back(i);

        for(int i=0 ; i<n ; i++) {
            if(mp[nums[i]].size() == 2) {
                if(mp[nums[i]][0] != -1)
                    mp[nums[i]][0] = -1;
                else
                    mp[nums[i]][1] = -1;
            }
            else
                mp[nums[i]][0] = -1;

            if(2*nums[i] == target && mp[target-nums[i]].size()>1) 
                return {i, mp[target-nums[i]][1]};
            if(mp[target-nums[i]].size()>0 && mp[target-nums[i]][0] != -1)
                return {i, mp[target-nums[i]][0]};
        }

        return {};
    }
};
