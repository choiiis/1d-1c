#include <iostream>
#include <queue>

using namespace std;
int main(void) {
    int N, M;
    int maze[101][101] = { 0, };
    int count[101][101] = { 0, };
    bool isVisited[101][101] = { false, };
    int dir[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
    queue<pair<int, int>> q;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%1d", &maze[i][j]);
        }
    }

    q.push(make_pair(1, 1));
    isVisited[1][1] = true;
    count[1][1] = 1;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        bool isConnected = false;
        int cur_x = cur.first;
        int cur_y = cur.second;
        for (int i = 0; i < 4; i++) {
            int next_x = cur.first + dir[i][0];
            int next_y = cur.second + dir[i][1];
            if(maze[next_x][next_y] == 1 && isVisited[next_x][next_y] == false){
                q.push(make_pair(next_x, next_y));
                isVisited[next_x][next_y] = true;
                count[next_x][next_y] = count[cur_x][cur_y] + 1;
                isConnected = true;
            }
        }
    }
    cout << count[N][M];
}