class Solution {
    void ComputeAllCombinations(int index, int []nums, int target, List<Integer> combination, List<List<Integer>> allCombinations) {
        if(target == 0) {
            allCombinations.add(new ArrayList<>(combination));
            return ;
        }

        int size = nums.length;

        if(target < 0 || index==size)
        return ;

        ComputeAllCombinations(index+1, nums, target, combination, allCombinations);

        combination.add(nums[index]);
        ComputeAllCombinations(index, nums, target - nums[index], combination, allCombinations);
        combination.remove(combination.size() - 1);      
    }

    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> allCombinations= new ArrayList<>();
        List<Integer> combination = new ArrayList<>();

        ComputeAllCombinations(0, nums, target, combination, allCombinations);

        return allCombinations;
    }
}
