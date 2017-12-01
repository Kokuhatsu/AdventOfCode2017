#include<iostream>
#include<string>

using namespace std;

template <int K>
int part(string);

template <>
int part<1>(string text)
{
	int sum = 0;

	text += text[0];

	for (int i = 0; i < text.size() -1; ++i)
		if (text[i] == text[i +1]) sum += text[i] -'0';

	return sum;
}

template <>
int part<2>(string text)
{
	int sum = 0;
	int offset = text.size() /2;

	for (int i = 0; i < offset; ++i)
		if (text[i] == text[i +offset]) sum += text[i] -'0';

	return sum *2;
}

int main()
{
	int select;
	string text;

	cin >> select >> text;

	switch (select)
	{
		case 1:
			cout << part<1>(text) << endl;
			break;
		case 2:
			cout << part<2>(text) << endl;
			break;
		default:
			throw "Unsupported choice";
	}

	return 0;
}