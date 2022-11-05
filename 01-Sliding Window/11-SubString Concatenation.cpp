using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        unordered_map<string, int> charFreqMap;
        for (string word : words)
        {
            charFreqMap[word]++;
        }
        vector<int> indices;
        int wordCount = words.size(), word_length = words[0].length();
        if (wordCount * word_length > s.size())
        {
            return {};
        }
        for (int i = 0;i <= s.length() - wordCount * word_length;i++)
        {
            unordered_map<string, int> seenWord;
            for (int j = 0;j < wordCount;j++)
            {
                int nextWordIndex = i + j * word_length;
                string word = s.substr(nextWordIndex, word_length);
                if (charFreqMap.find(word) == charFreqMap.end())
                {
                    break;
                }
                seenWord[word]++;
                if (seenWord[word] > charFreqMap[word])
                {
                    break;
                }
                if (j + 1 == wordCount)
                {
                    indices.push_back(i);
                }
            }
        }
        return indices;
    }
};
