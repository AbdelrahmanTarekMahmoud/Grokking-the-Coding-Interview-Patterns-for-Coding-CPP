using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
public:
    static int findMinSubArray(int S, const vector<int>& arr) {
        int windowStart = 0;
        int windowSum = 0;
        int result = numeric_limits<int>::max();

        for (int windowEnd = 0;windowEnd < arr.size(); windowEnd++)
        {
            windowSum += arr[windowEnd];
            while (windowSum >= S)
            {
                result = min(result, windowEnd - windowStart + 1);
                windowSum -= arr[windowStart];
                windowStart++;
            }

        }
        return result == numeric_limits<int>::max() ? 0 : result;
    }
};

	int main(int argc, char* argv[]) {
		int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
		cout << "Smallest subarray length: " << result << endl;
		result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
		cout << "Smallest subarray length: " << result << endl;
		result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
		cout << "Smallest subarray length: " << result << endl;
	}

