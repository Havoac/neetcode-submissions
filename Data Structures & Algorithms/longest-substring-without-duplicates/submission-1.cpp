class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, i=0, j=0, len = s.length();
        set<char> st;

        while(j < len) {
            if(st.count(s[j])) {
                while(i<j && s[i]!=s[j])
                {
                    st.erase(s[i]);
                    i++;
                }
                i++;
            }
            
            st.insert(s[j]);
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};
