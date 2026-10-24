class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> freq2;
        for (char ch : t)
            freq2[ch]++;

        int len1 = s.length();
        int need = freq2.size();   
        int have = 0;              

        unordered_map<char, int> freq1;
        int start = -1, end = -1, subStringSize = len1 + 1;
        int i = 0, j = 0;

        while (j < len1) {
            char ch = s[j];
            freq1[ch]++;

            if (freq2.count(ch) && freq1[ch] == freq2[ch]) {
                have++;
            }

            while (have == need) {
                if (subStringSize > (j - i + 1)) {
                    subStringSize = j - i + 1;
                    start = i;
                    end = j;
                }

                char leftCh = s[i];
                freq1[leftCh]--;

                if (freq2.count(leftCh) && freq1[leftCh] < freq2[leftCh]) {
                    have--;
                }

                i++;
            }

            j++;
        }

        if (start != -1)
            return s.substr(start, end - start + 1);

        return "";
    }
};