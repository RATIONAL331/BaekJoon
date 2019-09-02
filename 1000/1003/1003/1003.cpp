#include<iostream>
class SetZeroOne {
public:
	int zero;
	int one;
	SetZeroOne() : SetZeroOne(0, 0) {}
	SetZeroOne(int zero, int one) {
		this->zero = zero; this->one = one;
	}
	friend std::ostream& operator<<(std::ostream&, SetZeroOne&);
	SetZeroOne operator+(const SetZeroOne& element) {
		return SetZeroOne(this->zero + element.zero, this->one + element.one);
	}
};
std::ostream& operator<<(std::ostream& s, SetZeroOne& set) {
	s << set.zero << " " << set.one;
	return s;
}
SetZeroOne arr[41] = { SetZeroOne(), };
SetZeroOne& fibonachi(int n) {
	if (!(arr[n].one == 0 && arr[n].zero == 0)) return arr[n];
	if (n == 0) return arr[n] = SetZeroOne(1, 0);
	if (n == 1) return arr[n] = SetZeroOne(0, 1);
	return arr[n] = fibonachi(n - 1) + fibonachi(n - 2);
}

int main() {
	int T;
	std::cin >> T;

	int n;
	for (int i = 0; i < T; i++) {
		std::cin >> n;
		std::cout << fibonachi(n) << std::endl;
	}
	return 0;
}