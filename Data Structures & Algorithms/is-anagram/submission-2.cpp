class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        return false;

        unordered_map<char, int> frequency;

        for(int i=0 ; i<s.length() ; i++)
            frequency[s[i]]++;

        for(char ch:t) {
            if(frequency[ch] == 0)
            return false;

            frequency[ch]--;
        }

        return true;
    }
};
