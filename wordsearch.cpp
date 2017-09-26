#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;


bool searchStart(vector<vector<char> >& board, vector<vector<bool> >& footprint, string word, int x, int y, int wordIndex)
{
	if (wordIndex >= word.length())
	{
		//cout << wordIndex << " " << x << " " << y << endl;
		return true;
	}
	
	if (x - 1 >= 0 && board[x-1][y] == word[wordIndex] && !footprint[x-1][y])
	{
		footprint[x-1][y] = true;
		if (searchStart(board, footprint, word, x-1, y, wordIndex+1))
		{
			return true;
		}
		
		footprint[x-1][y] = false;
	}
		
	if (x+1 < board.size() && board[x+1][y] == word[wordIndex] && !footprint[x+1][y])
	{
		footprint[x+1][y] = true;
		if (searchStart(board, footprint, word, x+1, y, wordIndex+1))
		{
			return true;
		}
		footprint[x+1][y] = false;
	}
	
	if (y-1 >= 0 && board[x][y-1] == word[wordIndex] && !footprint[x][y-1])
	{
		footprint[x][y-1] = true;
		if (searchStart(board, footprint, word, x, y-1, wordIndex+1))
		{
			return true;
		}
		
		footprint[x][y-1] = false;
	}
	
	if (y+1 < board[x].size() && board[x][y+1] == word[wordIndex] && !footprint[x][y+1])
	{
		footprint[x][y+1] = true;
		if (searchStart(board, footprint, word, x, y+1, wordIndex+1))
		{
			return true;
		}
		
		footprint[x][y+1] = false;
	}
	
	return false;
}

bool exist(vector<vector<char> >& board, string word) {
	if (word.length() == 0)
	{
		return true;
	}
	
	vector<vector<bool> > footprint;
	for (int i = 0; i < board.size(); i++)
	{
		footprint.push_back(vector<bool>());
		for (int j = 0; j < board[i].size(); j++)
		{
			footprint[i].push_back(false);
		}
	}
	 
        for (int i = 0; i < board.size(); i++)
        {
        	for (int j = 0; j < board[i].size(); j++)
        	{
        		if (board[i][j] == word[0])
        		{
        			footprint[i][j] = true;
        			if (searchStart(board, footprint, word, i, j, 1))
        			{
        				return true;
					}
					
					footprint[i][j] = false;
				}
			}
		}
		
		return false;
}


int main()
{
	string a[4] = {
		"oaan", "etae", "ihkr", "iflv"
	};
	
	vector<vector<char> > array;
	for (int i = 0; i < 4; i++)
	{
		array.push_back(vector<char>());
		for (int j = 0; j < 4; j++)
		{
			array[i].push_back(a[i][j]);
			
			cout << array[i][j] << ',';
		}
		
		cout << endl;
	}
	
	cout << exist(array, "eat") << endl;
	
	
}
