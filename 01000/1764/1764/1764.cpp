#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	map<string, int> dict;

	string name;
	for (int i = 0; i < N + M; i++) {
		cin >> name;
		dict[name]++;
	}

	int cnt = 0;
	vector<string> res;
	for (auto elem : dict)
		if (elem.second == 2)
			res.push_back(elem.first);

	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (auto elem : res)
		cout << elem << '\n';

	return 0;
}