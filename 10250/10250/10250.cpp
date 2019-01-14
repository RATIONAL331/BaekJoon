#include<iostream>
int main() {
	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int H, W, N;
		std::cin >> H >> W >> N;
		int height, width;
		//맨끝에 올라갈 사람
		if (N%H == 0) {
			height = H;
			//맨끝층 맨오른쪽에 있는 사람
			if (N == H * W)
				width = W;
			else
				width = N / H;
		}
		// 맨끝에 올라갈 사람이 아닌 사람
		else {
			height = N % H;
			width = N / H + 1;
		}
		std::cout << height * 100 + width << std::endl;
	}
	return 0;
}