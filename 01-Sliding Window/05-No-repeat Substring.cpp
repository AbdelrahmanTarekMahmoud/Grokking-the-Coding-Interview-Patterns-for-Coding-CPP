using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>

class NoRepeatSubString {
public:
    static int findlength(const string &str)
    {
        int windowStart = 0; 
        int max_length = 0; 
        unordered_map<char, int> CharFreq;
        for (int windowEnd = 0;windowEnd < str.length();windowEnd++)
        {
            char rightChar  = str[windowEnd]; 
            CharFreq[rightChar]++; 
            while (CharFreq[rightChar] > 1)
            {
                char leftChar = str[windowStart];
                CharFreq[leftChar]--;
                windowStart++;
            }
            max_length = max(max_length, windowEnd - windowStart + 1);
        }
        return max_length;
    }
};

int main(int argc, char* argv[])
{
    cout << NoRepeatSubString::findlength("abccde") << endl;
}
