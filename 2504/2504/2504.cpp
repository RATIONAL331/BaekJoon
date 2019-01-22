#include<iostream>
#include<string>
#include<stack>

int calculate(std::string line) {
	// int 형 스택으로 해야 계산할때 오류가 발생하지 않는다. char로 할 경우 오버플로우가 발생할 수 있다.
	std::stack<int> checkStack;
	// 들어온 문자열 한글자 하나에 대해서
	for (char c : line) {
		// 스택에 바로 넣어버리고,
		checkStack.push(c);
		// 기호가 닫는 기호라면
		if (c == ')' || c == ']') {
			// 바로 빼버리고
			checkStack.pop();
			// temp는 기존 값을 더하기 위해 존재한다.
			int temp = 0;
			// hasNum은 기존 값이 있는지 없는지 체크하기 위한 불변수이다.
			bool hasNum = false;

			// 닫는기호가 ) 라면
			if (c == ')') {
				// 스택이 비지 않을 동안 ( 가 나올 때 까지 숫자를 뽑아낸다.
				while (!checkStack.empty() && checkStack.top() != '(') {
					// 도중에 [ 가 나오면 에러이므로 처리를 해준다.
					if (checkStack.top() == '[') return -1;
					// 모든 숫자를 더한다.
					temp += (checkStack.top());
					checkStack.pop();
					hasNum = true;
					
				}
				// 숫자 더한 값에 2를 곱한 값을 설정한다. 하지만 하나도 더해지지 않았다면 2로 설정한다.
				if (hasNum) temp *= 2;
				else temp = 2;

				// ( 기호를 스택에서 삭제한다.
				if (!checkStack.empty()) checkStack.pop();
				else return -1;

				// 설정한 값을 다시 스택에 넣는다.
				checkStack.push(temp);
			}
			// 닫는기호가 ] 라면 
			else { // (c == ']')
				// 스택이 비지 않을 동안 [ 가 나올 때 까지 숫자를 뽑아낸다.
				while (!checkStack.empty() && checkStack.top() != '[') {
					// 도중에 ( 가 나오면 에러이므로 처리를 해준다.
					if (checkStack.top() == '(') return -1;
					// 모든 숫자를 더한다.
					temp += (checkStack.top());
					checkStack.pop();
					hasNum = true;

				}
				// 숫자 더한 값에 3를 곱한 값을 설정한다. 하지만 하나도 더해지지 않았다면 3로 설정한다.
				if (hasNum) temp *= 3;
				else temp = 3;

				// [ 기호를 스택에서 삭제한다.
				if(!checkStack.empty()) checkStack.pop();
				else return -1;

				// 설정한 값을 다시 스택에 넣는다.
				checkStack.push(temp);
			}

		}
	}
	// ret변수는 스택 안에 있는 값을 모두 더하는 변수이다.
	int ret = 0;
	// 스택을 모두 비울동안
	while (!checkStack.empty()) {
		// 밑의 기호가 하나라도 등장하면 에러
		if (checkStack.top() == '(' || checkStack.top() == ')' || checkStack.top() == '[' || checkStack.top() == ']') return -1;
		ret += checkStack.top();
		checkStack.pop();
	}
	return ret;
}

int main() {
	std::string line;
	std::cin >> line;
	if (calculate(line) == -1) std::cout << 0 << std::endl;
	else std::cout << calculate(line);
	return 0;
}