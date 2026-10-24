class Solution {
    void Reverse(int start, int end, int []nums) {
        while(start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;

            start++;
            end--;
        }
    }

    void NextPermutation(int []nums) {
        int n = nums.length;
        int pivotIndex = -1;

        for(int i=n-2 ; i>=0 ; i--) {
            if(nums[i] < nums[i+1]) {
                pivotIndex = i;
                break; 
            }
        }
        
        if(pivotIndex == -1) {
            Reverse(0, n-1, nums);
            return ;
        }

        int indexToBeSwapped = 0;
        for(int i=n-1 ; i>pivotIndex ; i--) {
            if(nums[i] > nums[pivotIndex]) {
                indexToBeSwapped = i;
                break;
            }
        }

        int temp = nums[pivotIndex];
        nums[pivotIndex] = nums[indexToBeSwapped];
        nums[indexToBeSwapped] = temp;

        Reverse(pivotIndex+1, n-1, nums);
    }

    boolean ComparePermutation(int []nums1, int []nums2) {
        int n = nums1.length;

        for(int i=0 ; i<n ; i++) {
            if(nums1[i] != nums2[i])
                return false;
        }

        return true;
    }

    void ComputeAllPermutations(int []nums, int []originalArray, List<List<Integer>> ans) {
        List<Integer> tempValues = new ArrayList<>();
        for(int val:nums)
            tempValues.add(val);
        ans.add(tempValues);

        while(true)
        {
            NextPermutation(nums);

            List<Integer> values = new ArrayList<>();
            for(int val:nums)
            values.add(val);

            if(!ComparePermutation(nums, originalArray))
                ans.add(values);
            else
                break;
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length;
        int []originalArray = new int[n];

        for(int i=0 ; i<n ; i++)
            originalArray[i] = nums[i];

        ComputeAllPermutations(nums, originalArray, ans);

        return ans;
    }
}
