class Solution {
    public int[] twoSum(int[] nums, int target) {
        int len = nums.length;
        int [][]arr = new int[len][2];

        for(int i=0 ; i<len ; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }

        Arrays.sort(arr, (a, b) -> Integer.compare(a[0], b[0]));

        int i=0, j=len-1;

        while(i < j) {
            int sum = arr[i][0] + arr[j][0];

            if(sum > target)
            j--;
            else if(sum < target)
            i++;
            else
            {
                if(arr[i][1] < arr[j][1])
                return new int[]{arr[i][1], arr[j][1]};

                return new int[]{arr[j][1], arr[i][1]};
            }
        }

        return new int[]{-1, -1};
    }
}
