using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>

class StringAnagrams {
public:
    static vector<int> findStringAnagrams(const string &str , const string&pattern)
    {
        vector<int> resultIndices;
        int windowStart = 0, matched = 0;
        unordered_map<char, int> charFreqMap;
        for (auto ch : pattern)
        {
            charFreqMap[ch]++;
        }
        for (int windowEnd = 0;windowEnd < str.length();windowEnd++)
        {
            char rightChar = str[windowEnd];
            if (charFreqMap.find(rightChar) != charFreqMap.end())
            {
                charFreqMap[rightChar]--;
                if (charFreqMap[rightChar] == 0)
                {
                    matched++;
                }
            }
            if (matched == (int)charFreqMap.size())
            {
                resultIndices.push_back(windowStart);
            }
            if (windowEnd - windowStart + 1 >= pattern.length())
            {
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
        return resultIndices;
    }
};

int main(int argc, char* argv[])
{
    auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
    for (auto it : result)
    {
        cout << it << " ";
    }
}
