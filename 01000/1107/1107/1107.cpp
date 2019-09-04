#include<iostream>
#include<string>
#include<cmath>
// ���峭 ��ư�� ������ true���� �ƴϸ� false ����
int main() {
	std::ios::sync_with_stdio(false);
	// ���ϴ� ä�� �� N
	std::string N;
	std::cin >> N;
	// N�� ���� ���ڷ� ��ȯ�� �� integerN
	int integerN = std::stoi(N);
	// ���峭 ��ư���� M
	int M;
	std::cin >> M;
	// ���峭 ��ư �迭 �����ϱ�
	int button;
	int * breakButton = new int[10];
	for (int i = 0; i < 10; i++) {
		breakButton[i] = false;
	}
	for (int i = 0; i < M; i++) {
		std::cin >> button;
		breakButton[button] = true;
	}

	int Case1 = std::abs(integerN - 100);

	for (int i = 0; i <= 999999; i++) {
		// ��� ���� ������ Ȯ���ϱ� ���� ����
		bool flag = true;
		std::string current = std::to_string(i);
		for (int j = 0; j < current.length(); j++) {
			int curValue = current.at(j) - '0';
			// ���� ������ ���߱�
			if (breakButton[curValue]) {
				flag = false;
				break;
			}
		}
		// ��� ���� �ȳ�����
		if (flag) {
			int compare = std::abs(i - integerN) + current.length();
			if (Case1 > compare){
				Case1 = compare;
			}
		}
	}
	std::cout << Case1;
	delete[] breakButton;
	return 0;
}