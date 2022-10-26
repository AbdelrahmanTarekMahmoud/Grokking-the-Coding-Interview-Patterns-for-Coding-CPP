#include<iostream>
#include<vector>

using namespace std;

class AverageOfSubarrayOfSizeK
{
public:
	static vector<double> findAverages (int K, const vector<int>& arr)
	{
		vector<double> result(arr.size() - K + 1);
		for (int i = 0; i <= arr.size()- K;i++)
		{
			double sum = 0; 
			for (int j = i; j < i + K; j++)
			{
				sum += arr[j];
			}
			result[i] = sum / K;
		}
		return result;
	}
};
// TC = O(NK)  N -> NUMBER OF ELEMENTS   

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
