/*
6
1 2 3 4 1 6
7 8 9 1 4 2
2 3 4 1 1 3
6 6 6 6 9 4
9 1 9 1 9 5
1 1 1 1 9 9
*/

#include<iostream>
#include<algorithm>
using namespace std;

int N;
// x���� ���Ʒ�, y���� �޿�, d1�� ��������, d2�� �����޾�
bool check(int x, int y, int d1, int d2) {
	// x == y == 0 or x == y == N - 1 �̸� ���� �� ����
	if ((x == 0 || x == N - 1) && (x == y)) return false;
	// CASE 1
	if (x + d1 >= N || y - d1 < 0) return false;
	// CASE 2
	if (x + d2 >= N || y + d2 >= N) return false;
	// CASE 3
	if (x + d1 + d2 >= N || y - d1 + d2 >= N || y - d1 + d2 < 0) return false;
	// CASE 4
	if (x + d1 + d2 >= N || y + d2 - d1 >= N || y + d2 - d1 < 0) return false;

	return true;
}

int leftUp(int** arr, int x, int y, int d1, int d2) {

}
int rightUp(int** arr, int x, int y, int d1, int d2) {

}
int midCenter(int** arr, int x, int y, int d1, int d2) {

}
int leftDown(int** arr, int x, int y, int d1, int d2) {

}
int rightDown(int** arr, int x, int y, int d1, int d2) {

}

int main() {
	/* INIT Phase */
	cin >> N;
	int** board = new int* [N];
	for (int i = 0; i < N; i++)
		board[i] = new int[N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}
	/* SOLVE Phase */
	// X���� ���Ʒ�, Y���� �޿�
	int result = INT32_MAX;

	for (int PIVOT_X = 0; PIVOT_X < N; PIVOT_X++) {
		for (int PIVOT_Y = 0; PIVOT_Y < N; PIVOT_Y++) {
			// d1���� X(����,����), d2���� Y(����,�޾�)
			for (int d1 = 1; d1 < N; d1++) {
				for (int d2 = 1; d2 < N; d2++) {
					//��ȹ�� 5���� �������� Ȯ���ϰ�, �ȵǸ� �ǳ� �ڴ�.
					if (!check(PIVOT_X, PIVOT_Y, d1, d2)) continue;
					
					int lu = leftUp(board, PIVOT_X, PIVOT_Y, d1, d2);
					int ru = rightUp(board, PIVOT_X, PIVOT_Y, d1, d2);
					int ce = midCenter(board, PIVOT_X, PIVOT_Y, d1, d2);
					int ld = leftDown(board, PIVOT_X, PIVOT_Y, d1, d2);
					int rd = rightDown(board, PIVOT_X, PIVOT_Y, d1, d2);

					int maxValue = max(lu, max(ru, max(ce, max(ld, rd))));
					int minValue = min(lu, min(ru, min(ce, min(ld, rd))));

					result = min(result, maxValue - minValue);
				}
			}	
		}
	}

	/* PRINT Phase */
	cout << result;
	/* FINAL Phase */
	for (int i = 0; i < N; i++)
		delete[] board[i];
	delete[] board;
	return 0;
}