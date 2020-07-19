#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

int box[1001][1001] = { 0, };
queue<pair<int, int>> q;

int BFS(void) {
    bool isDone = false;
    pair<int, int> cur;
    pair<int, int> next;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            next = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (0 <= next.first && next.first < M && 0 <= next.second && next.second < N) {
                if (box[next.first][next.second] == 0) {
                    q.push(make_pair(next.first, next.second));
                    box[next.first][next.second] = box[cur.first][cur.second] + 1;
                }
            }
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (box[i][j] == 0) {
                isDone = true;
            }
        }
    }

    if (!isDone) {
        return box[cur.first][cur.second] - 1;
    }
    else {
        return -1;
    }
}

int main(void) {
    int tmp, res = 0;
    int none = 0;
    
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> tmp;
            if (tmp == 1) {
                q.push(make_pair(i, j));
            }
            else if (tmp == -1) {
                none++;
            }
            box[i][j] = tmp;
        }
    }
    if (q.size() + none == M * N) {
        cout << 0;
    }
    else {
        cout << BFS();
    }
    return 0;
}