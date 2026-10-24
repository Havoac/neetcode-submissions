class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> value_Index_Pair;
        int n = nums.size();

        for(int i=0 ; i<n ; i++) {
            value_Index_Pair.push_back({nums[i], i});
        }

        sort(value_Index_Pair.begin(), value_Index_Pair.end());

        int i=0, j=n-1;
        int index1 = 0, index2 = 0;

        while(i < j) {
            int sum = value_Index_Pair[i].first + value_Index_Pair[j].first;
            
            if(sum == target)
            {
                index1 = value_Index_Pair[i].second;
                index2 = value_Index_Pair[j].second;
                break;   
            }

            if(sum > target)
                j--;
            else
                i++;
        }

        if(index1 < index2)
        return {index1, index2};

        return {index2, index1};
    }
};
