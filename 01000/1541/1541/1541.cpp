#include <iostream>
#include <string>
using namespace std;

int minRes(string& str){
	int result = 0;
	string temp = "";

	bool minus = false;
	for (size_t i = 0; i <= str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') 
			temp += str[i];

		else {
			if (minus)
				result -= stoi(temp);
			else
				result += stoi(temp);
			temp = "";

			if (str[i] == '-')
				minus = true;
		}
	}
	return result;
}

int main(void){
	string str;
	cin >> str;
	cout << minRes(str);
	return 0;
}