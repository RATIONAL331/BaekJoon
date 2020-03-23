#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	map<string, string> passwd;
	string website, pw;
	while (N--) {
		cin >> website >> pw;
		passwd[website] = pw;
	}
	while (M--) {
		cin >> website;
		cout << passwd[website] << '\n';
	}

	return 0;
}