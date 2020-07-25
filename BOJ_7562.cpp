#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[8] = { 2, 1, -2, -1, 1, 2, -2, -1 };
int dy[8] = { 1, 2, 1, 2, -2, -1, -1, -2 };
int map[300][300];
int visit[300][300];

void BFS(int l, pair<int, int> start, pair<int, int> fin) {
    int count = 0;
    queue<pair<int, int>> q;
    pair<int, int> cur;
    pair<int, int> next;
    q.push(start);
    visit[start.first][start.second] = 0;

    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            next = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (0 <= next.first && next.first < l && 0 <= next.second && next.second < l) {
                if (visit[next.first][next.second] == -1) {
                    q.push(next);
                    visit[next.first][next.second] = visit[cur.first][cur.second] + 1;
                    if (next.first == fin.first && next.second == fin.second) {
                        return;
                    }
                }
            }
        }
    }
}

int main(void) {
    int N, l;
    vector<int> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        memset(map, 0, sizeof(map));
        memset(visit, -1, sizeof(visit));
        pair<int, int> start;
        pair<int, int> fin;
        cin >> l;
        cin >> start.first >> start.second;
        cin >> fin.first >> fin.second;
        if (start.first == fin.first && start.second == fin.second) {
            v.push_back(0);
        }
        else {
            BFS(l, start, fin);
            v.push_back(visit[fin.first][fin.second]);
        }
    }
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}