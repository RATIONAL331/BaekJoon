#include<iostream>
#include<string>
#include<vector>
class SetKind {
public:
	std::string kind;
	int num;
	SetKind() : SetKind("", 1) {}
	SetKind(std::string kind, int num = 1) {
		this->kind = kind; this->num = num;
	}
};
class SetKindVec {
public:
	std::vector<SetKind> kindVec;
	void push_back(SetKind element) {
		int index = isAlready(element);
		if (index == -1) kindVec.push_back(element);
		else kindVec.at(index).num++;
	}
	int isAlready(SetKind& element) {
		for (int i = 0; i < this->kindVec.size(); i++) {
			if (this->kindVec.at(i).kind == element.kind) return i;
		}
		return -1;
	}
};
int main() {
	int T, n;
	std::cin >> T;

	std::string name, kind;
	for (int testCase = 0; testCase < T; testCase++) {
		std::cin >> n;

		SetKindVec vec;
		for (int cloth = 0; cloth < n; cloth++) {
			std::cin >> name >> kind;
			vec.push_back(SetKind(kind));
		}
		int ret = 1;
		for (auto element : vec.kindVec) {
			ret *= (element.num + 1);
		}
		std::cout << --ret << std::endl;
	}
	return 0;
}