class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int pointer1=0,pointer2=numbers.size()-1;
        vector<int> result;
        while(pointer1 < pointer2)
        {
            if((numbers[pointer1] + numbers[pointer2]) == target)
            {
               result.push_back(pointer1+1);
               result.push_back(pointer2+1);
               return result;
            }
            if((numbers[pointer1] + numbers[pointer2]) < target)
            {
               pointer1++;
            }
            if((numbers[pointer1] + numbers[pointer2]) > target)
            {
               pointer2--;
            }
        }
        return {0,0};
    }
};
