class Solution {
    HashMap<Character, List<Character>> phoneMapping = new HashMap<>();

    void Traverse(int i, String digits, StringBuilder sb, List<String> allCombinations) {
        int len = digits.length();

        if(i == len) {
            allCombinations.add(sb.toString());
            return ;
        }

        for(char ch:phoneMapping.get(digits.charAt(i))) {
            sb.append(ch);
            Traverse(i+1, digits, sb, allCombinations);
            sb.setLength(sb.length()-1);
        }
    }

    void StorePhoneData() {
        phoneMapping.put('2', new ArrayList<>(List.of('a','b','c')));
        phoneMapping.put('3', new ArrayList<>(List.of('d','e','f')));
        phoneMapping.put('4', new ArrayList<>(List.of('g','h','i')));
        phoneMapping.put('5', new ArrayList<>(List.of('j','k','l')));
        phoneMapping.put('6', new ArrayList<>(List.of('m','n','o')));
        phoneMapping.put('7', new ArrayList<>(List.of('p','q','r','s')));
        phoneMapping.put('8', new ArrayList<>(List.of('t','u','v')));
        phoneMapping.put('9', new ArrayList<>(List.of('w','x','y','z')));
    }

    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0)
        return new ArrayList<>();

        StorePhoneData();

        List<String> allCombinations = new ArrayList<>();

        StringBuilder sb = new StringBuilder("");

        Traverse(0, digits, sb, allCombinations);

        return allCombinations;
    }
}
