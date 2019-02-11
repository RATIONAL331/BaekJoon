#include<iostream>
#include<string>
std::string stringReverse(std::string);
std::string bigIntegerAdd(std::string, std::string);
std::string zeroJustify(std::string&);
//������ �� ���ϱ�
std::string arr[101][101] = { "" };
std::string combination(int N, int M) {
	if (arr[N][M] != "") return arr[N][M];
	if (M > N / 2) return arr[N][M] = combination(N, N - M);
	if (M == 0 || M == N) return arr[N][M] = "1";
	if (M == 1 || N - M == 1) return arr[N][M] = std::to_string(N);
	return arr[N][M] = bigIntegerAdd(combination(N - 1, M - 1), combination(N - 1, M));
}
int main() {
	int N, M;
	std::cin >> N >> M;
	std::cout << combination(N, M);
	return 0;
}
//�Ʒ��� ���ʹ� Biginteger�����ϴ� �ڵ�
//intMax�Լ��� ���ڿ� ������ �ִ밪�� ���ϱ� ���� �Լ�
int intMax(int i1, int i2) {
	if (i1 > i2) return i1;
	else return i2;
}
//���ڿ� ������
std::string stringReverse(std::string s) {
	std::string temp;
	for (int i = s.length() - 1; i >= 0; i--) {
		temp += s.at(i);
	}
	return temp;
}
//�����ϱ�
std::string bigIntegerAdd(std::string s1, std::string s2) {
	std::string rev_s1 = stringReverse(s1);
	std::string rev_s2 = stringReverse(s2);
	//������� �����ϴ� ����
	std::string temp;

	int maxIndex = intMax(rev_s1.length(), rev_s2.length());
	int s1_char, s2_char;
	for (int index = 0, carry = 0; index < maxIndex + 1; index++) {
		//�� ���ھ� ������
		index <= (rev_s1.length() - 1) ? s1_char = rev_s1.at(index) - '0' : s1_char = 0;
		index <= (rev_s2.length() - 1) ? s2_char = rev_s2.at(index) - '0' : s2_char = 0;
		//���ؼ� ���� �ڸ��� �����ֱ�, carry�� 10�� �Ѱ� �ȴٸ� 1�� �ȴ�.
		temp += std::to_string((s1_char + s2_char + carry) % 10);
		carry = (s1_char + s2_char + carry) / 10;
	}
	return stringReverse(zeroJustify(temp));
}
//���� 0�������� �����
std::string zeroJustify(std::string& s) {
	if (s.at(s.length() - 1) == '0') { return s.substr(0, s.length() - 1); }
	else return s;
}