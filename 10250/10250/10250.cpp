#include<iostream>
int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int H, W, N;
		std::cin >> H >> W >> N;
		int height, width;
		//�ǳ��� �ö� ���
		if (N%H == 0) {
			height = H;
			//�ǳ��� �ǿ����ʿ� �ִ� ���
			if (N == H * W)
				width = W;
			else
				width = N / H;
		}
		// �ǳ��� �ö� ����� �ƴ� ���
		else {
			height = N % H;
			width = N / H + 1;
		}
		std::cout << height * 100 + width << std::endl;
	}
	return 0;
}