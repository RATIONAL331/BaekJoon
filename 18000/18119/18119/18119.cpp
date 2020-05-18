#include<iostream>
#include<string>
#include<vector>
#include<bitset>
using namespace std;

int N, M;
vector<bitset<26>> wordList;
vector<bitset<26>> copyWordList;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	wordList.resize(N);

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (char c : str)
			wordList[i][(size_t)c - 'a'] = true;
	}

	copyWordList = wordList;

	int op;
	char x;
	while (M--) {
		cin >> op >> x;
		if (op == 1) {
			for (int i = 0; i < N; i++) {
				if (copyWordList[i][(size_t)x - 'a'] == true)
					wordList[i][(size_t)x - 'a'] = false;
			}
		}
		else {
			for (int i = 0; i < N; i++) {
				if (copyWordList[i][(size_t)x - 'a'] == true)
					wordList[i][(size_t)x - 'a'] = true;
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (copyWordList[i] == wordList[i])
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}