#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int X, Y;
	
	map<int, int> xMap;
	map<int, int> yMap;
	
	for (int i = 0; i < 3; i++) {
		cin >> X >> Y;
		xMap[X]++;
		yMap[Y]++;
	}

	int retX = 0, retY = 0;
	for (auto it : xMap) {
		if (it.second == 1)
			retX = it.first;
	}
	for (auto it : yMap) {
		if (it.second == 1)
			retY = it.first;
	}

	cout << retX << " " << retY;

	return 0;
}