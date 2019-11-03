#include<iostream>
#include<algorithm>
using namespace std;

int N;
// x값이 위아래, y값이 왼오, d1은 왼위오아, d2는 오위왼아
bool check(int x, int y, int d1, int d2) {
	// x == y == 0 or x == y == N - 1 이면 나눌 수 없음
	if ((x == 0 || x == N - 1) && (x == y)) return false;
	// CASE 1
	if (x + d1 >= N || y - d1 < 0) return false;
	// CASE 2
	if (x + d2 >= N || y + d2 >= N) return false;
	// CASE 3
	if (x + d1 + d2 >= N || y - d1 + d2 >= N || y - d1 + d2 < 0) return false;
	// CASE 4
	if (x + d1 + d2 >= N || y + d1 - d2 >= N || y + d1 - d2 < 0) return false;

	return true;
}

int leftUp(int** arr, int x, int y, int d1, int d2) {
	int sum = 0;

	int tmp = y;
	for (int i = 0; i < x + d1; i++) {	
		tmp = (i >= x ? tmp - 1 : tmp);
		for (int j = 0; j <= tmp; j++) {
			sum += arr[i][j];
		}	
	}

	return sum;
}
int rightUp(int** arr, int x, int y, int d1, int d2) {
	int sum = 0;
	
	int tmp = y + 1;
	for (int i = 0; i <= x + d2; i++) {	
		tmp = (i > x ? tmp + 1 : tmp);
		for (int j = N - 1; j >= tmp; j--) {
			sum += arr[i][j];
		}		
	}
	return sum;
}
int midCenter(int** arr, int x, int y, int d1, int d2) {
	int sum = 0;
	
	int cnt = 1;
	int tmp = 1;
	int y_pos = y;
	for (int i = x; i <= x + d1 + d2; i++) {
		for (int j = y_pos; j < y_pos + tmp; j++) {
			sum += arr[i][j];
		}
		if (cnt <= d1) {
			tmp++;
			y_pos--;
		}
		else {
			y_pos++;
			tmp--;
		}
		if (cnt <= d2) tmp++;
		else tmp--;

		cnt++;
	}

	return sum;
}
int leftDown(int** arr, int x, int y, int d1, int d2) {
	int sum = 0;

	int tmp = y - d1 - 1;
	for (int i = x + d1; i < N; i++) {
		for (int j = 0; j <= tmp; j++) {
			sum += arr[i][j];
		}
		tmp = (i >= x + d1 + d2 ? tmp : tmp + 1);
	}

	return sum;
}
int rightDown(int** arr, int x, int y, int d1, int d2) {
	int sum = 0;

	int tmp = y + d2;
	for (int i = x + d2 + 1; i < N; i++) {		
		for (int j = N - 1; j >= tmp; j--) {
			sum += arr[i][j];
		}	
		tmp = (i <= x + d1 + d2 ? tmp - 1 : tmp);
	}
	
	return sum;
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
	// X값은 위아래, Y값은 왼오
	int result = INT32_MAX;

	for (int PIVOT_X = 0; PIVOT_X < N; PIVOT_X++) {
		for (int PIVOT_Y = 0; PIVOT_Y < N; PIVOT_Y++) {
			// d1값은 X(왼위,오아), d2값은 Y(오위,왼아)
			for (int d1 = 1; d1 < N; d1++) {
				for (int d2 = 1; d2 < N; d2++) {
					//구획이 5개로 나뉘는지 확인하고, 안되면 건너 뛴다.
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