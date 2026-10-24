class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0)
        return 0;

        HashMap<Integer, Integer> mp = new HashMap<>();
        int ans = 0;

        for(int val:nums) {
            if(!mp.containsKey(val)) {
                int left = mp.getOrDefault(val-1, 0);
                int right = mp.getOrDefault(val+1, 0);
                int len = left + right + 1;

                mp.put(val, len);
                mp.put(val - left, mp.getOrDefault(val, 0));
                mp.put(val + right, mp.getOrDefault(val, 0));
                ans = Math.max(ans, mp.getOrDefault(val, 0));
            }
        }

        return ans;
    }
}
