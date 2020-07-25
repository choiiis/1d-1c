#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct tomato {
    int x, y, z = 0;
};

int M, N, H;
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, -1, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int map[101][101][101] = {0,};
queue<tomato> q;

int BFS(void) {
    tomato cur;
    tomato next;
    int value = 0;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            next = tomato({ cur.x + dx[i], cur.y + dy[i], cur.z + dz[i] });
            if (0 <= next.x && next.x < M && 0 <= next.y && next.y < N && 0 <= next.z && next.z < H) {
                if (map[next.x][next.y][next.z] == 0) {
                    q.push(next);
                    map[next.x][next.y][next.z] = map[cur.x][cur.y][cur.z] + 1;
                    value = map[next.x][next.y][next.z];
                }
            }
        }
    }
    return value - 1;
}

int main(void) {
    bool isPossible = true;
    int done = 0;
    int none = 0;
    int res;

    cin >> N >> M >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < N; k++) {
                cin >> map[j][k][i];
                if (map[j][k][i] == 1) {
                    done++;
                    q.push(tomato({ j,k,i }));
                }
                if (map[j][k][i] == -1) {
                    none++;
                }
            }
        }
    }

    if (done + none == M * N * H) {
        if (none == M * N * H) {
            cout << -1;
        }
        else {
            cout << 0;
        }
    }
    else {
        res = BFS();

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < N; k++) {
                    if (map[j][k][i] == 0) {
                        isPossible = false;
                    }
                }
            }
        }

        if (isPossible) {
            cout << res;
        }
        else {
            cout << -1;
        }
    }
    
    return 0;
}