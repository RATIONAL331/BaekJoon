#include<iostream>
#include<string>
std::string stringReverse(std::string);
std::string bigIntegerAdd(std::string, std::string);
std::string zeroJustify(std::string&);
//조합의 수 구하기
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
//아래줄 부터는 Biginteger구현하는 코드
//intMax함수는 문자열 길이의 최대값을 구하기 위한 함수
int intMax(int i1, int i2) {
	if (i1 > i2) return i1;
	else return i2;
}
//문자열 뒤집기
std::string stringReverse(std::string s) {
	std::string temp;
	for (int i = s.length() - 1; i >= 0; i--) {
		temp += s.at(i);
	}
	return temp;
}
//연산하기
std::string bigIntegerAdd(std::string s1, std::string s2) {
	std::string rev_s1 = stringReverse(s1);
	std::string rev_s2 = stringReverse(s2);
	//결과값을 저장하는 변수
	std::string temp;

	int maxIndex = intMax(rev_s1.length(), rev_s2.length());
	int s1_char, s2_char;
	for (int index = 0, carry = 0; index < maxIndex + 1; index++) {
		//한 글자씩 빼오기
		index <= (rev_s1.length() - 1) ? s1_char = rev_s1.at(index) - '0' : s1_char = 0;
		index <= (rev_s2.length() - 1) ? s2_char = rev_s2.at(index) - '0' : s2_char = 0;
		//더해서 일의 자리를 더해주기, carry는 10이 넘게 된다면 1이 된다.
		temp += std::to_string((s1_char + s2_char + carry) % 10);
		carry = (s1_char + s2_char + carry) / 10;
	}
	return stringReverse(zeroJustify(temp));
}
//끝에 0들어가있으면 지우기
std::string zeroJustify(std::string& s) {
	if (s.at(s.length() - 1) == '0') { return s.substr(0, s.length() - 1); }
	else return s;
}