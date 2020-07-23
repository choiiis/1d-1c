#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };
int map[101][101] = {0,};
bool isVisited[101][101] = { false, };

void BFS(int i, int j, int max) {
    pair<int, int> cur;
    pair<int, int> next;
    queue<pair<int, int>> q;
    
    q.push(make_pair(i, j));
    isVisited[i][j] = true;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            next = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (0 <= next.first && next.first < N && 0 <= next.second && next.second < N) {
                if (map[next.first][next.second] > max && isVisited[next.first][next.second] == false) {
                    q.push(next);
                    isVisited[next.first][next.second] = true;
                }
            }
        }
    }
}

int main(void) {
    int cnt, max = 0;
    int max_cnt = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] > max) {
                max = map[i][j];
            }
        }
    }
    for (int i = 0; i <= max; i++) {
        cnt = 0;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                isVisited[j][k] = false;
            }
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (map[j][k] > i && isVisited[j][k] == false) {
                    BFS(j, k, i);
                    cnt++;
                }
            }
        }
        if (max_cnt < cnt) {
            max_cnt = cnt;
        }
    }
    cout << max_cnt;

    return 0;
}