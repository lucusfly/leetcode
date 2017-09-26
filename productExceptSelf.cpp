#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> result(nums.size());
	
	if (nums.size() == 0)
	{
		return result;
	}
	
	result[0] = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		result[i] = result[i-1] * nums[i-1];
	}
	
	int n = 1;
	for (int i = nums.size() - 2; i >= 0; i--)
	{
		n = n * nums[i+1];
		result[i] = result[i] * n;
	}
	
	return result;
}

int main()
{
	int b[] = {1, 2, 3, 4};
	vector<int> a(b, b + 4);
	
	vector<int> re = productExceptSelf(a);
	
	for (int i = 0; i < re.size(); i++)
	{
		cout << re[i] << ",";
	}
	cout << endl;
}
