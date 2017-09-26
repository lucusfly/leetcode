#include <iostream>
#include <vector>
#include <string>

using namespace std;
 
	
bool isAnagram(string s, string t) {
    int s1[26] = {0};
    int t2[26] = {0};
        
    for (int i = 0; i < s.length(); i++)
    {
    	s1[s[i]-'a']++;
	}
	
	for (int i = 0; i < t.length(); i++)
	{
		t2[t[i]-'a']++;
	}
	
	for (int i = 0; i < 26; i++)
	{
		//cout << s1[i] << "," << t2[i] << endl;
		if (s1[i] != t2[i])
		{
			return false;
		}
	}
	
	return true;
}

bool detectCapitalUse(string word) {
	if (word.length() == 0)
	{
		return true;
	}
	if (word.length() > 0)
	{
		if (word[0] >= 'a' && word[0] <= 'z')
		{
			for (int i = 1; i < word.length(); i++)
			{
				if (word[i] >= 'A' && word[i] <= 'Z')
				{
					return false;
				}
			}
		}
		else {
			if (word.length() > 1)
			{
				if (word[1] >= 'a' && word[1] <= 'z')
				{
					for (int i = 2; i < word.length(); i++)
					{
						if (word[i] >= 'A' && word[i] <= 'Z' )
						{
							return false;
						}
					}
				}
				else
				{
					for (int i = 2; i < word.length(); i++)
					{
						if (word[i] >= 'a' && word[i] <= 'z')
						{
							return false;
						}
					}
				}
			}
			else
			{
				return true;
			}
		}
	}
	
	return true;
}
    
int main()
{
	cout << detectCapitalUse("") << endl;
}
