class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size()-1;
        for(int i =0;i<= high;)
        {
            if(nums[i] == 0)
            {
                swap(nums[i] , nums[low]);
                low++;
                i++;
            }
            else if(nums[i] == 1)
            {
                i++;
            }
            else
            {
                swap(nums[i] , nums[high]);
                high--;
            }
        }
    }
};
