#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, M, N, K, cnt;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

bool isVisited[51][51];
int arr[51][51];
queue<pair<int, int>> q;

void DFS(pair<int, int> cur) {
    pair<int, int> next;
    isVisited[cur.first][cur.second] = true;
    for (int i = 0; i < 4; i++) {
        next = make_pair(cur.first + dx[i], cur.second + dy[i]);
        if (0 <= next.first && next.first < M && 0 <= next.second && next.second < N) {
            if (isVisited[next.first][next.second] == false && arr[next.first][next.second] == 1) {
                DFS(next);
            }
        }
    }
}

int main(void) {
    int a, b;
    vector<int> ans;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> M >> K;
        cnt = 0;
        for (int k = 0; k < M; k++) {
            for (int r = 0; r < N; r++) {
                isVisited[k][r] = false;
                arr[k][r] = 0;
            }
        }
        for (int j = 0; j < K; j++) {
            cin >> b >> a;
            arr[a][b] = 1;
        }

        for (int k = 0; k < M; k++) {
            for (int r = 0; r < N; r++) {
                if (isVisited[k][r] == false && arr[k][r] == 1) {
                    DFS(make_pair(k, r));
                    cnt++;
                }
            }
        }
        ans.push_back(cnt);
    }

    for (auto i = ans.begin(); i != ans.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}