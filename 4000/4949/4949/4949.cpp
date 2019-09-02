#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;
bool dist(const string& line) {
	stack<char> st;
	string::const_iterator it = line.begin();
	while (*it != '.') {
		if (*it == '(' || *it == '[') {
			if (*it == '(') 
				st.push('(');
			else
				st.push('[');
		}
		else if (*it == ')' || *it == ']') {
			if (st.empty()) 
				return false;

			if (*it == ')') {
				if (st.top() != '(')
					return false;
			}
			else {
				if (st.top() != '[')
					return false;
			}
			st.pop();
		}
		it++;
	}
	if (st.empty())
		return true;
	else return false;
}
int main() {
	string line;
	while (getline(cin, line)) {
		if (line.size() == 1) {
			if (line[0] == '.')
				return 0;
		}
		cout << (dist(line) ? "yes" : "no") << '\n';
	}
	return 0;
}