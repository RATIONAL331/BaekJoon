#include<iostream>
#include<algorithm>
int calculate(int * fileArr, int ** dp, int A, int B, int * sumArr) {
	// A ~ B까지 합하는 과정에서 A가 B보다 더 크면 애초에 합칠 수 없고,
	// 같은 번호를 합친다면 애초에 합칠 이유가 없으므로 0으로 한다.
	if (A >= B) return 0;
	
	if (dp[A][B] != -1) return dp[A][B];

	// 합칠 파일이 두개 뿐이라면 두개의 파일을 더한 값이다.
	if (A + 1 == B) return dp[A][B] = fileArr[A] + fileArr[B];

	dp[A][B] = INT32_MAX;
	// A ~ B까지 합하는 과정은 {A ~ i}, {i + 1 ~ B}까지 합하는 과정중 최소값이다.
	// 결과값의 누적을 구하려면 A ~ B에 있는 모든 원소의 합을 누적해서 더해준다.
	for (int i = A; i <= B; i++) {
		dp[A][B] = std::min(dp[A][B], calculate(fileArr, dp, A, i, sumArr) + calculate(fileArr, dp, i + 1, B, sumArr) + sumArr[B] - sumArr[A - 1]);
	}
	return dp[A][B];
}
int main() {
	int T;
	std::cin >> T;

	int K;
	for (int i = 0; i < T; i++) {
		std::cin >> K;
		// Input Phase
		int fileSize;
		int * fileArr = new int[K + 1];
		int * sumArr = new int[K + 1];
		sumArr[0] = 0;
		for (int fileIdx = 1; fileIdx < K + 1; fileIdx++) {
			std::cin >> fileSize;
			fileArr[fileIdx] = fileSize;
			sumArr[fileIdx] = sumArr[fileIdx - 1] + fileSize;
		}
		// Init DP
		int ** dp = new int*[K + 1];
		for (int dpIdx = 0; dpIdx < K + 1; dpIdx++) {
			dp[dpIdx] = new int[K + 1];
		}
		for (int col = 0; col < K + 1; col++) {
			for (int row = 0; row < K + 1; row++) {
				dp[col][row] = -1;
			}
		}
		// Calculate
		std::cout << calculate(fileArr, dp, 1, K, sumArr) << std::endl;
		// Delete Array
		for (int dpIdx = 0; dpIdx < K + 1; dpIdx++) {
			delete[] dp[dpIdx];
		}
		delete[] dp;
		delete[] fileArr;
	}
	return 0;
}