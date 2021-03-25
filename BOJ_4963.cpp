#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

int w, h;
bool isDoneFirst = false;
vector<vector<int>> vMap;
stack<pair<int, int>> s;

void DFS(int i, int j) {
    int xval[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int yval[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    pair<int, int> cur;
    pair<int, int> next;
    
    if(s.empty() && !isDoneFirst) {
        cur = make_pair(i, j);
        s.push(cur);
        vMap[cur.first][cur.second] = 0;
        isDoneFirst = true;
    }

    while(!s.empty()) {
        cur = s.top();
        for(int i = 0; i < 8; i++) {
            next = make_pair(cur.first + xval[i], cur.second + yval[i]);     
            if(0 <= next.first && next.first < h && 0 <= next.second && next.second < w) {
                if(vMap[next.first][next.second] == 1) {
                    s.push(next);
                    vMap[next.first][next.second] = 0;
                    DFS(next.first, next.second);
                }
            }
        }
        s.pop();
        break;
    }
}

int main(void) {
    int cnt, val;
    vector<int> temp;
    vector<int> ans;

    while(true) {
        cnt = 0;
        vMap.clear();
        cin >> w >> h;
        if(w == 0 && h == 0)
            break;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> val;
                temp.push_back(val);
            }
            vMap.push_back(temp);
            temp.clear();
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(vMap[i][j] == 0)
                    continue;
                isDoneFirst = false;
                DFS(i, j);
                cnt++;
            }
        }
        ans.push_back(cnt);
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}