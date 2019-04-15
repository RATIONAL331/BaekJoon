#include<iostream>
#include<vector>
void perm(std::vector<std::vector<int>>& permutation, std::vector<int>& vec, int start, int N) {
	if (start == N) {
		permutation.push_back(vec);
		return;
	}
	for (int i = 0; i < 4; i++) {
		vec.push_back(i);
		perm(permutation, vec, start + 1, N);
		vec.pop_back();
	}
}
int goRight(int** board, int height, int width, int curY, int curX, bool change) {
	if (curY < 0 || curX < 0 || curY >= height || curX >= width) return 0;
	if (board[curY][curX] == 6) return 0;

	if (board[curY][curX] != 0) {
		return goRight(board, height, width, curY, curX + 1, change);
	}
	if (board[curY][curX] == 0) {
		if (change) board[curY][curX] = -1;
		return 1 + goRight(board, height, width, curY, curX + 1, change);
	}
	return 0;
}
int goLeft(int** board, int height, int width, int curY, int curX, bool change) {
	if (curY < 0 || curX < 0 || curY >= height || curX >= width) return 0;
	if (board[curY][curX] == 6) return 0;
	if (board[curY][curX] != 0) {
		return goLeft(board, height, width, curY, curX - 1, change);
	}
	if (board[curY][curX] == 0) {
		if (change) board[curY][curX] = -1;
		return 1 + goLeft(board, height, width, curY, curX - 1, change);
	}
	return 0;
}
int goDown(int** board, int height, int width, int curY, int curX, bool change) {
	if (curY < 0 || curX < 0 || curY >= height || curX >= width) return 0;
	if (board[curY][curX] == 6) return 0;
	if (board[curY][curX] != 0) {
		return goDown(board, height, width, curY + 1, curX, change);
	}
	
	if (board[curY][curX] == 0) {
		if (change) board[curY][curX] = -1;
		return 1 + goDown(board, height, width, curY + 1, curX, change);
	}
	return 0;
}
int goUp(int** board, int height, int width, int curY, int curX, bool change) {
	if (curY < 0 || curX < 0 || curY >= height || curX >= width) return 0;
	if (board[curY][curX] == 6) return 0;
	if (board[curY][curX] != 0) {
		return goUp(board, height, width, curY - 1, curX, change);
	}
	if (board[curY][curX] == 0) {
		if (change) board[curY][curX] = -1;
		return 1 + goUp(board, height, width, curY - 1, curX, change);
	}
	return 0;
}
// direction 이 0이면 동 1이면 남 2면 서 3이면 북
int visit(int** board, int height, int width, int curY, int curX, int cameraDegree,int cameraDirection, bool change) {
	if (cameraDegree == 1) {
		if (cameraDirection == 0) return goRight(board, height, width, curY, curX, change);
		else if (cameraDirection == 1) return goDown(board, height, width, curY, curX, change);
		else if (cameraDirection == 2) return goLeft(board, height, width, curY, curX, change);
		else return goUp(board, height, width, curY, curX, change);
	}
	else if (cameraDegree == 2) {
		if (cameraDirection == 0) return goRight(board, height, width, curY, curX, change) + goLeft(board, height, width, curY, curX, change);
		else if (cameraDirection == 1) return goDown(board, height, width, curY, curX, change) + goUp(board, height, width, curY, curX, change);
		else if (cameraDirection == 2) return goLeft(board, height, width, curY, curX, change) + goRight(board, height, width, curY, curX, change);
		else return goUp(board, height, width, curY, curX, change) + goDown(board, height, width, curY, curX, change);
	}
	else if (cameraDegree == 3) {
		if (cameraDirection == 0) return goRight(board, height, width, curY, curX, change) + goDown(board, height, width, curY, curX, change);
		else if (cameraDirection == 1) return goDown(board, height, width, curY, curX, change) + goLeft(board, height, width, curY, curX, change);
		else if (cameraDirection == 2) return goLeft(board, height, width, curY, curX, change) + goUp(board, height, width, curY, curX, change);
		else return goUp(board, height, width, curY, curX, change) + goRight(board, height, width, curY, curX, change);
	}
	else if (cameraDegree == 4) {
		if (cameraDirection == 0) return goRight(board, height, width, curY, curX, change) + goDown(board, height, width, curY, curX, change) + goLeft(board, height, width, curY, curX, change);
		else if (cameraDirection == 1) return goDown(board, height, width, curY, curX, change) + goLeft(board, height, width, curY, curX, change) + goUp(board, height, width, curY, curX, change);
		else if (cameraDirection == 2) return goLeft(board, height, width, curY, curX, change) + goUp(board, height, width, curY, curX, change) + goRight(board, height, width, curY, curX, change);
		else return goUp(board, height, width, curY, curX, change) + goRight(board, height, width, curY, curX, change) + goDown(board, height, width, curY, curX, change);
	}
	else {
		return goRight(board, height, width, curY, curX, change) + goDown(board, height, width, curY, curX, change) + goLeft(board, height, width, curY, curX, change) + goUp(board, height, width, curY, curX, change);
	}
}
void init(int** board, int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j] == -1) board[i][j] = 0;
		}
	}
}
class Camera {
public:
	int posX, posY;
	int cameraDegree;
	int direct;
	
	Camera(int Y, int X, int degree) {
		this->posY = Y;
		this->posX = X;
		this->cameraDegree = degree;
		this->direct = 0;
	}
private:
	Camera() : Camera(0, 0, 0) {}
};

int main() {
	int N, M;
	std::cin >> N >> M;
	int** board = new int*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new int[M];
	}

	std::vector<Camera> cameraPositionVec;

	int zeroCount = 0;

	int status;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> status;
			board[i][j] = status;
			if (status >= 1 && status <= 5) {
				cameraPositionVec.push_back(Camera(i, j, status));
			}
			if (status == 0) zeroCount++;
		}
	}

	std::vector<std::vector<int>> permVec;
	std::vector<int> temp;
	perm(permVec, temp, 0, cameraPositionVec.size());
	
	int ret = -1;
	for (std::vector<int> vec : permVec) {
		int camDirectionIndex = 0;
		int change = 0;

		for (Camera cam : cameraPositionVec) {
			cam.direct = vec[camDirectionIndex++];
			change += visit(board, N, M, cam.posY, cam.posX, cam.cameraDegree, cam.direct, true);
		}
		if (ret < change) ret = change;		
		init(board, N, M);
	}
	
	std::cout << zeroCount - ret;


	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}