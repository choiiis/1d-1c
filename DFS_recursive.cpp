#include <iostream>
#include <vector>

using namespace std;

vector<int> v[10] = { {}, {2, 3}, {1, 3, 4, 5},
    {1, 2, 6, 7}, { 2, 8 }, { 2, 9 }, { 3 }, { 3 }, { 4 }, { 5 } };
bool isVisited[9];

void bfs(int cur_node) {
    cout << "cur node : " << cur_node << endl;
    isVisited[cur_node] = true;
    for (auto i = v[cur_node].begin(); i != v[cur_node].end(); i++) {
        if(!isVisited[*i])
            bfs(*i);
    }
}

int main(void) {
    bfs(1);
}