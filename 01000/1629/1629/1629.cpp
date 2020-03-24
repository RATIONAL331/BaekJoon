#include<iostream>
using namespace std;

long long A, B, C;

long long mulPow(long long A, long long num) {
	if (num == 0) return 1;

	long long ret = 1;
	if (num % 2 == 1) {
		num--;
		ret *= A;
		ret %= C;
	}

	long long tmp = mulPow(A, num / 2) % C;
	return (ret * ((tmp * tmp) % C) % C);
}

int main() {
	cin >> A >> B >> C;
	cout << mulPow(A, B);
	return 0;
}