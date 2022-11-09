class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>result(n);
        int left = 0;
        int right = n - 1;
        int hightestSquareIndex = n-1; // notice that big squares always be in the left or the right
        while(left <= right)
        {
            int leftSquare = nums[left] * nums[left];
            int rightSquare =nums[right] * nums[right];
            if(leftSquare > rightSquare)
            {
                result[hightestSquareIndex--]=leftSquare;
                left++;
            }
            else
            {
                result[hightestSquareIndex--]=rightSquare;
                right--;
            }
        }
        return result;
    }
};
