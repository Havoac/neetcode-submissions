class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0)
        return 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int val:nums)
            pq.add(val);

        int maxConsecutiveSequence = 1, currentConsecutiveSequence = 1;
        int lastVal = pq.peek();
        pq.poll();

        while(pq.size() > 0) {
            int currVal = pq.peek();
            pq.poll();

            if(lastVal-currVal <= 1) {
                if(lastVal != currVal)
                    currentConsecutiveSequence += 1;
            }
            else {
                currentConsecutiveSequence = 1;
            }

            lastVal = currVal;
            maxConsecutiveSequence = Math.max(maxConsecutiveSequence, currentConsecutiveSequence);
        }

        return maxConsecutiveSequence;
    } 
}

