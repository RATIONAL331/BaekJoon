#include<iostream>
#include<vector>
#include<stack>
int main() {
	int n; 
	scanf("%d", &n);
	
	int * numArr = new int[n];
	std::stack<int> copyNumArr;
	std::vector<char> ret;

	int num;
	for (int i = 0; i < n; i++) {
		std::cin >> num;
		numArr[i] = num;
	}

	int index = 0;
	for (int i = 1; i <= n; i++) {
		copyNumArr.push(i); 
		ret.push_back('+');
		while (!copyNumArr.empty() && numArr[index] == copyNumArr.top()) {
			index++;
			copyNumArr.pop();
			ret.push_back('-');
		}
	}
	if (!copyNumArr.empty()) {
		printf("%s", "NO");
	}
	else {
		for (char c : ret) {
			printf("%c\n", c);
		}
	}

	delete[] numArr;
	return 0;
}