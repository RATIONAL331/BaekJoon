#include<iostream>
using namespace std;

int solve(int x1, int y1, int r1, int x2, int y2, int r2) {
	int distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

	if (r1 > r2) swap(r1, r2);
	int radiusSum = (r1 + r2) * (r1 + r2);
	int radiusSub = (r2 - r1) * (r2 - r1);

	if (distance == 0) {
		if (r1 == r2)
			return -1;
		else return 0;
	}
	else if (distance < radiusSum && distance > radiusSub)
		return 2;
	else if (distance == radiusSum || distance == radiusSub)
		return 1;
	else 
		return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	
	int x1, y1, r1, x2, y2, r2;
	while (T--) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << solve(x1, y1, r1, x2, y2, r2) << endl;
	}
	return 0;
}