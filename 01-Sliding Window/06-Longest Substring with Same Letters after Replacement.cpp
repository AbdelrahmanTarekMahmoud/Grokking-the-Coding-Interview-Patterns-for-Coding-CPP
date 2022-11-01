// When it comes To sliding Window Pattern ASK Yourself the 2 QUESTIONS
/*
Quesiont 1 : What will be The Window Size ?

= Window Size Should be:
  -MaxrepeatedLetter : the main letters
  -internalletters   : the letters in between main letters (should be = k)

Question 2 : when will we shrink the window?

=We will shrink when (Windowsize - MaxRepeatedLetter > k)
*/
class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int windowStart = 0;
        int maxRepeatedLetter = 0;
        int max_length =0;
        unordered_map<char,int> CharFreq;
        for(int windowEnd = 0;windowEnd < s.size();windowEnd++)
        {
            char rightChar = s[windowEnd];
            CharFreq[rightChar]++;
            maxRepeatedLetter = max(maxRepeatedLetter , CharFreq[rightChar]);
            
            // here i used if not while like always because i can hold repeated letters -_-
            if(windowEnd - windowStart + 1 - maxRepeatedLetter > k)
            {
                char leftChar = s[windowStart];
                CharFreq[leftChar]--;
                windowStart++;
            }
          max_length = max (max_length , windowEnd - windowStart + 1);
        }
        return max_length;
    }
};
