#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << '*';
		return 0;
	}
	else {
		char** board = new char* [2 * N];
		for (int i = 0; i < 2 * N; i++) {
			board[i] = new char[N];
		}
		for (int i = 0; i < 2 * N; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = ' ';
			}
		}

		int i;
		for (int j = 0; j < N; j++) {
			for (j % 2 == 0 ? i = 0 : i = 1; i < 2 * N; i += 2) {
				board[i][j] = '*';
			}
		}

		for (int i = 0; i < 2 * N; i++) {
			for (int j = 0; j < N; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}

		for (int i = 0; i < 2 * N; i++) {
			delete[] board[i];
		}
		delete[] board;
	}
	return 0;
}