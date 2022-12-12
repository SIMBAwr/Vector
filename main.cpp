
#include <iostream>
#include <vector>
#include "Vector.h"

using namespace std;

int main()
{
	Vector<int> v(2);

	//vector<int> vv;


	v[1] = 5;

	v.push_back(11);


	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	cout << "\n";
	v.pop_back();

	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	v.shrink_to_fit();

	v.insert(1, 78);

	cout << "\n";
	for (size_t i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}