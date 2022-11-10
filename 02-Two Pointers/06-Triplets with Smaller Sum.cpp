class Solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) 
    {
        int count = 0;
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i =0;i<n-2;i++)
        {
            int left = i+1 ;
            int right = n-1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < target){
                    count+= right - left;
                    left++;
                }
                else
                    right--;
            }
        }
        return count;
    }
};
