class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int windowStart = 0;
        int max_length = 0;
        int maxOnes =0;
        for(int windowEnd =0;windowEnd<nums.size();windowEnd++)
        {
            if(nums[windowEnd] == 1)
            {
                maxOnes++;
            }
            if(windowEnd - windowStart + 1 - maxOnes > k)
            {
                if(nums[windowStart] == 1)
                {
                maxOnes--;
                }
                windowStart ++;
            }
            max_length = max(max_length , windowEnd - windowStart + 1);
        }
        return max_length;
    }
};
