class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int> > triplets;
        for(int i =0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i] == nums[i-1]) //dont take same element to avoid triplet duplicate
            {
                continue;
            }
          searchPair(nums,-nums[i],i+1,triplets);
        }
        return triplets;
    }
private:
    static void searchPair(vector<int>&nums , int targetSum , int left , vector<vector<int> >&triplets)
    {
        int right = nums.size()-1;
        while(left < right)
        {
            if(nums[left] + nums[right] == targetSum)
            {
                triplets.push_back({-targetSum , nums[left] , nums[right]});
                right--;
                left++;
                while(left < right && nums[left] == nums[left - 1])
                {
                left++;
                }
                while(left < right && nums[right] == nums[right + 1])
                {
                right--;
                }
            }
            else if (nums[left] + nums[right] < targetSum)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
};


Time complexity #

Sorting the array will take O(N∗logN). The searchPair() function will take O(N). As we are calling searchPair() for every number in the input array, 
means that overall searchTriplets() will take O(N∗logN+N^2), which is asymptotically equivalent to O(N^2).
  
Space complexity #

Ignoring the space required for the output array, the space complexity of the above algorithm will be O(N) which is required for sorting.
