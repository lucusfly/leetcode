#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void getLexical(int cur, int n, vector<int>& result)
{
	if (cur > n)
	{
		return;
	}
	
	result.push_back(cur);			
	for (int i = 0; i < 10; i++)
	{
		int temp = cur * 10 + i;
		if (temp > n)
		{
			return;
		}
		
		getLexical(temp, n, result);
	}
}

vector<int> lexicalOrder(int n) {
    vector<int> result;
    for (int i = 1; i < 10; i++)
    {
    	getLexical(i, n, result);
	}
    
    return result;
}

vector<int> lexicalOrder2(int n)
{
	vector<int> result;
	
	int cur = 1;
	for (int i = 0; i < n; i++)
	{
		result.push_back(cur);
		
		int temp = cur * 10;
		if (temp > n)
		{
			if (cur == n)
			{
				cur = cur / 10;
			}
			
			temp = cur + 1;			
			
			while (temp % 10 == 0)
				temp = temp / 10;
			
		}
		
		cur = temp;
	}
	
	return result;
}

int main()
{
	vector<int> result = lexicalOrder2(1999);
	
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ",";
		
		
		if (i > 0)
		{
					if (result[i] != result[i-1] + 1 )
		{
			cout << "wrong" << endl;
		}
		}

	}
	
	cout << endl;
}
