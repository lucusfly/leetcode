#include <iostream>
#include <vector>

using namespace std;



void printvector(vector<int> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << ",";
	}
	
	cout << endl;
}

int findPivot(vector<int>& a, int left, int right)
{
	int pivot = a[left];
	
	while(left < right)
	{	
		while(a[left] < pivot && left < right)
		{
			left++;
		}
		
		while(a[right] >= pivot && left < right)
		{
			right--;
		}
		
		swap(a[left], a[right]);			
	}
	
	a[left] = pivot;
	return left;
}

void qsort(vector<int>& a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	
	int pivot = findPivot(a, left, right);
	
	cout << pivot<<endl;
	
	qsort(a, left, pivot-1);
	qsort(a, pivot+1, right);
}

int main()
{
	int numbers[] = {6,5,4,3,2,1};
	vector<int> a(numbers, numbers + sizeof(numbers) / sizeof(int));
		
	printvector(a);
	
	qsort(a, 0, a.size()-1);
	printvector(a);
	
}
