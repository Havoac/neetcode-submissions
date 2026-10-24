class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
        return 0;

        priority_queue<int> pq;

        for(int val:nums)
            pq.push(val);

        int maxConsecutiveSequence = 1, currentConsecutiveSequence = 1;
        int lastVal = pq.top();
        pq.pop();

        while(!pq.empty()) {
            int currVal = pq.top();
            pq.pop();

            if(lastVal-currVal <= 1) {
                if(lastVal != currVal)
                    currentConsecutiveSequence++;
            }
            else {
                currentConsecutiveSequence = 1;
            }

            lastVal = currVal;
            maxConsecutiveSequence = max(maxConsecutiveSequence, currentConsecutiveSequence);
        }

        return maxConsecutiveSequence;
    }
};
