class Solution {
    void ComputeAllSubsets(int index, int[] nums, ArrayList<Integer> subset, HashSet<ArrayList<Integer>> uniqueSubsets) {
        int size = nums.length;

        if(index == size)
        {
            uniqueSubsets.add(new ArrayList<>(subset));
            return ;
        }

        ComputeAllSubsets(index+1, nums, subset, uniqueSubsets);

        subset.add(nums[index]);
        ComputeAllSubsets(index+1, nums, subset, uniqueSubsets);
        subset.remove(Integer.valueOf(nums[index]));
    }

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        HashSet<ArrayList<Integer>> uniqueSubsets = new HashSet<>();
        ArrayList<Integer> subset = new ArrayList<>();

        ComputeAllSubsets(0, nums, subset, uniqueSubsets);

        for(ArrayList<Integer> uniqueSubset:uniqueSubsets) {
            ans.add(uniqueSubset);
        }

        return ans;
    }
}
