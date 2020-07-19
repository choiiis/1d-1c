#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };

int waterTime[51][51] = { 0, };
int hedgeTime[51][51] = { 0, };
char map[51][51] = { 0, };

pair<int, int> start;
pair<int, int> finish;
queue<pair<int, int>> water;

int BFS(void) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            waterTime[i][j] = -1;
        }
    }
    queue<pair<int, int>> pos;
    pair<int, int> cur;
    pair<int, int> next;
    
    pos.push(make_pair(start.first, start.second));
    hedgeTime[start.first][start.second] = 0;
    if(!water.empty())
        waterTime[water.front().first][water.front().second] = 0;

    while (!water.empty()) {
        cur = water.front();
        water.pop();
        for (int i = 0; i < 4; i++) {
            next = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (0 <= next.first && next.first < R && 0 <= next.second && next.second < C) {
                if (map[next.first][next.second] != '*' && map[next.first][next.second] != 'D' && map[next.first][next.second] != 'X') {
                    if (waterTime[next.first][next.second] == -1) {
                        water.push(make_pair(next.first, next.second));
                        waterTime[next.first][next.second] = waterTime[cur.first][cur.second] + 1;
                    }
                    
                }
            }
        }
    }

    while (!pos.empty()) {
        cur = pos.front();
        pos.pop();
        for (int i = 0; i < 4; i++) {
            next = make_pair(cur.first + dx[i], cur.second + dy[i]);
            if (next.first == finish.first && next.second == finish.second) {
                return hedgeTime[cur.first][cur.second] + 1;
            }
            else if (0 <= next.first && next.first < R && 0 <= next.second && next.second < C) {
                if (map[next.first][next.second] == '.'&& hedgeTime[next.first][next.second] == 0) {
                    if (hedgeTime[cur.first][cur.second] + 1 != waterTime[next.first][next.second]) {
                        pos.push(make_pair(next.first, next.second));
                        hedgeTime[next.first][next.second] = hedgeTime[cur.first][cur.second] + 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main(void) {
    int res, start_i = 0, start_j = 0;
    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                start.first = i;
                start.second = j;
            }

            else if (map[i][j] == 'D') {
                finish.first = i;
                finish.second = j;
            }

            else if (map[i][j] == '*') {
                water.push(make_pair(i, j));
            }
        }
    }

    res = BFS();
    if (res == -1) {
        cout << "KAKTUS";
    }
    else {
        cout << res;
    }
    return 0;
}