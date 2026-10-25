class Solution {
    boolean IsPalindrome(StringBuilder sb) {
        int len = sb.length();

        int i=0, j=len-1;

        while(i < j) {
            if(sb.charAt(i) != sb.charAt(j))
            return false;

            i++;
            j--;
        }

        return true;
    }

    void Traverse(int i, String s, StringBuilder sb, List<String> validPalindromicSubstring, List<List<String>> allPalindromicSubstrings) {
        if(i == s.length()) {
            if(IsPalindrome(sb)) {
                if(sb.length() > 0) {
                    validPalindromicSubstring.add(sb.toString());
                    allPalindromicSubstrings.add(new ArrayList<>(validPalindromicSubstring));
                    validPalindromicSubstring.remove(validPalindromicSubstring.size()-1);
                }
            }

            return;
        }

        sb.append(s.charAt(i));

        if(IsPalindrome(sb)) {
            if(sb.length() > 0) {
                validPalindromicSubstring.add(sb.toString());
                Traverse(i+1, s, new StringBuilder(), validPalindromicSubstring, allPalindromicSubstrings);
                validPalindromicSubstring.remove(validPalindromicSubstring.size()-1);
            }
        }

        Traverse(i+1, s, sb, validPalindromicSubstring, allPalindromicSubstrings);
    }

    public List<List<String>> partition(String s) {
        List<List<String>> allPalindromicSubstrings = new ArrayList<>();
        StringBuilder sb = new StringBuilder(s.charAt(0));
        List<String> validPalindromicSubstring = new ArrayList<>();

        Traverse(0, s, sb, validPalindromicSubstring, allPalindromicSubstrings);

        return allPalindromicSubstrings;
    }
}
