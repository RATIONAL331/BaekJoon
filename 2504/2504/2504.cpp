#include<iostream>
#include<string>
#include<stack>

int calculate(std::string line) {
	// int �� �������� �ؾ� ����Ҷ� ������ �߻����� �ʴ´�. char�� �� ��� �����÷ο찡 �߻��� �� �ִ�.
	std::stack<int> checkStack;
	// ���� ���ڿ� �ѱ��� �ϳ��� ���ؼ�
	for (char c : line) {
		// ���ÿ� �ٷ� �־������,
		checkStack.push(c);
		// ��ȣ�� �ݴ� ��ȣ���
		if (c == ')' || c == ']') {
			// �ٷ� ��������
			checkStack.pop();
			// temp�� ���� ���� ���ϱ� ���� �����Ѵ�.
			int temp = 0;
			// hasNum�� ���� ���� �ִ��� ������ üũ�ϱ� ���� �Һ����̴�.
			bool hasNum = false;

			// �ݴ±�ȣ�� ) ���
			if (c == ')') {
				// ������ ���� ���� ���� ( �� ���� �� ���� ���ڸ� �̾Ƴ���.
				while (!checkStack.empty() && checkStack.top() != '(') {
					// ���߿� [ �� ������ �����̹Ƿ� ó���� ���ش�.
					if (checkStack.top() == '[') return -1;
					// ��� ���ڸ� ���Ѵ�.
					temp += (checkStack.top());
					checkStack.pop();
					hasNum = true;
					
				}
				// ���� ���� ���� 2�� ���� ���� �����Ѵ�. ������ �ϳ��� �������� �ʾҴٸ� 2�� �����Ѵ�.
				if (hasNum) temp *= 2;
				else temp = 2;

				// ( ��ȣ�� ���ÿ��� �����Ѵ�.
				if (!checkStack.empty()) checkStack.pop();
				else return -1;

				// ������ ���� �ٽ� ���ÿ� �ִ´�.
				checkStack.push(temp);
			}
			// �ݴ±�ȣ�� ] ��� 
			else { // (c == ']')
				// ������ ���� ���� ���� [ �� ���� �� ���� ���ڸ� �̾Ƴ���.
				while (!checkStack.empty() && checkStack.top() != '[') {
					// ���߿� ( �� ������ �����̹Ƿ� ó���� ���ش�.
					if (checkStack.top() == '(') return -1;
					// ��� ���ڸ� ���Ѵ�.
					temp += (checkStack.top());
					checkStack.pop();
					hasNum = true;

				}
				// ���� ���� ���� 3�� ���� ���� �����Ѵ�. ������ �ϳ��� �������� �ʾҴٸ� 3�� �����Ѵ�.
				if (hasNum) temp *= 3;
				else temp = 3;

				// [ ��ȣ�� ���ÿ��� �����Ѵ�.
				if(!checkStack.empty()) checkStack.pop();
				else return -1;

				// ������ ���� �ٽ� ���ÿ� �ִ´�.
				checkStack.push(temp);
			}

		}
	}
	// ret������ ���� �ȿ� �ִ� ���� ��� ���ϴ� �����̴�.
	int ret = 0;
	// ������ ��� ��ﵿ��
	while (!checkStack.empty()) {
		// ���� ��ȣ�� �ϳ��� �����ϸ� ����
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