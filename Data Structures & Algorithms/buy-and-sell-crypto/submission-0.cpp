class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(), minVal = prices[0];
        vector<int> prefixMin(n, 0);

        for(int i=1 ; i<n ; i++) {
            prefixMin[i] = minVal;
            minVal = min(minVal, prices[i]);
        }

        int ans = 0;
        for(int i=1 ; i<n ; i++) {
            if(prices[i] > prefixMin[i])
                ans = max(ans, prices[i]-prefixMin[i]);
        }

        return ans;
    }
};
