class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin() , nums.end());
        int smallestDiff = numeric_limits<int>::max();
        for(int i =0;i<nums.size()-2;i++)
        {
            int right = nums.size()-1 , left = i+1;
            while(left < right)
            {
                int targetDiff =target - (nums[i] + nums[left] + nums[right]);
                if(targetDiff ==0)
                {
                    return target - targetDiff;
                }
                if(abs(targetDiff) < abs(smallestDiff))
                {
                    smallestDiff = targetDiff;
                }
                if(targetDiff > 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return target - smallestDiff;
    }
};
