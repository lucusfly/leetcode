#include <iostream>
#include <vector>
#include <string>

using namespace std;

int lengthLongestPath(string input) {
	vector<int> deep;
	
	int maxLength = 0;
	int i = 0;
	while(i < input.length()) 
	{
		int currDeep = 0;
		while (input[i] == '\t')
		{
			i++;
			currDeep++;
		}
		
		string dir = "";
		bool isFile = false;
		while (input[i] != '\n' && i < input.length())
		{
			dir += input[i];
			if (input[i] == '.')
			{
				isFile = true;
			}
			
			i++;
		}
		 
		if (!isFile)
		{
			if (deep.size() == currDeep)
			{
				deep.push_back(dir.length());
			}
			else
			{
				deep[currDeep] = dir.length();
			}
			
			//cout << currDeep << "," << dir.length() << endl;
		}
		else
		{
			int length = 0;
			for (int j = 0; j < currDeep; j++)
			{
				length += deep[j] + 1;
			}
			
			length += dir.length();
			
			//cout << "length " << currDeep << "," << length << endl; 
			
			if (length > maxLength)
			{
				maxLength = length;
			}
		}
		
		i++;
	}
	
	return maxLength;
}

int minSteps(int n) {
	if (n == 1)
	{
		return 0;
	}
	
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			return minSteps(n/i) + i;
		}
	}
}

int main()
{
	/*
	cout << lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
	cout << lengthLongestPath("dir") << endl;
	cout << lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext") << endl;
	cout << lengthLongestPath("a\n\taa\n\t\taaa\n\t\t\tfile1.txt\naaaaaaaaaaaaaaaaaaaaa\n\tsth.png") << endl;
	*/
	
	cout << minSteps(10) << endl;
} 






