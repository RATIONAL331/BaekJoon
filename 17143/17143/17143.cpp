#include<iostream>
#include<vector>
#include<algorithm>
class Shark {
public:
	int posX;
	int posY;
	int speed;
	int direction;
	int zYew;

	bool operator< (const Shark& compareShark) const {
		if (posX < compareShark.posX) 
			return true;
		else
			return false;
	}

	Shark() : Shark(0, 0, 0, 0, 0) { /*empty construction */ }
	Shark(int posY, int posX, int speed, int direction, int zYew)
		:posX(posX), posY(posY), speed(speed), direction(direction), zYew(zYew) 
	{
		// empty construction
	}
	void move(int height, int width) {
		for (int i = 0; i < speed; i++) {
			switch (direction) {
			case 1:
				if (posY == 1) {
					direction = 2;
					posY = posY + 1;
				}
				else
					posY = posY - 1;
				break;
			case 2:
				if (posY == height) {
					direction = 1;
					posY = posY - 1;
				}
				else
					posY = posY + 1;
				break;
			case 3:
				if (posX == width) {
					direction = 4;
					posX = posX - 1;
				}
				else
					posX = posX + 1;
				break;
			case 4:
				if (posX == 1) {
					direction = 3;
					posX = posX + 1;
				}
				else
					posX = posX - 1;
				break;
			}
		}
	}
};

int main() {
	// R과 C는 세로와 가로, T는 상어의 마릿수
	int R, C, T;
	std::cin >> R >> C >> T;
	// 상어 없으면 바로 리턴
	if (T == 0) {
		std::cout << 0;
		return 0;
	}

	// 상어 위치 정보 저장하는 배열
	std::vector<Shark> sharkArr;

	// 상어 정보 입력
	/* r은 1보다 크거나 같고 R보다 작거나 같으며 세로 위치를 나타냄
	   c는 1보나 크거나 같고 C보다 작거나 같으며 가로 위치를 나타냄
	   s는 속력을 나타내며 1000보다 작은 정수
	   d는 1인 경우 위 2인 경우 아래 3인 경우 오른쪽 4인 경우 왼쪽 이다.
	   z는 상어의 크기이다.
	*/
	int r, c, s, d, z;
	for (int i = 1; i <= T; i++) {
		std::cin >> r >> c >> s >> d >> z;
		sharkArr.push_back(Shark(r, c, s, d, z));
	}

	std::sort(sharkArr.begin(), sharkArr.end());
	// 1번째 열부터 검사한다.
	int count = 0;
	for (int pivot = 1; pivot <= C; pivot++) {
		// 가장 위의 것 찾기
		int tmp = -1;
		int min = R + 1;
		for (int i = 0; i < sharkArr.size(); i++) {
			if (sharkArr[i].posX == pivot) {
				if (min > sharkArr[i].posY) {
					min = sharkArr[i].posY;
					tmp = i;
				}
			}
		}
		// 무게수 늘리기
		if (tmp != -1) {
			count += sharkArr[tmp].zYew;
			// 가장 위의 것 초기화 하기
			sharkArr[tmp] = Shark();
		}
		// 모든 상어에 대해서 움직인다.
		for (Shark shark : sharkArr) {
			shark.move(R, C);
		}
		// 정렬한다.
		std::sort(sharkArr.begin(), sharkArr.end());
		// 겹치는 부분이 있다면 제거한다.
		for (int i = 0; i < sharkArr.size() - 1; i++) {
			if (sharkArr[i].posX == sharkArr[i + 1].posX) {
				if (sharkArr[i].posY == sharkArr[i + 1].posY) {
					if (sharkArr[i].zYew < sharkArr[i + 1].zYew)
						sharkArr[i] = Shark();
					else
						sharkArr[i + 1] = Shark();
				}
			}
		}
	}

	std::cout << count;

	return 0;
}