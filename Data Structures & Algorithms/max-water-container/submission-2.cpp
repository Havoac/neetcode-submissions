class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), ans = 0, i=0, j=n-1;

        while(i < j) {
            ans = max(ans, min(heights[i], heights[j]) * (j-i));

            if(heights[i] >= heights[j])
                j--;
            else
                i++;
        }

        return ans;
    }
};
