#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
int compare(const void * left, const void * right) {
	int * tmpLeft = (int*)left;
	int * tmpRight = (int*)right;
	if (*tmpLeft > *tmpRight) return 1;
	else if (*tmpLeft < *tmpRight) return -1;
	else return 0;
}
int gcd(int a, int b) {
	if (a < b)return gcd(b, a);
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
void printNumDivide(int num) {
	std::vector<int> vec;
	for (int i = 1; i <= std::sqrt(num); i++) {
		if (num % i == 0) {
			vec.push_back(i);
			vec.push_back(num / i);
		}
	}
	if (vec.at(vec.size() - 1) == vec.at(vec.size() - 2)) vec.pop_back();
	std::sort(vec.begin(), vec.end());
	for (int N : vec) if (N != 1) std::cout << N << " ";
}
int main() {
	int N;
	std::cin >> N;

	int num;
	int * numArr = new int[N];
	for (int i = 0; i < N; i++) {
		std::cin >> num;
		numArr[i] = num;
	}
	std::qsort(numArr, N, sizeof(int), compare);
	int GCD = numArr[1] - numArr[0];
	for (int i = 2; i < N; i++) {
		GCD = gcd(GCD, numArr[i] - numArr[i - 1]);
	}
	printNumDivide(GCD);

	delete[] numArr;
	return 0;
}