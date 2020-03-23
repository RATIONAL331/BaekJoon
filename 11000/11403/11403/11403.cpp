#include<iostream>
#include<vector>
using namespace std;

int N;
vector<vector<bool>> graph;

int main() {
	cin >> N;
	graph.resize(N);

	for (int i = 0; i < N; i++)
		graph[i].resize(N);
		
	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			num == 1 ? graph[i][j] = true : graph[i][j] = false;
		}
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (graph[i][k] && graph[k][j])
					graph[i][j] = true;
			}
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << graph[i][j] << " ";
		cout << '\n';
	}

	return 0;
}