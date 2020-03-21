#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	string str;
	cin >> N >> str;

	
	long long sum = 0;
	for (int i = N - 1; i >= 0; i--) {
		sum *= 31;
		sum %= 1234567891;
		sum += (str[i] - 'a' + 1);
		sum %= 1234567891;
	}

	cout << sum;

	return 0;
}