#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findAnagrams(string s, string p) {
	int pMap[26] = {0};
	vector<int> result;
	
	for (int i = 0; i < p.length(); i++)
	{
		pMap[p[i] - 'a']++;
	}
	
	int cout = p.length();
	for (int i = 0; i < s.length(); i++)
	{
		if (pMap[s[i] - 'a'] > 0)
		{
			cout --;
		}
		
		pMap[s[i] - 'a']--;
				
		if (i >= p.length())
		{
			if (pMap[s[i - p.length()] - 'a'] >= 0)
			{
				cout++;
			}
			
			pMap[s[i - p.length()] - 'a']++;
		}
				
		if (cout == 0)
		{
			result.push_back(i - p.length() +1);
		}
	}
	
	return result;
}

int main()
{
	vector<int> result = findAnagrams("cbaebabacd", "abc");
	
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
}
