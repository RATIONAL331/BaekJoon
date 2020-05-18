#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	
	int cnt = 0;
	while (true) {
		if (A > B) {
			cout << -1;
			break;
		}
		if (A == B) {
			cout << cnt + 1;
			break;
		}
		if (B % 10 == 1) {
			B /= 10;
		}
		else if (B % 2 == 0) {
			B /= 2;
		}
		else {
			cout << -1;
			break;
		}
		++cnt;
	}

	return 0;
}