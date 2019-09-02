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
		else if (posX == compareShark.posX)
			if (posY < compareShark.posY)
				return true;
			else if (posY == compareShark.posY)
				if (zYew < compareShark.zYew)
					return true;
				else return false;
			else return false;
		else return false;
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
	// R�� C�� ���ο� ����, T�� ����� ������
	int R, C, T;
	std::cin >> R >> C >> T;
	// ��� ������ �ٷ� ����
	if (T == 0) {
		std::cout << 0;
		return 0;
	}

	// ��� ��ġ ���� �����ϴ� �迭
	std::vector<Shark> sharkArr;

	// ��� ���� �Է�
	/* r�� 1���� ũ�ų� ���� R���� �۰ų� ������ ���� ��ġ�� ��Ÿ��
	   c�� 1���� ũ�ų� ���� C���� �۰ų� ������ ���� ��ġ�� ��Ÿ��
	   s�� �ӷ��� ��Ÿ���� 1000���� ���� ����
	   d�� 1�� ��� �� 2�� ��� �Ʒ� 3�� ��� ������ 4�� ��� ���� �̴�.
	   z�� ����� ũ���̴�.
	*/
	int r, c, s, d, z;
	for (int i = 1; i <= T; i++) {
		std::cin >> r >> c >> s >> d >> z;
		sharkArr.push_back(Shark(r, c, s, d, z));
	}

	// 1��° ������ �˻��Ѵ�.
	int count = 0;
	for (int pivot = 1; pivot <= C; pivot++) {
		// ���� ���� �� ã��
		std::sort(sharkArr.begin(), sharkArr.end());
		for (int i = 0; i < sharkArr.size(); i++) {
			if (sharkArr[i].posX == pivot) {
				count += sharkArr[i].zYew;
				sharkArr[i] = Shark();
				break;
			}
		}	
		// ��� �� ���ؼ� �����δ�.
		for (Shark& shark : sharkArr) {
			shark.move(R, C);
		}
		// �����Ѵ�.
		std::sort(sharkArr.begin(), sharkArr.end());
		// ��ġ�� �κ��� �ִٸ� �����Ѵ�.
		for (int i = 0; i < sharkArr.size() - 1; i++) {
			if (sharkArr[i].posX == sharkArr[i + 1].posX && sharkArr[i].posY == sharkArr[i + 1].posY) {
				sharkArr[i] = Shark();
			}
		}
	}

	std::cout << count;

	return 0;
}