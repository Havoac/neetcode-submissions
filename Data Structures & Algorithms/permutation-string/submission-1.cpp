class Solution {
public:
    bool Compare(vector<int> &freq1, vector<int> &freq2) {
        for(int i=0 ; i<26 ; i++) {
            if(freq1[i] != freq2[i])
            return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int len1=s1.length(), len2=s2.length();

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char ch:s1)
            freq1[ch-'a']++;

        int i=0, j=0;

        while(j < len2) {
            if(j-i+1 <= len1)
            {
                freq2[s2[j]-'a']++;
                
            }
            else 
            {
                if(Compare(freq1, freq2)) 
                {
                    return true;
                }

                freq2[s2[i]-'a']--;
                i++;

                freq2[s2[j]-'a']++;
            }

            // cout<<i<<" "<<j<<"\n";

            j++;
        }

        if(Compare(freq1, freq2)) 
        {
            return true;
        }

        return false;
    }
};
