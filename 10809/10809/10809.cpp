#include<iostream>
#include<string>
int main() {
	int isTrue[26];

	for (int i = 0; i < 26; i++) {
		isTrue[i] = -1;
	}

	std::string line;
	std::getline(std::cin, line);
	
	for (int i = 0; i < line.length(); i++) {
		//���� �湮���� ���ߴٸ� isTrue[i]�� ��ġ ����
		if (isTrue[line[i] - 97] == -1) {
			isTrue[line[i] - 97] = i;
		}
		//�̹� �湮�ߴٸ� continue
		else {
			continue;
		}
	}

	// ����ϱ�
	for (int i = 0; i < 25; i++) {
		std::cout << isTrue[i] << " ";
	}
	std::cout << isTrue[25];

	return 0;
}