#include<iostream>
#include<vector>
using namespace std;

struct info {
	int weight;
	int height;
	int rank;
	bool operator>(const info& obj) const {
		if (weight > obj.weight && height > obj.height) return true;
		else return false;
	}
};
int main() {
	int N;
	cin >> N;

	vector<info> vec(N);

	int weight, height;
	for (int i = 0; i < N; i++) {
		cin >> weight >> height;
		vec[i] = { weight, height, 1 };
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (vec[j] > vec[i]) vec[i].rank++;
		}
	}

	for (auto obj : vec) cout << obj.rank << " ";

	return 0;
}