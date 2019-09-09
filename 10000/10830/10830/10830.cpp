#include<iostream>
using namespace std;

int N;
long long B;
int** matrix;

int** matrixMul(int** matrixA, int** matrixB) {
	int** temp = new int*[N];
	for (int i = 0; i < N; i++) {
		temp[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				temp[i][j] = (temp[i][j] + matrixA[i][k] * matrixB[k][j]) % 1000;
			}
		}
	}
	return temp;
}

int** matrixExp(int** matrixTarget, long long exp) {
	if (exp == 1)
		return matrixTarget;
	int** tempMat = matrixExp(matrixTarget, exp / 2);
	tempMat = matrixMul(tempMat, tempMat);

	if (exp % 2 == 1) tempMat = matrixMul(tempMat, matrixTarget);
	return tempMat;
}



int main() {
	cin >> N >> B;

	matrix = new int* [N];
	for (int i = 0; i < N; i++) {
		matrix[i] = new int[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> matrix[i][j];
		}
	}

	int** temp = matrixExp(matrix, B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", temp[i][j] % 1000);
		}
		printf("\n");
	}

	return 0;
}