#include<iostream> 
#include<vector>
using namespace std; 
 
const int DEL = -987654321;

int SUM;
int CNT;

int num[55][55]; 
int bias[55]; 
int N, M, T;  

int getNum(int i, int j) {  
	j += bias[i]; 
	while (j < 0) 
		j += M; 
	j %= M; 
	return num[i][j];
} 

void setNum(int i, int j, int v) {
	j += bias[i]; 
	while (j < 0)
		j += M; 
	j %= M;
	num[i][j] = v; 
} 

void solve() { 
	bool changed = false; 
	vector<vector<bool>> isDel(N);
	for (int i = 0; i < N; i++)
		isDel[i].resize(M);

	// 같은 원판에서 확인
	for (int i = 0; i < N; i++) { 
		for (int j = 0; j < M; j++) {
			int a = getNum(i, j); 
			int b = getNum(i, j + 1); 
			if (a != DEL && b != DEL && a == b) {
				isDel[i][j] = true;
				isDel[i][j + 1] = true;
				changed = true; 
			} 
		} 
	} 
	// 다른 원판에서 확인
	for (int i = 0; i + 1 < N; i++) {
		for (int j = 0; j < M; j++) {
			int a = getNum(i, j); 
			int b = getNum(i + 1, j); 
			if (a != DEL && b != DEL && a == b) {
				isDel[i][j] = true;
				isDel[i + 1][j] = true;
				changed = true; 
			} 
		} 
	} 

	// 확인된 값 모두 제거
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isDel[i][j] == true) {
				SUM -= num[i][j];
				CNT--;
				setNum(i, j, DEL);
			}
		}
	}

	if (changed == true) 
		return; 

	// 확인된 것이 없다면 평균보다 큰 값 + 1, 작은값 -1
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (num[i][j] != DEL) {
				if (num[i][j] > (double)SUM / CNT) {
					SUM--;
					num[i][j]--;
				}			
				else if (num[i][j] < (double)SUM / CNT) {
					SUM++;
					num[i][j]++;
				}					
			}
		}
	}
} 
int main() {
	/* INPUT Phase */
	cin >> N >> M >> T; 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num[i][j]; 
			SUM += num[i][j];
			CNT++;
		}
	} 
	/* SOLVE Phase */
	while (T--) {
		int x, d, k; 
		cin >> x >> d >> k; 
		int v = x; 
		int shift = k * (d == 0 ? -1 : +1); 

		while (v <= N) { 
			bias[v-1] += shift; 
			v += x; 
		} 
		solve(); 
	} 
	/* PRINT Phase */
	cout << SUM; 
} 