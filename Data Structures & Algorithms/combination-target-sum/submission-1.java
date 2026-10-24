class Solution {
    void ComputeAllCombinations(int index, int []nums, int target, List<Integer> combination, HashSet<List<Integer>> uniqueCombinations) {
        if(target == 0) {
            uniqueCombinations.add(new ArrayList<>(combination));
            return ;
        }

        if(target < 0)
        return ;

        int size = nums.length;

        if(((index+1) < size))
            ComputeAllCombinations(index+1, nums, target, combination, uniqueCombinations);
        
        combination.add(nums[index]);
        
        ComputeAllCombinations(index, nums, target-nums[index], combination, uniqueCombinations);
        
        if((index+1) < size)
            ComputeAllCombinations(index+1, nums, target-nums[index], combination, uniqueCombinations);
        
        combination.remove(Integer.valueOf(nums[index]));        
    }

    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> allCombinations= new ArrayList<>();
        List<Integer> combination = new ArrayList<>();
        HashSet<List<Integer>> uniqueCombinations = new HashSet<>();

        ComputeAllCombinations(0, nums, target, combination, uniqueCombinations);

        for(List<Integer> comb:uniqueCombinations) {
            allCombinations.add(comb);
        }

        return allCombinations;
    }
}
