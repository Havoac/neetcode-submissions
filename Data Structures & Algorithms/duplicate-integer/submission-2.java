class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> st = new HashSet<>();

        for(int val:nums) {
            if(st.contains(val))
            return true;

            st.add(val);
        }

        return false;
    }
}