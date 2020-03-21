#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

int N, M, B;
vector<vector<int>> vec;

pair<int, int> addBlockCount(int height) {
	int adding = 0;
	int mining = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vec[i][j] < height)
				adding += height - vec[i][j];
			if (vec[i][j] > height)
				mining += vec[i][j] - height;
		}
	}
	return { adding, mining };
}

int main() {
	cin >> N >> M >> B;
	vec.resize(N);
	for (int i = 0; i < N; i++)
		vec[i].resize(M);

	int minH = 987654321;
	int maxH = -987654321;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> vec[i][j];
			if (minH > vec[i][j])
				minH = vec[i][j];
			if (maxH < vec[i][j])
				maxH = vec[i][j];
		}
	}

	int minValue = 987654321;
	int maxHeight = -1;
	for (int elem = minH; elem <= maxH; elem++) {
		auto addBlock = addBlockCount(elem);

		if (addBlock.first <= B + addBlock.second) {
			if (minValue >= addBlock.first + addBlock.second * 2) {
				minValue = addBlock.first + addBlock.second * 2;
				maxHeight = elem;
			}
		}
		else {
			break;
		}
	}

	cout << minValue << " " << maxHeight;

	return 0;
}