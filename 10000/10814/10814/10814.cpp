#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, pair<int, string>>> vec;

	int age; string name;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		vec.push_back({ age ,{i, name} });
	}

	sort(vec.begin(), vec.end());

	for (auto& elem : vec) {
		cout << elem.first << " " << elem.second.second << '\n';
	}
	return 0;
}