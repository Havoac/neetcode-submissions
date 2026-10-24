class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //set<vector<int>> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] > 0)
            break;

            if(i>0 && nums[i]==nums[i-1])
            continue;

            int j=i+1, k=n-1, target = -nums[i];
            
            while(j < k) {
                int sum = nums[j]+nums[k];
                
                if(sum < target)
                    j++;
                else if(sum > target)
                    k--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j<k && nums[j]==nums[j-1])
                        j++;

                    while(j<k && nums[k]==nums[k+1])
                        k--;
                }
            }
        }

        // for(vector<int> v:st)
        // ans.push_back(v);


        return ans;
    }
};
