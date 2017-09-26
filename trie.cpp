#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define Count 26

class Trie {
private:
	bool isLeaf = false;
	Trie* children[Count];
public:

	
    /** Initialize your data structure here. */
    Trie() {
        for (int i = 0; i < Count; i++)
        {
        	children[i] = NULL;
		}
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
    	Trie* node = this;
    	
    	for (int i = 0; i < word.length(); i++)
    	{
    		int child = word[i] - 'a';
			if (node->children[child] == NULL)
			{
				node->children[child] = new Trie();
			}
			
			node = node->children[child];
		}
		
		node->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
    	if (word.length() == 0)
    	{
    		return true;
		}
    	
    	Trie* node = this;
        for (int i = 0; i < word.length(); i++)
        {
        	int child = word[i] - 'a';
        	if (node == NULL)
        	{
        		return false;
			}
			else
			{
				node = node->children[child];
			}
		}
		
		if (node == NULL)
		{
			return false;
		}
		else
		{
			return node->isLeaf;	
		}
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
    	if (prefix.length() == 0)
    	{
    		return true;
		}
    	
        Trie* node = this;
        for (int i = 0; i < prefix.length(); i++)
        {
        	int child = prefix[i] - 'a';
        	if (node->children[child] == NULL)
        	{
        		return false;
			}
			else
			{
				//cout << (char)('a' + child) << endl;
				node = node->children[child];
			}
		}
		
		return true;
    }
};

void dfs(vector<vector<char> >& board, vector<vector<bool> >& foot, set<string>& result, string cur, int i, int j, Trie& obj)
{
	if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || foot[i][j])
	{
		return;
	}
	
	cur += board[i][j];
	if (!obj.startsWith(cur))
	{
		return;
	}
	
	if (obj.search(cur))
	{
		result.insert(cur);
	}	
	
	foot[i][j] = true;
	
	dfs(board, foot, result, cur, i-1, j, obj);
	dfs(board, foot, result, cur, i+1, j, obj);
	dfs(board, foot, result, cur, i, j-1, obj);
	dfs(board, foot, result, cur, i, j+1, obj);
	
	foot[i][j] = false;
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    vector<vector<bool> > foot(board.size());
    for (int i = 0; i < board.size(); i++)
    {
    	foot[i] = vector<bool>(board[i].size());
    	for (int j = 0; j < foot[i].size(); j++)
    	{
    		foot[i][j] = false;
		}
	}
	
	Trie obj;
	for (int i = 0; i < words.size(); i++)
	{
		obj.insert(words[i]);
	}
	
	set<string> result;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			string cur = "";
			dfs(board, foot, result, cur, i, j, obj);
		}
	}
	
	vector<string> re;
	for(set<string>::iterator it = result.begin(); it != result.end(); it++)
	{
		re.push_back(*it);
	}
	
	return re;
}

int main()
{
	char b[5] = { 'b', 'a', 'b', 'b', 'a'};
	
	string c[5] = {
		"bbaaba","bbabaa","bbbbbb","aaabaa","abaabb"
	};
	
	string d[4] = {
		"oaan", "etae", "ihkr", "iflv"
	};
	
	vector<vector<char> > array;
	for (int i = 0; i < 5; i++)
	{
		array.push_back(vector<char>());
		for (int j = 0; j < 6; j++)
		{
			array[i].push_back(c[i][j]);
			
			cout << array[i][j] << ',';
		}
		
		cout << endl;
	}
	
	vector<string> words;
	words.push_back("aabb");
	words.push_back("bbaab");
	words.push_back("eat");
	words.push_back("rain");
	vector<string> result = findWords(array, words);
	
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
}





























