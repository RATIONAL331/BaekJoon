#include<iostream>
#include<vector>

using namespace std;

class Song {
public:
	int songNumber;
	int singerNumber;
	Song(int a = 0, int b = 0)
		: songNumber(a), singerNumber(b)
	{
	}
};


int main() {
	int N, K, J;
	cin >> N >> K >> J;

	Song* songArr = new Song[N + 1];
	vector<Song*>* songParent = new vector<Song*>[N + 1];

	int parent;
	for (int i = 2; i <= N; i++) {
		cin >> parent;
		songParent[parent].push_back(&songArr[i]);
	}

	int singer;
	for (int i = 1; i <= N; i++) {
		cin >> singer;
		songArr[i].songNumber = i;
		songArr[i].singerNumber = singer;
	}


	for (int i = 0; i < K; i++) {
		int T, P, S;
	}

	delete[] songArr;
	delete[] songParent;

	return 0;
}