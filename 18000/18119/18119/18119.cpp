#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int N, M;
vector<map<char, int>> wordList;
int main() {
	cin >> N >> M;
	wordList.resize(N);

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (char c : str)
			wordList[i][c] = 1;
	}

	int op;
	char x;
	while (M--) {
		cin >> op >> x;
		if (op == 1) {
			for (int i = 0; i < N; i++) {
				// wordList�� ���ĺ��� �����Ѵٸ� ���ҽ�Ű�� �ƴϸ� �����Ѵ�.
				if(wordList[i].find(x) != wordList[i].end())
					wordList[i][x] = 0;
			}	
		}
		else {
			for (int i = 0; i < N; i++)
				// wordList�� ���ĺ��� �����Ѵٸ� ������Ű�� �ƴϸ� �����Ѵ�.
				if (wordList[i].find(x) != wordList[i].end())
					wordList[i][x] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cnt++;
			for (const auto& elem : wordList[i]) {
				if (elem.second == 0) {
					cnt--;
					break;
				}			
			}		
		}
		cout << cnt << '\n';
	}
	return 0;
}