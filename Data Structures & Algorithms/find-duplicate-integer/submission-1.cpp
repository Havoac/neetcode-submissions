class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();

        for(int i=0 ; i<n ; i++) {
            int index = abs(nums[i])-1;

            if(nums[index] < 0)
            return abs(nums[i]);

            nums[index] = -nums[index];
        }

        return -1;
    }
};
