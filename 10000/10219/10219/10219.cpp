#include<iostream>
#include<string>
int main() {
	int T;
	std::cin >> T;

	int row, col;
	for (int i = 0; i < T; i++) {
		std::cin >> row >> col;
		// 동적 배열 생성하기
		char ** board = new char*[row];
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			board[rowIdx] = new char[col];
		}
		// 배열안에 문자 넣기
		std::string line;
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			std::cin >> line;
			for (int colIdx = 0; colIdx < col; colIdx++) {
				board[rowIdx][colIdx] = line.at(colIdx);
			}
		}
		// 뒤집기
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			for (int colIdx = 0; colIdx < col / 2; colIdx++) {
				std::swap(board[rowIdx][colIdx], board[rowIdx][col - colIdx - 1]);
			}
		}
		// 출력하기
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			for (int colIdx = 0; colIdx < col; colIdx++) {
				std::cout << board[rowIdx][colIdx];
			}
			std::cout << std::endl;
		}
		// 동적 배열 제거하기
		for (int rowIdx = 0; rowIdx < row; rowIdx++) {
			delete[] board[rowIdx];
		}
		delete[] board;
	}
	return 0;
}