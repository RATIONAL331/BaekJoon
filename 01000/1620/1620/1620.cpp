#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

pair<string, int> dict[100'001];
string copied[100'001];

int binarySearch(pair<string, int> vec[100'001], string search, int start, int end) {
	if (start > end) return -1;
	int mid = (start + end) / 2;
	if (vec[mid].first > search) return binarySearch(vec, search, start, mid - 1);
	else if (vec[mid].first < search) return binarySearch(vec, search, mid + 1, end);
	return mid;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	string name;
	for (int i = 0; i < N; i++) {
		cin >> name;
		dict[i] = { name, i };
		copied[i] = name;
	}

	sort(dict, dict + N);

	string opt;
	while (M--) {
		cin >> opt;
		/*if (isalpha(opt[0]))
			cout << dict[binarySearch(dict, opt, 0, N - 1)].second + 1 << '\n';
		else
			cout << copied[stoi(opt) - 1] << '\n';*/
		try {
			int num = stoi(opt);
			cout << copied[num - 1] << '\n';
		}
		catch (invalid_argument) {
			cout << dict[binarySearch(dict, opt, 0, N - 1)].second + 1 << '\n';
		}
	}
	return 0;
}