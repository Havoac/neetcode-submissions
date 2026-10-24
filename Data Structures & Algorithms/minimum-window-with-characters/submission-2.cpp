class Solution {
public:
    bool Compare(unordered_map<char, int> &freq1, unordered_map<char, int> &freq2) {
        for(auto &itr:freq2) {
            if(itr.second>0 && freq1[itr.first]<itr.second)
            return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;

        int len1=s.length(), len2=t.length();
        int start=-1, end=-1, subStringSize = len1+1, i=0, j=0;

        for(char ch:t)
            freq2[ch]++;

        while(j < len1) {
            freq1[s[j]]++;

            // cout<<i<<" "<<j<<" : ";
            if(Compare(freq1, freq2)) {
                while(i<j && (freq2[s[i]]==0 || freq1[s[i]]==(1+freq2[s[i]])))
                {
                    freq1[s[i]]--;
                    i++;
                }

                if(subStringSize > (j-i+1)) {
                    subStringSize = j-i+1;
                    start = i;
                    end = j;
                }
            }

            // cout<<i<<" "<<j<<" : "<<subStringSize<<" : "<<start<<" "<<end<<"\n";

            j++;
        }


        if(Compare(freq1, freq2)) {
            while(i<j && (freq2[s[i]]==0 || freq1[s[i]] > freq2[s[i]]))
            {
                freq1[s[i]]--;
                i++;
            }

            // cout<<i<<" "<<j<<" : "<<subStringSize<<" : "<<start<<" "<<end<<"\n";

            if(subStringSize > (j-i+1)) {
                subStringSize = j-i+1;
                start = i;
                end = j;
            }
        }

        if(start != -1)
            return s.substr(start, end-start+1);

        return "";
    }
};
