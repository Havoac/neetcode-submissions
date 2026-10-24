class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        return false;

        vector<int> frequency(26, 0);

        for(int i=0 ; i<s.length() ; i++)
            frequency[s[i]-'a']++;

        for(char ch:t) {
            if(frequency[ch-'a'] == 0)
            return false;

            frequency[ch-'a']--;
        }

        return true;
    }
};
