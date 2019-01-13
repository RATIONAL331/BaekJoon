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
		//아직 방문하지 못했다면 isTrue[i]에 위치 저장
		if (isTrue[line[i] - 97] == -1) {
			isTrue[line[i] - 97] = i;
		}
		//이미 방문했다면 continue
		else {
			continue;
		}
	}

	// 출력하기
	for (int i = 0; i < 25; i++) {
		std::cout << isTrue[i] << " ";
	}
	std::cout << isTrue[25];

	return 0;
}