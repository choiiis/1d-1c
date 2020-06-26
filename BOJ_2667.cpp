#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> isVisited;
int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };


int bfs(pair<int, int> init_pair) {
    queue<pair<int, int>> q;
    int count = 1;
    pair<int, int> cur = init_pair;
    isVisited[cur.first][cur.second] = true;
    q.push(init_pair);

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = make_pair(cur.first + dir[i][0], cur.second + dir[i][1]);
            if (isVisited[next.first][next.second] == false && map[next.first][next.second] == 1) {
                isVisited[next.first][next.second] = true;
                count += 1;
                q.push(make_pair(next.first, next.second));
            }
        }    
    }

    return count;
    
}


int dfs(pair<int, int> init_pair) {
    stack<pair<int, int>> q;
    int count = 1;
    pair<int, int> cur = init_pair;
    isVisited[cur.first][cur.second] = true;
    q.push(init_pair);

    while (!q.empty()) {
        pair<int, int> cur = q.top();
        bool isConnected = false;
        //q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = make_pair(cur.first + dir[i][0], cur.second + dir[i][1]);
            if (isVisited[next.first][next.second] == false && map[next.first][next.second] == 1) {
                isVisited[next.first][next.second] = true;
                count += 1;
                q.push(make_pair(next.first, next.second));
                isConnected = true;
                break;
            }
        }
        if (isConnected == false) {
            q.pop();
        }
    }

    return count;
}

int main(void) {
    int N, tmp;
    vector<int> complex;
    cin >> N;
    map.assign(N + 2, vector<int>(N + 2,0));
    isVisited.assign(N + 2, vector<bool>(N + 2, false));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 1 && isVisited[i][j] == 0) {
                int complex_num = dfs(make_pair(i, j));
                complex.push_back(complex_num);
            }
        }
    }

    cout << complex.size() << endl;
    sort(complex.begin(), complex.end());
    for (auto i = complex.begin(); i != complex.end(); i++) {
        cout << *i << endl;
    }
}