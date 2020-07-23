#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };
int map[101][101] = {0,};
bool isVisited[101][101] = { false, };

int BFS(int i, int j) {
    int cnt = 0;
    pair<int, int> cur;
    pair<int, int> next;
    queue<pair<int, int>> q;

    q.push(make_pair(i, j));
    isVisited[i][j] = true;
    cnt++;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            next = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (0 <= next.first && next.first < N && 0 <= next.second && next.second < M) {
                if (isVisited[next.first][next.second] == false && map[next.first][next.second] == 0) {
                    q.push(next);
                    isVisited[next.first][next.second] = true;
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

int main(void) {
    int K;
    int x1, y1, x2, y2;
    vector<int> res;

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = min(x1, x2); j < max(x1, x2); j++) {
            for (int k = min(y1, y2); k < max(y1, y2); k++) {
                map[k][j] = 1;
                isVisited[k][j] = false;
            }
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0 && isVisited[i][j] == false) {
                res.push_back(BFS(i, j));
            }
        }
    }
    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for (auto i = res.begin(); i != res.end(); i++) {
        cout << *i << " ";
    }

    return 0;
}