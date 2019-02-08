#include<iostream>
int numOfTwo(int num) {
	int cnt = 0;
	while (num % 2 == 0) {
		cnt++;
		num /= 2;
	}
	return cnt;
}
int numOfFive(int num) {
	int cnt = 0;
	while (num % 5 == 0) {
		cnt++;
		num /= 5;
	}
	return cnt;
}
int main() {
	int N; 
	std::cin >> N;
	int two = 0, five = 0;
	for (int i = 1; i <= N; i++) {
		two += numOfTwo(i);
		five += numOfFive(i);
	}
	if (two > five) {
		std::cout << five;
	}
	else {
		std::cout << two;
	}
	return 0;
}