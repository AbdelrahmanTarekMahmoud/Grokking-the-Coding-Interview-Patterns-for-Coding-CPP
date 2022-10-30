class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
     int windowStart = 0;
     int max_length = 0;
     unordered_map<int,int> fruitTreeFrequency;
     for(int windowEnd =0;windowEnd < fruits.size(); windowEnd++)
     {
        int rightTree = fruits[windowEnd];
        fruitTreeFrequency[rightTree]++;
        while(fruitTreeFrequency.size()>2)
        {
          int leftTree = fruits[windowStart];
          fruitTreeFrequency[leftTree]--;
          if(fruitTreeFrequency[leftTree] == 0)
          {
              fruitTreeFrequency.erase(leftTree);
          }
          windowStart++;
        }
        max_length = max(max_length , windowEnd-windowStart + 1);
     }   
     return max_length;
    }
};
