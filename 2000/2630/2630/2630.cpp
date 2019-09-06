#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int zeroCount, oneCount;

bool isAllSame(bool** board, int Y, int X, int size) {
	for (int i = Y; i < Y + size; i++) {
		for (int j = X; j < X + size; j++) {
			if (board[i][j] != board[Y][X]) return false;
		}
	}
	return true;
}
void boardCount(bool** board, int Y, int X, int size) {
	if (isAllSame(board, Y, X, size))
		board[Y][X] == true ? oneCount++ : zeroCount++;
	else {
		boardCount(board, Y, X, size / 2);
		boardCount(board, Y, X + size / 2, size / 2);
		boardCount(board, Y + size / 2, X, size / 2);
		boardCount(board, Y + size / 2, X + size / 2, size / 2);
	}
}
int main() {
	int N;
	cin >> N;
	
	bool** board = new bool* [N];
	for (int i = 0; i < N; i++)
		board[i] = new bool[N];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	boardCount(board, 0, 0, N);

	printf("%d\n%d", zeroCount, oneCount);

	return 0;
}