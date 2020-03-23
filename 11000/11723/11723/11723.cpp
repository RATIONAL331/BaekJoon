#include<iostream>
#include<string>
#include<bitset>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int M;
	cin >> M;
	
	bitset<21> A;

	string op;
	int num;
	while (M--) {
		cin >> op;
		switch (op[0]) {
		case 'a':
			if (op[1] == 'd') {
				cin >> num;
				A.set(num, true);
			}
			else
				A.set();
			break;
		case'r':
			cin >> num;
			A.set(num, false);
			break;
		case 'c':
			cin >> num;
			cout << A[num] << '\n';
			break;
		case 't':
			cin >> num;
			A.flip(num);
			break;
		case 'e':
			A.reset();
			break;
		}
	}
	return 0;
}