#include<iostream>
using namespace std;
bool isContinuous(int num) {
	if (num < 666) return false;

	int k = 0;
	while (num != 0) {
		int tmp = num % 10;

		if (tmp == 6) {
			k++;
			if (k >= 3)return true;
		}
		else 
			k = 0;

		num /= 10;
	}
	return false;
}
int main() {
	int N;
	cin >> N;

	int find = 0;

	int num = 1;
	while (find != N) {
		if (isContinuous(num++))
			find++;
	}

	cout << num - 1;

	return 0;
}


//#include <cstdio>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> v;
//
//int main() {
//	int n;
//
//	scanf("%d", &n);
//
//	for (int i = 0; i <= 10000; ++i) {
//		v.push_back(i * 1000 + 666);
//		v.push_back(i / 10 * 10000 + 6660 + i % 10);
//		v.push_back(i / 100 * 100000 + 66600 + i % 100);
//		v.push_back(i / 1000 * 1000000 + 666000 + i % 1000);
//		v.push_back(i / 10000 * 10000000 + 6660000 + i % 10000);
//	}
//
//	sort(v.begin(), v.end());
//	unique(v.begin(), v.end());
//
//	printf("%d", v[n - 1]);
//
//	return 0;
//}