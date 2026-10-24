class Solution {
    private static List<List<Integer>> allCombinations = new ArrayList<>();

    void ComputeAllCombinations(int index, int []nums, int target, List<Integer> combination)  {
    if(target == 0) {
        allCombinations.add(new ArrayList<>(combination));
        return ;
    }

    int size = nums.length;

    if(index==size)
    return ;

    for(int i=index ; i<size ; i++) { 
        if(i>index && nums[i]==nums[i-1])
        continue;

        if(target < nums[i])
        break;

        combination.add(nums[i]);
        ComputeAllCombinations(i+1, nums, target - nums[i], combination);
        combination.remove(combination.size() - 1);
    }     
}

    public List<List<Integer>> combinationSum2(int[] nums, int target) {
        List<Integer> combination = new ArrayList<>();
        Arrays.sort(nums);
        allCombinations.clear();

        ComputeAllCombinations(0, nums, target, combination);

        return allCombinations;
    }
}
