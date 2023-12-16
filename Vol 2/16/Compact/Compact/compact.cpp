#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void loadFile(vector<int> &list);
void compact (vector<int> &list, int &N);


int main()
{
	vector<int> nums(0);
	loadFile(nums);
	nums.push_back(0);

	cout << "Before: ";
	cout << nums[0];

	for (int i = 1; i < nums.size(); i++)
	{
		cout << ", " << nums[i];	
	}
	cout << endl;

	int size = nums.size();
	compact(nums, size);

	cout << "After: ";
	cout << nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		cout << ", " << nums[i];
	}
	cout << endl;
}

void loadFile(vector<int> &list)
{
	ifstream infile;
	infile.open("compact.txt", ios::in);

	int temp;
	while (infile >> temp)
		list.push_back(temp);
}

void compact(vector<int> &list, int& N)
{
	while (N > 0)
	{
		if (list[N - 1] == 0)
		{
			for (int i = N; i < list.size(); i++)
			{
				list[N - 1] = list[N];
			}
			list.resize(list.size() - 1);
		}
		N--;
	}

}