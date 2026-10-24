class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> ans = new ArrayList<>();
        HashMap<String, List<String>> mp = new HashMap<>();
        
        for(int i=0 ; i<strs.length ; i++) {
            int []freq = new int[26];

            for(char ch:strs[i].toCharArray()) {
                freq[ch-'a']++;
            }

            String temp = "";
            for(int j=0 ; j<26 ; j++) {
                if(freq[j] > 0) {
                    temp += String.valueOf(freq[j]) + String.valueOf('a'+j);
                }
            }

            if(!mp.containsKey(temp))
                mp.put(temp, new ArrayList<>());
            
            mp.get(temp).add(strs[i]);
        }
        
        for(Map.Entry<String, List<String>> entry:mp.entrySet()) {
            List<String> list = entry.getValue();
            ans.add(list);
        }

        return ans;
    }
}
