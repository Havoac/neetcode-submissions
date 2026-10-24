class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> frequencies = new HashMap<>();

        for(int val:nums) 
        {
            if(!frequencies.containsKey(val))
                frequencies.put(val, 1);
            else
                frequencies.put(val, frequencies.get(val)+1);
        }

        List<List<Integer>> list = new ArrayList<>();

        for(Map.Entry<Integer, Integer> itr:frequencies.entrySet()) {
            list.add(Arrays.asList(itr.getValue(), itr.getKey()));
        }

        list.sort((a, b) -> Integer.compare(b.get(0), a.get(0)));

        int []ans = new int[k];

        for(int i=0 ; i<k ; i++) {
            ans[i] = (list.get(i).get(1));
        }

        return ans;
    }
}
