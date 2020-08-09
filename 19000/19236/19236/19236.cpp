#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 0���� ������� �ʴ´�.
const int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

int RESULT = 0;

bool boundaryCheck(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void dfs(vector<vector<pair<int, int>>> board, int row, int col, int sum) {
    // ��� ��ƸԱ�
    sum += board[row][col].first;
    board[row][col].first = 0;
    int dir = board[row][col].second;
    board[row][col].second = 0;

    RESULT = max(RESULT, sum);
    // ����� �����̱�
    for (int num = 1; num <= 16; num++) {
        bool isFind = false;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (!isFind && board[i][j].first == num) {
                    int& newDir = board[i][j].second;

                    while (!(boundaryCheck(i + dx[newDir], j + dy[newDir]))
                        || (i + dx[newDir] == row && j + dy[newDir] == col))
                    {
                        newDir++;

                        if (newDir == 9)
                            newDir = 1;
                    }
                    swap(board[i][j], board[i + dx[newDir]][j + dy[newDir]]);
                    isFind = true;
                }
                if (isFind) break;
            }
            if (isFind) break;
        }
    }
    // ��� �����̱�
    row += dx[dir];
    col += dy[dir];
    while (boundaryCheck(row, col)) {
        if (board[row][col].first != 0)
            dfs(board, row, col, sum);

        row += dx[dir];
        col += dy[dir];
    }
}

int main() {
    vector<vector<pair<int, int>>> board;
    board.resize(4);
    for (int i = 0; i < 4; i++)
        board[i].resize(4);
    
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cin >> board[i][j].first >> board[i][j].second;
    
    dfs(board, 0, 0, 0);
    
    cout << RESULT;
    return 0;
}