#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int oplus, ominus, omulti, odivide;
vector<int> A;

int maxValue = -1987654321;
int minValue = 1987654321;

void solve(int idx, int plCount, int miCount, 
			int mulCount, int divCount) {	
	if (plCount > oplus || miCount > ominus ||
		mulCount > omulti || divCount > odivide)
		return;

	if (idx == N - 1) {
		maxValue = max(A[idx], maxValue);
		minValue = min(A[idx], minValue);
		return;
	}

	int tmp = A[idx + 1];

	A[idx + 1] = A[idx] + A[idx + 1];
	solve(idx + 1, plCount + 1, miCount, mulCount, divCount);
	A[idx + 1] = tmp;

	A[idx + 1] = A[idx] - A[idx + 1];
	solve(idx + 1, plCount, miCount + 1, mulCount, divCount);
	A[idx + 1] = tmp;

	A[idx + 1] = A[idx] * A[idx + 1];
	solve(idx + 1, plCount, miCount, mulCount + 1, divCount);
	A[idx + 1] = tmp;
	
	A[idx + 1] = A[idx] / A[idx + 1];
	solve(idx + 1, plCount, miCount, mulCount, divCount + 1);
	A[idx + 1] = tmp;
}


int main() {
	cin >> N;

	A.resize(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> oplus >> ominus >> omulti >> odivide;

	solve(0, 0, 0, 0, 0);

	cout << maxValue << '\n' << minValue;
	
	return 0;
}