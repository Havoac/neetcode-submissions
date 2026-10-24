class Solution {
public:
    bool AreCharactersSame(char ch1, char ch2) {
        if(ch1>='a' && ch1<='z')
            ch1 = ch1-32;

        if(ch2>='a' && ch2<='z')
            ch2 = ch2-32;

        return ch1==ch2;
    }

    bool IsAlphaNumeric(char ch) {
        return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
    }

    bool isPalindrome(string s) {
        int i=0, j=s.length()-1;

        while(i < j) {
            while(i<j && !IsAlphaNumeric(s[i]))
            i++;

            while(i<j && !IsAlphaNumeric(s[j]))
            j--;

            if(AreCharactersSame(s[i], s[j]))
            {
                i++;
                j--;
            }
            else
                return false;
        }

        return true;
    }
};
