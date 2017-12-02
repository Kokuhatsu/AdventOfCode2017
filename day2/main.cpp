#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> split(const string& text)
{
	vector<int> pieces;

	string tmp = "";

	for (int i = 0; i < text.size(); ++i)
	{
		if (text[i] != '\t') tmp += text[i];
		else
		{
			pieces.push_back(stoi(tmp));
			tmp = "";
		}
	}
	pieces.push_back(stoi(tmp));
	return pieces;
}

template <int K>
int findChecksum(const string& data);

template <>
int findChecksum<1>(const string& data)
{
	int min = numeric_limits<int>::max();
	int max = numeric_limits<int>::min();

	vector<int> pieces = split(data);

	for (int i = 0; i < pieces.size(); ++i)
	{
		int tmp = pieces[i];
		if (tmp > max) max = tmp;
		if (tmp < min) min = tmp;
	}
	return max - min;
}

template <>
int findChecksum<2>(const string& data)
{
	int result = 0;

	vector<int> pieces = split(data);

	sort(pieces.begin(), pieces.end(), greater<int>());

	for (int i = 0; i < pieces.size() - 1; ++i)
		for (int j = i + 1; j < pieces.size(); ++j)
		{
			int a = pieces[i];
			int b = pieces[j];
			if (!(a % b)) result += a / b;
		}

	return result;
}

int main()
{
	string text;

	int checksum = 0;
	int select;

	cin >> select;
	cin.ignore();

	while (getline(cin, text))
	{
		switch (select)
		{
			case 1:
				checksum += findChecksum<1>(text);
				break;
			case 2:
				checksum += findChecksum<2>(text);
				break;
			default:
				throw "Unsupported choice";
		}
	}

	cout << checksum << endl;
	return 0;
}