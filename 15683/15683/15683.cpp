#include<iostream>
#include<vector>
std::vector<int> getPermutation(std::vector<int>&  vec, int start, int N) {
	if (start == N) return vec;
	for (int i = 0; i < N; i++) {
		vec.push_back(i);
		getPermutation(vec, start+1, N);
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

	std::vector<std::vector<int>> perm;
	std::vector<int> temp;
	perm.push_back(getPermutation(temp, 0, cameraPositionVec.size()));

	for (Camera camera : cameraPositionVec) {
		int ret = -1;
		int retDirection = -1;

		for (int i = 0; i < 4; i++) {
			int temp = visit(board, N, M, camera.posY, camera.posX, camera.cameraDegree, i, false);
			if (ret < temp) {
				ret = temp;
				retDirection = i;
			}
		}
		visit(board, N, M, camera.posY, camera.posX, camera.cameraDegree, retDirection, true);
		zeroCount -= ret;
	}

	std::cout << zeroCount;

	for (int i = 0; i < N; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}