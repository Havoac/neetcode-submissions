class Solution {
public:
    int characterReplacement(string s, int k) {
        int len=s.length(), ans=0;
        set<char> uniqueSet;

        for(char ch:s)
            uniqueSet.insert(ch);

        for(char ch:uniqueSet) {
            string copy = s;
            int i=0, j=0, newK=k;
            // cout<<ch<<":\n";
            while(j < len) {
                if(s[j] != ch) {
                    if(newK > 0) {
                        copy[j] = ch;
                        newK--;
                    }
                    else {
                        copy[j] = ch;

                        while(i<j && s[i]==ch) {
                            copy[i] = s[i];
                            i++;
                        }

                        copy[i] = s[i];
                        i++;
                    }
                }

                ans = max(ans, j-i+1);
                // cout<<i<<" "<<j<<" "<<newK<<"\n";
                j++;
            }
        }

        return ans;
    }
};
