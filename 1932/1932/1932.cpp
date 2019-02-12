#include<iostream>
#include<algorithm>
int max(int* list, int length) {
	int ret = list[0];
	for (int idx = 1; idx < length; idx++) {
		if (ret < list[idx]) ret = list[idx];
	}
	return ret;
}
int main() {
	int n;
	std::cin >> n;
	// �ﰢ�� ��� �迭 ����
	int ** triangle = new int*[n];
	for (int i = 1; i <= n; i++) {
		triangle[i - 1] = new int[i];
	}
	// dp����
	int ** dp = new int*[n];
	for (int i = 1; i <= n; i++) {
		dp[i - 1] = new int[i];
	}
	// �ﰢ�� �ֱ�
	int num;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			std::cin >> num;
			triangle[i - 1][j - 1] = num;
		}
	}
	// dp�ʱ�ȭ
	dp[0][0] = triangle[0][0];
	// dp���
	for (int i = 1; i < n; i++) {
		// ���� ù��° ���Ҵ� �׻� ������ ù��° ���� �޴´�.
		dp[i][0] = triangle[i][0] + dp[i - 1][0];
		// ���� �߰� ���Ҵ� �� ���� �� ���� ū ���� �޴´�.
		for (int j = 1; j <= i - 1; j++) {
			dp[i][j] = triangle[i][j] + std::max(dp[i - 1][j - 1], dp[i - 1][j]);
		}
		// ���� ������ ���Ҵ� �׻� �� ���� ������ ���� �޴´�.
		dp[i][i] = triangle[i][i] + dp[i - 1][i - 1];
	}
	// �ִ밪 ���
	std::cout << max(dp[n - 1], n);

	// �����迭 ����
	for (int i = 0; i < n; i++) {
		delete[] dp[i];
	}
	delete[] dp;
	for (int i = 0; i < n; i++) {
		delete[] triangle[i];
	}
	delete[] triangle;
	return 0;
}