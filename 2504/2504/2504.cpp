#include<iostream>
#include<string>
#include<stack>
int calculate(std::string line) {
	std::stack<char> checkStack;
	//for (char c : line) {
	//	if (c == '(') checkStack.push(c);
	//	else {
	//		if (!checkStack.empty() && checkStack.top() == '(') {
	//			checkStack.pop();
	//		}
	//		else {
	//			return false;
	//		}
	//	}
	//}
	//if (!checkStack.empty()) return false;
	//else return true;
}
int main() {
	int T;
	std::cin >> T;

	std::string line;
	for (int i = 0; i < T; i++) {
		std::cin >> line;
		//if (calculate(line))

	}
	return 0;
}