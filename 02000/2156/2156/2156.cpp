#include<iostream>
#include<algorithm>
int main() {
	int n;
	std::cin >> n;

	int * glassArr = new int[n];
	int * df = new int[n];

	int glass;
	for (int i = 0; i < n; i++) {
		std::cin >> glass; 
		glassArr[i] = glass;
	}
	// df�ʱ�ȭ
	df[0] = glassArr[0]; df[1] = glassArr[1] + glassArr[0]; 
	df[2] = std::max(std::max(df[1], glassArr[2] + df[0]), glassArr[1] + glassArr[2]);
	// df����
	for (int i = 3; i < n; i++) {
		// ���� df��, ���� �����ϰ� �ִ� ���ΰ� + 2�ܰ� ��df��, ���� �����ϰ� �ִ� ���ΰ�, �� ���ΰ�, 3���ܰ��� df�� �� �ִ밪 ����
		df[i] = std::max(std::max(df[i - 1], glassArr[i] + df[i - 2]), glassArr[i] + glassArr[i - 1] + df[i - 3]);
	}
	std::cout << df[n - 1];
	delete[] df;
	delete[] glassArr;
	return 0;
}