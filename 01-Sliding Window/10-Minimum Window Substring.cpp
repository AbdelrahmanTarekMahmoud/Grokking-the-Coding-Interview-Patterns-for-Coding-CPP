using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>

class MinimumWindowSubstring {
public:
    static string findSubstring(const string &str , const string&pattern)
    {
        int windowStart = 0,  matched = 0 , min_length = str.length() + 1, subStrStart=0;
        unordered_map<char, int> charFreqMap;
        for (auto ch : pattern)
        {
            charFreqMap[ch]++;
        }
        
        for (int windowEnd = 0;windowEnd < str.length();windowEnd++)
        {
            int rightChar = str[windowEnd];
            if (charFreqMap.find(rightChar) != charFreqMap.end())
            {
                charFreqMap[rightChar]--;
                if (charFreqMap[rightChar] >= 0)
                {
                    matched++;
                }
            }
            while (matched == pattern.length())
            {
                if (min_length > windowEnd - windowStart + 1)
                {
                    min_length = windowEnd - windowStart + 1;
                    subStrStart = windowStart;
                }
                
                char leftChar = str[windowStart++];
                if (charFreqMap.find(leftChar) != charFreqMap.end())
                {
                    if (charFreqMap[leftChar] == 0)
                    {
                        matched--;
                    }
                    charFreqMap[leftChar]++;
                }
            }
        }
        return min_length > str.length() ? "" : str.substr(subStrStart, min_length);
    }
};

int main(int argc, char* argv[])
{
    cout << MinimumWindowSubstring::findSubstring("aabdec", "abc") << endl;
    cout << MinimumWindowSubstring::findSubstring("abdabca", "abc") << endl;
    cout << MinimumWindowSubstring::findSubstring("adcad", "abc") << endl;


}
