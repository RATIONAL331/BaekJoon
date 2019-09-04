#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
void calculate(std::string s1, std::string s2) {
	// 갯수구하기
	// df초기화
	int ** lcs = new int*[s2.length() + 1];
	for (int i = 0; i < s2.length() + 1; i++) {
		lcs[i] = new int[s1.length() + 1];
	}
	for (int i = 0; i <= s2.length(); i++) {
		for (int j = 0; j <= s1.length(); j++) {
			if (i == 0 || j == 0) lcs[i][j] = 0;
			else {
				// 글자가 같으면
				if (s1.at(j - 1) == s2.at(i - 1)) {
					lcs[i][j] = lcs[i - 1][j - 1] + 1;
				}
				// 글자가 다르면
				else {
					lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
				}
			}
		}
	}
	std::cout << lcs[s2.length()][s1.length()] << std::endl;
	// 문자열 구하기
	std::stack<char> lcsStack;
	int s2Idx = s2.length(), s1Idx = s1.length();
	while (s1Idx != 0 && s2Idx != 0) {
		if (lcs[s2Idx][s1Idx] == lcs[s2Idx][s1Idx - 1]) {
			s1Idx--;
		}
		else if (lcs[s2Idx][s1Idx] == lcs[s2Idx - 1][s1Idx]) {
			s2Idx--;
		}
		else if (lcs[s2Idx][s1Idx] - 1 == lcs[s2Idx - 1][s1Idx - 1]) {
			lcsStack.push(s1.at(s1Idx - 1));
			s1Idx--; s2Idx--;
		}
	}
	while (!lcsStack.empty()) {
		std::cout << lcsStack.top();
		lcsStack.pop();
	}
	for (int i = 0; i < s2.length() + 1; i++) {
		delete[] lcs[i];
	}
	delete[] lcs;
}
int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	calculate(s1, s2);
	return 0;
}