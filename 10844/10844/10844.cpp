#include<iostream>
const int DIVISION = 1000000000;
int main() {
	int N;
	std::cin >> N;
	// df�ʱ�ȭ
	long long df[10]; long long d[10];
	df[0] = 0; d[0] = 0; for (int idx = 1; idx < 10; idx++) { df[idx] = 1; d[idx] = 1; }
	
	for (int i = 1; i < N; i++) {
		// ù��° ����
		df[0] = d[1];
		// �߰� ����
		for (int idx = 1; idx < 9; idx++) df[idx] = (d[idx - 1] + d[idx + 1]) % DIVISION;
		// ������ ����
		df[9] = d[8];
		for (int save = 0; save < 10; save++) d[save] = df[save];
	}
	long long ret = 0;
	for (int i = 0; i < 10; i++) {
		ret += df[i];
		ret = ret % DIVISION;
	}
	std::cout << ret;
	return 0;
}