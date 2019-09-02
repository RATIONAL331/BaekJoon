#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int calculate(bool vec[51][51], int ypos, int xpos) {
	bool cmp1 = true;
	bool cmp2 = false;

	int cmp1Cnt = 0;
	int cmp2Cnt = 0;

	for (int i = ypos; i < ypos + 8; i++) {
		if (i % 2 == 0) {
			for (int j = xpos; j < xpos + 8; j++) {
				if (cmp1 != vec[i][j])
					cmp1Cnt++;
				if (cmp2 != vec[i][j])
					cmp2Cnt++;
				cmp1 = !cmp1;
				cmp2 = !cmp2;
			}
		}
		else {
			for (int j = xpos + 7; j >= xpos; j--) {
				if (cmp1 != vec[i][j])
					cmp1Cnt++;
				if (cmp2 != vec[i][j])
					cmp2Cnt++;
				cmp1 = !cmp1;
				cmp2 = !cmp2;
			}
		}
	}

	return min(cmp1Cnt, cmp2Cnt);
}

int main() {
	int N, M;
	cin >> N >> M;
	bool vec[51][51];

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++)
			str[j] == 'W' ? vec[i][j] = true : vec[i][j] = false;
	}

	int minVal = 987654321;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			minVal = min(minVal, calculate(vec, i, j));
		}
	}

	cout << minVal;

	return 0;
}