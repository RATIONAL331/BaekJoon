#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string dist(vector<int>& vec) {
	if (vec[0] + vec[1] < vec[2])
		return "wrong";

	if (vec[0] * vec[0] + vec[1] * vec[1] == vec[2] * vec[2])
		return "right";

	return "wrong";
}

int main() {
	int X, Y, Z;
	while (true) {
		cin >> X >> Y >> Z;
		if (X == 0 && Y == 0 && Z == 0)
			return 0;

		vector<int> vec;
		vec.push_back(X); vec.push_back(Y); vec.push_back(Z);

		sort(vec.begin(), vec.end());

		cout << dist(vec) << '\n';
	}
	return 0;
}