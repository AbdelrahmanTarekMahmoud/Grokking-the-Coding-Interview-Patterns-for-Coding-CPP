class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int low = 0 , high = nums.size()-1;
        while ( low < nums.size()-1 && nums[low] <= nums[low+1])
        {
            low++;
        }
        if(low ==nums.size()-1)
        {
            return 0;
        }
        while (high > 0 && nums[high] >= nums[high-1])
        {
            high--;
        }
        int minSubarray = numeric_limits<int>::max();
        int maxSubarray = numeric_limits<int>::min();
        for (int i = low ;i <= high; i++)
        {
          minSubarray = min(minSubarray , nums[i]);
          maxSubarray = max(maxSubarray , nums[i]);
        }
        while (low > 0 && nums[low-1] > minSubarray)
        {
            low--;
        }
        while (high < nums.size()-1 && nums[high + 1] < maxSubarray)
        {
            high++;
        }
        return high - low + 1;
    }
};
