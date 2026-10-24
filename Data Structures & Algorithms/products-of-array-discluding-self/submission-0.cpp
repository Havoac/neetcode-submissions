class Solution {
public:
    typedef long long ll;
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<ll>prefixProduct(n, 1);
        vector<ll>suffixProduct(n, 1);

        ll product = 1;

        for(int i=1 ; i<n ; i++)
        {
            product *= nums[i-1];
            prefixProduct[i] = product;
        }

        product = 1;
        for(int i=n-2 ; i>=0 ; i--) {
            product *= nums[i+1];
            suffixProduct[i] = product;
        }

        vector<int> ans;

        for(int i=0 ; i<n ; i++) {
            ans.push_back(prefixProduct[i] * suffixProduct[i]);
        }

        return ans;
    }
};
