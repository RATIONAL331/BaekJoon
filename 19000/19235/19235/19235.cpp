#include<iostream>
#include<vector>
using namespace std;

int RESULT = 0;

void shifting(vector<vector<int>>& board) {
	int overflowCount = 0;
	for (int i = 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != 0) {
				overflowCount = 2 - i;
			}
		}
	}
	if (overflowCount == 0) return;
	for (int i = 5 - overflowCount; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			board[i + overflowCount][j] = board[i][j];
			board[i][j] = 0;
		}
	}
}

void dropping(vector<vector<int>>& board) {
	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (board[i][j] != 0) {
				int type = board[i][j]; 
				int savedI = i; 
				int	savedJ = j;
				if (type == 1 || type == 3) {
					while (savedI + 1 <= 5 && board[savedI + 1][savedJ] == 0)
						savedI++;
					
					board[i][j] = 0;
					board[savedI][savedJ] = type;
					if (i != 0 && type == 3 && board[i - 1][j] == 3) {
						board[i - 1][j] = 0;
						board[savedI - 1][savedJ] = type;
					}
				}
				else if (type == 2) {
					while (savedI + 1 <= 5 && board[savedI + 1][savedJ] == 0 && board[savedI + 1][savedJ + 1] == 0)
						savedI++;

					board[i][j] = 0;
					board[i][j + 1] = 0;
					board[savedI][savedJ] = 2;
					board[savedI][savedJ + 1] = 2;
					j++;
				}
			}
		}
	}
}

bool checking(vector<vector<int>>& board) {
	bool checkDelLine = false;
	for (int i = 5; i >= 2; i--) {
		bool checkOneLine = true;
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 0) {
				checkOneLine = false;
			}
		}
		if (checkOneLine) {
			for (int j = 0; j < 4; j++) {
				board[i][j] = 0;
			}
			checkDelLine = true;
			RESULT++;
		}
	}
	if (checkDelLine) return false;
	else return true;
}

void holding(vector<vector<int>>& board, int t, int x, int y) {
	board[x][y] = t;
	if (t == 2) board[x][y + 1] = t;
	else if (t == 3) board[x + 1][y] = t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<vector<int>> greenBoard, blueBoard;
	greenBoard.resize(6);
	blueBoard.resize(6);
	for (int i = 0; i < 6; i++) {
		greenBoard[i].resize(4);
		blueBoard[i].resize(4);
	}

	int N;
	cin >> N;
	while (N--) {
		int t, x, y;
		cin >> t >> x >> y;
		// 벽돌 두기
		holding(greenBoard, t, 0, y);
		switch (t) {
		case 1:
			holding(blueBoard, 1, 0, 3 - x);
			break;
		case 2:
			holding(blueBoard, 3, 0, 3 - x);
			break;
		case 3:
			holding(blueBoard, 2, 0, 2 - x);
			break;
		}
		// 벽돌 내리기, 라인 완성 확인
		while (true) {
			dropping(greenBoard);
			if (checking(greenBoard)) break;
		}
		while (true) {
			dropping(blueBoard);
			if (checking(blueBoard)) break;
		}
		// 오버플로우 확인
		shifting(greenBoard);
		shifting(blueBoard);
	}

	int blockCount = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (greenBoard[i][j]) blockCount++;
			if (blueBoard[i][j]) blockCount++;
		}
	}
	cout << RESULT << '\n' << blockCount;

	return 0;
}