#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void binarySearch(vector<pair<int, int>>& info, int find, int from ,int to) {
	if (from > to) return;
	
	if (from == to) {
		if (info[from].first == find) 
			cout << info[from].second << " ";
		else
			cout << 0 << " ";

		return;
	}

	int mid = (from + to) / 2;
	if (info[mid].first > find)
		binarySearch(info, find, from, mid);
	else if (info[mid].first < find)
		binarySearch(info, find, mid + 1, to);
	else {
		cout << info[mid].second << " ";
		return;
	}
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> cards(N);
	for (int i = 0; i < N; i++)
		cin >> cards[i];
	sort(cards.begin(), cards.end());

	vector<pair<int, int>> info;
	int beforeNum = cards[0];
	int beforeIdx = 0;
	info.push_back({ cards[0], 1 });
	for (int i = 1; i < N; i++) {
		if (cards[i] == beforeNum) {
			info[beforeIdx].second++;
		}
		else {
			beforeNum = cards[i];
			beforeIdx++;
			info.push_back({ cards[i], 1});
		}
	}

	int M;
	cin >> M;

	int find;
	while (M--) {
		cin >> find;
		binarySearch(info, find, 0, info.size() - 1);
	}

	return 0;
}