class Solution {
    public String encode(List<String> strs) {
        if(strs.size() == 0)
            return "";

        List<Integer> sizes = new ArrayList<>();

        for(String s:strs) {
            sizes.add(s.length());
        }

        String ans = "";

        for(int i=0 ; i<sizes.size() ; i++) {
            ans += Integer.toString(sizes.get(i)) + ",";
        }

        ans += "#";

        for(String s:strs) 
            ans += s;
    
        return ans;
    }

    public List<String> decode(String str) {
        List<String> ans = new ArrayList<>();
        List<Integer> sizes = new ArrayList<>();

        if(str.length() == 0)
            return ans;

        int j=0;
        for(int i=0 ; i<str.length() ; i++) {
            if(str.charAt(i) == '#') {
                j = i+1;
                break;
            }

            if(str.charAt(i) == ',') {
                String temp = str.substring(j, i);
                sizes.add(Integer.parseInt(temp));
                j = i+1;
            }
        }

        int i=0;

        while(i < sizes.size()) {
            String temp = str.substring(j, j+sizes.get(i));
            ans.add(temp);
            j = j+sizes.get(i);
            i++;
        }

        return ans;
    }
}
