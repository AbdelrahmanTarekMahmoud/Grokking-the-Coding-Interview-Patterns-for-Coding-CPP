using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringkDistinct {
public:
    static int findlength(const string &s, int k)
    {
        int windowStart = 0;
        int max_length = 0;
        unordered_map<char, int> charFrequency;
        for (int windowEnd = 0;windowEnd < s.length();windowEnd++)
        {
            char rightChar = s[windowEnd];
            charFrequency[rightChar]++;

            while ((int)charFrequency.size() > k)
            {
                char leftChar = s[windowStart];
                charFrequency[leftChar]--;
                if (charFrequency[leftChar] == 0)
                {
                    charFrequency.erase(leftChar);
                }
                windowStart++;
            }
            max_length = max(max_length, windowEnd - windowStart + 1);
        }
        return max_length;
    }
};

int main(int argc, char* argv[])
{
    cout << "Length of the longest substring : " << LongestSubstringkDistinct::findlength("araaci", 2) << endl;
}
