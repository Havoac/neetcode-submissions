class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;

        for(int val:nums) {
            if(st.count(val))
            return val;

            st.insert(val);
        }

        return -1;
    }
};
