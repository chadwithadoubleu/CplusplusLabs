#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void loadFile(vector<int> &list);

int main()
{
	vector<int> nums(0);
	loadFile(nums);
	
	int mode = 0;
	long total = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] > mode)
			mode = nums[i];
		total += nums[i];
	}
	
	double avg = (float)total / nums.size();
	double totalDif = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		totalDif += pow(avg - nums[i],2);
	}

	double standardDev = sqrt(totalDif / (nums.size() - 1));

	cout << fixed << setprecision(2);
	cout << "Average:            " << avg << endl;
	cout << "Standard Deviation: " << standardDev << endl;
	cout << "Mode:               " << mode << endl;
}

void loadFile(vector<int> &list)
{
	ifstream infile;
	infile.open("numbers.txt", ios::in);
	int temp;
	while (infile >> temp)
	{
		list.push_back(temp);
	}
}