#include<iostream>
int ** calculate(int** rc1, int** rc2, int n1, int m1, int n2, int m2) {
	if (m1 != n2) return nullptr;
	// 배열 생성
	int ** newrc = new int*[n1];
	for (int i = 0; i < n1; i++) {
		newrc[i] = new int[m2];
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			newrc[i][j] = 0;
		}
	}
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			for (int k = 0; k < m1; k++) {
				newrc[i][j] += rc1[i][k] * rc2[k][j];
			}
		}
	}
	return newrc;
}
int main() {
	int N1, M1;
	// 행렬A초기화
	std::cin >> N1 >> M1;
	int ** rc1 = new int*[N1];
	for (int i = 0; i < N1; i++) {
		rc1[i] = new int[M1];
	}
	int elem;
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < M1; j++) {
			std::cin >> elem;
			rc1[i][j] = elem;
		}
	}
	int N2, M2;
	// 행렬B초기화
	std::cin >> N2 >> M2;
	int** rc2 = new int*[N2];
	for (int i = 0; i < N2; i++) {
		rc2[i] = new int[M2];
	}
	for (int i = 0; i < N2; i++) {
		for (int j = 0; j < M2; j++) {
			std::cin >> elem;
			rc2[i][j] = elem;
		}
	}
	int** rc3 = calculate(rc1, rc2, N1, M1, N2, M2);
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < M2; j++) {
			std::cout << rc3[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < N1; i++) {
		delete[] rc3[i];
	}
	delete[] rc3;
	for (int i = 0; i < N2; i++) {
		delete[] rc2[i];
	}
	delete[] rc2;
	for (int i = 0; i < N1; i++) {
		delete[] rc1[i];
	}
	delete[] rc1;
	return 0;
}