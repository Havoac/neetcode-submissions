class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        long []prefixProduct = new long[n];
        long []suffixProduct = new long[n];

        Arrays.fill(prefixProduct, 1);
        Arrays.fill(suffixProduct, 1);

        long product = 1;

        for(int i=1 ; i<n ; i++) {
            product *= nums[i-1];
            prefixProduct[i] = product;
        }

        product = 1;

        for(int i=n-2 ; i>=0 ; i--) {
            product *= nums[i+1];
            suffixProduct[i] = product;
        }

        int []ans = new int[n];

        for(int i=0 ; i<n ; i++)
        ans[i] = (int)prefixProduct[i] * (int)suffixProduct[i];

        return ans;
    }
}  
