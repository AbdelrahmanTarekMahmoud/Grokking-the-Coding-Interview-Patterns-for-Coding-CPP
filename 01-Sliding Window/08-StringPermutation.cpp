using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>

class PermutationInAString {
public:
    static bool isPermutation(const string &str , const string&pattern)
    {
        int windowStart = 0;
        int matched = 0;
        unordered_map<char, int > charFreq;
        for (auto ch : pattern)
        {
            charFreq[ch]++;
        }
        for (int windowEnd = 0;windowEnd < str.length();windowEnd++)
        {
            char rightChar = str[windowEnd];
            if (charFreq.find(rightChar) != charFreq.end())
            {
                charFreq[rightChar]--;
                if (charFreq[rightChar] == 0)
                {
                    matched++;
                }
            }
            if (matched == (int)charFreq.size())
            {
                return true;
            }
            if (windowEnd - windowStart + 1 >= pattern.length())
            {
                char leftChar = str[windowStart++];
                if (charFreq.find(leftChar) != charFreq.end())
                {
                    if (charFreq[leftChar] == 0)
                    {
                        matched--;
                    }
                    charFreq[leftChar]++;
                }
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    cout << PermutationInAString::isPermutation("odicf" , "dc") << endl;
}
