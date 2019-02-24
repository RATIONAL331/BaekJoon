#include<iostream>
#include<string>
int main() {
	int T;
	std::cin >> T;

	int row, col;
	for (int i = 0; i < T; i++) {
		std::cin >> row >> col;
		// ���� �迭 �����ϱ�
		char ** board = new char*[row];
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			board[rowIdx] = new char[col];
		}
		// �迭�ȿ� ���� �ֱ�
		std::string line;
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			std::cin >> line;
			for (int colIdx = 0; colIdx < col; colIdx++) {
				board[rowIdx][colIdx] = line.at(colIdx);
			}
		}
		// ������
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			for (int colIdx = 0; colIdx < col / 2; colIdx++) {
				std::swap(board[rowIdx][colIdx], board[rowIdx][col - colIdx - 1]);
			}
		}
		// ����ϱ�
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			for (int colIdx = 0; colIdx < col; colIdx++) {
				std::cout << board[rowIdx][colIdx];
			}
			std::cout << std::endl;
		}
		// ���� �迭 �����ϱ�
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			delete[] board[rowIdx];
		}
		delete[] board;
	}
	return 0;
}