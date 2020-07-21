#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, M, N, K, cnt;
vector<int> map[1001] = {};
queue<int> q;
bool isVisited[1001] = { false, };

void BFS(int start) {
    q.push(start);
    isVisited[start] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i = map[cur].begin(); i != map[cur].end(); i++) {
            if (isVisited[*i] == false) {
                q.push(*i);
                isVisited[*i] = true;
            }
        }
    }
}

int main(void) {
    int a, b, N, M;
    int cnt = 0;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (isVisited[i] == false) {
            BFS(i);
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}