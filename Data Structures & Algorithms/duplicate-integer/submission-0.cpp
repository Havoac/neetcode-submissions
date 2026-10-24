class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> st;

        for(int val:nums) {
            if(st.count(val))
            return true;

            st.insert(val);
        }

        return false;
    }
};