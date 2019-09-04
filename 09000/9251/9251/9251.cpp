#include<iostream>
#include<string>
#include<algorithm>
int calculate(std::string s1, std::string s2) {
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
	int ret = lcs[s2.length()][s1.length()];
	for (int i = 0; i < s2.length() + 1; i++) {
		delete lcs[i];
	}
	delete lcs;
	return ret;
}
int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	std::cout << calculate(s1, s2);
	return 0;
}