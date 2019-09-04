#include<iostream>
#include<string>
#include<deque>
bool functionD(std::deque<int>& deque, bool left) {
	if (deque.empty()) return false; // ����ٸ� false����
	if (left) deque.pop_front(); // ¦����ŭ �������ٸ� �� ���� ���� ����
	else deque.pop_back(); // Ȧ����ŭ �������ٸ� �� ���� ���� ����
	return true;
}
void printDeque(const std::deque<int>& deque, bool left) {
	if (deque.empty()) { // ����ִ� ���� ����ϸ� ����ִ� ���� ���� ǥ���ؼ� ����Ѵ�.
		std::cout << "[]" << std::endl;
		return;
	}
	std::cout << "[";
	if (left) { // ¦����ŭ �������� �迭�� �ִ� �״�� ���
		for (int i = 0; i < deque.size() - 1; i++) {
			std::cout << deque.at(i) << ",";
		}
		std::cout << deque.at(deque.size() - 1) << "]" << std::endl;
	}
	else { // Ȧ����ŭ �������� �迭 �ݴ�� ���
		for (int i = deque.size() - 1; i >= 1; i--) {
			std::cout << deque.at(i) << ",";
		}
		std::cout << deque.at(0) << "]" << std::endl;
	}
}
int main() {
	int T;
	std::cin >> T;

	std::string p;
	int n;
	std::string array;
	for (int i = 0; i < T; i++) {
		std::cin >> p; // ��ɾ� �Է�
		std::cin >> n; // ���� ���� �Է�
		std::cin >> array; // �迭 ���� �Է�

		std::deque<int> deque;

		if (n > 0) { // ������ ���� ��� �� �� �̻��� ���� �������� : 0�� ���� �ٸ��� ó��
			std::string num = ""; // temp����
			for (char c : array) { // �迭 ������ ���Ҹ� �ϳ��� ��
				if (c == ',' || c == ']') { // , �Ǵ� ]�� ������ ���ڰ� �������Ƿ� ���� ���ڸ� ��¥ ���ڷ� ����� ���� �ִ´�.
					deque.push_back(std::stoi(num));
					num = ""; // �ٽ� �ʱ�ȭ
				}
				else if (c != '[') num += c; // ���ڸ� ������ ������
			}
		}

		bool success = true; //�����ߴ��� ��Ÿ���� ����
		bool left = true; // ���������ִ��� Ȯ���ϴ� ����
		for (char function : p) { // ��ɾ� �ϳ��� ��
			if (function == 'R') { // ������ ��ɾ��̸�
				left = !left; // ������ ������ �����´�.
			}
			else { // function == 'D'
				if (!functionD(deque, left)) success = false; // ������ ��, ����ִٸ� �����ߴٰ� ǥ��
			}
		}
		if (!success) std::cout << "error" << std::endl;
		else printDeque(deque, left);
	}
	return 0;
}