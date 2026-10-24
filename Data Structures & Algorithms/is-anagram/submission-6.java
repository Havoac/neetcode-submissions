class Solution {
    boolean CheckIfAnagram(Map<Character, Integer> mp1, Map<Character, Integer> mp2) {
        for(Map.Entry<Character, Integer> entry:mp1.entrySet()) {
            char key = entry.getKey();
            int value = entry.getValue();

            if(!mp2.containsKey(key))
            return false;

            if(value != mp2.get(key))
            return false;
        }

        return true;
    }

    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> mp1 = new HashMap<>();
        Map<Character, Integer> mp2 = new HashMap<>();
    
        int len1 = s.length(), len2 = t.length();

        for(int i=0 ; i<len1 ; i++)
        {
            if(mp1.containsKey(s.charAt(i))) 
                mp1.put(s.charAt(i), mp1.get(s.charAt(i))+1);
            else
                mp1.put(s.charAt(i), 1);
        }

        for(int i=0 ; i<len2 ; i++)
        {
            if(mp2.containsKey(t.charAt(i))) 
                mp2.put(t.charAt(i), mp2.get(t.charAt(i))+1);
            else
                mp2.put(t.charAt(i), 1);
        }
    
        if(CheckIfAnagram(mp1, mp2) && CheckIfAnagram(mp2, mp1))
        return true;

        return false;
    }
}
