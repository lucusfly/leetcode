#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;

string simplifyPath(string path) {
	stringstream ss(path);
	string temp;
	vector<string> result;
	while(getline(ss, temp, '/'))
	{
		if (temp == "" || temp == ".")
		{
			continue;
		}
		
		if (temp == "..")
		{
			if (!result.empty())
			{
				result.pop_back();
			}
			
			continue;
		}
		
		result.push_back(temp);
	}
		
	if (result.empty())
	{
		return "/";
	}
	
	ostringstream ssresult; 
	for (int i = 0; i < result.size(); i++)
	{
		ssresult << '/' << result[i];
	}
	
	return ssresult.str();
}

int main()
{
	cout << simplifyPath("/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///") << endl;
}
