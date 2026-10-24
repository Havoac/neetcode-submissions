class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();

        for(int i=0 ; i<n ; i++) {
            if(st.empty() || st.top().first<temperatures[i])
                st.push({temperatures[i], i});
        }

        vector<int> ans(n, 0);

        for(int i=n-1 ; i>=0 ; i--) {
            int value = st.top().first;
            int index = st.top().second;
            
            while(!st.empty() && index >= i) {
                if(value>temperatures[i] && index>i) {
                    ans[i] = index-i;
                    break;
                }
                else
                st.pop();

                if(!st.empty()) {
                    value = st.top().first;
                    index = st.top().second;
                }
                
            }

            st.push({temperatures[i], i});
        }

        return ans;
    }
};
