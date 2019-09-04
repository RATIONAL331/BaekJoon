#include<iostream>
#include<algorithm>
int main() {
	int n;
	std::cin >> n;
	// �迭 ����
	int * stair = new int[n];
	int * dp = new int[n];
	// �Է¹ޱ�
	int num;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		stair[i] = num;
	}
	// dp�ʱ�ȭ
	dp[0] = stair[0];
	// dp ���
	for (int i = 1; i < n; i++) {
		if (i < 3) {
			if (i == 2) {
				// ����� 3���� ��� 3��° 1��° ����� ��� ���, �Ǵ� 2��° 3��° ����� ��� ��찡 �ִ�.
				dp[i] = std::max(stair[i] + stair[i-1], stair[i] + stair[i-2]);
			}
			else {
				// ����� 2���� ��� �� ��° ����� �״�� �����ش�.
				dp[i] = stair[i-1] + stair[i];
			}
		}
		else {
			// ����� 4�� �̻��� ��� �ϴ� ���� ����� ���� + (�� �ٷ� �� �ܰ��� ���� + 3 ���ܰ��� �� ������ �� ) �Ǵ� (2�� �ܰ��� ��)�� �ִ��� ���Ѵ�. 
			dp[i] = stair[i] + std::max(dp[i - 2], stair[i-1] + dp[i - 3]);
		}
	}
	std::cout << dp[n - 1];
	// ���� �迭 ����
	delete[] dp;
	delete[] stair;
	return 0;
}