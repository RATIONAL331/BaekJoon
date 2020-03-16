#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>> S;

int main() {
	cin >> N;
	S.resize(N);
	for (int i = 0; i < N; i++)
		S[i].resize(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> S[i][j];
	}

	// 0과 1로만 이루어진 순열 생성하기
	vector<int> per(N);
	for (int i = N / 2; i < N; i++)
		per[i] = 1;

	int minValue = 987654321;
	do {
		vector<int> Team1, Team2;
		for (int elem = 0; elem < N; elem++) {
			if (per[elem] == 0)
				Team1.push_back(elem);
			else
				Team2.push_back(elem);
		}

		int Team1Score = 0, Team2Score = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i != j) {
					Team1Score += S[Team1[i]][Team1[j]];
					Team2Score += S[Team2[i]][Team2[j]];
				}
			}
		}
		minValue = min(minValue, abs(Team1Score - Team2Score));
	} while (next_permutation(per.begin(), per.end()));

	cout << minValue;

	return 0;
}