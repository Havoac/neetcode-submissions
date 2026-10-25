class Solution {
    void ComputeAllSubsets(int index, int[] nums, List<Integer> list, List<List<Integer>> ans) {
        int n = nums.length;

        ans.add(new ArrayList<>(list));

        if(index == n)
        {
            return ;
        }

        for(int i=index ; i<n ; i++) {
            if(i>index && nums[i]==nums[i-1])
            continue;

            list.add(nums[i]);
            ComputeAllSubsets(i+1, nums, list, ans);
            list.remove(list.size()-1);            
        }
    }

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);

        List<Integer> list = new ArrayList<>();

        ComputeAllSubsets(0, nums, list, ans);

        return ans;
    }
}
