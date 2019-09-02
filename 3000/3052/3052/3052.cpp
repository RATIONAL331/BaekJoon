#include<iostream>
using namespace std;

int modula[42];

int main() {
	int num;
	for (int i = 0; i < 10; i++) {
		cin >> num;
		modula[num % 42]++;
	}

	int cnt = 0;
	for (int i = 0; i < 42; i++) {
		if (modula[i] != 0)
			cnt++;
	}

	cout << cnt;

	return 0;
}