#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, M, N, K;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

bool isVisited[51][51];
int arr[51][51];
queue<pair<int, int>> q;

int BFS(void) {
    pair<int, int> cur;
    pair<int, int> next;
    int cnt = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1 && isVisited[i][j] == false) {
                q.push(make_pair(i, j));
                cnt++;
                while (!q.empty()) {
                    cur = q.front();
                    q.pop();
                    if (isVisited[cur.first][cur.second] == false) {
                        isVisited[cur.first][cur.second] = true;
                        for (int i = 0; i < 4; i++) {
                            next = make_pair(cur.first + dx[i], cur.second + dy[i]);
                            if (0 <= next.first && next.first < M && 0 <= next.second && next.second < N) {
                                if (isVisited[next.first][next.second] == false && arr[next.first][next.second] == 1) {
                                    q.push(make_pair(next.first, next.second));
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return cnt;
}

int main(void) {
    int a, b;
    vector<int> ans;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> M >> K;
        for (int k = 0; k < 51; k++) {
            for (int r = 0; r < 51; r++) {
                isVisited[k][r] = false;
                arr[k][r] = 0;
            }
        }
        for (int j = 0; j < K; j++) {
            cin >> b >> a;
            arr[a][b] = 1;
        }
        ans.push_back(BFS());
    }

    for (auto i = ans.begin(); i != ans.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}