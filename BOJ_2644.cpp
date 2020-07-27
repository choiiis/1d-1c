#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, start, fin;
int visit[101] = { 0, };
vector<int> v[101];

int BFS(int start) {
    queue<int> q;
    int cur;
    visit[start] = 0;
    q.push(start);

    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for (auto next = v[cur].begin(); next != v[cur].end(); next++) {
            if (*next == fin) {
                return visit[cur] + 1;
            }
            if (visit[*next] == 0) {
                q.push(*next);
                visit[*next] = visit[cur] + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    int a, b;
    cin >> n;
    cin >> start >> fin;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout << BFS(start);
    
    return 0;
}