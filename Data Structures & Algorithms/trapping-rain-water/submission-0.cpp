class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefixMaxHeight(n, 0);
        vector<int> suffixMaxHeight(n, 0);

        int maxHeightSoFar = 0;
        for(int i=0 ; i<n ; i++) {
            prefixMaxHeight[i] = maxHeightSoFar;
            maxHeightSoFar = max(maxHeightSoFar, height[i]);
        }

        maxHeightSoFar = 0;
        for(int i=n-1 ; i>=0 ; i--) {
            suffixMaxHeight[i] = maxHeightSoFar;
            maxHeightSoFar = max(maxHeightSoFar, height[i]);
        }

        int ans = 0;

        for(int i=0 ; i<n ; i++) {
            if(min(prefixMaxHeight[i], suffixMaxHeight[i]) > height[i])
            {
                ans += min(prefixMaxHeight[i], suffixMaxHeight[i]) - height[i];
                // cout<<i<<" : "<<min(prefixMaxHeight[i], suffixMaxHeight[i]) - height[i]<<"\n";
            }
        }

        return ans;
    }
};
