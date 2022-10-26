#include<iostream>
#include<vector>

using namespace std;

class AverageOfSubarrayOfSizeK
{
public:
	static vector<double> findAverages (int K, const vector<int>& arr)
	{
		vector<double> result(arr.size() - K + 1);
		double windowSum = 0;
		int windowStart = 0;
		for (int windowEnd = 0;windowEnd < arr.size();windowEnd++)
		{
			windowSum += arr[windowEnd]; // add elements one by one

			if (windowEnd >= K - 1)
			{
				result[windowStart] = windowSum / K; //calculate avg
				windowSum -=arr[windowStart]; // subtract the element going out
				windowStart++; // slide the window ahead 
			}
		}
		return result;
	}
};
// TC = O(N)  N -> NUMBER OF ELEMENTS   

int main(int argc, char* argv[])
{
	vector<double> result = AverageOfSubarrayOfSizeK::findAverages(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
	cout << "Averages of subarrays of size K : ";
	for (auto it : result)
	{
		cout << it << " ";
	}
	cout << endl;
}
