#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> v[1001];
bool isVisitedB[1001];
bool isVisitedD[1001];

void bfs(int a) {
    queue<int> q;
    
    q.push(a);
    cout << a << " ";
    isVisitedB[a] = true;
   
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto i = v[cur].begin(); i != v[cur].end(); i++) {
            if (!isVisitedB[*i]) {
                cout << *i << " ";
                isVisitedB[*i] = true;
                q.push(*i);
            }
        }
    }
    
}

void dfs(int a) {
    stack<int> s;
    s.push(a);
    isVisitedD[a] = true;
    cout << a << " ";

    while (!s.empty()) {
        bool isConnected = false;
        int cur = s.top();
        for (auto i = v[cur].begin(); i != v[cur].end(); i++) {
            if (!isVisitedD[*i]) {
                isConnected = true;
                s.push(*i);
                isVisitedD[*i] = true;
                cout << *i << " ";
                break;
            }
        }
        if (!isConnected) {
            s.pop();
        }
    }

}
int main(void) {
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i <= N; i++) {
        sort(v[i].begin(), v[i].end());
    }

    dfs(V);
    cout << endl;
    bfs(V);
}