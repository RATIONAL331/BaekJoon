#include<iostream>
using namespace std;
void dfs(int* arr, bool* visited, int node) {
	if (visited[node] == true) return;
	visited[node] = true;
	dfs(arr, visited, arr[node]);
}
int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		int arr[1001];
		bool visited[1001];
		for (int j = 0; j < 1001; j++) {
			arr[j] = 0;
			visited[j] = false;
		}
		for (int j = 1; j <= N; j++) {
			cin >> arr[j];
		}
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (visited[j] == false) {
				dfs(arr, visited, j);
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}