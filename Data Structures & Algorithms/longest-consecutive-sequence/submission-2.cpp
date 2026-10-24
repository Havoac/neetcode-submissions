class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
       return 0;

        unordered_map<int, int> mp;
        int ans = 0;

        for(int val:nums) {
            if(!mp[val]) {
                mp[val] = mp[val-1] + mp[val+1] + 1;
                mp[val - mp[val-1]] = mp[val];
                mp[val + mp[val+1]] = mp[val];
                ans = max(ans, mp[val]);
            }
        } 

        return ans;
    }
};
