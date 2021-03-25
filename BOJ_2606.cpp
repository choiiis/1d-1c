#include <vector>
#include <iostream>

using namespace std;

vector<int> net[101];
bool isVisited[101] = {0, };
int count = 0;

void DFS(int x) {
    int next = 0;
    isVisited[x] = 1;
    count++;
    for(int i = 0; i < net[x].size(); i++) {
        next = net[x][i];
        if(isVisited[next] == 0) {
            isVisited[next] = 1;
            DFS(next);
        }
        
    }
}

int main(void) {
    int a, b, computer, connect;
    cin >> computer;
    cin >> connect;
    for(int i = 0; i < connect; i++) {
        cin >> a >> b;
        net[a].push_back(b);
        net[b].push_back(a);
    }
    DFS(1);
    // not including 1
    cout << count - 1 << endl;

    return 0;
}